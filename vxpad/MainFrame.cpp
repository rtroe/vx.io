///////////////////////////////////////////////////////////////////////////////
// Name:        auidemo.cpp
// Purpose:     wxaui: wx advanced user interface - sample/test program
// Author:      Benjamin I. Williams
// Modified by:
// Created:     2005-10-03
// RCS-ID:      $Id$
// Copyright:   (C) Copyright 2005, Kirix Corporation, All Rights Reserved.
// Licence:     wxWindows Library Licence, Version 3.1
///////////////////////////////////////////////////////////////////////////////

 #include "MainFrame.h"
 #include "include/gui/vxAUIToolbarArt.h"
 #include "include/gui/vxAuiTabArt.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    
    //Menu Events
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
    EVT_MENU (ID_CHANGELOWER,        MainFrame::OnChangeCase)
    EVT_MENU (ID_CHANGEUPPER,        MainFrame::OnChangeCase)
    EVT_MENU (ID_CONVERTCR,          MainFrame::OnConvertEOL)
    EVT_MENU (ID_CONVERTCRLF,        MainFrame::OnConvertEOL)
    EVT_MENU (ID_CONVERTLF,          MainFrame::OnConvertEOL)
    EVT_MENU (ID_FOLDTOGGLE,         MainFrame::OnFoldToggle)

    //Updates the toolbars everytime a key is pressed
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
    EVT_MENU(ID_NotebookAlignTop,     MainFrame::OnTabAlignment)
    EVT_MENU(ID_NotebookAlignBottom,  MainFrame::OnTabAlignment)
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
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
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
    EVT_MENU_RANGE(MainFrame::ID_FirstPerspective, MainFrame::ID_FirstPerspective+1000,
                   MainFrame::OnRestorePerspective)
    EVT_AUITOOLBAR_TOOL_DROPDOWN(ID_DropDownToolbarItem, MainFrame::OnDropDownToolbarItem)
    EVT_AUI_PANE_CLOSE(MainFrame::OnPaneClose)
    //EVT_AUINOTEBOOK_PAGE_CHANGED(wxID_ANY, MainFrame::OnToolbar)
    EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, MainFrame::OnAllowNotebookDnD)
    EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, MainFrame::OnNotebookPageClose)
    EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, MainFrame::OnNotebookPageClosed)
    EVT_AUINOTEBOOK_PAGE_CHANGED(wxID_ANY, MainFrame::OnNotebookPageChanged)
    EVT_TEXT(ID_TEXTCHANGE, MainFrame::OnFind)
END_EVENT_TABLE()


//BEGIN_EVENT_TABLE(txtCntrl_Find, wxTextCtrl)
//END_EVENT_TABLE()




// Declare the bitmap loading function
extern void wxC9ED9InitBitmapResources();

static bool bBitmapLoaded = false;

