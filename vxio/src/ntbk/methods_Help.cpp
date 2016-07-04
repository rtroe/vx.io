#include "MainFrame.h"


void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    // wxUnusedVar(event);
    wxAboutDialogInfo info;
    info.SetCopyright(_("(C) Virtex Edge Design"));
    info.SetLicence(_("MIT Licence"));
    info.SetDescription(_("vx.io is a cross platform \nfeature-rich text editor."));
    info.SetName(VXIO_APPLICATIONNAME);
    info.SetVersion(VXIO_VERSION);
    
    wxIcon icon;
    icon.CopyFromBitmap(vxAppImgs->AppIcon16);
    info.SetIcon(icon);
    
    info.SetWebSite(_("http://virte-c.github.io/vx.io/"));
    
    wxArrayString devlopers;
    devlopers.Add(_("R.T.Roe (@virte-c)"));
    info.SetDevelopers(devlopers);
    
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