///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jan  3 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Gui.h"

///////////////////////////////////////////////////////////////////////////

FrameMain::FrameMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	gui_lstFiles = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLC_REPORT );
	bSizer1->Add( gui_lstFiles, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();
	gui_menuBar = new wxMenuBar( 0 );
	gui_mnbFile = new wxMenu();
	wxMenuItem* gui_mnbAddFolder;
	gui_mnbAddFolder = new wxMenuItem( gui_mnbFile, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbFile->Append( gui_mnbAddFolder );

	wxMenuItem* gui_mnbAddFiles;
	gui_mnbAddFiles = new wxMenuItem( gui_mnbFile, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbFile->Append( gui_mnbAddFiles );

	gui_mnbFile->AppendSeparator();

	wxMenuItem* gui_mnbExit;
	gui_mnbExit = new wxMenuItem( gui_mnbFile, ID_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbFile->Append( gui_mnbExit );

	gui_menuBar->Append( gui_mnbFile, _("&File") );

	gui_mnbEdit = new wxMenu();
	wxMenuItem* gui_mnbRemoveFiles;
	gui_mnbRemoveFiles = new wxMenuItem( gui_mnbEdit, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbEdit->Append( gui_mnbRemoveFiles );

	wxMenuItem* gui_mnbClearList;
	gui_mnbClearList = new wxMenuItem( gui_mnbEdit, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbEdit->Append( gui_mnbClearList );

	gui_mnbEdit->AppendSeparator();

	wxMenuItem* gui_mnbSettings;
	gui_mnbSettings = new wxMenuItem( gui_mnbEdit, ID_SETTINGS, wxString( _("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbEdit->Append( gui_mnbSettings );

	gui_menuBar->Append( gui_mnbEdit, _("&Edit") );

	gui_mnbActions = new wxMenu();
	wxMenuItem* gui_mnbEncode;
	gui_mnbEncode = new wxMenuItem( gui_mnbActions, ID_ENCODE, wxString( _("Encode WAV / Re-Encode MP3") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbActions->Append( gui_mnbEncode );

	wxMenuItem* gui_mnbDecode;
	gui_mnbDecode = new wxMenuItem( gui_mnbActions, ID_DECODE, wxString( _("Decode MP3") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbActions->Append( gui_mnbDecode );

	gui_menuBar->Append( gui_mnbActions, _("&Actions") );

	gui_mnbHelp = new wxMenu();
	wxMenuItem* gui_mnbToolWebsite;
	gui_mnbToolWebsite = new wxMenuItem( gui_mnbHelp, ID_WEBSITE, wxString( _("LAME Website") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbHelp->Append( gui_mnbToolWebsite );

	wxMenuItem* gui_mnbWebsite;
	gui_mnbWebsite = new wxMenuItem( gui_mnbHelp, ID_TOOL_WEBSITE, wxString( _("wxLame Website") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbHelp->Append( gui_mnbWebsite );

	gui_mnbHelp->AppendSeparator();

	wxMenuItem* gui_mnbAbout;
	gui_mnbAbout = new wxMenuItem( gui_mnbHelp, ID_ABOUT, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	gui_mnbHelp->Append( gui_mnbAbout );

	gui_menuBar->Append( gui_mnbHelp, _("&Help") );

	this->SetMenuBar( gui_menuBar );

	gui_mainStatusBar = this->CreateStatusBar( 3, wxSTB_SIZEGRIP, wxID_ANY );
	gui_toolBar = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY );
	gui_tbAddFolder = gui_toolBar->AddTool( ID_ADD_FOLDER, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add folder"), wxEmptyString, NULL );

	gui_tbAddFiles = gui_toolBar->AddTool( ID_ADD_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add files"), wxEmptyString, NULL );

	gui_tbRemoveFiles = gui_toolBar->AddTool( ID_REMOVE_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Remove files"), wxEmptyString, NULL );

	gui_tbClearList = gui_toolBar->AddTool( ID_CLEAR_LIST, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Clear list"), wxEmptyString, NULL );

	gui_toolBar->AddSeparator();

	gui_tbEncode = gui_toolBar->AddTool( ID_ENCODE, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Encode WAV / Re-Encode MP3"), wxEmptyString, NULL );

	gui_tbDecode = gui_toolBar->AddTool( ID_DECODE, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Decode MP3"), wxEmptyString, NULL );

	gui_toolBar->AddSeparator();

	gui_tbSettings = gui_toolBar->AddTool( ID_SETTINGS, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Settings"), wxEmptyString, NULL );

	gui_tbAbout = gui_toolBar->AddTool( ID_ABOUT, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("About"), wxEmptyString, NULL );

	gui_toolBar->Realize();

	gui_menu = new wxMenu();
	wxMenuItem* gui_mnuAddFolder;
	gui_mnuAddFolder = new wxMenuItem( gui_menu, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	gui_menu->Append( gui_mnuAddFolder );

	wxMenuItem* gui_mnuAddFiles;
	gui_mnuAddFiles = new wxMenuItem( gui_menu, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	gui_menu->Append( gui_mnuAddFiles );

	wxMenuItem* gui_mnuRemoveFiles;
	gui_mnuRemoveFiles = new wxMenuItem( gui_menu, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	gui_menu->Append( gui_mnuRemoveFiles );

	wxMenuItem* gui_mnuClearList;
	gui_mnuClearList = new wxMenuItem( gui_menu, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	gui_menu->Append( gui_mnuClearList );

	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( FrameMain::FrameMainOnContextMenu ), NULL, this );

	m_timer1.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	gui_lstFiles->Connect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	gui_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, gui_mnbAddFolder->GetId());
	gui_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, gui_mnbAddFiles->GetId());
	gui_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuExit ), this, gui_mnbExit->GetId());
	gui_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, gui_mnbRemoveFiles->GetId());
	gui_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, gui_mnbClearList->GetId());
	gui_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuSettings ), this, gui_mnbSettings->GetId());
	gui_mnbActions->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuEncode ), this, gui_mnbEncode->GetId());
	gui_mnbActions->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuDecode ), this, gui_mnbDecode->GetId());
	gui_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuToolWebsite ), this, gui_mnbToolWebsite->GetId());
	gui_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuWebsite ), this, gui_mnbWebsite->GetId());
	gui_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAbout ), this, gui_mnbAbout->GetId());
	this->Connect( gui_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Connect( gui_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Connect( gui_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Connect( gui_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Connect( gui_tbEncode->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuEncode ) );
	this->Connect( gui_tbDecode->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuDecode ) );
	this->Connect( gui_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Connect( gui_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	gui_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, gui_mnuAddFolder->GetId());
	gui_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, gui_mnuAddFiles->GetId());
	gui_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, gui_mnuRemoveFiles->GetId());
	gui_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, gui_mnuClearList->GetId());
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );
}

FrameMain::~FrameMain()
{
	// Disconnect Events
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	gui_lstFiles->Disconnect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	this->Disconnect( gui_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Disconnect( gui_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Disconnect( gui_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Disconnect( gui_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Disconnect( gui_tbEncode->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuEncode ) );
	this->Disconnect( gui_tbDecode->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuDecode ) );
	this->Disconnect( gui_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Disconnect( gui_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );

	delete gui_menu;
}

DialogSettings::DialogSettings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxNotebook* m_notebook1;
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxPanel* m_panel1;
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Bitrate") ), wxVERTICAL );

	gui_lblBitrate = new wxStaticText( sbSizer6->GetStaticBox(), wxID_ANY, _("Current bitrate:"), wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblBitrate->Wrap( -1 );
	sbSizer6->Add( gui_lblBitrate, 0, wxALL, 5 );

	gui_sldBitrate = new wxSlider( sbSizer6->GetStaticBox(), wxID_ANY, 50, 0, 1, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_SELRANGE );
	sbSizer6->Add( gui_sldBitrate, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( sbSizer6, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Mode") ), wxVERTICAL );

	wxString gui_chcModeChoices[] = { _("default"), _("joint"), _("simple"), _("force"), _("dual-mono"), _("mono") };
	int gui_chcModeNChoices = sizeof( gui_chcModeChoices ) / sizeof( wxString );
	gui_chcMode = new wxChoice( sbSizer7->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, gui_chcModeNChoices, gui_chcModeChoices, 0 );
	gui_chcMode->SetSelection( 0 );
	sbSizer7->Add( gui_chcMode, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( sbSizer7, 1, wxEXPAND, 5 );


	bSizer5->Add( bSizer6, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Output directory") ), wxVERTICAL );

	gui_optUseSameDir = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Same as input directory"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( gui_optUseSameDir, 0, wxALL, 2 );

	gui_optEnableOutDir = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Use below:"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( gui_optEnableOutDir, 0, wxALL, 2 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	gui_dpkOutputDirectory = new wxDirPickerCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("/home/cristiano"), _("Select directory"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bSizer7->Add( gui_dpkOutputDirectory, 1, wxALL, 5 );


	sbSizer4->Add( bSizer7, 0, wxEXPAND, 5 );


	bSizer5->Add( sbSizer4, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("File options") ), wxHORIZONTAL );

	gui_chkDeleteFiles = new wxCheckBox( sbSizer5->GetStaticBox(), wxID_ANY, _("Delete source file after processing"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( gui_chkDeleteFiles, 0, wxALL, 2 );


	bSizer5->Add( sbSizer5, 0, wxEXPAND, 5 );


	m_panel1->SetSizer( bSizer5 );
	m_panel1->Layout();
	bSizer5->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, _("General"), true );
	wxPanel* m_panel2;
	m_panel2 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer61;
	sbSizer61 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("VBR") ), wxVERTICAL );

	gui_chkEnabledVBR = new wxCheckBox( sbSizer61->GetStaticBox(), wxID_ANY, _("Enable Variable Bitrate (VBR)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( gui_chkEnabledVBR, 0, wxALL, 2 );


	bSizer71->Add( sbSizer61, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizer71;
	sbSizer71 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Maximum VBR bitrate") ), wxVERTICAL );

	gui_lblBitrateVBR = new wxStaticText( sbSizer71->GetStaticBox(), wxID_ANY, _("Current bitrate:"), wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblBitrateVBR->Wrap( -1 );
	sbSizer71->Add( gui_lblBitrateVBR, 0, wxALL, 5 );

	gui_sldBitrateVBR = new wxSlider( sbSizer71->GetStaticBox(), wxID_ANY, 0, 0, 1, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_SELRANGE );
	sbSizer71->Add( gui_sldBitrateVBR, 0, wxALL|wxEXPAND, 5 );


	bSizer8->Add( sbSizer71, 1, wxEXPAND, 5 );


	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer71->Add( bSizer8, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Others") ), wxVERTICAL );

	gui_chkDisableVBRTag = new wxCheckBox( sbSizer8->GetStaticBox(), wxID_ANY, _("Disable writing of VBR Tag"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( gui_chkDisableVBRTag, 0, wxALL, 2 );

	gui_chkEnforceMinBitrate = new wxCheckBox( sbSizer8->GetStaticBox(), wxID_ANY, _("Strictly enforce minimum bitrate"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( gui_chkEnforceMinBitrate, 0, wxALL, 2 );

	gui_chkUseABR = new wxCheckBox( sbSizer8->GetStaticBox(), wxID_ANY, _("Use ABR instead VBR"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( gui_chkUseABR, 0, wxALL, 2 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	gui_lblVBRQuality = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Quality of VBR encoding:"), wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblVBRQuality->Wrap( -1 );
	fgSizer1->Add( gui_lblVBRQuality, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_spcVBRQuality = new wxSpinCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9, 0 );
	fgSizer1->Add( gui_spcVBRQuality, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_lblABR = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Average bitrate encoding ABR:"), wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblABR->Wrap( -1 );
	fgSizer1->Add( gui_lblABR, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_spcAverageBitrateABR = new wxSpinCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 8, 320, 0 );
	fgSizer1->Add( gui_spcAverageBitrateABR, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer8->Add( fgSizer1, 0, wxEXPAND, 5 );


	bSizer9->Add( sbSizer8, 1, 0, 5 );


	bSizer71->Add( bSizer9, 0, wxEXPAND, 5 );


	m_panel2->SetSizer( bSizer71 );
	m_panel2->Layout();
	bSizer71->Fit( m_panel2 );
	m_notebook1->AddPage( m_panel2, _("VBR"), false );
	wxPanel* m_panel3;
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, _("Output sampling frequency") ), wxHORIZONTAL );

	wxArrayString gui_chcResamplingChoices;
	gui_chcResampling = new wxChoice( sbSizer11->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, gui_chcResamplingChoices, 0 );
	gui_chcResampling->SetSelection( 0 );
	sbSizer11->Add( gui_chcResampling, 1, wxALL, 5 );


	bSizer11->Add( sbSizer11, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, _("Highpass filter") ), wxVERTICAL );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );

	gui_chkHighpass = new wxCheckBox( sbSizer12->GetStaticBox(), wxID_ANY, _("Highpass filtering frequency (in Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( gui_chkHighpass, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );

	gui_spcHighpassFreq = new wxSpinCtrl( sbSizer12->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 50, 50000, 0 );
	gSizer1->Add( gui_spcHighpassFreq, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_chkHighpassWidth = new wxCheckBox( sbSizer12->GetStaticBox(), wxID_ANY, _("Width of Highpass filter (in Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( gui_chkHighpassWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );

	gui_spcHighpassWidth = new wxSpinCtrl( sbSizer12->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 50, 50000, 0 );
	gSizer1->Add( gui_spcHighpassWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer12->Add( gSizer1, 0, 0, 5 );


	bSizer11->Add( sbSizer12, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer13;
	sbSizer13 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, _("Lowpass filter") ), wxVERTICAL );

	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer( 2, 2, 0, 0 );

	gui_chkLowpass = new wxCheckBox( sbSizer13->GetStaticBox(), wxID_ANY, _("Lowpass filtering frequency (in Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( gui_chkLowpass, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );

	gui_spcLowpassFreq = new wxSpinCtrl( sbSizer13->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 50, 50000, 0 );
	gSizer11->Add( gui_spcLowpassFreq, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_chkLowpassWidth = new wxCheckBox( sbSizer13->GetStaticBox(), wxID_ANY, _("Width of Lowpass filter (in Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( gui_chkLowpassWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );

	gui_spcLowpassWidth = new wxSpinCtrl( sbSizer13->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 50, 50000, 0 );
	gSizer11->Add( gui_spcLowpassWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer13->Add( gSizer11, 0, 0, 5 );


	bSizer11->Add( sbSizer13, 0, wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer11 );
	m_panel3->Layout();
	bSizer11->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, _("Audio processing"), false );
	wxPanel* m_panel4;
	m_panel4 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, _("Flags") ), wxVERTICAL );

	gui_chkMarkNonOriginal = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Mark as non-original"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( gui_chkMarkNonOriginal, 0, wxALL, 3 );

	gui_chkMarkCopyright = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Mark as copyright"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( gui_chkMarkCopyright, 0, wxALL, 3 );

	gui_chkCrc = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Include CRC error detection"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( gui_chkCrc, 0, wxALL, 2 );

	gui_chkEnforceISO = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Comply as much as possible to ISO MPEG spec"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( gui_chkEnforceISO, 0, wxALL, 2 );


	bSizer10->Add( sbSizer9, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, _("Options") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	gui_lblQualitySelection = new wxStaticText( sbSizer10->GetStaticBox(), wxID_ANY, _("Algorithm quality selection:"), wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblQualitySelection->Wrap( -1 );
	fgSizer2->Add( gui_lblQualitySelection, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxArrayString gui_chcAlgorithmQualitySelChoices;
	gui_chcAlgorithmQualitySel = new wxChoice( sbSizer10->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), gui_chcAlgorithmQualitySelChoices, 0 );
	gui_chcAlgorithmQualitySel->SetSelection( 0 );
	fgSizer2->Add( gui_chcAlgorithmQualitySel, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	gui_chkCustomOptions = new wxCheckBox( sbSizer10->GetStaticBox(), wxID_ANY, _("Custom options:"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( gui_chkCustomOptions, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	gui_txtCustomOptions = new wxTextCtrl( sbSizer10->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	fgSizer2->Add( gui_txtCustomOptions, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer10->Add( fgSizer2, 0, wxEXPAND, 5 );


	bSizer10->Add( sbSizer10, 0, wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer10 );
	m_panel4->Layout();
	bSizer10->Fit( m_panel4 );
	m_notebook1->AddPage( m_panel4, _("Advanced"), false );

	bSizer2->Add( m_notebook1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	gui_btnDefault = new wxButton( this, wxID_ANY, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( gui_btnDefault, 1, wxALL, 5 );

	gui_btnOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( gui_btnOK, 1, wxALL, 5 );

	gui_btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( gui_btnCancel, 1, wxALL, 5 );


	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	gui_sldBitrate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_optUseSameDir->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_optEnableOutDir->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkEnabledVBR->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_chkUseABR->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkHighpass->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkHighpassWidth->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkLowpass->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkLowpassWidth->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkCustomOptions->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_btnDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	gui_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	gui_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );
}

DialogSettings::~DialogSettings()
{
	// Disconnect Events
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_sldBitrate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldBitrateSliderUpdated ), NULL, this );
	gui_optUseSameDir->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_optEnableOutDir->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkEnabledVBR->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_sldBitrateVBR->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRSliderUpdated ), NULL, this );
	gui_chkUseABR->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkHighpass->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkHighpassWidth->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkLowpass->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkLowpassWidth->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_chkCustomOptions->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	gui_btnDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	gui_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	gui_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );

}

DialogProgress::DialogProgress( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	gui_lblStatusList = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblStatusList->Wrap( -1 );
	bSizer12->Add( gui_lblStatusList, 0, wxALL, 5 );

	gui_gaugeListProgress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 370,-1 ), wxGA_HORIZONTAL );
	gui_gaugeListProgress->SetValue( 0 );
	bSizer12->Add( gui_gaugeListProgress, 0, wxALL, 5 );

	gui_lblStatusFile = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gui_lblStatusFile->Wrap( -1 );
	bSizer12->Add( gui_lblStatusFile, 0, wxALL, 5 );

	gui_gaugeFileProgress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 370,-1 ), wxGA_HORIZONTAL );
	gui_gaugeFileProgress->SetValue( 0 );
	bSizer12->Add( gui_gaugeFileProgress, 0, wxALL, 5 );

	gui_btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( gui_btnCancel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer12 );
	this->Layout();
	bSizer12->Fit( this );
	m_timer2.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogProgress::OnClose ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( DialogProgress::OnIdle ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogProgress::OnInit ) );
	gui_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogProgress::OnbtnCancelClick ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( DialogProgress::OnTimer2Trigger ) );
}

DialogProgress::~DialogProgress()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogProgress::OnClose ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( DialogProgress::OnIdle ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogProgress::OnInit ) );
	gui_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogProgress::OnbtnCancelClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( DialogProgress::OnTimer2Trigger ) );

}
