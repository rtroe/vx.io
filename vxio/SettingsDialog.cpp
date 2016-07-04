#include "SettingsDialog.h"
#include <wx/fontenum.h>

SettingsDialog::SettingsDialog(MainFrame* mainFrame, wxWindow* parent)
    : SettingsDialogBase(parent)
{
    m_mainFrame = mainFrame;
    
    //Load Fonts
    wxFontEnumerator* fonts = new wxFontEnumerator();
    
    wxArrayString fontArray = fonts->GetFacenames();    
    cmbbx_fonts->Insert(fonts->GetFacenames(), 0);
    
    
    wxArrayString fontSizes;
    fontSizes.Add("8");
    fontSizes.Add("9");
    fontSizes.Add("10");
    fontSizes.Add("11");
    fontSizes.Add("12");
    fontSizes.Add("14");
    fontSizes.Add("16");
    fontSizes.Add("18");
    fontSizes.Add("20");
    fontSizes.Add("24");
    fontSizes.Add("36");
    fontSizes.Add("72");
    
    cmbbx_font_size->Insert(fontSizes,0);
    
    
    
    cmbbx_fonts->SetSelection(cmbbx_fonts->FindString(m_mainFrame->MainSettings->FontName.value()));
    cmbbx_font_size->SetSelection(cmbbx_font_size->FindString(m_mainFrame->MainSettings->FontSize.toString()));
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::ApplySettings()
{
    m_mainFrame->MainSettings->FontName = cmbbx_fonts->GetStringSelection();
    
        long t;
    cmbbx_font_size->GetStringSelection().ToLong(&t);
    m_mainFrame->MainSettings->FontSize = t;
    
    cout<<m_mainFrame->MainSettings->toXML()<<endl;
    m_mainFrame->MainSettings->Save();
    
    m_mainFrame->ApplySettings();
}

void SettingsDialog::OnCmbbx_fontsChoiceSelected(wxCommandEvent& event)
{
    long t;
    cmbbx_font_size->GetStringSelection().ToLong(&t);
    m_mainFrame->GetActiveDocument()->SetMainFont(cmbbx_fonts->GetStringSelection(), t);
}
void SettingsDialog::OnBtn_applyButtonClicked(wxCommandEvent& event)
{
    ApplySettings();
}
void SettingsDialog::OnBtn_cancelButtonClicked(wxCommandEvent& event)
{
    //Reload the settings
    m_mainFrame->MainSettings->Load();
    m_mainFrame->ApplySettings();
    this->Close();
}
void SettingsDialog::OnBtn_okButtonClicked(wxCommandEvent& event)
{
    ApplySettings();
    this->Close();
}
void SettingsDialog::OnCmbbx_font_sizeChoiceSelected(wxCommandEvent& event)
{
    
    long t;
    cmbbx_font_size->GetStringSelection().ToLong(&t);
    m_mainFrame->GetActiveDocument()->SetMainFont(cmbbx_fonts->GetStringSelection(), t);
}
