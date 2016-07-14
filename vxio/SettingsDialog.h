#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H
#include "wxcrafter.h"
#include "MainFrame.h"

class SettingsDialog : public SettingsDialogBase
{
public:
    SettingsDialog(MainFrame* mainFrame, wxWindow* parent);
    virtual ~SettingsDialog();
    
    MainFrame* m_mainFrame;
    
    //Applies settings to the MainFrame 
    void ApplySettings();
    
    Settings tempSettings;
    
protected:
    virtual void OnColourpicker330ColourpickerChanged(wxColourPickerEvent& event);
    virtual void OnColourlistctrlListItemSelected(wxListEvent& event);
    virtual void OnCmbbx_themeChoiceSelected(wxCommandEvent& event);
    virtual void OnCmbbx_font_sizeChoiceSelected(wxCommandEvent& event);
    virtual void OnBtn_applyButtonClicked(wxCommandEvent& event);
    virtual void OnBtn_cancelButtonClicked(wxCommandEvent& event);
    virtual void OnBtn_okButtonClicked(wxCommandEvent& event);
    virtual void OnCmbbx_fontsChoiceSelected(wxCommandEvent& event);
};
#endif // SETTINGSDIALOG_H