void MainFrame::LoadAllImages()
{
      if ( !bBitmapLoaded ) {
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

    VXIO_VERSION = "v 0.3.2.1";
    
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

    // create menu
    wxMenuBar* mb = new wxMenuBar;



    //
    //File
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
    wxMenu *menuConvertEOL = new wxMenu;
    menuConvertEOL->Append (ID_CONVERTCR, _("CR (&Linux)"));
    menuConvertEOL->Append (ID_CONVERTCRLF, _("CR+LF (&Windows)"));
    menuConvertEOL->Append (ID_CONVERTLF, _("LF (&Macintosh)"));

        // change case submenu
    wxMenu *menuChangeCase = new wxMenu;
    menuChangeCase->Append (ID_CHANGEUPPER, _("&Upper case"));
    menuChangeCase->Append (ID_CHANGELOWER, _("&Lower case"));

    // -- view --
    wxMenu* view_menu = new wxMenu;
/*
    view_menu->Append(wxID_ANY,_("&Hilight language .."), menu_lexar);
    view_menu->AppendSeparator();
    */
    view_menu->Append(ID_DISPLAYEOL,_("&Toggle EOL"));
    view_menu->Append(wxID_ANY,_("Convert line &endings to .."), menuConvertEOL);
    view_menu->AppendSeparator();
    view_menu->Append(wxID_ANY,_("Change &case to .."), menuChangeCase);
    view_menu->AppendSeparator();
    view_menu->Append(ID_FOLDTOGGLE,_("&Toggle Fold"));


/********************************************************************************************/
                    /*          settings            */
/********************************************************************************************/

    //notebook settings
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

    //toolbar settings
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

    //layout
    m_perspectives_menu = new wxMenu;
    m_perspectives_menu->Append(ID_CreatePerspective, _("Save Layout"));
    m_perspectives_menu->Append(ID_CopyPerspectiveCode, _("Copy Layout Data To Clipboard"));
    m_perspectives_menu->AppendSeparator();
    m_perspectives_menu->Append(ID_FirstPerspective+0, _("Default Startup"));
    m_perspectives_menu->Append(ID_FirstPerspective+1, _("All Panes"));

    wxMenu* menu_setting = new wxMenu;
    menu_setting->Append(wxID_ANY,_("Layout"), m_perspectives_menu);
    menu_setting->Append(wxID_ANY,_("Toolbars"), notebook_menu);
    menu_setting->Append(wxID_ANY,_("Notebook"), options_menu);


/********************************************************************************************/
                    /*          help            */
/********************************************************************************************/
    wxMenu* help_menu = new wxMenu;
    help_menu->Append(wxID_ABOUT);

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
    SetMinSize(wxSize(400,300));



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


    tb_mainmenu = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                         wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    tb_mainmenu->SetArtProvider(new vxAuiToolbarArt());
    tb_mainmenu->SetToolBitmapSize(wxSize(16,16));

    wxBitmap tb_mainmenu_bmp1 = wxArtProvider::GetBitmap(wxART_QUESTION, wxART_OTHER, wxSize(16,16));
    tb_mainmenu->AddTool(ID_New, wxT("New"), vxAppImgs->FileNew16);
    tb_mainmenu->AddTool(wxID_OPEN, wxT("Open"),  vxAppImgs->FileOpen16);
    tb_mainmenu->AddTool(wxID_SAVE, wxT("Save"),  vxAppImgs->Save16);
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
    
    //tb_mainmenu->EnableTool(ID_SampleItem+6, false);
    tb_mainmenu->Realize();
    
    
    
    
    
    
   wxAuiToolBar* tb_textmodify = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                         wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    tb_textmodify->SetArtProvider(new vxAuiToolbarArt());
    tb_textmodify->SetToolBitmapSize(wxSize(16,16));

    tb_textmodify->AddTool(ID_CHANGEUPPER, wxT("Change to Upper"), vxAppImgs->ToUpperCase);
    tb_textmodify->AddTool(ID_CHANGELOWER, wxT("Change to Lower"),  vxAppImgs->ToLowerCase);
    tb_textmodify->AddSeparator();
    tb_textmodify->AddTool(ID_DISPLAYEOL, wxT("Toggle Endline View"),  vxAppImgs->ToggleEndline);
    
    tb_textmodify->SetCustomOverflowItems(prepend_items, append_items);
    
    //tb_mainmenu->EnableTool(ID_SampleItem+6, false);
    tb_textmodify->Realize();



tb_find = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                         wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    tb_find->SetArtProvider(new vxAuiToolbarArt());
    tb_find->SetToolBitmapSize(wxSize(16,16));
    
    txtCntrl_Find = new wxTextCtrl( tb_find,  ID_TEXTCHANGE, wxT(""), wxDefaultPosition, wxSize(250,-1));
    
    wxStaticText* textFind = new wxStaticText(tb_find,  -1, wxT("Find: "));
    int clr = 150;
    textFind->SetForegroundColour(wxColor(clr,clr,clr));
    tb_find->AddControl(textFind);
    tb_find->AddControl(txtCntrl_Find);

    tb_find->AddTool(ID_FIND, wxT("Find"), vxAppImgs->FindWord);
    tb_find->AddSeparator();
    tb_find->AddTool(ID_FIND_PREV, wxT("Find Previous"),  vxAppImgs->FindPrev);
    tb_find->AddTool(ID_FIND_NEXT, wxT("Find Next"),  vxAppImgs->FindNext);
    
    tb_find->SetCustomOverflowItems(prepend_items, append_items);
    
    //tb_mainmenu->EnableTool(ID_SampleItem+6, false);
    tb_find->Realize();



    m_mgr.AddPane(CreateNotebook(), wxAuiPaneInfo().Name(wxT("notebook_content")).
                  CenterPane().PaneBorder(false));


    m_mgr.AddPane(tb_mainmenu, wxAuiPaneInfo().
                  Name(wxT("tb_mainmenu")).Caption(wxT("Main Menu")).
                  ToolbarPane().Top().Row(1).Position(1));
                  
    m_mgr.AddPane(tb_textmodify, wxAuiPaneInfo().
                  Name(wxT("tb_textmodify")).Caption(wxT("Text Modify")).
                  ToolbarPane().Top().Row(1).Position(3));
                  
    m_mgr.AddPane(tb_find, wxAuiPaneInfo().
                  Name(wxT("tb_find")).Caption(wxT("Find")).
                  ToolbarPane().Bottom().Row(1).Position(1).Hide());

    // make some default perspectives

    wxString perspective_all = m_mgr.SavePerspective();

    int i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i)
        if (!all_panes.Item(i).IsToolbar())
            all_panes.Item(i).Hide();
    m_mgr.GetPane(wxT("notebook_content")).Show();
    wxString perspective_default = m_mgr.SavePerspective();

    m_perspectives.Add(perspective_default);
    m_perspectives.Add(perspective_all);
    
    
    
    
    wxColour BackgroundColour(50, 50, 50);
    wxColour ForegroundColour(150, 150, 150);
    wxColour Controls_Header(255, 150, 25);

    GetStatusBar()->SetBackgroundColour(BackgroundColour);
    GetStatusBar()->SetForegroundColour(wxColour(255,255,255));

    // Set AUI
    GetDockArt()->SetColor(wxAUI_DOCKART_BACKGROUND_COLOUR, BackgroundColour);
    GetDockArt()->SetColor(wxAUI_DOCKART_BORDER_COLOUR, BackgroundColour);
    GetDockArt()->SetColor(wxAUI_DOCKART_GRIPPER_COLOUR, BackgroundColour);
    GetDockArt()->SetColor(wxAUI_DOCKART_SASH_COLOUR, BackgroundColour);
    GetDockArt()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR, Controls_Header.ChangeLightness(125));
    GetDockArt()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR, Controls_Header);

    m_ntbk->SetBackgroundColour(BackgroundColour);
    
    m_ntbk->Update();

    //Set Property Grid
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

    void MainFrame::OnDropFiles(wxDropFilesEvent& event)    
    {
        if (event.GetNumberOfFiles() > 0) {

            wxString* dropped = event.GetFiles();
            wxASSERT(dropped);

            wxBusyCursor busyCursor;
            wxWindowDisabler disabler;      
            wxBusyInfo busyInfo(_("Opening files, Please wait..."));

            wxString name;
            wxArrayString files;

            for (int i = 0; i < event.GetNumberOfFiles(); i++) {
                name = dropped[i];
                if (wxFileExists(name))
                    files.push_back(name);
                else if (wxDirExists(name))
                    wxDir::GetAllFiles(name, &files);                                    
            }

            for (size_t i = 0; i < files.size(); i++) {
               m_ntbk->AddPage(CreateStyleTextCtrl(files[i]), files[i], true,vxAppImgs->FileTypeScript);
                std::cout<<files[i]<<std::endl;
            }
        }
    }

