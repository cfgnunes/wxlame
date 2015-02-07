/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmProgress.h"
#include "Global.h"

//(*InternalHeaders(frmProgress)
#include <wx/string.h>
#include <wx/intl.h>
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
: mp_configBase(configBase), mp_lstFilesData(lstFilesData), m_fileIterator(0), m_workType(workType), m_workingProgress(false) {
    //(*Initialize(frmProgress)
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Progress"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    g_lblStatusList = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(g_lblStatusList, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    g_gaugeListProgress = new wxGauge(this, ID_GAUGE1, 100, wxDefaultPosition, wxSize(370, 20), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    BoxSizer1->Add(g_gaugeListProgress, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_lblStatusFile = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer1->Add(g_lblStatusFile, 0, wxALL | wxEXPAND | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5);
    g_gaugeFileProgress = new wxGauge(this, ID_GAUGE2, 100, wxDefaultPosition, wxSize(370, 20), 0, wxDefaultValidator, _T("ID_GAUGE2"));
    BoxSizer1->Add(g_gaugeFileProgress, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
    g_btnCancel = new wxButton(this, ID_BUTTON1, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(g_btnCancel, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
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
    mp_process = new wxProcess(this);
    mp_process->Redirect();
}

frmProgress::~frmProgress() {
    delete mp_process;
}

void frmProgress::OnInit(wxInitDialogEvent& event) {
    // Change the button's label to "Cancel"
    g_btnCancel->SetLabel(_("Cancel"));
    m_workingProgress = true;

    // Initializes the timer for the async process
    Timer1.Start(100);

    // Sets the maximum of "bar list"
    g_gaugeListProgress->SetRange(mp_lstFilesData->GetCount());

    // Processes the first file
    processNextFile();

    // Updates the labels
    stringLabelsUpdate();
}

void frmProgress::processNextFile() {
    FileInfo& fileInfo = mp_lstFilesData->Item(m_fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    wxFileName filenameOutput = filenameInput;
    wxString fullCommand = mp_configBase->getEncoderExecutable() + _T(" ");

    // Encode or Decode
    if (m_workType == LAME_ENCODE)
        fullCommand.append(mp_configBase->getStringLameOptions());
    else
        fullCommand.append(_T("--decode"));

    // Sets the output directory of the file
    if (mp_configBase->getEnableOutDir())
        filenameOutput.SetPath(mp_configBase->getOutDir());

    // Defines the file extension
    if (m_workType == LAME_ENCODE)
        filenameOutput.SetExt(_T("mp3"));
    else
        filenameOutput.SetExt(_T("wav"));

    // Execute external application
    m_processPID = wxExecute(fullCommand + _T(" \"") + filenameInput.GetFullPath() + _T("\" \"") + filenameOutput.GetFullPath() + _T("\""), wxEXEC_ASYNC, mp_process);
}

void frmProgress::stringLabelsUpdate() {
    size_t total = mp_lstFilesData->GetCount();
    g_lblStatusList->SetLabel(wxString::Format(_("Processed %lu files of %lu."), m_fileIterator, total));
    if (m_fileIterator < total) {
        FileInfo& fileInfo = mp_lstFilesData->Item(m_fileIterator);
        wxFileName filenameInput = fileInfo.getFileName();

        g_lblStatusFile->SetLabel((m_workType == LAME_ENCODE ? _("Encoding: ") : _("Decoding: ")) + filenameInput.GetFullName());
    }
}

void frmProgress::OnTimer1Trigger(wxTimerEvent& event) {
    wxWakeUpIdle();

    // Updates the "files bar" every 500 ms
    stringToGaugeUpdate(m_inputString);

    // Updates the labels
    stringLabelsUpdate();
}

void frmProgress::OnIdle(wxIdleEvent& event) {
    wxString tempString;

    if (mp_process->IsErrorAvailable()) {
        wxTextInputStream tis(*mp_process->GetErrorStream());
        tempString = tis.ReadLine();

        if (m_workType == LAME_ENCODE) {
            // Capturing the correct line string
            if (tempString.Find('(') > 0 && tempString.Find('%') > 0)
                m_inputString = tempString;
        } else {
            // Capturing the correct line string
            if (tempString.Find('#') > 0 && tempString.Find('/') > 0)
                m_inputString = tempString;
        }
        event.RequestMore();
    }
    event.Skip();
}

void frmProgress::OnbtnCancelClick(wxCommandEvent& event) {
    Close();
}

void frmProgress::OnProcessTerm(wxProcessEvent& event) {
    // Positions for next file
    if (m_workingProgress)
        m_fileIterator++;

    // Update the value of "bar list"
    g_gaugeListProgress->SetValue(m_fileIterator);

    // Updates the labels
    stringLabelsUpdate();

    // Processes the next file
    if (m_workingProgress) {
        // Delete the file already processed
        if (mp_configBase->getDeleteFiles()) {
            FileInfo& fileInfo = mp_lstFilesData->Item(m_fileIterator - 1);
            wxFileName filenameInput = fileInfo.getFileName();
            wxRemoveFile(filenameInput.GetFullPath());
        }

        size_t total = mp_lstFilesData->GetCount();
        if (m_fileIterator < total)
            processNextFile();
        else
            finishedWork();
    }
}

void frmProgress::finishedWork() {
    Timer1.Stop();

    g_gaugeFileProgress->SetRange(1);
    g_gaugeFileProgress->SetValue(1);

    // Change the button's label to "Close"
    g_btnCancel->SetLabel(_("Close"));
    m_workingProgress = false;
}

void frmProgress::stringToGaugeUpdate(const wxString & inputString) {
    long maxValue = 0;
    long currentValue = 0;
    if (m_workType == LAME_ENCODE) {
        inputString.BeforeFirst('%').AfterFirst('(').ToLong(&currentValue);
        g_gaugeFileProgress->SetRange(100);
        g_gaugeFileProgress->SetValue(currentValue);
    } else {
        inputString.AfterFirst('/').BeforeFirst(' ').ToLong(&maxValue);
        inputString.BeforeFirst('/').AfterFirst(' ').ToLong(&currentValue);
        g_gaugeFileProgress->SetRange(maxValue);
        g_gaugeFileProgress->SetValue(currentValue);
    }
}

void frmProgress::OnClose(wxCloseEvent& event) {
    if (event.CanVeto()) {
        if (m_workingProgress) {
            if (wxMessageBox(_("Do you want to stop process now?"), APP_NAME, wxYES_NO | wxICON_QUESTION) == wxYES) {
                // Kill the process
                m_workingProgress = false;
                mp_process->Detach();
                wxKill(m_processPID, wxSIGKILL);
                finishedWork();
            } else {
                event.Veto();
                return;
            }
        }
    }
    Destroy();
}
