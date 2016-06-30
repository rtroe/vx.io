///////////////////////////////////////////////////////////////////////////////
// Name:        MainFrame.cpp
// Purpose:     The main wxaui frame which handles all 
// Author:      R.T. Roe
// Modified by:
// Created:     2016-06-30
// Licence:     MIT
///////////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"
#include "include/gui/vxAUIToolbarArt.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)

// Menu Events
EVT_MENU(ID_New, MainFrame::New)
EVT_MENU(wxID_OPEN, MainFrame::Open)
EVT_MENU(wxID_SAVE, MainFrame::Save)
EVT_MENU(wxID_SAVEAS, MainFrame::SaveAs)
EVT_MENU(wxID_EXIT, MainFrame::OnExit)
EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
EVT_CLOSE(MainFrame::OnCloseWindow)

// -- edit --
EVT_MENU(wxID_UNDO, MainFrame::Undo)
EVT_MENU(wxID_REDO, MainFrame::Redo)
EVT_MENU(wxID_CUT, MainFrame::Cut)
EVT_MENU(wxID_COPY, MainFrame::Copy)
EVT_MENU(wxID_PASTE, MainFrame::Paste)

// -- search --
EVT_MENU(ID_FIND, MainFrame::OnFind)
EVT_MENU(ID_FIND_NEXT, MainFrame::OnFindNext)
EVT_MENU(ID_FIND_PREV, MainFrame::OnFindPrev)
EVT_MENU(ID_REPLACE, MainFrame::OnReplace)
EVT_MENU(ID_REPLACE_NEXT, MainFrame::OnReplaceNext)

// -- lexars --
EVT_MENU(MainFrame::ID_C, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_CPP, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_CS, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_CSS, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_HTML, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_HLSL, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_JS, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_PY, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_PHP, MainFrame::OnLexarUpdate)
EVT_MENU(MainFrame::ID_TXT, MainFrame::OnLexarUpdate)

// -- view --
EVT_MENU(MainFrame::ID_DISPLAYEOL, MainFrame::OnEOLToggle)
EVT_MENU(ID_CHANGELOWER, MainFrame::OnChangeCase)
EVT_MENU(ID_CHANGEUPPER, MainFrame::OnChangeCase)
EVT_MENU(ID_CONVERTCR, MainFrame::OnConvertEOL)
EVT_MENU(ID_CONVERTCRLF, MainFrame::OnConvertEOL)
EVT_MENU(ID_CONVERTLF, MainFrame::OnConvertEOL)
EVT_MENU(ID_FOLDTOGGLE, MainFrame::OnFoldToggle)


// -- help --
EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
EVT_MENU(MainFrame::ID_Help, MainFrame::OnHelp)
EVT_MENU(MainFrame::ID_ReportBug, MainFrame::OnReportBug)
EVT_MENU(MainFrame::ID_ViewChangeLog, MainFrame::OnViewChangeLog)
EVT_MENU(MainFrame::ID_CheckForUpdates, MainFrame::OnCheckForUpdates)

// Updates the toolbars everytime a key is pressed
EVT_CHAR_HOOK(MainFrame::SetToolbarStatusEvent)

