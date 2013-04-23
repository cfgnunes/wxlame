/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmProgress.h"

//(*InternalHeaders(frmProgress)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/app.h>
#include <wx/txtstrm.h>
#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <wx/filefn.h>
#include <wx/file.h>

//(*IdInit(frmProgress)
const long frmProgress::ID_STATICTEXT1 = wxNewId();
const long frmProgress::ID_GAUGE1 = wxNewId();
const long frmProgress::ID_STATICTEXT2 = wxNewId();
const long frmProgress::ID_GAUGE2 = wxNewId();
const long frmProgress::ID_BUTTON1 = wxNewId();
const long frmProgress::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(frmProgress, wxDialog)
//(*EventTable(frmProgress)
//*)
    EVT_IDLE(frmProgress::OnIdle)
    EVT_END_PROCESS(wxID_ANY, frmProgress::OnProcessTerm)
END_EVENT_TABLE()

frmProgress::frmProgress(wxWindow* parent, ConfigBase* configBase, ArrayOfFiles* lstFilesData, int workType, wxWindowID id, const wxPoint& pos, const wxSize& size)
    : configBase(configBase), lstFilesData(lstFilesData), fileIterator(0), workType(workType), workingProgress(false)
{
    //(*Initialize(frmProgress)
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Working progress"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    lblStatusList = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(lblStatusList, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    gaugeListProgress = new wxGauge(this, ID_GAUGE1, 100, wxDefaultPosition, wxSize(370, 20), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    BoxSizer1->Add(gaugeListProgress, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    lblStatusFile = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer1->Add(lblStatusFile, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    gaugeFileProgress = new wxGauge(this, ID_GAUGE2, 100, wxDefaultPosition, wxSize(370, 20), 0, wxDefaultValidator, _T("ID_GAUGE2"));
    BoxSizer1->Add(gaugeFileProgress, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    btnCancel = new wxButton(this, ID_BUTTON1, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(btnCancel, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    Timer1.SetOwner(this, ID_TIMER1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction) & frmProgress::OnbtnCancelClick);
    Connect(ID_TIMER1, wxEVT_TIMER, (wxObjectEventFunction) & frmProgress::OnTimer1Trigger);
    Connect(wxID_ANY, wxEVT_INIT_DIALOG, (wxObjectEventFunction) & frmProgress::OnInit);
    Connect(wxID_ANY, wxEVT_CLOSE_WINDOW, (wxObjectEventFunction) & frmProgress::OnClose);
    //*)

    // Initializes the process
    process = new wxProcess(this);
    process->Redirect();
}

frmProgress::~frmProgress()
{
    //(*Destroy(frmProgress)
    //*)
}

void frmProgress::OnInit(wxInitDialogEvent& event)
{
    // Change the button's label to "Cancel"
    btnCancel->SetLabel(wxT("Cancel"));
    workingProgress = true;

    // Initializes the timer for the process async
    Timer1.Start(100);

    // Sets the maximum of "bar list"
    gaugeListProgress->SetRange(lstFilesData->GetCount());

    // Processes the first file
    processNextFile();

    // Updates the labels
    stringLabelsUpdate();
}

void frmProgress::processNextFile()
{
    FileInfo& fileInfo = lstFilesData->Item(fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    wxFileName filenameOutput = filenameInput;
    wxString fullCommand = configBase->getEncoderExecutable() + wxT(" ");

    // Encode or Decode
    if (workType == LAME_ENCODE)
        fullCommand.append(configBase->getStringLameOptions());
    else
        fullCommand.append(wxT("--decode"));

    // Sets the output directory of the file
    if (configBase->getEnableOutDir())
        filenameOutput.SetPath(configBase->getOutDir());

    // Defines the file extension
    if (workType == LAME_ENCODE)
        filenameOutput.SetExt(wxT("mp3"));
    else
        filenameOutput.SetExt(wxT("wav"));

    // Execute external application
    processPID = wxExecute(fullCommand + wxT(" \"") + filenameInput.GetFullPath() + wxT("\" \"") + filenameOutput.GetFullPath() + wxT("\""), wxEXEC_ASYNC, process);
}

void frmProgress::stringLabelsUpdate()
{
    lblStatusList->SetLabel(wxString::Format(wxT("Processed %i files of %i."), fileIterator, lstFilesData->GetCount()));
    int total = lstFilesData->GetCount();
    if (fileIterator < total)
    {
        FileInfo& fileInfo = lstFilesData->Item(fileIterator);
        wxFileName filenameInput = fileInfo.getFileName();

        lblStatusFile->SetLabel((workType == LAME_ENCODE ? wxT("Encoding: ") : wxT("Decoding: ")) + filenameInput.GetFullName());
    }
}

void frmProgress::OnTimer1Trigger(wxTimerEvent& event)
{
    wxWakeUpIdle();

    // Updates the "files bar" every 500 ms
    stringToGaugeUpdate(inputString);

    // Updates the labels
    stringLabelsUpdate();
}

void frmProgress::OnIdle(wxIdleEvent& event)
{
    wxString tempString;

    if (process->IsErrorAvailable())
    {
        wxTextInputStream tis(*process->GetErrorStream());
        tempString = tis.ReadLine();

        if (workType == LAME_ENCODE)
        {
            // Capturing the correct line string
            if (tempString.Find('(') > 0 && tempString.Find('%') > 0)
                inputString = tempString;
        }
        else
        {
            // Capturing the correct line string
            if (tempString.Find('#') > 0 && tempString.Find('/') > 0)
                inputString = tempString;
        }
        event.RequestMore();
    }
    event.Skip();
}

void frmProgress::OnbtnCancelClick(wxCommandEvent& event)
{
    Close();
}

void frmProgress::OnProcessTerm(wxProcessEvent& event)
{
    // Positions for next file
    if (workingProgress)
        fileIterator++;

    // Update the value of "bar list"
    gaugeListProgress->SetValue(fileIterator);

    // Updates the labels
    stringLabelsUpdate();

    // Processes the next file
    if (workingProgress)
    {
        // Delete the file already processed
        if (configBase->getDeleteFiles())
        {
            FileInfo& fileInfo = lstFilesData->Item(fileIterator-1);
            wxFileName filenameInput = fileInfo.getFileName();
            wxRemoveFile(filenameInput.GetFullPath());
        }

        int total = lstFilesData->GetCount();
        if (fileIterator < total)
            processNextFile();
        else
            finishedWork();
    }
}

void frmProgress::finishedWork()
{
    Timer1.Stop();

    gaugeFileProgress->SetRange(1);
    gaugeFileProgress->SetValue(1);

    // Change the button's label to "Close"
    btnCancel->SetLabel(wxT("Close"));
    workingProgress = false;
}

void frmProgress::stringToGaugeUpdate(const wxString & inputString)
{
    long maxValue = 0;
    long currentValue = 0;
    if (workType == LAME_ENCODE)
    {
        inputString.BeforeFirst('%').AfterFirst('(').ToLong(&currentValue);
        gaugeFileProgress->SetRange(100);
        gaugeFileProgress->SetValue(currentValue);
    }
    else
    {
        inputString.AfterFirst('/').BeforeFirst(' ').ToLong(&maxValue);
        inputString.BeforeFirst('/').AfterFirst(' ').ToLong(&currentValue);
        gaugeFileProgress->SetRange(maxValue);
        gaugeFileProgress->SetValue(currentValue);
    }
}

void frmProgress::OnClose(wxCloseEvent& event)
{
    if (event.CanVeto())
    {
        if (workingProgress)
        {
            if (wxMessageBox(wxT("Do you want to stop process now?"), wxT("Question"), wxYES_NO | wxICON_QUESTION) == wxYES)
            {
                // Kill the process
                workingProgress = false;
                process->Detach();
                wxKill(processPID, wxSIGKILL);

                finishedWork();
            }
            else
            {
                event.Veto();
                return;
            }
        }
    }
    Destroy();
}
