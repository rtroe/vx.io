//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef VX_IO_VXIO_WXCRAFTER_BASE_CLASSES_H
#define VX_IO_VXIO_WXCRAFTER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/statbox.h>
#include <wx/statbmp.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/treebook.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/clrpicker.h>
#include <wx/listctrl.h>
#include <wx/tglbtn.h>
#include <wx/combobox.h>
#include <wx/bmpbuttn.h>
#include <wx/collpane.h>
#include <wx/checklst.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class ImageFrameBaseClass : public wxFrame
{
protected:
    wxNotebook* m_notebook81;
    wxPanel* m_panel83;
    wxStaticBitmap* m_staticBitmap51;
    wxStaticBitmap* m_staticBitmap53;
    wxStaticBitmap* m_staticBitmap55;
    wxStaticBitmap* m_staticBitmap57;
    wxStaticBitmap* m_staticBitmap59;
    wxStaticBitmap* m_staticBitmap61;
    wxStaticBitmap* m_staticBitmap63;
    wxStaticBitmap* m_staticBitmap65;
    wxStaticBitmap* m_staticBitmap67;
    wxStaticBitmap* m_staticBitmap69;
    wxStaticBitmap* m_staticBitmap71;
    wxStaticBitmap* m_staticBitmap13;
    wxStaticBitmap* m_staticBitmap15;
    wxStaticBitmap* m_staticBitmap17;
    wxStaticBitmap* m_staticBitmap19;
    wxStaticBitmap* m_staticBitmap21;
    wxStaticBitmap* m_staticBitmap23;
    wxStaticBitmap* m_staticBitmap25;
    wxStaticBitmap* m_staticBitmap27;
    wxStaticBitmap* m_staticBitmap29;
    wxStaticBitmap* m_staticBitmap31;
    wxStaticBitmap* m_staticBitmap37;
    wxStaticBitmap* m_staticBitmap39;
    wxStaticBitmap* m_staticBitmap41;
    wxStaticBitmap* m_staticBitmap43;
    wxStaticBitmap* m_staticBitmap45;
    wxStaticBitmap* m_staticBitmap47;
    wxStaticBitmap* m_staticBitmap101;
    wxPanel* m_panel85;
    wxStaticBitmap* m_staticBitmap75;
    wxStaticBitmap* m_staticBitmap77;
    wxStaticBitmap* m_staticBitmap79;
    wxStaticBitmap* m_staticBitmap95;
    wxStaticBitmap* m_staticBitmap97;
    wxStaticBitmap* m_staticBitmap99;
    wxMenuBar* m_menuBar;
    wxMenu* m_name6;
    wxMenuItem* m_menuItem7;
    wxMenu* m_name8;
    wxMenuItem* m_menuItem9;
    wxToolBar* m_mainToolbar;

protected:
    virtual void OnExit(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAbout(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticBitmap* GetStaticBitmap51() { return m_staticBitmap51; }
    wxStaticBitmap* GetStaticBitmap53() { return m_staticBitmap53; }
    wxStaticBitmap* GetStaticBitmap55() { return m_staticBitmap55; }
    wxStaticBitmap* GetStaticBitmap57() { return m_staticBitmap57; }
    wxStaticBitmap* GetStaticBitmap59() { return m_staticBitmap59; }
    wxStaticBitmap* GetStaticBitmap61() { return m_staticBitmap61; }
    wxStaticBitmap* GetStaticBitmap63() { return m_staticBitmap63; }
    wxStaticBitmap* GetStaticBitmap65() { return m_staticBitmap65; }
    wxStaticBitmap* GetStaticBitmap67() { return m_staticBitmap67; }
    wxStaticBitmap* GetStaticBitmap69() { return m_staticBitmap69; }
    wxStaticBitmap* GetStaticBitmap71() { return m_staticBitmap71; }
    wxStaticBitmap* GetStaticBitmap13() { return m_staticBitmap13; }
    wxStaticBitmap* GetStaticBitmap15() { return m_staticBitmap15; }
    wxStaticBitmap* GetStaticBitmap17() { return m_staticBitmap17; }
    wxStaticBitmap* GetStaticBitmap19() { return m_staticBitmap19; }
    wxStaticBitmap* GetStaticBitmap21() { return m_staticBitmap21; }
    wxStaticBitmap* GetStaticBitmap23() { return m_staticBitmap23; }
    wxStaticBitmap* GetStaticBitmap25() { return m_staticBitmap25; }
    wxStaticBitmap* GetStaticBitmap27() { return m_staticBitmap27; }
    wxStaticBitmap* GetStaticBitmap29() { return m_staticBitmap29; }
    wxStaticBitmap* GetStaticBitmap31() { return m_staticBitmap31; }
    wxStaticBitmap* GetStaticBitmap37() { return m_staticBitmap37; }
    wxStaticBitmap* GetStaticBitmap39() { return m_staticBitmap39; }
    wxStaticBitmap* GetStaticBitmap41() { return m_staticBitmap41; }
    wxStaticBitmap* GetStaticBitmap43() { return m_staticBitmap43; }
    wxStaticBitmap* GetStaticBitmap45() { return m_staticBitmap45; }
    wxStaticBitmap* GetStaticBitmap47() { return m_staticBitmap47; }
    wxStaticBitmap* GetStaticBitmap101() { return m_staticBitmap101; }
    wxPanel* GetPanel83() { return m_panel83; }
    wxStaticBitmap* GetStaticBitmap75() { return m_staticBitmap75; }
    wxStaticBitmap* GetStaticBitmap77() { return m_staticBitmap77; }
    wxStaticBitmap* GetStaticBitmap79() { return m_staticBitmap79; }
    wxStaticBitmap* GetStaticBitmap95() { return m_staticBitmap95; }
    wxStaticBitmap* GetStaticBitmap97() { return m_staticBitmap97; }
    wxStaticBitmap* GetStaticBitmap99() { return m_staticBitmap99; }
    wxPanel* GetPanel85() { return m_panel85; }
    wxNotebook* GetNotebook81() { return m_notebook81; }
    wxMenuBar* GetMenuBar() { return m_menuBar; }
    wxToolBar* GetMainToolbar() { return m_mainToolbar; }
    ImageFrameBaseClass(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("My Frame"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,400), long style = wxCAPTION|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxCLOSE_BOX);
    virtual ~ImageFrameBaseClass();
};


class MainFrameBase : public wxFrame
{
protected:

protected:

public:
    MainFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxDEFAULT_FRAME_STYLE);
    virtual ~MainFrameBase();
};


class SettingsDialogBase : public wxFrame
{
public:
    enum {
        ID_CHOICE_FONT = 1001,
        ID_CNTRL_COLOURLIST = 1002,
        ID_CNTRL_THEMENAME = 1003,
    };
protected:
    wxTreebook* m_treebook249;
    wxPanel* m_panel115;
    wxStaticBitmap* m_staticBitmap269;
    wxStaticText* m_staticText285;
    wxStaticText* m_staticText273;
    wxStaticText* m_staticText279;
    wxButton* m_button298;
    wxCheckBox* m_checkBox296;
    wxStaticBitmap* m_staticBitmap309;
    wxStaticText* m_staticText311;
    wxButton* m_button319;
    wxPanel* m_panel255;
    wxStaticText* m_staticText138;
    wxChoice* cmbbx_fonts;
    wxStaticText* m_staticText154;
    wxChoice* cmbbx_font_size;
    wxPanel* m_panel257;
    wxPanel* m_panel160;
    wxStaticText* m_staticText166;
    wxChoice* cmbbx_theme;
    wxStaticLine* m_staticLine353;
    wxStaticLine* m_staticLine351;
    wxStaticText* m_staticText347;
    wxTextCtrl* m_textCtrl_themeName;
    wxStaticText* m_staticText328;
    wxColourPickerCtrl* m_colourPicker330;
    wxListCtrl* m_colourListCtrl;
    wxPanel* m_panel117;
    wxPanel* m_panel259;
    wxPanel* m_panel261;
    wxPanel* m_panel265;
    wxButton* btn_OK;
    wxButton* btn_apply;
    wxButton* btn_cancel;

protected:
    virtual void OnCmbbx_fontsChoiceSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCmbbx_font_sizeChoiceSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCmbbx_themeChoiceSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnColourpicker330ColourpickerChanged(wxColourPickerEvent& event) { event.Skip(); }
    virtual void OnColourlistctrlListItemSelected(wxListEvent& event) { event.Skip(); }
    virtual void OnBtn_okButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBtn_applyButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBtn_cancelButtonClicked(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticBitmap* GetStaticBitmap269() { return m_staticBitmap269; }
    wxStaticText* GetStaticText285() { return m_staticText285; }
    wxStaticText* GetStaticText273() { return m_staticText273; }
    wxStaticText* GetStaticText279() { return m_staticText279; }
    wxButton* GetButton298() { return m_button298; }
    wxCheckBox* GetCheckBox296() { return m_checkBox296; }
    wxStaticBitmap* GetStaticBitmap309() { return m_staticBitmap309; }
    wxStaticText* GetStaticText311() { return m_staticText311; }
    wxButton* GetButton319() { return m_button319; }
    wxPanel* GetPanel115() { return m_panel115; }
    wxStaticText* GetStaticText138() { return m_staticText138; }
    wxChoice* GetCmbbx_fonts() { return cmbbx_fonts; }
    wxStaticText* GetStaticText154() { return m_staticText154; }
    wxChoice* GetCmbbx_font_size() { return cmbbx_font_size; }
    wxPanel* GetPanel160() { return m_panel160; }
    wxStaticText* GetStaticText166() { return m_staticText166; }
    wxChoice* GetCmbbx_theme() { return cmbbx_theme; }
    wxStaticLine* GetStaticLine353() { return m_staticLine353; }
    wxStaticLine* GetStaticLine351() { return m_staticLine351; }
    wxStaticText* GetStaticText347() { return m_staticText347; }
    wxTextCtrl* GetTextCtrl_themeName() { return m_textCtrl_themeName; }
    wxStaticText* GetStaticText328() { return m_staticText328; }
    wxColourPickerCtrl* GetColourPicker330() { return m_colourPicker330; }
    wxListCtrl* GetColourListCtrl() { return m_colourListCtrl; }
    wxPanel* GetPanel257() { return m_panel257; }
    wxPanel* GetPanel255() { return m_panel255; }
    wxPanel* GetPanel117() { return m_panel117; }
    wxPanel* GetPanel261() { return m_panel261; }
    wxPanel* GetPanel259() { return m_panel259; }
    wxPanel* GetPanel265() { return m_panel265; }
    wxTreebook* GetTreebook249() { return m_treebook249; }
    wxButton* GetBtn_OK() { return btn_OK; }
    wxButton* GetBtn_apply() { return btn_apply; }
    wxButton* GetBtn_cancel() { return btn_cancel; }
    SettingsDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,400), long style = wxDEFAULT_FRAME_STYLE|wxFRAME_TOOL_WINDOW|wxFRAME_NO_TASKBAR|wxSTAY_ON_TOP);
    virtual ~SettingsDialogBase();
};