EVT_ERASE_BACKGROUND(MainFrame::OnEraseBackground)
EVT_SIZE(MainFrame::OnSize)
EVT_MENU(MainFrame::ID_CreateTree, MainFrame::OnCreateTree)
EVT_MENU(MainFrame::ID_CreateGrid, MainFrame::OnCreateGrid)
EVT_MENU(MainFrame::ID_CreateHTML, MainFrame::OnCreateHTML)
EVT_MENU(MainFrame::ID_CreateStyleText, MainFrame::OnCreateStyleTextCtrl)
EVT_MENU(MainFrame::ID_CreateNotebook, MainFrame::OnCreateNotebook)
EVT_MENU(MainFrame::ID_CreatePerspective, MainFrame::OnCreatePerspective)
EVT_MENU(MainFrame::ID_CopyPerspectiveCode, MainFrame::OnCopyPerspectiveCode)
EVT_MENU(ID_AllowFloating, MainFrame::OnManagerFlag)
EVT_MENU(ID_TransparentHint, MainFrame::OnManagerFlag)
EVT_MENU(ID_VenetianBlindsHint, MainFrame::OnManagerFlag)
EVT_MENU(ID_RectangleHint, MainFrame::OnManagerFlag)
EVT_MENU(ID_NoHint, MainFrame::OnManagerFlag)
EVT_MENU(ID_HintFade, MainFrame::OnManagerFlag)
EVT_MENU(ID_NoVenetianFade, MainFrame::OnManagerFlag)
EVT_MENU(ID_TransparentDrag, MainFrame::OnManagerFlag)
EVT_MENU(ID_LiveUpdate, MainFrame::OnManagerFlag)
EVT_MENU(ID_AllowActivePane, MainFrame::OnManagerFlag)
EVT_MENU(ID_NotebookTabFixedWidth, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookNoCloseButton, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookCloseButton, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookCloseButtonAll, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookCloseButtonActive, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookAllowTabMove, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookAllowTabExternalMove, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookAllowTabSplit, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookScrollButtons, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookWindowList, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookArtGloss, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookArtSimple, MainFrame::OnNotebookFlag)
EVT_MENU(ID_NotebookAlignTop, MainFrame::OnTabAlignment)
EVT_MENU(ID_NotebookAlignBottom, MainFrame::OnTabAlignment)
EVT_MENU(ID_NoGradient, MainFrame::OnGradient)
EVT_MENU(ID_VerticalGradient, MainFrame::OnGradient)
EVT_MENU(ID_HorizontalGradient, MainFrame::OnGradient)
EVT_MENU(ID_AllowToolbarResizing, MainFrame::OnToolbarResizing)
EVT_MENU(ID_Settings, MainFrame::OnSettings)
EVT_MENU(ID_CustomizeToolbar, MainFrame::OnCustomizeToolbar)
EVT_MENU(ID_GridContent, MainFrame::OnChangeContentPane)
EVT_MENU(ID_TreeContent, MainFrame::OnChangeContentPane)
EVT_MENU(ID_TextContent, MainFrame::OnChangeContentPane)
EVT_MENU(ID_SizeReportContent, MainFrame::OnChangeContentPane)
EVT_MENU(ID_HTMLContent, MainFrame::OnChangeContentPane)
EVT_MENU(ID_NotebookContent, MainFrame::OnChangeContentPane)
EVT_MENU(wxID_EXIT, MainFrame::OnExit)
EVT_UPDATE_UI(ID_NotebookTabFixedWidth, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookNoCloseButton, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookCloseButton, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookCloseButtonAll, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookCloseButtonActive, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookAllowTabMove, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookAllowTabExternalMove, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookAllowTabSplit, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookScrollButtons, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NotebookWindowList, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_AllowFloating, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_TransparentHint, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_VenetianBlindsHint, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_RectangleHint, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NoHint, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_HintFade, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NoVenetianFade, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_TransparentDrag, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_LiveUpdate, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_NoGradient, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_VerticalGradient, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_HorizontalGradient, MainFrame::OnUpdateUI)
EVT_UPDATE_UI(ID_AllowToolbarResizing, MainFrame::OnUpdateUI)
EVT_MENU_RANGE(MainFrame::ID_FirstPerspective, MainFrame::ID_FirstPerspective + 1000, MainFrame::OnRestorePerspective)
EVT_AUITOOLBAR_TOOL_DROPDOWN(ID_DropDownToolbarItem, MainFrame::OnDropDownToolbarItem)
EVT_AUI_PANE_CLOSE(MainFrame::OnPaneClose)
// EVT_AUINOTEBOOK_PAGE_CHANGED(wxID_ANY, MainFrame::OnToolbar)
EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, MainFrame::OnAllowNotebookDnD)
EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, MainFrame::OnNotebookPageClose)
EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, MainFrame::OnNotebookPageClosed)
EVT_AUINOTEBOOK_PAGE_CHANGED(wxID_ANY, MainFrame::OnNotebookPageChanged)

// Find and Replace Events
EVT_TEXT(ID_TEXTCHANGE, MainFrame::OnFind)

// Directory Control Events
EVT_DIRCTRL_FILEACTIVATED(ID_CNTRL_DIRTREE, MainFrame::OnFileActivated)
END_EVENT_TABLE()

// Declare the bitmap loading function
extern void wxC9ED9InitBitmapResources();

static bool bBitmapLoaded = false;

void MainFrame::LoadAllImages()
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9InitBitmapResources();
        bBitmapLoaded = true;
    }

    vxAppImgs = new vxIcons();

    wxIcon icon;
    icon.CopyFromBitmap(vxAppImgs->AppIcon16);
}

