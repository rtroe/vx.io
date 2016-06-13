#ifndef MAINFRAME_H
#define MAINFRAME_H
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "wx/app.h"
#include "wx/grid.h"
#include "wx/treectrl.h"
#include "wx/spinctrl.h"
#include "wx/artprov.h"
#include "wx/clipbrd.h"
#include "wx/image.h"
#include "wx/colordlg.h"
#include "wx/wxhtml.h"
#include "wx/imaglist.h"
#include "wx/dataobj.h"
#include "wx/dcclient.h"
#include "wx/bmpbuttn.h"
#include "wx/menu.h"
#include "wx/toolbar.h"
#include "wx/statusbr.h"
#include "wx/msgdlg.h"
#include "wx/textdlg.h"
#include <wx/filedlg.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/arrstr.h>
#include <wx/dir.h>
#include <wx/busyinfo.h>
#include <wx/aboutdlg.h>

#include "wx/aui/aui.h"
//#include "../sample.xpm"

#include "controls/vxTextCtrl.h"
#include "include/gui/Icon.h"


// -- menu methods --
//#include "menus/menu_file.h"
//#include "menus/menu_edit.h"

// -- controls --
//#include "controls/notebook.h"


// -- frame --

class MainFrame : public wxFrame
{
    enum
    {
        // -- file --
        ID_New,
        ID_Open,
        ID_Save,
        ID_SaveAs,
        ID_SaveAll,
        ID_Close_File,
        ID_Close_All,
        ID_Close_Program,
        ID_DocumentProperties,


        // -- edit --
        ID_Cut,
        ID_Copy,
        ID_Paste,
        ID_Undo,
        ID_Redo,

        // -- lexars --
        ID_C,
        ID_CPP,
        ID_CS,
        ID_CSS,
        ID_HLSL,
        ID_HTML,
        ID_JS,
        ID_PY,
        ID_PHP,
        ID_TXT,

        // -- View --
        ID_DISPLAYEOL,
        myID_CONVERTCR,
        myID_CONVERTCRLF,
        myID_CONVERTLF,
        myID_CHANGELOWER,
        myID_CHANGEUPPER,
        myID_FOLDTOGGLE,

        ID_CreateTree = wxID_HIGHEST+1,
        ID_CreateGrid,
        ID_CreateText,
        ID_CreateHTML,
        ID_CreateNotebook,
        ID_CreateSizeReport,
        ID_CreateStyleText,
        ID_GridContent,
        ID_TextContent,
        ID_TreeContent,
        ID_HTMLContent,
        ID_NotebookContent,
        ID_SizeReportContent,
        ID_CreatePerspective,
        ID_CopyPerspectiveCode,
        ID_AllowFloating,
        ID_AllowActivePane,
        ID_TransparentHint,
        ID_VenetianBlindsHint,
        ID_RectangleHint,
        ID_NoHint,
        ID_HintFade,
        ID_NoVenetianFade,
        ID_TransparentDrag,
        ID_NoGradient,
        ID_VerticalGradient,
        ID_HorizontalGradient,
        ID_LiveUpdate,
        ID_AllowToolbarResizing,
        ID_Settings,
        ID_CustomizeToolbar,
        ID_DropDownToolbarItem,
        ID_NotebookNoCloseButton,
        ID_NotebookCloseButton,
        ID_NotebookCloseButtonAll,
        ID_NotebookCloseButtonActive,
        ID_NotebookAllowTabMove,
        ID_NotebookAllowTabExternalMove,
        ID_NotebookAllowTabSplit,
        ID_NotebookWindowList,
        ID_NotebookScrollButtons,
        ID_NotebookTabFixedWidth,
        ID_NotebookArtGloss,
        ID_NotebookArtSimple,
        ID_NotebookAlignTop,
        ID_NotebookAlignBottom,

        ID_SampleItem,

        ID_FirstPerspective = ID_CreatePerspective+1000
    };

public:
    MainFrame(wxWindow* parent,
            wxWindowID id,
            const wxString& title,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);

    ~MainFrame();

    wxAuiDockArt* GetDockArt();
    void DoUpdate();
    vxIcons* vxAppImgs;
    
    wxString VXIO_VERSION;
    void OnDropFiles(wxDropFilesEvent& event);
    //global variables
    int INT_NewFileList;
    
private:
    vxTextCtrl* CreateTextCtrl(const wxString& text = wxEmptyString);
    wxGrid* CreateGrid();
    wxTreeCtrl* CreateTreeCtrl();
    vxTextCtrl* CreateStyleTextCtrl(wxString FileName);
    wxPoint GetStartPosition();
    wxHtmlWindow* CreateHTMLCtrl(wxWindow* parent = NULL);
    wxAuiNotebook* CreateNotebook();