void MainFrame::OnChangeContentPane(wxCommandEvent& evt)
{
    m_mgr.GetPane(wxT("notebook_content")).Show(evt.GetId() == ID_NotebookContent);
    SetToolbarStatus();
    m_mgr.Update();
}

vxTextCtrl* MainFrame::CreateStyleTextCtrl(wxString FilePath)
{
    vxTextCtrl* text = new vxTextCtrl(this, FilePath);
    return text;
}

wxHtmlWindow* MainFrame::CreateHTMLCtrl(wxWindow* parent)
{
    if (!parent)
        parent = this;

    wxHtmlWindow* ctrl = new wxHtmlWindow(parent, wxID_ANY,
                                          wxDefaultPosition,
                                          wxSize(400,300));
    ctrl->SetPage(GetIntroText());
    return ctrl;
}

wxAuiNotebook* MainFrame::CreateNotebook()
{
    // create the notebook off-window to avoid flicker
    wxSize client_size = GetClientSize();

    m_ntbk = new wxAuiNotebook(this, wxID_ANY,
                               wxPoint(client_size.x, client_size.y),
                               wxSize(430,200),
                               m_notebook_style);
    m_ntbk->Freeze();

    m_ntbk->SetArtProvider(new vxDefaultAuiTabArt());
    
    m_ntbk->AddPage(CreateStyleTextCtrl(wxString::Format(wxT("newFile %i"),INT_NewFileList)), wxString::Format(wxT("newFile %i"),INT_NewFileList), true, vxAppImgs->FileTypeScript);
    INT_NewFileList++;

    m_ntbk->Thaw();



    return m_ntbk;
}

void MainFrame::OnNotebookPageChanged(wxAuiNotebookEvent& evt)
{
    SetToolbarStatus();
}

