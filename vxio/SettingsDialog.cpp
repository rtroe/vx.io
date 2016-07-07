#include "SettingsDialog.h"
#include <wx/fontenum.h>
#include "controls/vxTextCtrl.h"

vxTextCtrl* textCtrl;

vector<ColourScheme*> Themes;

SettingsDialog::SettingsDialog(MainFrame* mainFrame, wxWindow* parent)
    : SettingsDialogBase(parent)
{
    m_mainFrame = mainFrame;
    
    textCtrl = new vxTextCtrl(m_panel160, "misc/main.cpp", m_mainFrame->MainSettings);
    
    textCtrl->SetSize(m_panel160->GetSize());
    
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
    
    
    //Add Theme Settings
     wxArrayString str;
  
  //Get All Files in /usr/local/include  directory
  //Set wxDIR_FILES flag. There's no wxDIR_DIRS in flags argument, so 
  //this command lists only files under /usr/local/include directory non-recursively.
  wxDir::GetAllFiles("schemes",&str,"*.xml",wxDIR_FILES);
  
    
  for (unsigned int index=0;index < str.GetCount();index++)
  {
    //cout<< str[index]<< endl;
    
    ColourScheme* temp_scheme = new ColourScheme;
    temp_scheme->Load(str[index]);
    
    Themes.push_back(temp_scheme);
        
    cmbbx_theme->Append(temp_scheme->Name.value());
  }
  
  //cmbbx_theme->SetLabel(m_mainFrame->MainSettings->CurColSchm.Name.value());
  
    cmbbx_theme->SetSelection(cmbbx_theme->FindString(m_mainFrame->MainSettings->CurColSchm.Name.value()));
  

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
    
    //Set Colour Scheme    
    m_mainFrame->MainSettings->CurColSchm.Copy(Themes[cmbbx_theme->GetSelection()]);
    
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
void SettingsDialog::OnCmbbx_themeChoiceSelected(wxCommandEvent& event)
{
    textCtrl->m_settings->CurColSchm.Copy(Themes[cmbbx_theme->GetSelection()]);
    textCtrl->ParseLexar();
    
    //std::cout<<Themes[cmbbx_theme->GetSelection()]->Name.value()<<endl;
}