MainFrame::MainFrame(wxWindow* parent,
                     wxWindowID id,
                     const wxString& title,
                     const wxPoint& pos,
                     const wxSize& size,
                     long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    // tell wxAuiManager to manage this frame
    m_mgr.SetManagedWindow(this);

    // set frame icon
    LoadAllImages();

    VXIO_APPLICATIONNAME = wxT("vx.io");
    VXIO_VERSION = wxT("v 0.2.0.0");
    VXIO_RELEASE = wxT("Bamboo");

#if defined(__WXMSW__)
    std::cout << "Starting Under Windows" << std::endl;
#elif defined(__WXMAC__)
// Mac Specific Initilazations here
#elif defined(__UNIX__)
    //'nix Specific Initilazations here
    std::cout << "Starting Under Linux" << std::endl;
#endif

    wxIcon icon;
    icon.CopyFromBitmap(vxAppImgs->AppIcon16);

    SetIcon(icon);

    // set up default notebook style
    m_notebook_style = wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER;
    m_notebook_theme = 0;
    INT_NewFileList = 0;
    FindResultIndex = 0;
    
    
    
    
        htmlWindow_changeLog = CreateHTMLCtrl();
    htmlWindow_changeLog->LoadPage("doc/changelog.html");
    m_mgr.AddPane(
        htmlWindow_changeLog,
         wxAuiPaneInfo()
                      .Name(wxT("ctrl_changeLog"))
                      .Caption(wxT("Change Log"))
                      .Right()
                      .Layer(1)
                      .Position(1)
                      .CloseButton(true)
                      .MaximizeButton(true));
    
    
   htmlWindow_help= CreateHTMLCtrl();
    htmlWindow_help->SetPage(GetIntroText());
    
    m_mgr.AddPane(
        htmlWindow_help,
         wxAuiPaneInfo()
                      .Name(wxT("ctrl_help"))
                      .Caption(wxT("Help"))
                      .Right()
                      .Layer(1)
                      .Position(1)
                      .CloseButton(true)
                      .MaximizeButton(true));
                      
                      

    // create menu
    wxMenuBar* mb = new wxMenuBar;

    //
    // File
    //
    // -- main menu --
    file_menu = new wxMenu;
    file_menu->Append(ID_New, _("New\tCTRL+N"), "Creates a new document");
    file_menu->Append(wxID_OPEN);
    file_menu->AppendSeparator();
    file_menu->Append(wxID_SAVE);
    file_menu->Append(wxID_SAVEAS);
    file_menu->Append(ID_SaveAll, _("Save All"));
    file_menu->AppendSeparator();
    file_menu->Append(ID_DocumentProperties, _("Document Properties"));
    file_menu->AppendSeparator();
    file_menu->Append(wxID_EXIT);

    // -- edit --
    menu_edit = new wxMenu;
    menu_edit->Append(wxID_UNDO);
    menu_edit->Append(wxID_REDO);
    menu_edit->AppendSeparator();
    menu_edit->Append(wxID_CUT);
    menu_edit->Append(wxID_COPY);
    menu_edit->Append(wxID_PASTE);

    // -- edit --
    wxMenu* menu_search = new wxMenu;
    menu_search->Append(ID_FIND, "&Find...\tCTRL+F", "Creates a new XYZ document");
    menu_search->Append(ID_FIND_NEXT, "&Find Next\tF3", "Creates a new XYZ document");
    menu_search->Append(ID_FIND_PREV, "&Find Prev\tSHIFT+F3", "Creates a new XYZ document");
    menu_search->AppendSeparator();
    menu_search->Append(ID_REPLACE, "&Replace...\tCTRL+H", "Creates a new XYZ document");
    menu_search->Append(ID_REPLACE_NEXT, "& Replace Next\tSHIFT+CTRL+H", "Creates a new XYZ document");

    /********************************************************************************************/
    /*          view            */
    /********************************************************************************************/

    // -- lexars --
    wxMenu* menu_lexar = new wxMenu;
    menu_lexar->AppendRadioItem(ID_C, _("C Source File(*.c)"));
    menu_lexar->AppendRadioItem(ID_CPP, _("C++ Source File(*.cpp, *.h)"));
    menu_lexar->AppendRadioItem(ID_CS, _("C# Source File(*.cs)"));
    menu_lexar->AppendRadioItem(ID_CSS, _("CSS Source File(*.css)"));
    menu_lexar->AppendRadioItem(ID_HLSL, _("HLSL - High Level Shader Language(*.fx)"));
    menu_lexar->AppendRadioItem(ID_HTML, _("HTML(*.html,*.htm)"));
    menu_lexar->AppendRadioItem(ID_JS, _("Java Script File(*.js)"));
    menu_lexar->AppendRadioItem(ID_PHP, _("PHP Script(*.php)"));
    menu_lexar->AppendRadioItem(ID_PY, _("Python Script(*.py, *.pyw)"));
    menu_lexar->AppendRadioItem(ID_TXT, _("Text(*.txt)"));

    // convert EOL submenu
    wxMenu* menuConvertEOL = new wxMenu;
    menuConvertEOL->Append(ID_CONVERTCR, _("CR (&Linux)"));
    menuConvertEOL->Append(ID_CONVERTCRLF, _("CR+LF (&Windows)"));
    menuConvertEOL->Append(ID_CONVERTLF, _("LF (&Macintosh)"));

    // change case submenu
    wxMenu* menuChangeCase = new wxMenu;
    menuChangeCase->Append(ID_CHANGEUPPER, _("&Upper case"));
    menuChangeCase->Append(ID_CHANGELOWER, _("&Lower case"));

    // -- view --
    view_menu = new wxMenu;
    /*
        view_menu->Append(wxID_ANY,_("&Hilight language .."), menu_lexar);
        view_menu->AppendSeparator();
        */
    view_menu->AppendCheckItem(ID_ToggleTree, _("Toggle Tree View"));
    view_menu->AppendCheckItem(ID_ToggleConsole, _("Toggle Console"));
    view_menu->AppendSeparator();
    view_menu->Append(ID_DISPLAYEOL, _("&Toggle EOL"));
    view_menu->Append(wxID_ANY, _("Convert line &endings to .."), menuConvertEOL);
    view_menu->AppendSeparator();
    view_menu->Append(wxID_ANY, _("Change &case to .."), menuChangeCase);
    view_menu->AppendSeparator();
    view_menu->Append(ID_FOLDTOGGLE, _("&Toggle Fold"));

    /********************************************************************************************/
    /*          settings            */
    /********************************************************************************************/

    // notebook settings
    wxMenu* options_menu = new wxMenu;
    options_menu->AppendRadioItem(ID_TransparentHint, _("Transparent Hint"));
    options_menu->AppendRadioItem(ID_VenetianBlindsHint, _("Venetian Blinds Hint"));
    options_menu->AppendRadioItem(ID_RectangleHint, _("Rectangle Hint"));
    options_menu->AppendRadioItem(ID_NoHint, _("No Hint"));
    options_menu->AppendSeparator();
    options_menu->AppendCheckItem(ID_HintFade, _("Hint Fade-in"));
    options_menu->AppendCheckItem(ID_AllowFloating, _("Allow Floating"));
    options_menu->AppendCheckItem(ID_NoVenetianFade, _("Disable Venetian Blinds Hint Fade-in"));
    options_menu->AppendCheckItem(ID_TransparentDrag, _("Transparent Drag"));
    options_menu->AppendCheckItem(ID_AllowActivePane, _("Allow Active Pane"));
    options_menu->AppendCheckItem(ID_LiveUpdate, _("Live Resize Update"));
    options_menu->AppendSeparator();
    options_menu->AppendRadioItem(ID_NoGradient, _("No Caption Gradient"));
    options_menu->AppendRadioItem(ID_VerticalGradient, _("Vertical Caption Gradient"));
    options_menu->AppendRadioItem(ID_HorizontalGradient, _("Horizontal Caption Gradient"));
    options_menu->AppendSeparator();
    options_menu->AppendCheckItem(ID_AllowToolbarResizing, _("Allow Toolbar Resizing"));
    options_menu->AppendSeparator();
    options_menu->Append(ID_Settings, _("Settings Pane"));

    // toolbar settings
    wxMenu* notebook_menu = new wxMenu;
    notebook_menu->AppendRadioItem(ID_NotebookNoCloseButton, _("No Close Button"));
    notebook_menu->AppendRadioItem(ID_NotebookCloseButton, _("Close Button at Right"));
    notebook_menu->AppendRadioItem(ID_NotebookCloseButtonAll, _("Close Button on All Tabs"));
    notebook_menu->AppendRadioItem(ID_NotebookCloseButtonActive, _("Close Button on Active Tab"));
    notebook_menu->AppendSeparator();
    notebook_menu->AppendRadioItem(ID_NotebookAlignTop, _("Tab Top Alignment"));
    notebook_menu->AppendRadioItem(ID_NotebookAlignBottom, _("Tab Bottom Alignment"));
    notebook_menu->AppendSeparator();
    notebook_menu->AppendCheckItem(ID_NotebookAllowTabMove, _("Allow Tab Move"));
    notebook_menu->AppendCheckItem(ID_NotebookAllowTabExternalMove, _("Allow External Tab Move"));
    notebook_menu->AppendCheckItem(ID_NotebookAllowTabSplit, _("Allow Notebook Split"));
    notebook_menu->AppendCheckItem(ID_NotebookScrollButtons, _("Scroll Buttons Visible"));
    notebook_menu->AppendCheckItem(ID_NotebookWindowList, _("Window List Button Visible"));
    notebook_menu->AppendCheckItem(ID_NotebookTabFixedWidth, _("Fixed-width Tabs"));

    // layout
    m_perspectives_menu = new wxMenu;
    m_perspectives_menu->Append(ID_CreatePerspective, _("Save Layout"));
    m_perspectives_menu->Append(ID_CopyPerspectiveCode, _("Copy Layout Data To Clipboard"));
    m_perspectives_menu->AppendSeparator();
    m_perspectives_menu->Append(ID_FirstPerspective + 0, _("Default Startup"));
    m_perspectives_menu->Append(ID_FirstPerspective + 1, _("All Panes"));

    wxMenu* menu_setting = new wxMenu;
    menu_setting->Append(wxID_ANY, _("Layout"), m_perspectives_menu);
    menu_setting->Append(wxID_ANY, _("Toolbars"), notebook_menu);
    menu_setting->Append(wxID_ANY, _("Notebook"), options_menu);

    /********************************************************************************************/
    /*          help            */
    /********************************************************************************************/
    wxMenu* help_menu = new wxMenu;
    help_menu->Append(wxID_ABOUT);
    help_menu->Append(ID_Help, _("Help"));
    help_menu->AppendSeparator();
    help_menu->Append(ID_ReportBug, _("Report Bug"));
    help_menu->AppendSeparator();
    help_menu->Append(ID_ViewChangeLog, _("View Change Log"));
    help_menu->Append(ID_CheckForUpdates, _("Check for Updates..."));

    mb->Append(file_menu, _("&File"));
    mb->Append(menu_edit, _("&Edit"));
    mb->Append(view_menu, _("&View"));
    mb->Append(menu_search, _("&Search"));
    mb->Append(menu_lexar, _("&Language"));
    mb->Append(menu_setting, _("&Settings"));
    mb->Append(help_menu, _("&Help"));

    SetMenuBar(mb);

    CreateStatusBar();
    GetStatusBar()->SetStatusText(_("Ready"));

    // min size for the frame itself isn't completely done.
    // see the end up wxAuiManager::Update() for the test
    // code. For now, just hard code a frame minimum size
    SetMinSize(wxSize(400, 300));

    // prepare a few custom overflow elements for the toolbars' overflow buttons

    wxAuiToolBarItemArray prepend_items;
    wxAuiToolBarItemArray append_items;
    wxAuiToolBarItem item;
    item.SetKind(wxITEM_SEPARATOR);
    append_items.Add(item);
    item.SetKind(wxITEM_NORMAL);
    item.SetId(ID_CustomizeToolbar);
    item.SetLabel(_("Customize..."));
    append_items.Add(item);

    tb_mainmenu =
        new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    tb_mainmenu->SetArtProvider(new vxAuiToolbarArt());
    tb_mainmenu->SetToolBitmapSize(wxSize(16, 16));

    wxBitmap tb_mainmenu_bmp1 = wxArtProvider::GetBitmap(wxART_QUESTION, wxART_OTHER, wxSize(16, 16));
    tb_mainmenu->AddTool(ID_New, wxT("New"), vxAppImgs->FileNew16);
    tb_mainmenu->AddTool(wxID_OPEN, wxT("Open"), vxAppImgs->FileOpen16);
    tb_mainmenu->AddTool(wxID_SAVE, wxT("Save"), vxAppImgs->Save16);
    tb_mainmenu->AddTool(wxID_SAVEAS, wxT("Save As"), vxAppImgs->SaveAs16);
    tb_mainmenu->AddTool(ID_SaveAll, wxT("Save All"), vxAppImgs->SaveAll16);
    tb_mainmenu->AddSeparator();
    tb_mainmenu->AddTool(wxID_UNDO, wxT("Undo"), vxAppImgs->Undo16);
    tb_mainmenu->AddTool(wxID_REDO, wxT("Redo"), vxAppImgs->Redo16);
    tb_mainmenu->AddSeparator();
    tb_mainmenu->AddTool(wxID_CUT, wxT("Cut"), vxAppImgs->Cut16);
    tb_mainmenu->AddTool(wxID_COPY, wxT("Copy"), vxAppImgs->Copy16);
    tb_mainmenu->AddTool(wxID_PASTE, wxT("Paste"), vxAppImgs->Paste16);
    tb_mainmenu->SetCustomOverflowItems(prepend_items, append_items);

    // tb_mainmenu->EnableTool(ID_SampleItem+6, false);
    tb_mainmenu->Realize();
    
    
    tb_system = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    tb_system->SetArtProvider(new vxAuiToolbarArt());
    tb_system->SetToolBitmapSize(wxSize(16, 16));

    tb_system->AddTool(
        ID_ShowGlobalSettings, wxT("Application Settings"),  vxAppImgs->AppSettings16, wxT("Application Settings"));
    tb_system->AddSeparator();
    tb_system->AddTool(ID_ToggleTree, wxT("Toggle Tree"), vxAppImgs->Treeview16, wxT("Hide/Show Tree"), wxITEM_CHECK);
    tb_system->AddTool(ID_ToggleConsole, wxT("Toggle Console"), vxAppImgs->Console16, wxT("Hide/Show Console"), wxITEM_CHECK);
    tb_system->AddSeparator();

    tb_system->AddTool(ID_ManageAddons, wxT("Manage Add-Ins"), vxAppImgs->ManageAddins16, wxT("Manage Add-Ins"));

    m_mgr.AddPane(tb_system,
                  wxAuiPaneInfo().Name(wxT("tb_system")).Caption(wxT("System")).ToolbarPane().Top().Row(1).Position(3));


/*    this->Connect(ID_ShowGlobalSettings,
                  wxEVT_COMMAND_MENU_SELECTED,
                  wxCommandEventHandler(MainFrame::ShowGloabelSettings),
                  NULL,
                  this);*/

    this->Connect(ID_ToggleTree, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnToggleDirTree), NULL, this);
    this->Connect(ID_ToggleConsole, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnToggleConsole), NULL, this);
    tb_system->Realize();
    
    

    wxAuiToolBar* tb_textmodify =
        new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    tb_textmodify->SetArtProvider(new vxAuiToolbarArt());
    tb_textmodify->SetToolBitmapSize(wxSize(16, 16));

    tb_textmodify->AddTool(ID_CHANGEUPPER, wxT("Change to Upper"), vxAppImgs->ToUpperCase);
    tb_textmodify->AddTool(ID_CHANGELOWER, wxT("Change to Lower"), vxAppImgs->ToLowerCase);
    tb_textmodify->AddSeparator();
    tb_textmodify->AddTool(ID_DISPLAYEOL, wxT("Toggle Endline View"), vxAppImgs->ToggleEndline);

    tb_textmodify->SetCustomOverflowItems(prepend_items, append_items);

    // tb_mainmenu->EnableTool(ID_SampleItem+6, false);
    tb_textmodify->Realize();

    tb_find =
        new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    tb_find->SetArtProvider(new vxAuiToolbarArt());
    tb_find->SetToolBitmapSize(wxSize(16, 16));

    txtCntrl_Find = new wxTextCtrl(tb_find, ID_TEXTCHANGE, wxT(""), wxDefaultPosition, wxSize(250, -1));

    wxStaticText* textFind = new wxStaticText(tb_find, -1, wxT("Find: "));
    int clr = 150;
    textFind->SetForegroundColour(wxColor(clr, clr, clr));
    tb_find->AddControl(textFind);
    tb_find->AddControl(txtCntrl_Find);

    tb_find->AddTool(ID_FIND, wxT("Find"), vxAppImgs->FindWord);
    tb_find->AddSeparator();
    tb_find->AddTool(ID_FIND_PREV, wxT("Find Previous"), vxAppImgs->FindPrev);
    tb_find->AddTool(ID_FIND_NEXT, wxT("Find Next"), vxAppImgs->FindNext);

    tb_find->SetCustomOverflowItems(prepend_items, append_items);

    // tb_mainmenu->EnableTool(ID_SampleItem+6, false);
    tb_find->Realize();

    m_mgr.AddPane(CreateNotebook(), wxAuiPaneInfo().Name(wxT("notebook_content")).CenterPane().PaneBorder(false));

    m_mgr.AddPane(
        tb_mainmenu,
        wxAuiPaneInfo().Name(wxT("tb_mainmenu")).Caption(wxT("Main Menu")).ToolbarPane().Top().Row(1).Position(1));

    m_mgr.AddPane(
        tb_textmodify,
        wxAuiPaneInfo().Name(wxT("tb_textmodify")).Caption(wxT("Text Modify")).ToolbarPane().Top().Row(2).Position(1));

    m_mgr.AddPane(
        tb_find,
        wxAuiPaneInfo().Name(wxT("tb_find")).Caption(wxT("Find")).ToolbarPane().Bottom().Row(1).Position(1).Hide());

    ctrl_DirTreeView = CreateDirViewCtrl();
    m_mgr.AddPane(ctrl_DirTreeView,
                  wxAuiPaneInfo()
                      .Name(wxT("ctrl_dirTree"))
                      .Caption(wxT("Directory View"))
                      .Left()
                      .Layer(1)
                      .Position(1)
                      .CloseButton(true)
                      .MaximizeButton(true));
                      
                      CreateConsole();