wxString MainFrame::GetIntroText()
{
    const char* text =
        "<html><body>"
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

void MainFrame::New(wxCommandEvent& WXUNUSED(event))
{
    m_ntbk->AddPage(CreateStyleTextCtrl(wxString::Format(wxT("newFile %i"),INT_NewFileList)), wxString::Format(wxT("newFile %i"),INT_NewFileList), true,vxAppImgs->FileTypeScript);
    INT_NewFileList++;
    SetToolbarStatus();
}

void MainFrame::Open(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog* OpenDialog = new wxFileDialog(
        this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
        fileFilter,
        wxFD_OPEN, wxDefaultPosition);

    // Creates a "open file" dialog with 4 file types
    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
        m_ntbk->AddPage(CreateStyleTextCtrl(OpenDialog->GetPath()), OpenDialog->GetFilename(), true,vxAppImgs->FileTypeScript);

    // Clean up after ourselves
    OpenDialog->Destroy();
    SetToolbarStatus();
}

void MainFrame::SaveActiveFile()
{
    if(GetActiveDocument()->IsNewFile == true)
    {       
        SaveActiveFileAs();   
    }
    else
    {
        GetActiveDocument()->Save();
        SetToolbarStatus();
    }
}

void MainFrame::SaveActiveFileAs()
{
    wxFileDialog *SaveDialog = new wxFileDialog(
		this, _("Save File As..."), wxEmptyString, wxEmptyString, fileFilter,
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
        
		// Creates a Save Dialog with 4 file types
	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
	{
	    GetActiveDocument()->FilePath = SaveDialog->GetPath();
	    GetActiveDocument()->FileName = SaveDialog->GetFilename();
	    		// set the path of our current document to the file the user chose to save under
		GetActiveDocument()->Save(); // Save the file to the selected path
	}

	// Clean up after ourselves
	SaveDialog->Destroy();
    SetToolbarStatus();
}
void MainFrame::SaveAllOpenFIles()
{
    
}

void MainFrame::Save(wxCommandEvent& WXUNUSED(event))
{
    SaveActiveFile();
}

void MainFrame::SaveAs(wxCommandEvent& WXUNUSED(event))
{
    SaveActiveFileAs();
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
        //wxUnusedVar(event);
    wxAboutDialogInfo info;
    info.SetCopyright(_("My MainFrame"));
    info.SetLicence(_("GPL v2 or later"));
    info.SetDescription(_("Short description goes here"));
    ::wxAboutBox(info);
    
    /*
    m_mgr.AddPane(CreateHTMLCtrl(), wxAuiPaneInfo().
                  Caption(wxT("About")).
                  Right().Layer(1).Position(1).
                  CloseButton(true));
    m_mgr.Update();*/
}


void MainFrame::Undo(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Undo();
    SetToolbarStatus();
}

void MainFrame::Redo(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Redo();
    SetToolbarStatus();
}

/***********************************************************/

void MainFrame::Cut(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Cut();
    SetToolbarStatus();
}

void MainFrame::Copy(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Copy();
    SetToolbarStatus();
}

void MainFrame::Paste(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->Paste();
    SetToolbarStatus();
}







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
//Returns the Active Document
//
vxTextCtrl* MainFrame::GetActiveDocument()
{
    if(m_ntbk->GetPageCount()>0)
    {
        if (m_ntbk->GetPage(m_ntbk->GetSelection())->IsKindOf(CLASSINFO(vxTextCtrl)))
        {
            return  (vxTextCtrl*)(m_ntbk->GetPage(m_ntbk->GetSelection()));
        }
        else
            wxMessageBox(wxT("Error Finding Active Document"));
    }
    return NULL;
}

void MainFrame::OnEOLToggle(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->SetViewEOL (!(GetActiveDocument()->GetViewEOL()));

}

void MainFrame::OnChangeCase (wxCommandEvent &event) {
    switch (event.GetId()) {
        case ID_CHANGELOWER: {
            GetActiveDocument()->CmdKeyExecute (wxSTC_CMD_LOWERCASE);
            break;
        }
        case ID_CHANGEUPPER: {
            GetActiveDocument()->CmdKeyExecute (wxSTC_CMD_UPPERCASE);
            break;
        }
    }
}

void MainFrame::OnConvertEOL (wxCommandEvent &event) {
    int eolMode = GetActiveDocument()->GetEOLMode();
    switch (event.GetId()) {
        case ID_CONVERTCR: { eolMode = wxSTC_EOL_CR; break;}
        case ID_CONVERTCRLF: { eolMode = wxSTC_EOL_CRLF; break;}
        case ID_CONVERTLF: { eolMode = wxSTC_EOL_LF; break;}
    }
    GetActiveDocument()->ConvertEOLs (eolMode);
    GetActiveDocument()->SetEOLMode (eolMode);
}

void MainFrame::OnFoldToggle (wxCommandEvent &WXUNUSED(event))
{
    GetActiveDocument()->ToggleFold (GetActiveDocument()->GetFoldParent(GetActiveDocument()->GetCurrentLine()));
}

//Set Toolbar Status
void MainFrame::SetToolbarStatusEvent(wxKeyEvent& event)
{
    SetToolbarStatus();
    event.Skip();
}

void MainFrame::SetToolbarStatus()
{
    //Set Status Bar
    const int width_filename = 450;
    GetStatusBar()->SetFieldsCount(3);

    //Set Active Document
    GetStatusBar()->SetStatusText( GetActiveDocument()->FilePath, 0);

    //Set Caret Position
    GetStatusBar()->SetStatusText(wxString::Format(_("Line %i, Column %i"), GetActiveDocument()->GetLineCount(),
                                                   GetActiveDocument()->GetColumn(GetActiveDocument()->GetCurrentPos())+1), 1);

    //Set Read/Write Status
    wxString IsReadOnly = _("Read");
    if(!GetActiveDocument()->GetReadOnly())
        IsReadOnly = _("Read/Write");

    GetStatusBar()->SetStatusText(IsReadOnly, 2);

    file_menu->Enable(wxID_SAVE, GetActiveDocument()->GetModify());
    tb_mainmenu->EnableTool(wxID_SAVE, GetActiveDocument()->GetModify());

    menu_edit->Enable(wxID_UNDO, GetActiveDocument()->CanUndo());
    menu_edit->Enable(wxID_REDO, GetActiveDocument()->CanRedo());
    menu_edit->Enable(wxID_PASTE, GetActiveDocument()->CanPaste());

    tb_mainmenu->EnableTool(wxID_UNDO, GetActiveDocument()->CanUndo());
    tb_mainmenu->EnableTool(wxID_REDO, GetActiveDocument()->CanRedo());
    tb_mainmenu->EnableTool(wxID_PASTE, GetActiveDocument()->CanPaste());
    m_mgr.Update();

    if(m_ntbk->GetPageCount()>0)
    {
        wxString title = GetActiveDocument()->FileName;

        if(GetActiveDocument()->GetModify())
            title = _("*")+title;

        m_ntbk->SetPageText(m_ntbk->GetSelection(), title);
    }
    
        SetTitle(_("vx.io - ")+VXIO_VERSION+_(" - [") + GetActiveDocument()->FileName+_("]"));
}

void MainFrame::OnCreateTree(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateTreeCtrl(), wxAuiPaneInfo().
                  Caption(wxT("Tree Control")).
                  Float().FloatingPosition(GetStartPosition()).
                  FloatingSize(wxSize(150,300)));
    m_mgr.Update();
}

void MainFrame::OnCreateGrid(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateGrid(), wxAuiPaneInfo().
                  Caption(wxT("Grid")).
                  Float().FloatingPosition(GetStartPosition()).
                  FloatingSize(wxSize(300,200)));
    m_mgr.Update();
}

