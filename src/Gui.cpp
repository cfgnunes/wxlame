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

	g_lstFiles = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLC_REPORT );
	bSizer1->Add( g_lstFiles, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();
	g_mainMenuBar = new wxMenuBar( 0 );
	g_mnbFile = new wxMenu();
	wxMenuItem* g_mnbAddFolder;
	g_mnbAddFolder = new wxMenuItem( g_mnbFile, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbAddFolder );

	wxMenuItem* g_mnbAddFiles;
	g_mnbAddFiles = new wxMenuItem( g_mnbFile, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbAddFiles );

	g_mnbFile->AppendSeparator();

	wxMenuItem* g_mnbExit;
	g_mnbExit = new wxMenuItem( g_mnbFile, ID_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbExit );

	g_mainMenuBar->Append( g_mnbFile, _("&File") );

	g_mnbEdit = new wxMenu();
	wxMenuItem* g_mnbRemoveFiles;
	g_mnbRemoveFiles = new wxMenuItem( g_mnbEdit, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbRemoveFiles );

	wxMenuItem* g_mnbClearList;
	g_mnbClearList = new wxMenuItem( g_mnbEdit, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbClearList );

	g_mnbEdit->AppendSeparator();

	wxMenuItem* g_mnbSettings;
	g_mnbSettings = new wxMenuItem( g_mnbEdit, ID_SETTINGS, wxString( _("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbSettings );

	g_mainMenuBar->Append( g_mnbEdit, _("&Edit") );

	g_mnbActions = new wxMenu();
	wxMenuItem* g_mnbEncode;
	g_mnbEncode = new wxMenuItem( g_mnbActions, ID_ENCODE, wxString( _("Encode WAV / Re-Encode MP3") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbActions->Append( g_mnbEncode );

	wxMenuItem* g_mnbDecode;
	g_mnbDecode = new wxMenuItem( g_mnbActions, ID_DECODE, wxString( _("Decode MP3") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbActions->Append( g_mnbDecode );

	g_mainMenuBar->Append( g_mnbActions, _("&Actions") );

	g_mnbHelp = new wxMenu();
	wxMenuItem* g_mnbToolWebsite;
	g_mnbToolWebsite = new wxMenuItem( g_mnbHelp, ID_WEBSITE, wxString( _("LAME Website") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbToolWebsite );

	wxMenuItem* g_mnbWebsite;
	g_mnbWebsite = new wxMenuItem( g_mnbHelp, ID_TOOL_WEBSITE, wxString( _("wxLame Website") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbWebsite );

	g_mnbHelp->AppendSeparator();

	wxMenuItem* g_mnbAbout;
	g_mnbAbout = new wxMenuItem( g_mnbHelp, ID_ABOUT, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbAbout );

	g_mainMenuBar->Append( g_mnbHelp, _("&Help") );

	this->SetMenuBar( g_mainMenuBar );

	g_mainStatusBar = this->CreateStatusBar( 3, wxSTB_SIZEGRIP, wxID_ANY );
	g_mainToolBar = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY );
	g_tbAddFolder = g_mainToolBar->AddTool( ID_ADD_FOLDER, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add folder"), wxEmptyString, NULL );

	g_tbAddFiles = g_mainToolBar->AddTool( ID_ADD_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add files"), wxEmptyString, NULL );

	g_tbRemoveFiles = g_mainToolBar->AddTool( ID_REMOVE_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Remove files"), wxEmptyString, NULL );

	g_tbClearList = g_mainToolBar->AddTool( ID_CLEAR_LIST, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Clear list"), wxEmptyString, NULL );

	g_mainToolBar->AddSeparator();

	g_tbEncode = g_mainToolBar->AddTool( ID_ENCODE, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Encode WAV / Re-Encode MP3"), wxEmptyString, NULL );

	g_tbDecode = g_mainToolBar->AddTool( ID_DECODE, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Decode MP3"), wxEmptyString, NULL );

	g_mainToolBar->AddSeparator();

	g_tbSettings = g_mainToolBar->AddTool( ID_SETTINGS, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Settings"), wxEmptyString, NULL );

	g_tbAbout = g_mainToolBar->AddTool( ID_ABOUT, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("About"), wxEmptyString, NULL );

	g_mainToolBar->Realize();

	g_mainMenu = new wxMenu();
	wxMenuItem* g_mnuAddFolder;
	g_mnuAddFolder = new wxMenuItem( g_mainMenu, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuAddFolder );

	wxMenuItem* g_mnuAddFiles;
	g_mnuAddFiles = new wxMenuItem( g_mainMenu, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuAddFiles );

	wxMenuItem* g_mnuRemoveFiles;
	g_mnuRemoveFiles = new wxMenuItem( g_mainMenu, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuRemoveFiles );

	wxMenuItem* g_mnuClearList;
	g_mnuClearList = new wxMenuItem( g_mainMenu, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuClearList );

	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( FrameMain::FrameMainOnContextMenu ), NULL, this );

	m_timer1.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, g_mnbAddFolder->GetId());
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, g_mnbAddFiles->GetId());
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuExit ), this, g_mnbExit->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, g_mnbRemoveFiles->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, g_mnbClearList->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuSettings ), this, g_mnbSettings->GetId());
	g_mnbActions->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuEncode ), this, g_mnbEncode->GetId());
	g_mnbActions->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuDecode ), this, g_mnbDecode->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuToolWebsite ), this, g_mnbToolWebsite->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuWebsite ), this, g_mnbWebsite->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAbout ), this, g_mnbAbout->GetId());
	this->Connect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Connect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Connect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Connect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Connect( g_tbEncode->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuEncode ) );
	this->Connect( g_tbDecode->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuDecode ) );
	this->Connect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Connect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, g_mnuAddFolder->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, g_mnuAddFiles->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, g_mnuRemoveFiles->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, g_mnuClearList->GetId());
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );
}