ConsoleWriteLine("Starting vx.io - " + 
                             wxString::Format(wxT(" [") + VXIO_VERSION + wxT("] - ") + wxNow()));
ConsoleWriteLine("======================================");
ConsoleWriteLine("(C) @virt3.c 2016");
ConsoleWriteLine("Release: \t" + VXIO_RELEASE);
ConsoleWriteLine("Version: \t" + VXIO_VERSION);

    // make some default perspectives

    wxString perspective_all = m_mgr.SavePerspective();

    int i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for(i = 0, count = all_panes.GetCount(); i < count; ++i)
        if(!all_panes.Item(i).IsToolbar())
            all_panes.Item(i).Hide();

    //m_mgr.GetPane(wxT("ctrl_dirTree")).Show();
    m_mgr.GetPane(wxT("notebook_content")).Show();
    wxString perspective_default = m_mgr.SavePerspective();

    m_perspectives.Add(perspective_default);
    m_perspectives.Add(perspective_all);

    wxColour BackgroundColour(50, 50, 50);
    wxColour ForegroundColour(150, 150, 150);
    wxColour Controls_Header(255, 150, 25);

    GetStatusBar()->SetBackgroundColour(BackgroundColour);
    GetStatusBar()->SetForegroundColour(wxColour(255, 255, 255));

    // Set AUI
    GetDockArt()->SetColor(wxAUI_DOCKART_BACKGROUND_COLOUR, BackgroundColour);
    GetDockArt()->SetColor(wxAUI_DOCKART_BORDER_COLOUR, BackgroundColour);
    GetDockArt()->SetColor(wxAUI_DOCKART_GRIPPER_COLOUR, BackgroundColour);
    GetDockArt()->SetColor(wxAUI_DOCKART_SASH_COLOUR, BackgroundColour);
    GetDockArt()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR, Controls_Header.ChangeLightness(125));
    GetDockArt()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR, Controls_Header);

    m_ntbk->SetBackgroundColour(BackgroundColour);

    m_ntbk->Update();

    // Set Property Grid
    /*    Ctrl_PropertyGrid->SetCellBackgroundColour(BackgroundColour);
        Ctrl_PropertyGrid->SetCellTextColour(ForegroundColour);
        Ctrl_PropertyGrid->SetEmptySpaceColour(BackgroundColour.ChangeLightness(120));*/

    // Drop all Pane Boundaries for Dark Theme. Otherwise an annoying white border shows on the left and upper edges
    wxAuiPaneInfoArray panes = m_mgr.GetAllPanes();
    for(size_t i = 0; i < panes.GetCount(); i++) {
        m_mgr.GetPane(panes.Item(i).name).PaneBorder(false);
    }

    this->DragAcceptFiles(true);

    this->Connect(wxEVT_DROP_FILES, wxDropFilesEventHandler(MainFrame::OnDropFiles), NULL, this);

    // "commit" all changes made to wxAuiManager
    m_mgr.Update();

    SetToolbarStatus();

    fileFilter = _("Any File (*.*)|*.*");

    fileFilter += _("|C File (*.c)|*.c");
    fileFilter += _("|C++ File (*.cpp;*.h)|*.cpp;*.h");
    fileFilter += _("|C# File (*.cs)|*.cs");
    fileFilter += _("|HLSL File (*.fx)|*.fx");
    fileFilter += _("|HTML File (*.html;*.htm)|*.html;*.htm");
    fileFilter += _("|Python Script (*.py;*.pyw)|*.py;*.pyw");
    fileFilter += _("|Text File (*.txt)|*.txt");
    fileFilter += _("");
    fileFilter += _("");
}