void MainFrame::OnCreateHTML(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateHTMLCtrl(), wxAuiPaneInfo().
                  Caption(wxT("HTML Control")).
                  Float().FloatingPosition(GetStartPosition()).
                  FloatingSize(wxSize(300,200)));
    m_mgr.Update();
}

void MainFrame::OnCreateNotebook(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateNotebook(), wxAuiPaneInfo().
                  Caption(wxT("Notebook")).
                  Float().FloatingPosition(GetStartPosition()).
                  //FloatingSize(300,200).
                  CloseButton(true).MaximizeButton(true));
    m_mgr.Update();
}

void MainFrame::OnCreateStyleTextCtrl(wxCommandEvent& WXUNUSED(event))
{
    m_ntbk->AddPage(CreateStyleTextCtrl(wxString::Format(wxT("newFile %i"),INT_NewFileList)), wxString::Format(wxT("newFile %i"),INT_NewFileList), true);
    INT_NewFileList++;
    SetToolbarStatus();
}



wxAuiDockArt* MainFrame::GetDockArt()
{
    return m_mgr.GetArtProvider();
}

void MainFrame::DoUpdate()
{
    m_mgr.Update();
}

void MainFrame::OnEraseBackground(wxEraseEvent& event)
{
    event.Skip();
}

void MainFrame::OnSize(wxSizeEvent& event)
{
    event.Skip();
}

void MainFrame::OnSettings(wxCommandEvent& WXUNUSED(evt))
{
    // show the settings pane, and float it
    wxAuiPaneInfo& floating_pane = m_mgr.GetPane(wxT("settings")).Float().Show();

    if (floating_pane.floating_pos == wxDefaultPosition)
        floating_pane.FloatingPosition(GetStartPosition());

    m_mgr.Update();
}

void MainFrame::OnCustomizeToolbar(wxCommandEvent& WXUNUSED(evt))
{
    wxMessageBox(_("Customize Toolbar clicked"));
}

void MainFrame::OnGradient(wxCommandEvent& event)
{
    int gradient = 0;

    switch (event.GetId())
    {
    case ID_NoGradient:
        gradient = wxAUI_GRADIENT_NONE;
        break;
    case ID_VerticalGradient:
        gradient = wxAUI_GRADIENT_VERTICAL;
        break;
    case ID_HorizontalGradient:
        gradient = wxAUI_GRADIENT_HORIZONTAL;
        break;
    }

    m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, gradient);
    m_mgr.Update();
}

void MainFrame::OnToolbarResizing(wxCommandEvent& WXUNUSED(evt))
{
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    const size_t count = all_panes.GetCount();
    for (size_t i = 0; i < count; ++i)
    {
        wxAuiToolBar* toolbar = wxDynamicCast(all_panes[i].window, wxAuiToolBar);
        if (toolbar)
        {
            all_panes[i].Resizable(!all_panes[i].IsResizable());
        }
    }

    m_mgr.Update();
}

void MainFrame::OnManagerFlag(wxCommandEvent& event)
{
    unsigned int flag = 0;

#if !defined(__WXMSW__) && !defined(__WXMAC__) && !defined(__WXGTK__)
    if (event.GetId() == ID_TransparentDrag ||
            event.GetId() == ID_TransparentHint ||
            event.GetId() == ID_HintFade)
    {
        wxMessageBox(wxT("This option is presently only available on wxGTK, wxMSW and wxMac"));
        return;
    }
#endif

    int id = event.GetId();

    if (id == ID_TransparentHint ||
            id == ID_VenetianBlindsHint ||
            id == ID_RectangleHint ||
            id == ID_NoHint)
    {
        unsigned int flags = m_mgr.GetFlags();
        flags &= ~wxAUI_MGR_TRANSPARENT_HINT;
        flags &= ~wxAUI_MGR_VENETIAN_BLINDS_HINT;
        flags &= ~wxAUI_MGR_RECTANGLE_HINT;
        m_mgr.SetFlags(flags);
    }

    switch (id)
    {
    case ID_AllowFloating:
        flag = wxAUI_MGR_ALLOW_FLOATING;
        break;
    case ID_TransparentDrag:
        flag = wxAUI_MGR_TRANSPARENT_DRAG;
        break;
    case ID_HintFade:
        flag = wxAUI_MGR_HINT_FADE;
        break;
    case ID_NoVenetianFade:
        flag = wxAUI_MGR_NO_VENETIAN_BLINDS_FADE;
        break;
    case ID_AllowActivePane:
        flag = wxAUI_MGR_ALLOW_ACTIVE_PANE;
        break;
    case ID_TransparentHint:
        flag = wxAUI_MGR_TRANSPARENT_HINT;
        break;
    case ID_VenetianBlindsHint:
        flag = wxAUI_MGR_VENETIAN_BLINDS_HINT;
        break;
    case ID_RectangleHint:
        flag = wxAUI_MGR_RECTANGLE_HINT;
        break;
    case ID_LiveUpdate:
        flag = wxAUI_MGR_LIVE_RESIZE;
        break;
    }

    if (flag)
    {
        m_mgr.SetFlags(m_mgr.GetFlags() ^ flag);
    }

    m_mgr.Update();
}


