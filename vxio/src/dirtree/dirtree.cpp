#include "MainFrame.h"


wxGenericDirCtrl* MainFrame::CreateDirViewCtrl()
{
    wxGenericDirCtrl* dirCtrl = new wxGenericDirCtrl(
        this, ID_CNTRL_DIRTREE, wxDirDialogDefaultFolderStr, wxPoint(0, 0), wxSize(250, 250), wxDIRCTRL_SHOW_FILTERS);

    return dirCtrl;
}

void MainFrame::OnToggleDirTree(wxCommandEvent& evt)
{
    if(m_mgr.GetPane(wxT("ctrl_dirTree")).IsShown())
    {
        tb_system->ToggleTool(ID_ToggleTree, false);
        view_menu->Check(ID_ToggleTree, false);
        m_mgr.GetPane(wxT("ctrl_dirTree")).Hide();
    }
    else
    {
        tb_system->ToggleTool(ID_ToggleTree, true);
        view_menu->Check(ID_ToggleTree, true);
        m_mgr.GetPane(wxT("ctrl_dirTree")).Show();
    }

    m_mgr.Update();
}


void MainFrame::OnFileActivated(wxTreeEvent& event)
{
    if(ctrl_DirTreeView) {

        
    ConsoleWriteLine("vx.IO.Open('"+ctrl_DirTreeView->GetPath(event.GetItem())+"')");
        // if the user click "Open" instead of "Cancel"
        m_ntbk->AddPage(CreateStyleTextCtrl(ctrl_DirTreeView->GetPath(event.GetItem())),
                        ctrl_DirTreeView->GetPath(event.GetItem()),
                        true,
                        vxAppImgs->FileTypeScript);

        SetToolbarStatus();
    }

    event.Skip();
}