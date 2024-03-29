/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiFrameMain.hpp"
#include "../Constants.hpp"
#include "GuiDialogProgress.hpp"
#include "GuiDialogSettings.hpp"

#include <wx/aboutdlg.h>

GuiFrameMain::GuiFrameMain(wxWindow *parent) : FrameMain(parent) {
    // Disable status bar pane used to display menu and toolbar help
    SetStatusBarPane(-1);

    // File list manager
    mp_listManager = new ListManager(gui_lstFiles);

    // List Drag & Drop
    mp_fileDrop = new FileDrop(mp_listManager);
    gui_lstFiles->SetDropTarget(mp_fileDrop);

    // List title
    gui_lstFiles->InsertColumn(ID_LIST_FILE, _("File"), wxLIST_FORMAT_LEFT, 300);
    gui_lstFiles->InsertColumn(ID_LIST_FOLDER, _("Folder"), wxLIST_FORMAT_LEFT, 300);
    gui_lstFiles->InsertColumn(ID_LIST_FORMAT, _("Format"), wxLIST_FORMAT_LEFT, 70);

    // Set statusbar widths
    const int wxStatusBarWidths[3] = {-10, -5, -10};
    gui_mainStatusBar->SetStatusWidths(3, wxStatusBarWidths);

    // Configuration file
    mp_appSettings = new AppSettings(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Updates the controls
    updateControls();
}

GuiFrameMain::~GuiFrameMain() {
    delete mp_listManager;
    delete mp_appSettings;
}

void GuiFrameMain::OnlstFilesDeleteItem(wxListEvent &event) {
    mp_listManager->deleteItem((unsigned long)event.GetIndex());

    updateControls();
    event.Skip();
}

void GuiFrameMain::OnlstFilesInsertItem(wxListEvent &event) {
    updateControls();
    event.Skip();
}

void GuiFrameMain::OnlstFilesItemSelect(wxListEvent &event) {
    updateControls();
    event.Skip();
}

void GuiFrameMain::OnlstFilesItemRClick(wxListEvent &event) {
    updateControls();

    // Displays the popup menu when you click a list item
    gui_lstFiles->PopupMenu(gui_menu);
    event.Skip();
}

void GuiFrameMain::OnlstFilesKeyDown(wxListEvent &event) {
    // Remove files with Delete key
    int keyCode = event.GetKeyCode();
    if (keyCode == WXK_DELETE)
        mnuRemoveFiles(event);

    event.Skip();
}

void GuiFrameMain::mnuAddDirectory(wxCommandEvent &event) {
    wxString msg = _("Select directory");
    wxDirDialog dirDialog(this, msg, wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    dirDialog.SetPath(mp_appSettings->getLastOpenDir());
    if (dirDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);
        mp_listManager->insertDir(dirDialog.GetPath());

        // Remembers the last used directory
        mp_appSettings->setLastOpenDir(dirDialog.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
    event.Skip(false);
}

void GuiFrameMain::mnuAddFiles(wxCommandEvent &event) {
    wxArrayString files;
    wxString msg = _("Select file");
    wxFileDialog fileDialog(this, msg, wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    fileDialog.SetDirectory(mp_appSettings->getLastOpenDir());

    if (fileDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        fileDialog.GetPaths(files);
        mp_listManager->insertFiles(files);

        // Remembers the last used directory
        mp_appSettings->setLastOpenDir(fileDialog.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
    event.Skip(false);
}

void GuiFrameMain::mnuExit(wxCommandEvent &event) {
    // Terminates the program
    Close();
    event.Skip(false);
}

void GuiFrameMain::mnuRemoveFiles(wxCommandEvent &event) {
    int itemCount = gui_lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++) {
        long item = gui_lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        gui_lstFiles->DeleteItem(item);
    }
    SetCursor(wxCURSOR_ARROW);

    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuClearList(wxCommandEvent &event) {
    event.Skip(false);
    // Deletes all items from the list
    mp_listManager->clear();

    updateControls();
}

void GuiFrameMain::mnuSettings(wxCommandEvent &event) {
    // Displays the "Settings" window
    GuiDialogSettings guiSettings(this, mp_appSettings);
    guiSettings.ShowModal();

    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuEncode(wxCommandEvent &event) {
    event.Skip(false);
    // Displays the "Progress" window
    GuiDialogProgress dialogProgress(this, mp_appSettings, mp_listManager, LAME_ENCODE);
    dialogProgress.ShowModal();
}

void GuiFrameMain::mnuDecode(wxCommandEvent &event) {
    // Displays the "Progress" window
    GuiDialogProgress dialogProgress(this, mp_appSettings, mp_listManager, LAME_DECODE);
    dialogProgress.ShowModal();
    event.Skip(false);
}

void GuiFrameMain::mnuToolWebsite(wxCommandEvent &event) {
    wxLaunchDefaultBrowser(_T("https://lame.sourceforge.io/"));
    event.Skip(false);
}

void GuiFrameMain::mnuWebsite(wxCommandEvent &event) {
    event.Skip(false);
    wxLaunchDefaultBrowser(APP_WEBSITE);
}

void GuiFrameMain::mnuAbout(wxCommandEvent &event) {
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(APP_NAME);
    aboutInfo.SetVersion(APP_VERSION);
    aboutInfo.SetDescription(_("Free front-end for the Lame"));
    aboutInfo.SetCopyright(APP_COPYRIGHT);
    wxString dataDir = getDataDir();
    aboutInfo.SetIcon(wxIcon(dataDir + _T("icons/app.ico"), wxBITMAP_TYPE_ICO));
    wxAboutBox(aboutInfo);
    event.Skip(false);
}

void GuiFrameMain::OnTimer1Trigger(wxTimerEvent &event) {
    wxString newExeTool = APP_TOOL_EXECUTABLE;
    if (!m_exeTool.IsSameAs(newExeTool, false)) {
        m_exeInputString.Clear();
        m_exeInputErrorString.Clear();
        m_exeTool = newExeTool;
        // Execute external application
        wxExecute(m_exeTool + _T(" -v"), m_exeInputString, m_exeInputErrorString, wxEXEC_NODISABLE);

        // Show the version of tool
        if (!m_exeInputErrorString.IsEmpty())
            gui_mainStatusBar->SetStatusText(m_exeInputErrorString.Item(0), 0);
        else
            gui_mainStatusBar->SetStatusText(_("LAME not found!"), 0);
    }

    // Show the number of files in list on status bar
    wxString msg;
    msg = wxString::Format(_T("%i "), gui_lstFiles->GetItemCount());
    msg += _("files");
    gui_mainStatusBar->SetStatusText(msg, 1);

    // Show the parameters
    msg = _("Lame options: ");
    msg = mp_appSettings->getStringLameOptions();
    gui_mainStatusBar->SetStatusText(msg, 2);

    // Disables the menu item "Remove files" if no item is selected
    gui_menu->Enable(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0);
    gui_menuBar->Enable(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0);
    gui_toolBar->EnableTool(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0);

    // Disables the menu item "Clear list" if there is no item in the list
    gui_menu->Enable(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0);
    gui_menuBar->Enable(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0);
    gui_toolBar->EnableTool(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0);

    // Disables menus Encode and Decode case there is no item in the list
    gui_menuBar->Enable(ID_ENCODE, gui_lstFiles->GetItemCount() > 0);
    gui_menuBar->Enable(ID_DECODE, gui_lstFiles->GetItemCount() > 0);
    gui_toolBar->EnableTool(ID_ENCODE, gui_lstFiles->GetItemCount() > 0);
    gui_toolBar->EnableTool(ID_DECODE, gui_lstFiles->GetItemCount() > 0);
    event.Skip(false);
}

void GuiFrameMain::loadResources() {
    wxString dataDir = getDataDir();

    // Window icon
    SetIcon(wxIcon(dataDir + _T("icons/app.ico"), wxBITMAP_TYPE_ICO));

    // Toolbar bitmaps
    gui_toolBar->SetToolNormalBitmap(ID_ADD_FILES, wxBitmap(wxImage(dataDir + _T("toolbar/add-file.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_ADD_FOLDER, wxBitmap(wxImage(dataDir + _T("toolbar/add-folder.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_REMOVE_FILES, wxBitmap(wxImage(dataDir + _T("toolbar/remove.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_CLEAR_LIST, wxBitmap(wxImage(dataDir + _T("toolbar/clear.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_ENCODE, wxBitmap(wxImage(dataDir + _T("toolbar/encode.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_DECODE, wxBitmap(wxImage(dataDir + _T("toolbar/decode.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_SETTINGS, wxBitmap(wxImage(dataDir + _T("toolbar/settings.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_ABOUT, wxBitmap(wxImage(dataDir + _T("toolbar/about.png"))));
}

void GuiFrameMain::updateControls() {
    /*
     * :KLUDGE:
     * EVT_LIST_INSERT_ITEM is triggered before or after item is added:
     *   on wxGTK -> triggered before item is added;
     *   on wxMSW -> triggered after item is added.
     */
    m_timer1.Start(20, true);
}

void GuiFrameMain::setFilesCmdLine(const wxArrayString &filenames) {
    mp_listManager->insertFilesAndDir(filenames);
}