void MainFrame::OnNotebookFlag(wxCommandEvent& event)
{
    int id = event.GetId();

    if (id == ID_NotebookNoCloseButton ||
            id == ID_NotebookCloseButton ||
            id == ID_NotebookCloseButtonAll ||
            id == ID_NotebookCloseButtonActive)
    {
        m_notebook_style &= ~(wxAUI_NB_CLOSE_BUTTON |
                              wxAUI_NB_CLOSE_ON_ACTIVE_TAB |
                              wxAUI_NB_CLOSE_ON_ALL_TABS);

        switch (id)
        {
        case ID_NotebookNoCloseButton:
            break;
        case ID_NotebookCloseButton:
            m_notebook_style |= wxAUI_NB_CLOSE_BUTTON;
            break;
        case ID_NotebookCloseButtonAll:
            m_notebook_style |= wxAUI_NB_CLOSE_ON_ALL_TABS;
            break;
        case ID_NotebookCloseButtonActive:
            m_notebook_style |= wxAUI_NB_CLOSE_ON_ACTIVE_TAB;
            break;
        }
    }

    if (id == ID_NotebookAllowTabMove)
    {
        m_notebook_style ^= wxAUI_NB_TAB_MOVE;
    }
    if (id == ID_NotebookAllowTabExternalMove)
    {
        m_notebook_style ^= wxAUI_NB_TAB_EXTERNAL_MOVE;
    }
    else if (id == ID_NotebookAllowTabSplit)
    {
        m_notebook_style ^= wxAUI_NB_TAB_SPLIT;
    }
    else if (id == ID_NotebookWindowList)
    {
        m_notebook_style ^= wxAUI_NB_WINDOWLIST_BUTTON;
    }
    else if (id == ID_NotebookScrollButtons)
    {
        m_notebook_style ^= wxAUI_NB_SCROLL_BUTTONS;
    }
    else if (id == ID_NotebookTabFixedWidth)
    {
        m_notebook_style ^= wxAUI_NB_TAB_FIXED_WIDTH;
    }


    size_t i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i)
    {
        wxAuiPaneInfo& pane = all_panes.Item(i);
        if (pane.window->IsKindOf(CLASSINFO(wxAuiNotebook)))
        {
            wxAuiNotebook* nb = (wxAuiNotebook*)pane.window;

            if (id == ID_NotebookArtGloss)
            {
                nb->SetArtProvider(new wxAuiDefaultTabArt);
                m_notebook_theme = 0;
            }
            else if (id == ID_NotebookArtSimple)
            {
                nb->SetArtProvider(new wxAuiSimpleTabArt);
                m_notebook_theme = 1;
            }


            nb->SetWindowStyleFlag(m_notebook_style);
            nb->Refresh();
        }
    }


}