FrameMain::~FrameMain()
{
	// Disconnect Events
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	this->Disconnect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Disconnect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Disconnect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Disconnect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Disconnect( g_tbEncode->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuEncode ) );
	this->Disconnect( g_tbDecode->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuDecode ) );
	this->Disconnect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Disconnect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );

	delete g_mainMenu;
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

	g_lblBitrate = new wxStaticText( sbSizer6->GetStaticBox(), wxID_ANY, _("Current bitrate:"), wxDefaultPosition, wxDefaultSize, 0 );
	g_lblBitrate->Wrap( -1 );
	sbSizer6->Add( g_lblBitrate, 0, wxALL, 5 );

	g_sldBitrate = new wxSlider( sbSizer6->GetStaticBox(), wxID_ANY, 50, 0, 1, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_SELRANGE );
	sbSizer6->Add( g_sldBitrate, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( sbSizer6, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Mode") ), wxVERTICAL );

	wxString g_chcModeChoices[] = { _("default"), _("joint"), _("simple"), _("force"), _("dual-mono"), _("mono") };
	int g_chcModeNChoices = sizeof( g_chcModeChoices ) / sizeof( wxString );
	g_chcMode = new wxChoice( sbSizer7->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, g_chcModeNChoices, g_chcModeChoices, 0 );
	g_chcMode->SetSelection( 0 );
	sbSizer7->Add( g_chcMode, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( sbSizer7, 1, wxEXPAND, 5 );


	bSizer5->Add( bSizer6, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Output directory") ), wxVERTICAL );

	g_optUseSameDir = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Same as input directory"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( g_optUseSameDir, 0, wxALL, 2 );

	g_optEnableOutDir = new wxRadioButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Use below:"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( g_optEnableOutDir, 0, wxALL, 2 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	g_dpkOutputDirectory = new wxDirPickerCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("/home/cristiano"), _("Select directory"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bSizer7->Add( g_dpkOutputDirectory, 1, wxALL, 5 );


	sbSizer4->Add( bSizer7, 0, wxEXPAND, 5 );


	bSizer5->Add( sbSizer4, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("File options") ), wxHORIZONTAL );

	g_chkDeleteFiles = new wxCheckBox( sbSizer5->GetStaticBox(), wxID_ANY, _("Delete source file after processing"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( g_chkDeleteFiles, 0, wxALL, 2 );


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

	g_chkEnabledVBR = new wxCheckBox( sbSizer61->GetStaticBox(), wxID_ANY, _("Enable Variable Bitrate (VBR)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( g_chkEnabledVBR, 0, wxALL, 2 );


	bSizer71->Add( sbSizer61, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizer71;
	sbSizer71 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Maximum VBR bitrate") ), wxVERTICAL );

	g_lblBitrateVBR = new wxStaticText( sbSizer71->GetStaticBox(), wxID_ANY, _("Current bitrate:"), wxDefaultPosition, wxDefaultSize, 0 );
	g_lblBitrateVBR->Wrap( -1 );
	sbSizer71->Add( g_lblBitrateVBR, 0, wxALL, 5 );

	g_sldBitrateVBR = new wxSlider( sbSizer71->GetStaticBox(), wxID_ANY, 0, 0, 1, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_SELRANGE );
	sbSizer71->Add( g_sldBitrateVBR, 0, wxALL|wxEXPAND, 5 );


	bSizer8->Add( sbSizer71, 1, wxEXPAND, 5 );


	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer71->Add( bSizer8, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, _("Others") ), wxVERTICAL );

	g_chkDisableVBRTag = new wxCheckBox( sbSizer8->GetStaticBox(), wxID_ANY, _("Disable writing of VBR Tag"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( g_chkDisableVBRTag, 0, wxALL, 2 );

	g_chkEnforceMinBitrate = new wxCheckBox( sbSizer8->GetStaticBox(), wxID_ANY, _("Strictly enforce minimum bitrate"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( g_chkEnforceMinBitrate, 0, wxALL, 2 );

	g_chkUseABR = new wxCheckBox( sbSizer8->GetStaticBox(), wxID_ANY, _("Use ABR instead VBR"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( g_chkUseABR, 0, wxALL, 2 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	g_lblVBRQuality = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Quality of VBR encoding:"), wxDefaultPosition, wxDefaultSize, 0 );
	g_lblVBRQuality->Wrap( -1 );
	fgSizer1->Add( g_lblVBRQuality, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_spcVBRQuality = new wxSpinCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9, 0 );
	fgSizer1->Add( g_spcVBRQuality, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_lblABR = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Average bitrate encoding ABR:"), wxDefaultPosition, wxDefaultSize, 0 );
	g_lblABR->Wrap( -1 );
	fgSizer1->Add( g_lblABR, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_spcAverageBitrateABR = new wxSpinCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 8, 320, 0 );
	fgSizer1->Add( g_spcAverageBitrateABR, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


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

	wxArrayString g_chcResamplingChoices;
	g_chcResampling = new wxChoice( sbSizer11->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, g_chcResamplingChoices, 0 );
	g_chcResampling->SetSelection( 0 );
	sbSizer11->Add( g_chcResampling, 1, wxALL, 5 );


	bSizer11->Add( sbSizer11, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, _("Highpass filter") ), wxVERTICAL );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );

	g_chkHighpass = new wxCheckBox( sbSizer12->GetStaticBox(), wxID_ANY, _("Highpass filtering frequency (in Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( g_chkHighpass, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );

	g_spcHighpassFreq = new wxSpinCtrl( sbSizer12->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 50, 50000, 0 );
	gSizer1->Add( g_spcHighpassFreq, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_chkHighpassWidth = new wxCheckBox( sbSizer12->GetStaticBox(), wxID_ANY, _("Width of Highpass filter (in Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( g_chkHighpassWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );

	g_spcHighpassWidth = new wxSpinCtrl( sbSizer12->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 50, 50000, 0 );
	gSizer1->Add( g_spcHighpassWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer12->Add( gSizer1, 0, 0, 5 );


	bSizer11->Add( sbSizer12, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer13;
	sbSizer13 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, _("Lowpass filter") ), wxVERTICAL );

	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer( 2, 2, 0, 0 );

	g_chkLowpass = new wxCheckBox( sbSizer13->GetStaticBox(), wxID_ANY, _("Lowpass filtering frequency (in Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( g_chkLowpass, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );

	g_spcLowpassFreq = new wxSpinCtrl( sbSizer13->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 50, 50000, 0 );
	gSizer11->Add( g_spcLowpassFreq, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_chkLowpassWidth = new wxCheckBox( sbSizer13->GetStaticBox(), wxID_ANY, _("Width of Lowpass filter (in Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( g_chkLowpassWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2 );

	g_spcLowpassWidth = new wxSpinCtrl( sbSizer13->GetStaticBox(), wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 50, 50000, 0 );
	gSizer11->Add( g_spcLowpassWidth, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


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

	g_chkMarkNonOriginal = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Mark as non-original"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( g_chkMarkNonOriginal, 0, wxALL, 3 );

	g_chkMarkCopyright = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Mark as copyright"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( g_chkMarkCopyright, 0, wxALL, 3 );

	g_chkCrc = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Include CRC error detection"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( g_chkCrc, 0, wxALL, 2 );

	g_chkEnforceISO = new wxCheckBox( sbSizer9->GetStaticBox(), wxID_ANY, _("Comply as much as possible to ISO MPEG spec"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( g_chkEnforceISO, 0, wxALL, 2 );


	bSizer10->Add( sbSizer9, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, _("Options") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	g_lblQualitySelection = new wxStaticText( sbSizer10->GetStaticBox(), wxID_ANY, _("Algorithm quality selection:"), wxDefaultPosition, wxDefaultSize, 0 );
	g_lblQualitySelection->Wrap( -1 );
	fgSizer2->Add( g_lblQualitySelection, 0, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxArrayString g_chcAlgorithmQualitySelChoices;
	g_chcAlgorithmQualitySel = new wxChoice( sbSizer10->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), g_chcAlgorithmQualitySelChoices, 0 );
	g_chcAlgorithmQualitySel->SetSelection( 0 );
	fgSizer2->Add( g_chcAlgorithmQualitySel, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	g_chkCustomOptions = new wxCheckBox( sbSizer10->GetStaticBox(), wxID_ANY, _("Custom options:"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( g_chkCustomOptions, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_txtCustomOptions = new wxTextCtrl( sbSizer10->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	fgSizer2->Add( g_txtCustomOptions, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer10->Add( fgSizer2, 0, wxEXPAND, 5 );


	bSizer10->Add( sbSizer10, 0, wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer10 );
	m_panel4->Layout();
	bSizer10->Fit( m_panel4 );
	m_notebook1->AddPage( m_panel4, _("Advanced"), false );

	bSizer2->Add( m_notebook1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	g_btnDefault = new wxButton( this, wxID_ANY, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnDefault, 1, wxALL, 5 );

	g_btnOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnOK, 1, wxALL, 5 );

	g_btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnCancel, 1, wxALL, 5 );


	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	g_sldBitrate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_optUseSameDir->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_optEnableOutDir->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkEnabledVBR->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_chkUseABR->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkHighpass->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkHighpassWidth->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkLowpass->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkLowpassWidth->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkCustomOptions->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_btnDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );
}

DialogSettings::~DialogSettings()
{
	// Disconnect Events
	g_sldBitrate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_sldBitrate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldBitrateCmdSliderUpdated ), NULL, this );
	g_optUseSameDir->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_optEnableOutDir->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkEnabledVBR->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_sldBitrateVBR->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogSettings::OnsldBitrateVBRCmdSliderUpdated ), NULL, this );
	g_chkUseABR->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkHighpass->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkHighpassWidth->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkLowpass->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkLowpassWidth->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_chkCustomOptions->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DialogSettings::updateDisabledControlsEvent ), NULL, this );
	g_btnDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );

}

DialogProgress::DialogProgress( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	g_lblStatusList = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	g_lblStatusList->Wrap( -1 );
	bSizer12->Add( g_lblStatusList, 0, wxALL, 5 );

	g_gaugeListProgress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 370,-1 ), wxGA_HORIZONTAL );
	g_gaugeListProgress->SetValue( 0 );
	bSizer12->Add( g_gaugeListProgress, 0, wxALL, 5 );

	g_lblStatusFile = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	g_lblStatusFile->Wrap( -1 );
	bSizer12->Add( g_lblStatusFile, 0, wxALL, 5 );

	g_gaugeFileProgress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 370,-1 ), wxGA_HORIZONTAL );
	g_gaugeFileProgress->SetValue( 0 );
	bSizer12->Add( g_gaugeFileProgress, 0, wxALL, 5 );

	g_btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( g_btnCancel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer12 );
	this->Layout();
	bSizer12->Fit( this );
	m_timer2.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogProgress::OnClose ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( DialogProgress::OnIdle ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogProgress::OnInit ) );
	g_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogProgress::OnbtnCancelClick ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( DialogProgress::OnTimer2Trigger ) );
}

DialogProgress::~DialogProgress()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogProgress::OnClose ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( DialogProgress::OnIdle ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DialogProgress::OnInit ) );
	g_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogProgress::OnbtnCancelClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( DialogProgress::OnTimer2Trigger ) );

}
