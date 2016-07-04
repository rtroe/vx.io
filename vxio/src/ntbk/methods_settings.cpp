#include "MainFrame.h"
#include "SettingsDialog.h"

void MainFrame::OnSettings(wxCommandEvent& WXUNUSED(evt))
{
    SettingsDialog* settingsDialog = new SettingsDialog(this, this);
     settingsDialog->Show();
}

void MainFrame::ApplySettings()
{   
    this->GetActiveDocument()->SetMainFont(this->MainSettings->FontName.value(), this->MainSettings->FontSize.value());
}