void MainFrame::OnLexarUpdate(wxCommandEvent& event)
{
    unsigned int flags = m_mgr.GetFlags();

    switch (event.GetId())
    {
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

void MainFrame::OnUpdateUI(wxUpdateUIEvent& event)
{
    unsigned int flags = m_mgr.GetFlags();

    switch (event.GetId())
    {
    case ID_NoGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_NONE);
        break;
    case ID_VerticalGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_VERTICAL);
        break;
    case ID_HorizontalGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_HORIZONTAL);
        break;
    case ID_AllowToolbarResizing:
    {
        wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
        const size_t count = all_panes.GetCount();
        for (size_t i = 0; i < count; ++i)
        {
            wxAuiToolBar* toolbar = wxDynamicCast(all_panes[i].window, wxAuiToolBar);
            if (toolbar)
            {
                event.Check(all_panes[i].IsResizable());
                break;
            }
        }
        break;
    }
    case ID_AllowFloating:
        event.Check((flags & wxAUI_MGR_ALLOW_FLOATING) != 0);
        break;
    case ID_TransparentDrag:
        event.Check((flags & wxAUI_MGR_TRANSPARENT_DRAG) != 0);
        break;
    case ID_TransparentHint:
        event.Check((flags & wxAUI_MGR_TRANSPARENT_HINT) != 0);
        break;
    case ID_LiveUpdate:
        event.Check((flags & wxAUI_MGR_LIVE_RESIZE) != 0);
        break;
    case ID_VenetianBlindsHint:
        event.Check((flags & wxAUI_MGR_VENETIAN_BLINDS_HINT) != 0);
        break;
    case ID_RectangleHint:
        event.Check((flags & wxAUI_MGR_RECTANGLE_HINT) != 0);
        break;
    case ID_NoHint:
        event.Check(((wxAUI_MGR_TRANSPARENT_HINT |
                      wxAUI_MGR_VENETIAN_BLINDS_HINT |
                      wxAUI_MGR_RECTANGLE_HINT) & flags) == 0);
        break;
    case ID_HintFade:
        event.Check((flags & wxAUI_MGR_HINT_FADE) != 0);
        break;
    case ID_NoVenetianFade:
        event.Check((flags & wxAUI_MGR_NO_VENETIAN_BLINDS_FADE) != 0);
        break;

    case ID_NotebookNoCloseButton:
        event.Check((m_notebook_style & (wxAUI_NB_CLOSE_BUTTON|wxAUI_NB_CLOSE_ON_ALL_TABS|wxAUI_NB_CLOSE_ON_ACTIVE_TAB)) != 0);
        break;
    case ID_NotebookCloseButton:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_BUTTON) != 0);
        break;
    case ID_NotebookCloseButtonAll:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ALL_TABS) != 0);
        break;
    case ID_NotebookCloseButtonActive:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ACTIVE_TAB) != 0);
        break;
    case ID_NotebookAllowTabSplit:
        event.Check((m_notebook_style & wxAUI_NB_TAB_SPLIT) != 0);
        break;
    case ID_NotebookAllowTabMove:
        event.Check((m_notebook_style & wxAUI_NB_TAB_MOVE) != 0);
        break;
    case ID_NotebookAllowTabExternalMove:
        event.Check((m_notebook_style & wxAUI_NB_TAB_EXTERNAL_MOVE) != 0);
        break;
    case ID_NotebookScrollButtons:
        event.Check((m_notebook_style & wxAUI_NB_SCROLL_BUTTONS) != 0);
        break;
    case ID_NotebookWindowList:
        event.Check((m_notebook_style & wxAUI_NB_WINDOWLIST_BUTTON) != 0);
        break;
    case ID_NotebookTabFixedWidth:
        event.Check((m_notebook_style & wxAUI_NB_TAB_FIXED_WIDTH) != 0);
        break;
    case ID_NotebookArtGloss:
        event.Check(m_notebook_style == 0);
        break;
    case ID_NotebookArtSimple:
        event.Check(m_notebook_style == 1);
        break;

    }
}

void MainFrame::OnPaneClose(wxAuiManagerEvent& evt)
{/*
    if (evt.pane->name == wxT("test10"))
    {
        */
        int res = wxMessageBox(wxT("Are you sure you want to close/hide this pane?"),
                               wxT("wxAUI"),
                               wxYES_NO,
                               this);
        if (res != wxYES)
            evt.Veto();
    //}
}

void MainFrame::OnCreatePerspective(wxCommandEvent& WXUNUSED(event))
{
    wxTextEntryDialog dlg(this, wxT("Enter a name for the new layout:"),
                          wxT("Save Layout"));

    dlg.SetValue(wxString::Format(wxT("layout. %u"), unsigned(m_perspectives.GetCount() + 1)));
    if (dlg.ShowModal() != wxID_OK)
        return;

    if (m_perspectives.GetCount() == 0)
    {
        m_perspectives_menu->AppendSeparator();
    }

    m_perspectives_menu->Append(ID_FirstPerspective + m_perspectives.GetCount(), dlg.GetValue());
    m_perspectives.Add(m_mgr.SavePerspective());
}

void MainFrame::OnCopyPerspectiveCode(wxCommandEvent& WXUNUSED(evt))
{
    wxString s = m_mgr.SavePerspective();

#if wxUSE_CLIPBOARD
    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData(new wxTextDataObject(s));
        wxTheClipboard->Close();
    }
#endif
}

void MainFrame::OnRestorePerspective(wxCommandEvent& evt)
{
    m_mgr.LoadPerspective(m_perspectives.Item(evt.GetId() - ID_FirstPerspective));
}

void MainFrame::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{
    wxAuiNotebook* ctrl = (wxAuiNotebook*)evt.GetEventObject();
    //if (ctrl->GetPage(evt.GetSelection())->IsKindOf(CLASSINFO(wxHtmlWindow)))
    if(GetActiveDocument()->GetModify())
    {
        int res = wxMessageBox(wxT("Do you want to save before closing this file?"),
                               wxT("Save before closing?"),
                               wxYES_NO|wxCANCEL|wxICON_QUESTION,
                               this);
                               
        //If Yes is clicked, then Save the File before closing.
        if (res == wxYES)
        {
            SaveActiveFile();
        }
        //wxNO Means Nothing should Happen
        
        //If Canceled is clicked, then abort closing the file
        else if (res == wxCANCEL)
            evt.Veto();            
    }
}

