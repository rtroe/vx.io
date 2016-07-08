//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC9ED9InitBitmapResources();

static bool bBitmapLoaded = false;


ImageFrameBaseClass::ImageFrameBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);
    
    m_notebook81 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    m_notebook81->SetName(wxT("m_notebook81"));
    
    boxSizer1->Add(m_notebook81, 0, wxALL, 5);
    
    m_panel83 = new wxPanel(m_notebook81, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook81->AddPage(m_panel83, _("Main"), false);
    
    wxBoxSizer* boxSizer89 = new wxBoxSizer(wxVERTICAL);
    m_panel83->SetSizer(boxSizer89);
    
    wxStaticBoxSizer* staticBoxSizer49 = new wxStaticBoxSizer( new wxStaticBox(m_panel83, wxID_ANY, _("My Label")), wxHORIZONTAL);
    
    boxSizer89->Add(staticBoxSizer49, 1, wxALL|wxEXPAND, 5);
    
    m_staticBitmap51 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("file_ext_script")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap51, 0, wxALL, 5);
    
    m_staticBitmap53 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap53, 0, wxALL, 5);
    
    m_staticBitmap55 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_c")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap55, 0, wxALL, 5);
    
    m_staticBitmap57 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_code")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap57, 0, wxALL, 5);
    
    m_staticBitmap59 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_cplusplus")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap59, 0, wxALL, 5);
    
    m_staticBitmap61 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_csharp")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap61, 0, wxALL, 5);
    
    m_staticBitmap63 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_database")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap63, 0, wxALL, 5);
    
    m_staticBitmap65 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_h")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap65, 0, wxALL, 5);
    
    m_staticBitmap67 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_php")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap67, 0, wxALL, 5);
    
    m_staticBitmap69 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_ruby")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap69, 0, wxALL, 5);
    
    m_staticBitmap71 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("page_white_visualstudio")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer49->Add(m_staticBitmap71, 0, wxALL, 5);
    
    wxStaticBoxSizer* staticBoxSizer11 = new wxStaticBoxSizer( new wxStaticBox(m_panel83, wxID_ANY, _("My Label")), wxHORIZONTAL);
    
    boxSizer89->Add(staticBoxSizer11, 1, wxALL|wxEXPAND, 5);
    
    m_staticBitmap13 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("file_new_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap13, 0, wxALL, 5);
    
    m_staticBitmap15 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("file_open_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap15, 0, wxALL, 5);
    
    m_staticBitmap17 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("file_save_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap17, 0, wxALL, 5);
    
    m_staticBitmap19 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("file_saveas_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap19, 0, wxALL, 5);
    
    m_staticBitmap21 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("file_saveall_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap21, 0, wxALL, 5);
    
    m_staticBitmap23 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("undo_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap23, 0, wxALL, 5);
    
    m_staticBitmap25 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("redo_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap25, 0, wxALL, 5);
    
    m_staticBitmap27 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("cut16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap27, 0, wxALL, 5);
    
    m_staticBitmap29 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("copy_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap29, 0, wxALL, 5);
    
    m_staticBitmap31 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("paste_16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer11->Add(m_staticBitmap31, 0, wxALL, 5);
    
    wxStaticBoxSizer* staticBoxSizer35 = new wxStaticBoxSizer( new wxStaticBox(m_panel83, wxID_ANY, _("My Label")), wxHORIZONTAL);
    
    boxSizer89->Add(staticBoxSizer35, 1, wxALL|wxEXPAND, 5);
    
    m_staticBitmap37 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("AppSettings16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer35->Add(m_staticBitmap37, 0, wxALL, 5);
    
    m_staticBitmap39 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("Addin16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer35->Add(m_staticBitmap39, 0, wxALL, 5);
    
    m_staticBitmap41 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("projectTree16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer35->Add(m_staticBitmap41, 0, wxALL, 5);
    
    m_staticBitmap43 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("prop16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer35->Add(m_staticBitmap43, 0, wxALL, 5);
    
    m_staticBitmap45 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("SysHrdwr16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer35->Add(m_staticBitmap45, 0, wxALL, 5);
    
    m_staticBitmap47 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("console16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer35->Add(m_staticBitmap47, 0, wxALL, 5);
    
    m_staticBitmap101 = new wxStaticBitmap(m_panel83, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("reportBug16")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer35->Add(m_staticBitmap101, 0, wxALL, 5);
    
    m_panel85 = new wxPanel(m_notebook81, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook81->AddPage(m_panel85, _("Modify Text"), false);
    
    wxBoxSizer* boxSizer91 = new wxBoxSizer(wxVERTICAL);
    m_panel85->SetSizer(boxSizer91);
    
    wxStaticBoxSizer* staticBoxSizer73 = new wxStaticBoxSizer( new wxStaticBox(m_panel85, wxID_ANY, _("My Label")), wxHORIZONTAL);
    
    boxSizer91->Add(staticBoxSizer73, 1, wxALL|wxEXPAND, 5);
    
    m_staticBitmap75 = new wxStaticBitmap(m_panel85, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("text_allcaps")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer73->Add(m_staticBitmap75, 0, wxALL, 5);
    
    m_staticBitmap77 = new wxStaticBitmap(m_panel85, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("text_smallcaps")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer73->Add(m_staticBitmap77, 0, wxALL, 5);
    
    m_staticBitmap79 = new wxStaticBitmap(m_panel85, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("tgle_endln")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer73->Add(m_staticBitmap79, 0, wxALL, 5);
    
    wxStaticBoxSizer* staticBoxSizer93 = new wxStaticBoxSizer( new wxStaticBox(m_panel85, wxID_ANY, _("My Label")), wxHORIZONTAL);
    
    boxSizer91->Add(staticBoxSizer93, 1, wxALL|wxEXPAND, 5);
    
    m_staticBitmap95 = new wxStaticBitmap(m_panel85, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("table_tab_search")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer93->Add(m_staticBitmap95, 0, wxALL, 5);
    
    m_staticBitmap97 = new wxStaticBitmap(m_panel85, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("search_plus")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer93->Add(m_staticBitmap97, 0, wxALL, 5);
    
    m_staticBitmap99 = new wxStaticBitmap(m_panel85, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("search_minus")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    staticBoxSizer93->Add(m_staticBitmap99, 0, wxALL, 5);
    
    m_menuBar = new wxMenuBar(0);
    this->SetMenuBar(m_menuBar);
    
    m_name6 = new wxMenu();
    m_menuBar->Append(m_name6, _("File"));
    
    m_menuItem7 = new wxMenuItem(m_name6, wxID_EXIT, _("Exit\tAlt-X"), _("Quit"), wxITEM_NORMAL);
    m_name6->Append(m_menuItem7);
    
    m_name8 = new wxMenu();
    m_menuBar->Append(m_name8, _("Help"));
    
    m_menuItem9 = new wxMenuItem(m_name8, wxID_ABOUT, _("About..."), wxT(""), wxITEM_NORMAL);
    m_name8->Append(m_menuItem9);
    
    m_mainToolbar = this->CreateToolBar(wxTB_FLAT, wxID_ANY);
    m_mainToolbar->SetToolBitmapSize(wxSize(16,16));
    
    
    #if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(m_notebook81)){
        wxPersistenceManager::Get().RegisterAndRestore(m_notebook81);
    } else {
        wxPersistenceManager::Get().Restore(m_notebook81);
    }
    #endif
    
    SetName(wxT("ImageFrameBaseClass"));
    SetSizeHints(500,400);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    this->Connect(m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ImageFrameBaseClass::OnExit), NULL, this);
    this->Connect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ImageFrameBaseClass::OnAbout), NULL, this);
    
}

ImageFrameBaseClass::~ImageFrameBaseClass()
{
    this->Disconnect(m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ImageFrameBaseClass::OnExit), NULL, this);
    this->Disconnect(m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ImageFrameBaseClass::OnAbout), NULL, this);
    
}

MainFrameBase::MainFrameBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    SetName(wxT("MainFrameBase"));
    SetSizeHints(500,300);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
}

MainFrameBase::~MainFrameBase()
{
}

SettingsDialogBase::SettingsDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer168 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer168);
    
    m_treebook249 = new wxTreebook(this, wxID_ANY, wxDefaultPosition, wxSize(800, 400), wxBK_DEFAULT);
    m_treebook249->SetName(wxT("m_treebook249"));
    
    boxSizer168->Add(m_treebook249, 0, wxALL, 5);
    
    m_panel115 = new wxPanel(m_treebook249, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook249->AddPage(m_panel115, _("General"), false, wxNOT_FOUND);
    
    wxStaticBoxSizer* staticBoxSizer267 = new wxStaticBoxSizer( new wxStaticBox(m_panel115, wxID_ANY, _("vx.io Editor")), wxVERTICAL);
    m_panel115->SetSizer(staticBoxSizer267);
    
    wxBoxSizer* boxSizer277 = new wxBoxSizer(wxVERTICAL);
    
    staticBoxSizer267->Add(boxSizer277, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer312 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer277->Add(boxSizer312, 1, wxALL|wxEXPAND, 5);
    
    wxFlexGridSizer* flexGridSizer291 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer291->SetFlexibleDirection( wxBOTH );
    flexGridSizer291->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    boxSizer312->Add(flexGridSizer291, 1, wxALL|wxEXPAND, 5);
    
    m_staticBitmap269 = new wxStaticBitmap(m_panel115, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("Addin32")), wxDefaultPosition, wxSize(-1,-1), 0 );
    
    flexGridSizer291->Add(m_staticBitmap269, 0, wxALL, 5);
    
    wxFlexGridSizer* flexGridSizer287 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer287->SetFlexibleDirection( wxBOTH );
    flexGridSizer287->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    flexGridSizer291->Add(flexGridSizer287, 1, wxALL|wxEXPAND, 5);
    
    m_staticText285 = new wxStaticText(m_panel115, wxID_ANY, _("edit.io - version x.x.x.x"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer287->Add(m_staticText285, 0, wxALL, 5);
    
    m_staticText273 = new wxStaticText(m_panel115, wxID_ANY, _("vx.io lightwieght footprint and crossplatform ability allows it to be versitile for the simplest to the\nmost complex needs of modern code devlopment in any computer enviroment."), wxDefaultPosition, wxSize(300,100), 0);
    
    flexGridSizer287->Add(m_staticText273, 0, wxALL, 5);
    
    wxStaticBoxSizer* staticBoxSizer294 = new wxStaticBoxSizer( new wxStaticBox(m_panel115, wxID_ANY, _("Updates")), wxVERTICAL);
    
    boxSizer312->Add(staticBoxSizer294, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer305 = new wxBoxSizer(wxVERTICAL);
    
    staticBoxSizer294->Add(boxSizer305, 1, wxALL|wxEXPAND, 5);
    
    m_staticText279 = new wxStaticText(m_panel115, wxID_ANY, _("Last Checked:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer305->Add(m_staticText279, 0, wxALL, 5);
    
    m_button298 = new wxButton(m_panel115, wxID_ANY, _("Check For Updates Now"), wxDefaultPosition, wxSize(250,-1), 0);
    
    boxSizer305->Add(m_button298, 0, wxALL, 5);
    
    m_checkBox296 = new wxCheckBox(m_panel115, wxID_ANY, _("Check For Updates At Start"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_checkBox296->SetValue(false);
    
    boxSizer305->Add(m_checkBox296, 0, wxALL, 5);
    
    wxStaticBoxSizer* staticBoxSizer307 = new wxStaticBoxSizer( new wxStaticBox(m_panel115, wxID_ANY, _("Open Source")), wxHORIZONTAL);
    
    boxSizer277->Add(staticBoxSizer307, 1, wxALL|wxEXPAND, 5);
    
    m_staticBitmap309 = new wxStaticBitmap(m_panel115, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("open-source-logo")), wxDefaultPosition, wxSize(128,128), 0 );
    
    staticBoxSizer307->Add(m_staticBitmap309, 0, wxALL, 5);
    
    wxFlexGridSizer* flexGridSizer317 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer317->SetFlexibleDirection( wxBOTH );
    flexGridSizer317->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    staticBoxSizer307->Add(flexGridSizer317, 1, wxALL|wxEXPAND, 5);
    
    m_staticText311 = new wxStaticText(m_panel115, wxID_ANY, _("edit.io is an open source project released under the MIT License. If you'd like to contribute, comment, or get the source code, you can do so over at the project Github page."), wxDefaultPosition, wxSize(350,50), 0);
    
    flexGridSizer317->Add(m_staticText311, 0, wxALL, 5);
    
    m_button319 = new wxButton(m_panel115, wxID_ANY, _("View Github Page"), wxDefaultPosition, wxSize(-1,-1), 0);
    #if wxVERSION_NUMBER >= 2904
    m_button319->SetBitmap(wxXmlResource::Get()->LoadBitmap(wxT("GitHub-Mark-16px")), wxLEFT);
    m_button319->SetBitmapMargins(2,2);
    #endif
    
    flexGridSizer317->Add(m_button319, 0, wxALL, 5);
    
    m_panel255 = new wxPanel(m_treebook249, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook249->AddPage(m_panel255, _("Theme"), false, wxNOT_FOUND);
    
    wxBoxSizer* boxSizer167 = new wxBoxSizer(wxHORIZONTAL);
    m_panel255->SetSizer(boxSizer167);
    
    wxStaticBoxSizer* staticBoxSizer251 = new wxStaticBoxSizer( new wxStaticBox(m_panel255, wxID_ANY, _("My Label")), wxHORIZONTAL);
    
    boxSizer167->Add(staticBoxSizer251, 1, wxALL|wxEXPAND, 5);
    
    m_staticText138 = new wxStaticText(m_panel255, wxID_ANY, _("Editor Font:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    staticBoxSizer251->Add(m_staticText138, 0, wxALL, 5);
    
    wxArrayString cmbbx_fontsArr;
    cmbbx_fonts = new wxChoice(m_panel255, ID_CHOICE_FONT, wxDefaultPosition, wxSize(300,-1), cmbbx_fontsArr, 0);
    
    staticBoxSizer251->Add(cmbbx_fonts, 0, wxALL, 5);
    
    m_staticText154 = new wxStaticText(m_panel255, wxID_ANY, _("Size:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    staticBoxSizer251->Add(m_staticText154, 0, wxALL, 5);
    
    wxArrayString cmbbx_font_sizeArr;
    cmbbx_font_size = new wxChoice(m_panel255, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), cmbbx_font_sizeArr, 0);
    
    staticBoxSizer251->Add(cmbbx_font_size, 0, wxALL, 5);
    
    m_panel257 = new wxPanel(m_treebook249, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook249->InsertSubPage(1, m_panel257, _("Color Scheme"), false, wxNOT_FOUND);
    
    wxBoxSizer* boxSizer158 = new wxBoxSizer(wxHORIZONTAL);
    m_panel257->SetSizer(boxSizer158);
    
    wxStaticBoxSizer* staticBoxSizer263 = new wxStaticBoxSizer( new wxStaticBox(m_panel257, wxID_ANY, _("Editor Colour Scheme")), wxHORIZONTAL);
    
    boxSizer158->Add(staticBoxSizer263, 1, wxALL|wxEXPAND, 5);
    
    m_panel160 = new wxPanel(m_panel257, wxID_ANY, wxDefaultPosition, wxSize(350,350), wxTAB_TRAVERSAL);
    m_panel160->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
    
    staticBoxSizer263->Add(m_panel160, 0, wxALL, 5);
    
    wxFlexGridSizer* flexGridSizer345 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer345->SetFlexibleDirection( wxBOTH );
    flexGridSizer345->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    staticBoxSizer263->Add(flexGridSizer345, 1, wxALL|wxEXPAND, 5);
    
    wxFlexGridSizer* flexGridSizer164 = new wxFlexGridSizer(5, 2, 0, 0);
    flexGridSizer164->SetFlexibleDirection( wxBOTH );
    flexGridSizer164->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    flexGridSizer345->Add(flexGridSizer164, 1, wxALL|wxEXPAND, 5);
    
    m_staticText166 = new wxStaticText(m_panel257, wxID_ANY, _("Theme:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer164->Add(m_staticText166, 0, wxALL, 5);
    
    wxArrayString cmbbx_themeArr;
    cmbbx_theme = new wxChoice(m_panel257, wxID_ANY, wxDefaultPosition, wxSize(150,-1), cmbbx_themeArr, 0);
    
    flexGridSizer164->Add(cmbbx_theme, 0, wxALL, 5);
    
    m_staticLine353 = new wxStaticLine(m_panel257, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLI_HORIZONTAL);
    
    flexGridSizer164->Add(m_staticLine353, 0, wxALL|wxEXPAND, 5);
    
    m_staticLine351 = new wxStaticLine(m_panel257, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLI_HORIZONTAL);
    
    flexGridSizer164->Add(m_staticLine351, 0, wxALL|wxEXPAND, 5);
    
    m_staticText347 = new wxStaticText(m_panel257, wxID_ANY, _("Theme Name:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer164->Add(m_staticText347, 0, wxALL, 5);
    
    m_textCtrl349 = new wxTextCtrl(m_panel257, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(150,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrl349->SetHint(wxT(""));
    #endif
    
    flexGridSizer164->Add(m_textCtrl349, 0, wxALL, 5);
    
    m_staticText328 = new wxStaticText(m_panel257, wxID_ANY, _("Setting Colour:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer164->Add(m_staticText328, 0, wxALL, 5);
    
    m_colourPicker330 = new wxColourPickerCtrl(m_panel257, wxID_ANY, wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT), wxDefaultPosition, wxSize(150,-1), wxCLRP_DEFAULT_STYLE);
    
    flexGridSizer164->Add(m_colourPicker330, 0, wxALL, 5);
    
    m_listCtrl336 = new wxListCtrl(m_panel257, wxID_ANY, wxDefaultPosition, wxSize(275,-1), wxLC_REPORT);
    
    flexGridSizer345->Add(m_listCtrl336, 0, wxALL, 5);
    
    m_panel117 = new wxPanel(m_treebook249, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook249->AddPage(m_panel117, _("Snippets"), false, wxNOT_FOUND);
    
    m_panel259 = new wxPanel(m_treebook249, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook249->AddPage(m_panel259, _("Scripting"), false, wxNOT_FOUND);
    
    m_panel261 = new wxPanel(m_treebook249, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook249->InsertSubPage(4, m_panel261, _("Python Scripts"), false, wxNOT_FOUND);
    
    m_panel265 = new wxPanel(m_treebook249, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook249->AddPage(m_panel265, _("Plugins"), false, wxNOT_FOUND);
    
    wxGridSizer* gridSizer132 = new wxGridSizer(0, 2, 0, 0);
    
    boxSizer168->Add(gridSizer132, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer134 = new wxBoxSizer(wxVERTICAL);
    
    gridSizer132->Add(boxSizer134, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer128 = new wxBoxSizer(wxHORIZONTAL);
    
    gridSizer132->Add(boxSizer128, 1, wxALL|wxEXPAND, 5);
    
    btn_OK = new wxButton(this, wxID_ANY, _("OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer128->Add(btn_OK, 0, wxALL, 5);
    
    btn_apply = new wxButton(this, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer128->Add(btn_apply, 0, wxALL, 5);
    
    btn_cancel = new wxButton(this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer128->Add(btn_cancel, 0, wxALL, 5);
    
    
    #if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(m_treebook249)){
        wxPersistenceManager::Get().RegisterAndRestore(m_treebook249);
    } else {
        wxPersistenceManager::Get().Restore(m_treebook249);
    }
    #endif
    m_treebook249->ExpandNode( 0, true );
    m_treebook249->ExpandNode( 1, true );
    m_treebook249->ExpandNode( 2, true );
    m_treebook249->ExpandNode( 3, true );
    m_treebook249->ExpandNode( 4, true );
    m_treebook249->ExpandNode( 5, true );
    m_treebook249->ExpandNode( 6, true );
    
    SetName(wxT("SettingsDialogBase"));
    SetSizeHints(700,400);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    cmbbx_fonts->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(SettingsDialogBase::OnCmbbx_fontsChoiceSelected), NULL, this);
    cmbbx_font_size->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(SettingsDialogBase::OnCmbbx_font_sizeChoiceSelected), NULL, this);
    cmbbx_theme->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(SettingsDialogBase::OnCmbbx_themeChoiceSelected), NULL, this);
    btn_OK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialogBase::OnBtn_okButtonClicked), NULL, this);
    btn_apply->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialogBase::OnBtn_applyButtonClicked), NULL, this);
    btn_cancel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialogBase::OnBtn_cancelButtonClicked), NULL, this);
    
}

SettingsDialogBase::~SettingsDialogBase()
{
    cmbbx_fonts->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(SettingsDialogBase::OnCmbbx_fontsChoiceSelected), NULL, this);
    cmbbx_font_size->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(SettingsDialogBase::OnCmbbx_font_sizeChoiceSelected), NULL, this);
    cmbbx_theme->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(SettingsDialogBase::OnCmbbx_themeChoiceSelected), NULL, this);
    btn_OK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialogBase::OnBtn_okButtonClicked), NULL, this);
    btn_apply->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialogBase::OnBtn_applyButtonClicked), NULL, this);
    btn_cancel->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(SettingsDialogBase::OnBtn_cancelButtonClicked), NULL, this);
    
}

SettingsFrameBase::SettingsFrameBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxFlexGridSizer* flexGridSizer204 = new wxFlexGridSizer(3, 1, 0, 0);
    flexGridSizer204->SetFlexibleDirection( wxBOTH );
    flexGridSizer204->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    this->SetSizer(flexGridSizer204);
    
    wxGridSizer* gridSizer205 = new wxGridSizer(0, 2, 0, 0);
    
    flexGridSizer204->Add(gridSizer205, 1, wxALL|wxEXPAND, 5);
    
    m_treebook233 = new wxTreebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    m_treebook233->SetName(wxT("m_treebook233"));
    
    flexGridSizer204->Add(m_treebook233, 0, wxALL, 5);
    
    m_panel235 = new wxPanel(m_treebook233, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook233->AddPage(m_panel235, _("Page"), false, wxNOT_FOUND);
    
    wxBoxSizer* boxSizer239 = new wxBoxSizer(wxVERTICAL);
    m_panel235->SetSizer(boxSizer239);
    
    wxFlexGridSizer* flexGridSizer207 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer207->SetFlexibleDirection( wxBOTH );
    flexGridSizer207->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    boxSizer239->Add(flexGridSizer207, 1, wxALL|wxEXPAND, 5);
    
    m_button201 = new wxButton(m_panel235, wxID_ANY, _("OK"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer207->Add(m_button201, 0, wxALL, 5);
    
    m_button199 = new wxButton(m_panel235, wxID_ANY, _("Apply"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer207->Add(m_button199, 0, wxALL, 5);
    
    m_button197 = new wxButton(m_panel235, wxID_ANY, _("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer207->Add(m_button197, 0, wxALL, 5);
    
    m_panel241 = new wxPanel(m_treebook233, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook233->InsertSubPage(0, m_panel241, _("Page"), false, wxNOT_FOUND);
    
    wxBoxSizer* boxSizer243 = new wxBoxSizer(wxVERTICAL);
    m_panel241->SetSizer(boxSizer243);
    
    m_textCtrl245 = new wxTextCtrl(m_panel241, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrl245->SetHint(wxT(""));
    #endif
    
    boxSizer243->Add(m_textCtrl245, 0, wxALL, 5);
    
    wxArrayString m_choice247Arr;
    m_choice247 = new wxChoice(m_panel241, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_choice247Arr, 0);
    
    boxSizer243->Add(m_choice247, 0, wxALL, 5);
    
    m_panel237 = new wxPanel(m_treebook233, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_treebook233->AddPage(m_panel237, _("Page"), false, wxNOT_FOUND);
    
    wxGridSizer* gridSizer231 = new wxGridSizer(2, 2, 0, 0);
    m_panel237->SetSizer(gridSizer231);
    
    m_staticText221 = new wxStaticText(m_panel237, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridSizer231->Add(m_staticText221, 0, wxALL, 5);
    
    m_textCtrl223 = new wxTextCtrl(m_panel237, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrl223->SetHint(wxT(""));
    #endif
    
    gridSizer231->Add(m_textCtrl223, 0, wxALL, 5);
    
    m_staticText226 = new wxStaticText(m_panel237, wxID_ANY, _("Static Text Label"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    gridSizer231->Add(m_staticText226, 0, wxALL, 5);
    
    wxArrayString m_comboBox228Arr;
    m_comboBox228 = new wxComboBox(m_panel237, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), m_comboBox228Arr, 0);
    #if wxVERSION_NUMBER >= 3000
    m_comboBox228->SetHint(wxT(""));
    #endif
    
    gridSizer231->Add(m_comboBox228, 0, wxALL, 5);
    
    
    #if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(m_treebook233)){
        wxPersistenceManager::Get().RegisterAndRestore(m_treebook233);
    } else {
        wxPersistenceManager::Get().Restore(m_treebook233);
    }
    #endif
    m_treebook233->ExpandNode( 0, true );
    m_treebook233->ExpandNode( 1, true );
    m_treebook233->ExpandNode( 2, true );
    
    SetName(wxT("SettingsFrameBase"));
    SetSizeHints(630,400);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
}

SettingsFrameBase::~SettingsFrameBase()
{
}
