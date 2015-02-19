/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiMain.h"
#include "GuiSettings.h"
#include "GuiProgress.h"
#include "Constants.h"

#include <wx/aboutdlg.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>

GuiMain::GuiMain(wxWindow* parent)
: Main(parent) {
    // Disable status bar pane used to display menu and toolbar help
    SetStatusBarPane(-1);

    // File list manager
    mp_fileListManager = new FileListManager(g_lstFiles);

    // List Drag & Drop
    mp_dndFile = new DndFile(mp_fileListManager);
    g_lstFiles->SetDropTarget(mp_dndFile);

    // List title
    g_lstFiles->InsertColumn(0, _("File"), wxLIST_FORMAT_LEFT, 300);
    g_lstFiles->InsertColumn(1, _("Format"), wxLIST_FORMAT_LEFT, 70);
    g_lstFiles->InsertColumn(2, _("Folder"), wxLIST_FORMAT_LEFT, 300);

    // Set statusbar widths
    const int wxStatusBarWidths [3] = {-10, -5, -10};
    g_mainStatusBar->SetStatusWidths(3, wxStatusBarWidths);

    // Configuration file
    mp_configBase = new ConfigBase(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Updates the controls
    updateControls();
}

GuiMain::~GuiMain() {
    delete mp_fileListManager;
    delete mp_configBase;
}

void GuiMain::OnlstFilesDeleteItem(wxListEvent& event) {
    mp_fileListManager->deleteItem(event.GetIndex());

    updateControls();
    event.Skip();
}

void GuiMain::OnlstFilesInsertItem(wxListEvent& event) {
    updateControls();
    event.Skip();
}

void GuiMain::OnlstFilesItemSelect(wxListEvent& event) {
    updateControls();
    event.Skip();
}

void GuiMain::OnlstFilesItemRClick(wxListEvent& event) {
    updateControls();

    // Displays the popup menu when you click a list item
    g_lstFiles->PopupMenu(g_mainMenu);
    event.Skip();
}

void GuiMain::OnlstFilesKeyDown(wxListEvent& event) {
    // Remove files with Delete key
    int keyCode = event.GetKeyCode();
    if (keyCode == WXK_DELETE)
        mnuRemoveFiles(event);

    event.Skip();
}

void GuiMain::mnuAddDirectory(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    dirDialog.SetPath(mp_configBase->getLastOpenDir());
    if (dirDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);
        mp_fileListManager->insertDir(dirDialog.GetPath());

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(dirDialog.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
}

void GuiMain::mnuAddFiles(wxCommandEvent& event) {
    wxArrayString files;
    wxFileDialog fileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    fileDialog.SetDirectory(mp_configBase->getLastOpenDir());

    if (fileDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        fileDialog.GetPaths(files);
        mp_fileListManager->insertFiles(files);

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(fileDialog.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
}

void GuiMain::mnuExit(wxCommandEvent& event) {
    // Terminates the program
    Close();
}

void GuiMain::mnuRemoveFiles(wxCommandEvent& event) {
    int itemCount = g_lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++)
        g_lstFiles->DeleteItem(g_lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED));
    SetCursor(wxCURSOR_ARROW);

    updateControls();
}

void GuiMain::mnuClearList(wxCommandEvent& event) {
    // Deletes all items from the list
    mp_fileListManager->clear();

    updateControls();
}

void GuiMain::mnuSettings(wxCommandEvent& event) {
    // Displays the "Settings" window
    GuiSettings Dlg(this, mp_configBase);
    Dlg.ShowModal();

    updateControls();
}

void GuiMain::mnuEncode(wxCommandEvent& event) {
    // Displays the "Progress" window
    GuiProgress Dlg(this, mp_configBase, mp_fileListManager, LAME_ENCODE);
    Dlg.ShowModal();
}

void GuiMain::mnuDecode(wxCommandEvent& event) {
    // Displays the "Progress" window
    GuiProgress Dlg(this, mp_configBase, mp_fileListManager, LAME_DECODE);
    Dlg.ShowModal();
}

void GuiMain::mnuToolWebsite(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(_T("http://lame.sourceforge.net/"));
}

void GuiMain::mnuWebsite(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(APP_WEBSITE);
}

void GuiMain::mnuAbout(wxCommandEvent& event) {
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(APP_NAME);
    aboutInfo.SetVersion(APP_VERSION);
    aboutInfo.SetDescription(_("Free front-end for the Lame"));
    aboutInfo.SetCopyright(APP_COPYRIGHT);
    aboutInfo.SetWebSite(APP_WEBSITE);
    aboutInfo.AddDeveloper(APP_AUTHOR);
    aboutInfo.AddTranslator(APP_AUTHOR);
    aboutInfo.AddTranslator(_T("Carlos Sánchez <carlos1994sanchez@gmail.com>"));
    aboutInfo.AddTranslator(_T("Jan Rimmek <jan@rimmek.de>"));
    aboutInfo.AddTranslator(_T("Sergey Basalaev <sbasalaev@gmail.com>"));
    aboutInfo.AddTranslator(_T("Pavel Fric <pavelfric@seznam.cz>"));
    wxAboutBox(aboutInfo);
}

void GuiMain::OnTimer1Trigger(wxTimerEvent& event) {
    wxString newExeTool = APP_TOOL_EXECUTABLE;
    if (!m_exeTool.IsSameAs(newExeTool, false)) {
        m_exeInputString.Clear();
        m_exeInputErrorString.Clear();
        m_exeTool = newExeTool;
        // Execute external application
        wxExecute(m_exeTool + _T(" -v"), m_exeInputString, m_exeInputErrorString, wxEXEC_NODISABLE);

        // Show the version of tool
        if (!m_exeInputErrorString.IsEmpty())
            g_mainStatusBar->SetStatusText(m_exeInputErrorString.Item(0), 0);
        else
            g_mainStatusBar->SetStatusText(_("LAME not found!"), 0);
    }

    // Show the number of files in list on status bar
    g_mainStatusBar->SetStatusText(wxString::Format(_T("%i "), g_lstFiles->GetItemCount()) + _("files"), 1);

    // Show the parameters
    g_mainStatusBar->SetStatusText(_("Lame options: ") + mp_configBase->getStringLameOptions(), 2);

    // Disables the menu item "Remove files" if no item is selected
    g_mainMenu->Enable(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0);
    g_mainMenuBar->Enable(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0);
    g_mainToolBar->EnableTool(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0);

    // Disables the menu item "Clear list" if there is no item in the list
    g_mainMenu->Enable(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0);

    // Disables menus Encode and Decode case there is no item in the list
    g_mainMenuBar->Enable(ID_ENCODE, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_DECODE, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_ENCODE, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_DECODE, g_lstFiles->GetItemCount() > 0);
}

void GuiMain::loadResources() {
    wxString resourceDir = GetResourceDir();

    // Window icon
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(wxImage(resourceDir + _T("icon2.ico"))));
    SetIcon(FrameIcon);

    // Toolbar bitmaps
    g_mainToolBar->SetToolNormalBitmap(ID_ADD_FILES, wxBitmap(wxImage(resourceDir + _T("toolbar/add-file.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_ADD_FOLDER, wxBitmap(wxImage(resourceDir + _T("toolbar/add-folder.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_REMOVE_FILES, wxBitmap(wxImage(resourceDir + _T("toolbar/remove.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_CLEAR_LIST, wxBitmap(wxImage(resourceDir + _T("toolbar/clear.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_ENCODE, wxBitmap(wxImage(resourceDir + _T("toolbar/encode.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_DECODE, wxBitmap(wxImage(resourceDir + _T("toolbar/decode.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_SETTINGS, wxBitmap(wxImage(resourceDir + _T("toolbar/settings.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_ABOUT, wxBitmap(wxImage(resourceDir + _T("toolbar/about.png"))));
}

void GuiMain::updateControls() {
    /*
     * :KLUDGE:
     * EVT_LIST_INSERT_ITEM is triggered before or after item is added:
     *   on wxGTK -> triggered before item is added;
     *   on wxMSW -> triggered after item is added.
     */
    m_timer1.Start(20, true);
}

void GuiMain::setFilesCmdLine(const wxArrayString& filenames) {
    mp_dndFile->OnDropFiles(0, 0, filenames);
}