void MainFrame::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{
    wxAuiNotebook* ctrl = (wxAuiNotebook*)evt.GetEventObject();

    // selection should always be a valid index
    wxASSERT_MSG( ctrl->GetSelection() < (int)ctrl->GetPageCount(),
                  wxString::Format("Invalid selection %d, only %d pages left",
                                   ctrl->GetSelection(),
                                   (int)ctrl->GetPageCount()) );

    evt.Skip();
}

void MainFrame::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
    // for the purpose of this test application, explicitly
    // allow all noteboko drag and drop events
    evt.Allow();
}

wxPoint MainFrame::GetStartPosition()
{
    static int x = 0;
    x += 20;
    wxPoint pt = ClientToScreen(wxPoint(0,0));
    return wxPoint(pt.x + x, pt.y + x);
}

void MainFrame::OnDropDownToolbarItem(wxAuiToolBarEvent& evt)
{
    if (evt.IsDropDownClicked())
    {
        wxAuiToolBar* tb = static_cast<wxAuiToolBar*>(evt.GetEventObject());

        tb->SetToolSticky(evt.GetId(), true);

        // create the popup menu
        wxMenu menuPopup;

        wxBitmap bmp = wxArtProvider::GetBitmap(wxART_QUESTION, wxART_OTHER, wxSize(16,16));

        wxMenuItem* m1 =  new wxMenuItem(&menuPopup, 10001, _("Drop Down Item 1"));
        m1->SetBitmap(bmp);
        menuPopup.Append(m1);

        wxMenuItem* m2 =  new wxMenuItem(&menuPopup, 10002, _("Drop Down Item 2"));
        m2->SetBitmap(bmp);
        menuPopup.Append(m2);

        wxMenuItem* m3 =  new wxMenuItem(&menuPopup, 10003, _("Drop Down Item 3"));
        m3->SetBitmap(bmp);
        menuPopup.Append(m3);

        wxMenuItem* m4 =  new wxMenuItem(&menuPopup, 10004, _("Drop Down Item 4"));
        m4->SetBitmap(bmp);
        menuPopup.Append(m4);

        // line up our menu with the button
        wxRect rect = tb->GetToolRect(evt.GetId());
        wxPoint pt = tb->ClientToScreen(rect.GetBottomLeft());
        pt = ScreenToClient(pt);


        PopupMenu(&menuPopup, pt);


        // make sure the button is "un-stuck"
        tb->SetToolSticky(evt.GetId(), false);
    }
}


void MainFrame::OnTabAlignment(wxCommandEvent &evt)
{
    size_t i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i)
    {
        wxAuiPaneInfo& pane = all_panes.Item(i);
        if (pane.window->IsKindOf(CLASSINFO(wxAuiNotebook)))
        {
            wxAuiNotebook* nb = (wxAuiNotebook*)pane.window;

            long style = nb->GetWindowStyleFlag();
            style &= ~(wxAUI_NB_TOP | wxAUI_NB_BOTTOM);
            if (evt.GetId() == ID_NotebookAlignTop)
                style |= wxAUI_NB_TOP;
            else if (evt.GetId() == ID_NotebookAlignBottom)
                style |= wxAUI_NB_BOTTOM;
            nb->SetWindowStyleFlag(style);

            nb->Refresh();
        }
    }
}

void MainFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

wxGrid* MainFrame::CreateGrid()
{
    wxGrid* grid = new wxGrid(this, wxID_ANY,
                              wxPoint(0,0),
                              wxSize(150,250),
                              wxNO_BORDER | wxWANTS_CHARS);
    grid->CreateGrid(50, 20);
    return grid;
}

wxTreeCtrl* MainFrame::CreateTreeCtrl()
{
    wxTreeCtrl* tree = new wxTreeCtrl(this, wxID_ANY,
                                      wxPoint(0,0), wxSize(160,250),
                                      wxTR_DEFAULT_STYLE | wxNO_BORDER);

    wxImageList* imglist = new wxImageList(16, 16, true, 2);
    imglist->Add(wxArtProvider::GetBitmap(wxART_FOLDER, wxART_OTHER, wxSize(16,16)));
    imglist->Add(wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16)));
    tree->AssignImageList(imglist);

    wxTreeItemId root = tree->AddRoot(wxT("wxAUI Project"), 0);
    wxArrayTreeItemIds items;



    items.Add(tree->AppendItem(root, wxT("Item 1"), 0));
    items.Add(tree->AppendItem(root, wxT("Item 2"), 0));
    items.Add(tree->AppendItem(root, wxT("Item 3"), 0));
    items.Add(tree->AppendItem(root, wxT("Item 4"), 0));
    items.Add(tree->AppendItem(root, wxT("Item 5"), 0));


    int i, count;
    for (i = 0, count = items.Count(); i < count; ++i)
    {
        wxTreeItemId id = items.Item(i);
        tree->AppendItem(id, wxT("Subitem 1"), 1);
        tree->AppendItem(id, wxT("Subitem 2"), 1);
        tree->AppendItem(id, wxT("Subitem 3"), 1);
        tree->AppendItem(id, wxT("Subitem 4"), 1);
        tree->AppendItem(id, wxT("Subitem 5"), 1);
    }


    tree->Expand(root);

    return tree;
}
