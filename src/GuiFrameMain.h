/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUIFRAMEMAIN_H
#define GUIFRAMEMAIN_H

#include "Gui.h"
#include "ConfigBase.h"
#include "FileListManager.h"
#include "DndFile.h"

class GuiFrameMain : public FrameMain {
public:
    GuiFrameMain(wxWindow *parent);

    virtual ~GuiFrameMain();

    void setFilesCmdLine(const wxArrayString &filenames);

protected:
    void OnlstFilesDeleteItem(wxListEvent &event);

    void OnlstFilesInsertItem(wxListEvent &event);

    void OnlstFilesItemSelect(wxListEvent &event);

    void OnlstFilesItemRClick(wxListEvent &event);

    void OnlstFilesKeyDown(wxListEvent &event);

    void mnuAddDirectory(wxCommandEvent &event);

    void mnuAddFiles(wxCommandEvent &event);

    void mnuExit(wxCommandEvent &event);

    void mnuRemoveFiles(wxCommandEvent &event);

    void mnuClearList(wxCommandEvent &event);

    void mnuSettings(wxCommandEvent &event);

    void mnuEncode(wxCommandEvent &event);

    void mnuDecode(wxCommandEvent &event);

    void mnuToolWebsite(wxCommandEvent &event);

    void mnuWebsite(wxCommandEvent &event);

    void mnuAbout(wxCommandEvent &event);

    void OnTimer1Trigger(wxTimerEvent &event);

private:
    void updateControls();

    void loadResources();

    ConfigBase *mp_configBase;
    FileListManager *mp_fileListManager;
    DndFile *mp_dndFile;
    wxString m_exeTool;
    wxArrayString m_exeInputString;
    wxArrayString m_exeInputErrorString;
};

#endif // GUIFRAMEMAIN_H