MainFrame::~MainFrame()
{
    m_mgr.UnInit();
}


wxString MainFrame::GetIntroText()
{
    const char* text = "<html><body>"
                       "<h3>Welcome to wxAUI</h3>"
                       "<br/><b>Overview</b><br/>"
                       "<p>wxAUI is an Advanced User Interface library for the wxWidgets toolkit "
                       "that allows developers to create high-quality, cross-platform user "
                       "interfaces quickly and easily.</p>"
                       "<p><b>Features</b></p>"
                       "<p>With wxAUI, developers can create application frameworks with:</p>"
                       "<ul>"
                       "<li>Native, dockable floating frames</li>"
                       "<li>Perspective saving and loading</li>"
                       "<li>Native toolbars incorporating real-time, &quot;spring-loaded&quot; dragging</li>"
                       "<li>Customizable floating/docking behaviour</li>"
                       "<li>Completely customizable look-and-feel</li>"
                       "<li>Optional transparent window effects (while dragging or docking)</li>"
                       "<li>Splittable notebook control</li>"
                       "</ul>"
                       "<p><b>What's new in 0.9.4?</b></p>"
                       "<p>wxAUI 0.9.4, which is bundled with wxWidgets, adds the following features:"
                       "<ul>"
                       "<li>New wxAuiToolBar class, a toolbar control which integrates more "
                       "cleanly with wxAuiFrameManager.</li>"
                       "<li>Lots of bug fixes</li>"
                       "</ul>"
                       "<p><b>What's new in 0.9.3?</b></p>"
                       "<p>wxAUI 0.9.3, which is now bundled with wxWidgets, adds the following features:"
                       "<ul>"
                       "<li>New wxAuiNotebook class, a dynamic splittable notebook control</li>"
                       "<li>New wxAuiMDI* classes, a tab-based MDI and drop-in replacement for classic MDI</li>"
                       "<li>Maximize/Restore buttons implemented</li>"
                       "<li>Better hinting with wxGTK</li>"
                       "<li>Class rename.  'wxAui' is now the standard class prefix for all wxAUI classes</li>"
                       "<li>Lots of bug fixes</li>"
                       "</ul>"
                       "<p><b>What's new in 0.9.2?</b></p>"
                       "<p>The following features/fixes have been added since the last version of wxAUI:</p>"
                       "<ul>"
                       "<li>Support for wxMac</li>"
                       "<li>Updates for wxWidgets 2.6.3</li>"
                       "<li>Fix to pass more unused events through</li>"
                       "<li>Fix to allow floating windows to receive idle events</li>"
                       "<li>Fix for minimizing/maximizing problem with transparent hint pane</li>"
                       "<li>Fix to not paint empty hint rectangles</li>"
                       "<li>Fix for 64-bit compilation</li>"
                       "</ul>"
                       "<p><b>What changed in 0.9.1?</b></p>"
                       "<p>The following features/fixes were added in wxAUI 0.9.1:</p>"
                       "<ul>"
                       "<li>Support for MDI frames</li>"
                       "<li>Gradient captions option</li>"
                       "<li>Active/Inactive panes option</li>"
                       "<li>Fix for screen artifacts/paint problems</li>"
                       "<li>Fix for hiding/showing floated window problem</li>"
                       "<li>Fix for floating pane sizing problem</li>"
                       "<li>Fix for drop position problem when dragging around center pane margins</li>"
                       "<li>LF-only text file formatting for source code</li>"
                       "</ul>"
                       "<p>See README.txt for more information.</p>"
                       "</body></html>";

    return wxString::FromAscii(text);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Returns the Active Document
//
vxTextCtrl* MainFrame::GetActiveDocument()
{
    if(m_ntbk->GetPageCount() > 0) {
        if(m_ntbk->GetPage(m_ntbk->GetSelection())->IsKindOf(CLASSINFO(vxTextCtrl))) {
            return (vxTextCtrl*)(m_ntbk->GetPage(m_ntbk->GetSelection()));
        } else
        {
            //wxMessageBox(wxT("Error Finding Active Document"));
            return (vxTextCtrl*)(m_ntbk->GetPage(0));
        }
    }
    return NULL;
}


// Set Toolbar Status
void MainFrame::SetToolbarStatusEvent(wxKeyEvent& event)
{
    SetToolbarStatus();
    event.Skip();
}

void MainFrame::SetToolbarStatus()
{
    // Set Status Bar
    const int width_filename = 450;
    GetStatusBar()->SetFieldsCount(3);

    // Set Active Document
    GetStatusBar()->SetStatusText(GetActiveDocument()->FilePath, 0);

    // Set Caret Position
    GetStatusBar()->SetStatusText(
        wxString::Format(_("Line %i, Column %i"),
                         GetActiveDocument()->GetLineCount(),
                         GetActiveDocument()->GetColumn(GetActiveDocument()->GetCurrentPos()) + 1),
        1);

    // Set Read/Write Status
    wxString IsReadOnly = _("Read");
    if(!GetActiveDocument()->GetReadOnly())
        IsReadOnly = _("Read/Write");

    GetStatusBar()->SetStatusText(IsReadOnly, 2);

    //file_menu->Enable(wxID_SAVE, GetActiveDocument()->GetModify());
    //tb_mainmenu->EnableTool(wxID_SAVE, GetActiveDocument()->GetModify());

    menu_edit->Enable(wxID_UNDO, GetActiveDocument()->CanUndo());
    menu_edit->Enable(wxID_REDO, GetActiveDocument()->CanRedo());
    menu_edit->Enable(wxID_PASTE, GetActiveDocument()->CanPaste());

    tb_mainmenu->EnableTool(wxID_UNDO, GetActiveDocument()->CanUndo());
    tb_mainmenu->EnableTool(wxID_REDO, GetActiveDocument()->CanRedo());
    tb_mainmenu->EnableTool(wxID_PASTE, GetActiveDocument()->CanPaste());
    m_mgr.Update();

    if(m_ntbk->GetPageCount() > 0) {
        wxString title = GetActiveDocument()->FileName;

        if(GetActiveDocument()->GetModify())
            title = _("*") + title;

        m_ntbk->SetPageText(m_ntbk->GetSelection(), title);
    }

    SetTitle(VXIO_APPLICATIONNAME +_(" - ") + VXIO_RELEASE +_(" - (") + VXIO_VERSION + _(") - [") + GetActiveDocument()->FileName + _("]"));
}

void MainFrame::OnLexarUpdate(wxCommandEvent& event)
{
    unsigned int flags = m_mgr.GetFlags();

    switch(event.GetId()) {
    case ID_C:
        GetActiveDocument()->SetLexarAsC(GetActiveDocument());
        break;
    case ID_CPP:
        GetActiveDocument()->SetLexarAsCPP(GetActiveDocument());
        break;
    case ID_CS:
        GetActiveDocument()->SetLexarAsCS(GetActiveDocument());
        break;
    case ID_CSS:
        GetActiveDocument()->SetLexarAsCSS(GetActiveDocument());
        break;
    case ID_HLSL:
        GetActiveDocument()->SetLexarAsHLSL(GetActiveDocument());
        break;
    case ID_HTML:
        GetActiveDocument()->SetLexarAsHTML(GetActiveDocument());
        break;
    case ID_JS:
        GetActiveDocument()->SetLexarAsJS(GetActiveDocument());
        break;
    case ID_PY:
        GetActiveDocument()->SetLexarAsPython(GetActiveDocument());
        break;
    case ID_PHP:
        GetActiveDocument()->SetLexarAsPHP(GetActiveDocument());
        break;
    }
}


void MainFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}
