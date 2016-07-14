#include "MainFrame.h"
#include "SettingsDialog.h"

void MainFrame::OnSettings(wxCommandEvent& WXUNUSED(evt))
{
     SettingsDialog* settingsDialog = new SettingsDialog(this, this);
     settingsDialog->Show();

    //SettingsFrame* settingsFrame = new SettingsFrame(this);
     //settingsFrame->Show();
}

void MainFrame::ApplySettings()
{   
    for(unsigned int i = 0; i < m_ntbk->GetPageCount(); i++)
    {
        GetActiveDocument()->SetMainFont(this->MainSettings->FontName.value(), this->MainSettings->FontSize.value());
        GetDocumentAt(i)->ParseLexar();
    }
}