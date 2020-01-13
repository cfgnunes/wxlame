/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUIDIALOGPROGRESS_H
#define GUIDIALOGPROGRESS_H

#include "Gui.h"
#include "ConfigBase.h"
#include "FileListManager.h"

#include <wx/process.h>

enum {
    LAME_ENCODE = 0,
    LAME_DECODE = 1,
};

const int ID_TOOL_PROCESS = ::wxNewId();

class GuiDialogProgress : public DialogProgress {
public:
    GuiDialogProgress(wxWindow *parent, ConfigBase *configBase, FileListManager *fileListManager, int workType);

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

    ConfigBase *mp_configBase;
    FileListManager *mp_fileListManager;
    wxProcess *mp_process;
    unsigned long int m_fileIterator;
    int m_workType;
    bool m_workingProgress;
    long m_processPID;
    wxString m_inputString;

DECLARE_EVENT_TABLE()
};

#endif // GUIDIALOGPROGRESS_H
