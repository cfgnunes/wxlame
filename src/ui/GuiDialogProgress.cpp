/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "../Constants.hpp"
#include "GuiDialogProgress.hpp"

#include <wx/app.h>
#include <wx/msgdlg.h>
#include <wx/txtstrm.h>

BEGIN_EVENT_TABLE(GuiDialogProgress, DialogProgress)
EVT_END_PROCESS(ID_TOOL_PROCESS, GuiDialogProgress::OnProcessTerm)
END_EVENT_TABLE()

GuiDialogProgress::GuiDialogProgress(wxWindow *parent, AppSettings *appSettings, ListCtrlManager *listCtrlManager, int workType)
    : DialogProgress(parent), mp_appSettings(appSettings), mp_listCtrlManager(listCtrlManager), m_fileIterator(0),
      m_workType(workType), m_workingProgress(false) {
    // Initializes the process
    mp_process = new wxProcess(this, ID_TOOL_PROCESS);
    mp_process->Redirect();
}

GuiDialogProgress::~GuiDialogProgress() {
}

void GuiDialogProgress::OnClose(wxCloseEvent &event) {
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
    event.Skip(false);
}

void GuiDialogProgress::OnIdle(wxIdleEvent &event) {
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

void GuiDialogProgress::OnInit(wxInitDialogEvent &event) {
    // Change the button's label to "Cancel"
    gui_btnCancel->SetLabel(_("Cancel"));
    m_workingProgress = true;

    // Initializes the timer for the async process
    m_timer2.Start(100);

    // Sets the maximum of "bar list"
    gui_gaugeListProgress->SetRange((int)mp_listCtrlManager->size());

    // Processes the first file
    processNextFile();

    // Updates the labels
    stringLabelsUpdate();
    event.Skip(false);
}

void GuiDialogProgress::OnbtnCancelClick(wxCommandEvent &event) {
    Close();
    event.Skip(false);
}

void GuiDialogProgress::OnTimer2Trigger(wxTimerEvent &event) {
    wxWakeUpIdle();

    // Updates the "files bar" every 500 ms
    stringToGaugeUpdate(m_inputString);

    // Updates the labels
    stringLabelsUpdate();
    event.Skip(false);
}

void GuiDialogProgress::OnProcessTerm(wxProcessEvent &event) {
    // Positions for next file
    if (m_workingProgress)
        m_fileIterator++;

    // Update the value of "bar list"
    gui_gaugeListProgress->SetValue((int)m_fileIterator);

    // Updates the labels
    stringLabelsUpdate();

    // Processes the next file
    if (m_workingProgress) {
        // Delete the file already processed
        if (mp_appSettings->getDeleteFiles()) {
            FileInfo &fileInfo = mp_listCtrlManager->getItem(m_fileIterator - 1);
            wxFileName filenameInput = fileInfo.getFileName();

            wxRemoveFile(filenameInput.GetFullPath());
        }

        unsigned long int total = mp_listCtrlManager->size();
        if (m_fileIterator < total)
            processNextFile();
        else
            finishedWork();
    }
    event.Skip(false);
}

void GuiDialogProgress::finishedWork() {
    m_timer2.Stop();

    gui_gaugeFileProgress->SetRange(1);
    gui_gaugeFileProgress->SetValue(1);

    // Change the button's label to "Close"
    gui_btnCancel->SetLabel(_("Close"));
    m_workingProgress = false;
}

void GuiDialogProgress::stringToGaugeUpdate(const wxString &inputString) {
    long maxValue = 0;
    long currentValue = 0;
    if (m_workType == LAME_ENCODE) {
        inputString.BeforeFirst('%').AfterFirst('(').ToLong(&currentValue);
        gui_gaugeFileProgress->SetRange(100);
        gui_gaugeFileProgress->SetValue((int)currentValue);
    } else {
        inputString.AfterFirst('/').BeforeFirst(' ').ToLong(&maxValue);
        inputString.BeforeFirst('/').AfterFirst(' ').ToLong(&currentValue);
        gui_gaugeFileProgress->SetRange((int)maxValue);
        gui_gaugeFileProgress->SetValue((int)currentValue);
    }
}

void GuiDialogProgress::processNextFile() {
    FileInfo &fileInfo = mp_listCtrlManager->getItem(m_fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    wxFileName filenameOutput = filenameInput;
    wxString fullCommand = APP_TOOL_EXECUTABLE + _T(" ");

    // Encode or Decode
    if (m_workType == LAME_ENCODE)
        fullCommand.append(mp_appSettings->getStringLameOptions());
    else
        fullCommand.append(_T("--decode"));

    // Sets the output directory of the file
    if (mp_appSettings->getEnableOutDir())
        filenameOutput.SetPath(mp_appSettings->getOutDir());

    // Defines the file extension
    if (m_workType == LAME_ENCODE)
        filenameOutput.SetExt(_T("mp3"));
    else
        filenameOutput.SetExt(_T("wav"));

    // Execute external application
    m_processPID = wxExecute(
        fullCommand + _T(" \"") + filenameInput.GetFullPath() + _T("\" \"") + filenameOutput.GetFullPath() +
            _T("\""),
        wxEXEC_ASYNC, mp_process);
}

void GuiDialogProgress::stringLabelsUpdate() {
    unsigned long int total = mp_listCtrlManager->size();
    gui_lblStatusList->SetLabel(wxString::Format(_("Processed %lu files of %lu."), m_fileIterator, total));
    if (m_fileIterator < total) {
        FileInfo fileInfo = mp_listCtrlManager->getItem(m_fileIterator);
        wxFileName filenameInput = fileInfo.getFileName();

        gui_lblStatusFile->SetLabel(
            (m_workType == LAME_ENCODE ? _("Encoding: ") : _("Decoding: ")) + filenameInput.GetFullName());
    }
}
