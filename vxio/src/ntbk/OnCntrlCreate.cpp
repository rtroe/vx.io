#include "MainFrame.h"
#include "include/gui/vxAuiTabArt.h"


wxAuiNotebook* MainFrame::CreateNotebook()
{
    // create the notebook off-window to avoid flicker
    wxSize client_size = GetClientSize();

    m_ntbk =
        new wxAuiNotebook(this, wxID_ANY, wxPoint(client_size.x, client_size.y), wxSize(430, 200), m_notebook_style);
    m_ntbk->Freeze();

    m_ntbk->SetArtProvider(new vxDefaultAuiTabArt());

    m_ntbk->AddPage(CreateStyleTextCtrl(wxString::Format(wxT("newFile %i"), INT_NewFileList)),
                    wxString::Format(wxT("newFile %i"), INT_NewFileList),
                    true,
                    vxAppImgs->FileTypeScript);
    INT_NewFileList++;

    m_ntbk->Thaw();

    return m_ntbk;
}

vxTextCtrl* MainFrame::CreateStyleTextCtrl(wxString FilePath)
{
    vxTextCtrl* text = new vxTextCtrl(this, FilePath, this->MainSettings);
    return text;
}



void MainFrame::OnCreateStyleTextCtrl(wxCommandEvent& WXUNUSED(event))
{
    m_ntbk->AddPage(CreateStyleTextCtrl(wxString::Format(wxT("newFile %i"), INT_NewFileList)),
                    wxString::Format(wxT("newFile %i"), INT_NewFileList),
                    true);
    INT_NewFileList++;
    SetToolbarStatus();
}

void MainFrame::OnCreateTree(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(
        CreateTreeCtrl(),
        wxAuiPaneInfo().Caption(wxT("Tree Control")).Float().FloatingPosition(GetStartPosition()).FloatingSize(
            wxSize(150, 300)));
    m_mgr.Update();
}

void MainFrame::OnCreateGrid(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateGrid(),
                  wxAuiPaneInfo().Caption(wxT("Grid")).Float().FloatingPosition(GetStartPosition()).FloatingSize(
                      wxSize(300, 200)));
    m_mgr.Update();
}





wxHtmlWindow* MainFrame::CreateHTMLCtrl(wxWindow* parent)
{
    if(!parent)
        parent = this;

    wxHtmlWindow* ctrl = new wxHtmlWindow(parent, wxID_ANY, wxDefaultPosition, wxSize(400, 300));
    ctrl->SetPage(GetIntroText());
    return ctrl;
}

void MainFrame::OnCreateHTML(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(
        CreateHTMLCtrl(),
        wxAuiPaneInfo().Caption(wxT("HTML Control")).Float().FloatingPosition(GetStartPosition()).FloatingSize(
            wxSize(300, 200)));
    m_mgr.Update();
}

void MainFrame::OnCreateNotebook(wxCommandEvent& WXUNUSED(event))
{
    m_mgr.AddPane(CreateNotebook(),
                  wxAuiPaneInfo()
                      .Caption(wxT("Notebook"))
                      .Float()
                      .FloatingPosition(GetStartPosition())
                      .
                  // FloatingSize(300,200).
                  CloseButton(true)
                      .MaximizeButton(true));
    m_mgr.Update();
}

wxGrid* MainFrame::CreateGrid()
{
    wxGrid* grid = new wxGrid(this, wxID_ANY, wxPoint(0, 0), wxSize(150, 250), wxNO_BORDER | wxWANTS_CHARS);
    grid->CreateGrid(50, 20);
    return grid;
}



wxTreeCtrl* MainFrame::CreateTreeCtrl()
{
    wxTreeCtrl* tree =
        new wxTreeCtrl(this, wxID_ANY, wxPoint(0, 0), wxSize(160, 250), wxTR_DEFAULT_STYLE | wxNO_BORDER);

    wxImageList* imglist = new wxImageList(16, 16, true, 2);
    imglist->Add(wxArtProvider::GetBitmap(wxART_FOLDER, wxART_OTHER, wxSize(16, 16)));
    imglist->Add(wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16)));
    tree->AssignImageList(imglist);

    wxTreeItemId root = tree->AddRoot(wxT("wxAUI Project"), 0);
    wxArrayTreeItemIds items;

    items.Add(tree->AppendItem(root, wxT("Item 1"), 0));
    items.Add(tree->AppendItem(root, wxT("Item 2"), 0));
    items.Add(tree->AppendItem(root, wxT("Item 3"), 0));
    items.Add(tree->AppendItem(root, wxT("Item 4"), 0));
    items.Add(tree->AppendItem(root, wxT("Item 5"), 0));

    int i, count;
    for(i = 0, count = items.Count(); i < count; ++i) {
        wxTreeItemId id = items.Item(i);
        tree->AppendItem(id, wxT("Subitem 1"), 1);
        tree->AppendItem(id, wxT("Subitem 2"), 1);
        tree->AppendItem(id, wxT("Subitem 3"), 1);
        tree->AppendItem(id, wxT("Subitem 4"), 1);
        tree->AppendItem(id, wxT("Subitem 5"), 1);
    }

    tree->Expand(root);

    return tree;
}
