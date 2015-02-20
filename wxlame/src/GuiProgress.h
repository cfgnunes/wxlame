/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUIPROGRESS_H
#define GUIPROGRESS_H

#include "Gui.h"
#include "FileInfo.h"
#include "ConfigBase.h"

#include <wx/process.h>
#include <list>

enum {
    LAME_ENCODE = 0,
    LAME_DECODE = 1,
};

const int ID_TOOL_PROCESS = ::wxNewId();

class GuiProgress : public Progress {
public:
    GuiProgress(wxWindow *parent, ConfigBase *configBase, std::list<FileInfo> *lstFilesData, int workType);
    virtual ~GuiProgress();

protected:
    void OnClose(wxCloseEvent& event);
    void OnIdle(wxIdleEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnbtnCancelClick(wxCommandEvent& event);
    void OnTimer2Trigger(wxTimerEvent& event);
    void OnProcessTerm(wxProcessEvent& event);

private:
    void processNextFile();
    void finishedWork();
    void stringToGaugeUpdate(const wxString& inputString);
    void stringLabelsUpdate();

    ConfigBase *mp_configBase;
    std::list<FileInfo> *mp_lstFilesData;
    wxProcess *mp_process;
    size_t m_fileIterator;
    int m_workType;
    bool m_workingProgress;
    long m_processPID;
    wxString m_inputString;

    DECLARE_EVENT_TABLE()
};

#endif // GUIPROGRESS_H