class FindReplaceBase : public wxPanel
{
public:
    enum {
        ID_CNTRL_FIND = 1001,
        ID_CNTRL_REPLACE = 1002,
    };
protected:
    wxBitmapToggleButton* m_matchCase;
    wxBitmapToggleButton* m_btn_wholeWord;
    wxStaticText* m_staticText385;
    wxComboBox* m_txtCntrl_Find;
    wxBitmapButton* m_btn_find;
    wxBitmapButton* m_btn_findPrev;
    wxBitmapButton* m_btn_findNext;
    wxBitmapToggleButton* m_bmpToggleBtn411;
    wxBitmapToggleButton* m_bmpToggleBtn413;
    wxBitmapToggleButton* m_bmpToggleBtn415;
    wxStaticText* m_staticText419;
    wxComboBox* m_txtCntrl_Repalce;
    wxBitmapButton* m_replaceNext;
    wxBitmapButton* m_replaceAll;
    wxCollapsiblePane* m_collPane465;
    wxCheckListBox* m_checkListBox477;

protected:
    virtual void OnMatchcaseTogglebuttonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBtn_wholewordTogglebuttonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnTxtcntrl_findTextUpdated(wxCommandEvent& event) { event.Skip(); }
    virtual void OnTxtcntrl_findTextEnter(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBtn_findButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBtn_findprevButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBtn_findnextButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnReplacenextButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnReplaceallButtonClicked(wxCommandEvent& event) { event.Skip(); }

public:
    wxBitmapToggleButton* GetMatchCase() { return m_matchCase; }
    wxBitmapToggleButton* GetBtn_wholeWord() { return m_btn_wholeWord; }
    wxStaticText* GetStaticText385() { return m_staticText385; }
    wxComboBox* GetTxtCntrl_Find() { return m_txtCntrl_Find; }
    wxBitmapButton* GetBtn_find() { return m_btn_find; }
    wxBitmapButton* GetBtn_findPrev() { return m_btn_findPrev; }
    wxBitmapButton* GetBtn_findNext() { return m_btn_findNext; }
    wxBitmapToggleButton* GetBmpToggleBtn411() { return m_bmpToggleBtn411; }
    wxBitmapToggleButton* GetBmpToggleBtn413() { return m_bmpToggleBtn413; }
    wxBitmapToggleButton* GetBmpToggleBtn415() { return m_bmpToggleBtn415; }
    wxStaticText* GetStaticText419() { return m_staticText419; }
    wxComboBox* GetTxtCntrl_Repalce() { return m_txtCntrl_Repalce; }
    wxBitmapButton* GetReplaceNext() { return m_replaceNext; }
    wxBitmapButton* GetReplaceAll() { return m_replaceAll; }
    wxCheckListBox* GetCheckListBox477() { return m_checkListBox477; }
    wxCollapsiblePane* GetCollPane465() { return m_collPane465; }
    FindReplaceBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,200), long style = wxTAB_TRAVERSAL);
    virtual ~FindReplaceBase();
};

#endif