    wxString GetIntroText();

private:

    void SaveActiveFile();
    void SaveActiveFileAs();
    void SaveAllOpenFIles();

    //MENU EVENTS

    // -- file --
    void New(wxCommandEvent& evt);
    void Open(wxCommandEvent& evt);
    void Save(wxCommandEvent& evt);
    void SaveAs(wxCommandEvent& evt);
    void SaveAll(wxCommandEvent& evt);
    void CloseFile(wxCommandEvent& evt);
    void CloseAllFiles(wxCommandEvent& evt);
    void OnExit(wxCommandEvent& evt);

    // -- edit --
    void Undo(wxCommandEvent& evt);
    void Redo(wxCommandEvent& evt);
    void Cut(wxCommandEvent& evt);
    void Copy(wxCommandEvent& evt);
    void Paste(wxCommandEvent& evt);

    //Loads all Images for Toolbars and Window's
    void LoadAllImages();

    //Sets the Toolbar Status based off the current text control
    void SetToolbarStatus();
    void SetToolbarStatusEvent(wxKeyEvent& event);
    void OnEraseBackground(wxEraseEvent& evt);
    void OnSize(wxSizeEvent& evt);

    // -- view --
    void OnLexarUpdate(wxCommandEvent& evt);
    void OnEOLToggle(wxCommandEvent& evt);
    void OnChangeCase (wxCommandEvent &event);
    void OnConvertEOL (wxCommandEvent &event);
    void OnFoldToggle(wxCommandEvent &event);

    void OnCreateTree(wxCommandEvent& evt);
    void OnCreateGrid(wxCommandEvent& evt);
    void OnCreateHTML(wxCommandEvent& evt);
    void OnCreateNotebook(wxCommandEvent& evt);
    void OnCreateText(wxCommandEvent& evt);
    void OnCreateStyleTextCtrl(wxCommandEvent& evt);
    void OnCreateSizeReport(wxCommandEvent& evt);
    void OnChangeContentPane(wxCommandEvent& evt);
    void OnDropDownToolbarItem(wxAuiToolBarEvent& evt);
    void OnCreatePerspective(wxCommandEvent& evt);
    void OnCopyPerspectiveCode(wxCommandEvent& evt);
    void OnRestorePerspective(wxCommandEvent& evt);
    void OnSettings(wxCommandEvent& evt);
    void OnCustomizeToolbar(wxCommandEvent& evt);
    void OnAllowNotebookDnD(wxAuiNotebookEvent& evt);
    void OnNotebookPageClose(wxAuiNotebookEvent& evt);
    void OnNotebookPageClosed(wxAuiNotebookEvent& evt);
    void OnNotebookPageChanged(wxAuiNotebookEvent& evt);
    void OnAbout(wxCommandEvent& evt);
    void OnTabAlignment(wxCommandEvent &evt);

    void OnGradient(wxCommandEvent& evt);
    void OnToolbarResizing(wxCommandEvent& evt);
    void OnManagerFlag(wxCommandEvent& evt);
    void OnNotebookFlag(wxCommandEvent& evt);
    void OnUpdateUI(wxUpdateUIEvent& evt);

    void OnPaneClose(wxAuiManagerEvent& evt);

    //lexars
    /*
    void SetLexarAsC(wxStyledTextCtrl* text);
    void SetLexarAsCPP(wxStyledTextCtrl* text);
    void SetLexarAsCS(wxStyledTextCtrl* text);
    void SetLexarAsHLSL(wxStyledTextCtrl* text);
    void SetLexarAsHTML(wxStyledTextCtrl* text);
    void SetLexarAsNASTRAN(wxStyledTextCtrl* text);
    void SetLexarAsPython(wxStyledTextCtrl* text);
*/

    //get pane
    vxTextCtrl* GetActiveDocument();

private:

    wxAuiManager m_mgr;
    wxAuiNotebook* m_ntbk;
    wxArrayString m_perspectives;
    wxMenu* m_perspectives_menu;
    long m_notebook_style;
    long m_notebook_theme;
    
    wxString fileFilter;
    
    // -- toolbars --
    wxAuiToolBar* tb_mainmenu;

    //Menus
    wxMenu* file_menu;
    wxMenu* menu_edit;

    DECLARE_EVENT_TABLE()
};

#endif // MAINFRAME_H
