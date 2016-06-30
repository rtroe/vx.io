#include "MainFrame.h"


void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    // wxUnusedVar(event);
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

void MainFrame::OnHelp(wxCommandEvent& evt)
{
    m_mgr.GetPane(wxT("ctrl_help")).Show();
    m_mgr.Update();
}

void MainFrame::OnReportBug(wxCommandEvent& evt)
{
    wxLaunchDefaultBrowser(_("https://github.com/virte-c/vx.io/issues"));
}

void MainFrame::OnViewChangeLog(wxCommandEvent& evt)
{
    m_mgr.GetPane(wxT("ctrl_changeLog")).Show();
    m_mgr.Update();
}

void MainFrame::OnCheckForUpdates(wxCommandEvent& evt)
{
    wxLaunchDefaultBrowser(_("https://github.com/virte-c/vx.io/releases"));
}