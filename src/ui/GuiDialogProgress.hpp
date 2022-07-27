/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUI_DIALOG_PROGRESS_HPP
#define GUI_DIALOG_PROGRESS_HPP

#include "../AppSettings.hpp"
#include "../ListManager.hpp"
#include "Gui.h"

#include <wx/process.h>

enum {
    LAME_ENCODE = 0,
    LAME_DECODE = 1,
};

const int ID_TOOL_PROCESS = ::wxNewId();

class GuiDialogProgress : public DialogProgress {
  public:
    GuiDialogProgress(wxWindow *parent, AppSettings *appSettings, ListManager *listManager, int workType);
    virtual ~GuiDialogProgress();

  protected:
    void OnClose(wxCloseEvent &event);
    void OnIdle(wxIdleEvent &event);
    void OnInit(wxInitDialogEvent &event);
    void OnbtnCancelClick(wxCommandEvent &event);
    void OnTimer2Trigger(wxTimerEvent &event);
    void OnProcessTerm(wxProcessEvent &event);

  private:
    void processNextFile();
    void finishedWork();
    void stringToGaugeUpdate(const wxString &inputString);
    void stringLabelsUpdate();

    AppSettings *mp_appSettings;
    ListManager *mp_listManager;
    wxProcess *mp_process;
    unsigned long int m_fileIdx;
    int m_workType;
    bool m_workingProgress;
    long m_processPID;
    wxString m_inputString;

    DECLARE_EVENT_TABLE()
};

#endif // GUI_DIALOG_PROGRESS_HPP
