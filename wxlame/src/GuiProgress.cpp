/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiProgress.h"
#include "Global.h"

#include <wx/app.h>
#include <wx/txtstrm.h>
#include <wx/msgdlg.h>
#include <wx/filename.h>
#include <wx/filefn.h>
#include <wx/file.h>

BEGIN_EVENT_TABLE(GuiProgress, Progress)
EVT_END_PROCESS(ID_TOOL_PROCESS, GuiProgress::OnProcessTerm)
END_EVENT_TABLE()

GuiProgress::GuiProgress(wxWindow* parent, ConfigBase* configBase, ArrayOfFiles* lstFilesData, int workType)
: Progress(parent), mp_configBase(configBase), mp_lstFilesData(lstFilesData), m_fileIterator(0), m_workType(workType), m_workingProgress(false) {
    // Initializes the process
    mp_process = new wxProcess(this, ID_TOOL_PROCESS);
    mp_process->Redirect();
}

GuiProgress::~GuiProgress() {
}

void GuiProgress::OnClose(wxCloseEvent& event) {
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

void GuiProgress::OnIdle(wxIdleEvent& event) {
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

void GuiProgress::OnInit(wxInitDialogEvent& event) {
    // Change the button's label to "Cancel"
    g_btnCancel->SetLabel(_("Cancel"));
    m_workingProgress = true;

    // Initializes the timer for the async process
    m_timer2.Start(100);

    // Sets the maximum of "bar list"
    g_gaugeListProgress->SetRange(mp_lstFilesData->GetCount());

    // Processes the first file
    processNextFile();

    // Updates the labels
    stringLabelsUpdate();
}

void GuiProgress::OnbtnCancelClick(wxCommandEvent& event) {
    Close();
}

void GuiProgress::OnTimer2Trigger(wxTimerEvent& event) {
    wxWakeUpIdle();

    // Updates the "files bar" every 500 ms
    stringToGaugeUpdate(m_inputString);

    // Updates the labels
    stringLabelsUpdate();
}

void GuiProgress::OnProcessTerm(wxProcessEvent& event) {
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

void GuiProgress::finishedWork() {
    m_timer2.Stop();

    g_gaugeFileProgress->SetRange(1);
    g_gaugeFileProgress->SetValue(1);

    // Change the button's label to "Close"
    g_btnCancel->SetLabel(_("Close"));
    m_workingProgress = false;
}

void GuiProgress::stringToGaugeUpdate(const wxString & inputString) {
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

void GuiProgress::processNextFile() {
    FileInfo& fileInfo = mp_lstFilesData->Item(m_fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    wxFileName filenameOutput = filenameInput;
    wxString fullCommand = APP_TOOL_EXECUTABLE + _T(" ");

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

void GuiProgress::stringLabelsUpdate() {
    size_t total = mp_lstFilesData->GetCount();
    g_lblStatusList->SetLabel(wxString::Format(_("Processed %lu files of %lu."), m_fileIterator, total));
    if (m_fileIterator < total) {
        FileInfo& fileInfo = mp_lstFilesData->Item(m_fileIterator);
        wxFileName filenameInput = fileInfo.getFileName();

        g_lblStatusFile->SetLabel((m_workType == LAME_ENCODE ? _("Encoding: ") : _("Decoding: ")) + filenameInput.GetFullName());
    }
}
