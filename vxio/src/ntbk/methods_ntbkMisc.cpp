#include "MainFrame.h"


void MainFrame::OnPaneClose(wxAuiManagerEvent& evt)
{ 
     if (evt.pane->name == wxT("ctrl_dirTree"))
     {         
        tb_system->ToggleTool(ID_ToggleTree, false);
        view_menu->Check(ID_ToggleTree, false);
     }
     else if (evt.pane->name == wxT("ctrl_console"))
     {         
        tb_system->ToggleTool(ID_ToggleConsole, false);
        view_menu->Check(ID_ToggleConsole, false);
     }
     else
     {
         
    int res = wxMessageBox(wxT("Are you sure you want to close/hide this pane?"), this->VXIO_APPLICATIONNAME, wxYES_NO, this);
    if(res != wxYES)
        evt.Veto();
    }
}

void MainFrame::OnDropFiles(wxDropFilesEvent& event)
{
    if(event.GetNumberOfFiles() > 0) {

        wxString* dropped = event.GetFiles();
        wxASSERT(dropped);

        wxBusyCursor busyCursor;
        wxWindowDisabler disabler;
        wxBusyInfo busyInfo(_("Opening files, Please wait..."));

        wxString name;
        wxArrayString files;

        for(int i = 0; i < event.GetNumberOfFiles(); i++) {
            name = dropped[i];
            if(wxFileExists(name))
                files.push_back(name);
            else if(wxDirExists(name))
                wxDir::GetAllFiles(name, &files);
        }

        for(size_t i = 0; i < files.size(); i++) {
            m_ntbk->AddPage(CreateStyleTextCtrl(files[i]), files[i], true, vxAppImgs->FileTypeScript);
            std::cout << files[i] << std::endl;
        }
    }
}

void MainFrame::OnChangeContentPane(wxCommandEvent& evt)
{
    m_mgr.GetPane(wxT("notebook_content")).Show(evt.GetId() == ID_NotebookContent);
    SetToolbarStatus();
    m_mgr.Update();
}



void MainFrame::OnNotebookPageChanged(wxAuiNotebookEvent& evt)
{
    SetToolbarStatus();
}

wxAuiDockArt* MainFrame::GetDockArt()
{
    return m_mgr.GetArtProvider();
}

void MainFrame::DoUpdate()
{
    m_mgr.Update();
}

void MainFrame::OnEraseBackground(wxEraseEvent& event)
{
    event.Skip();
}

void MainFrame::OnSize(wxSizeEvent& event)
{
    event.Skip();
}

void MainFrame::OnSettings(wxCommandEvent& WXUNUSED(evt))
{
    // show the settings pane, and float it
    wxAuiPaneInfo& floating_pane = m_mgr.GetPane(wxT("settings")).Float().Show();

    if(floating_pane.floating_pos == wxDefaultPosition)
        floating_pane.FloatingPosition(GetStartPosition());

    m_mgr.Update();
}

void MainFrame::OnCustomizeToolbar(wxCommandEvent& WXUNUSED(evt))
{
    wxMessageBox(_("Customize Toolbar clicked"));
}

void MainFrame::OnGradient(wxCommandEvent& event)
{
    int gradient = 0;

    switch(event.GetId()) {
    case ID_NoGradient:
        gradient = wxAUI_GRADIENT_NONE;
        break;
    case ID_VerticalGradient:
        gradient = wxAUI_GRADIENT_VERTICAL;
        break;
    case ID_HorizontalGradient:
        gradient = wxAUI_GRADIENT_HORIZONTAL;
        break;
    }

    m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, gradient);
    m_mgr.Update();
}

void MainFrame::OnToolbarResizing(wxCommandEvent& WXUNUSED(evt))
{
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    const size_t count = all_panes.GetCount();
    for(size_t i = 0; i < count; ++i) {
        wxAuiToolBar* toolbar = wxDynamicCast(all_panes[i].window, wxAuiToolBar);
        if(toolbar) {
            all_panes[i].Resizable(!all_panes[i].IsResizable());
        }
    }

    m_mgr.Update();
}

void MainFrame::OnManagerFlag(wxCommandEvent& event)
{
    unsigned int flag = 0;

#if !defined(__WXMSW__) && !defined(__WXMAC__) && !defined(__WXGTK__)
    if(event.GetId() == ID_TransparentDrag || event.GetId() == ID_TransparentHint || event.GetId() == ID_HintFade) {
        wxMessageBox(wxT("This option is presently only available on wxGTK, wxMSW and wxMac"));
        return;
    }
#endif

    int id = event.GetId();

    if(id == ID_TransparentHint || id == ID_VenetianBlindsHint || id == ID_RectangleHint || id == ID_NoHint) {
        unsigned int flags = m_mgr.GetFlags();
        flags &= ~wxAUI_MGR_TRANSPARENT_HINT;
        flags &= ~wxAUI_MGR_VENETIAN_BLINDS_HINT;
        flags &= ~wxAUI_MGR_RECTANGLE_HINT;
        m_mgr.SetFlags(flags);
    }

    switch(id) {
    case ID_AllowFloating:
        flag = wxAUI_MGR_ALLOW_FLOATING;
        break;
    case ID_TransparentDrag:
        flag = wxAUI_MGR_TRANSPARENT_DRAG;
        break;
    case ID_HintFade:
        flag = wxAUI_MGR_HINT_FADE;
        break;
    case ID_NoVenetianFade:
        flag = wxAUI_MGR_NO_VENETIAN_BLINDS_FADE;
        break;
    case ID_AllowActivePane:
        flag = wxAUI_MGR_ALLOW_ACTIVE_PANE;
        break;
    case ID_TransparentHint:
        flag = wxAUI_MGR_TRANSPARENT_HINT;
        break;
    case ID_VenetianBlindsHint:
        flag = wxAUI_MGR_VENETIAN_BLINDS_HINT;
        break;
    case ID_RectangleHint:
        flag = wxAUI_MGR_RECTANGLE_HINT;
        break;
    case ID_LiveUpdate:
        flag = wxAUI_MGR_LIVE_RESIZE;
        break;
    }

    if(flag) {
        m_mgr.SetFlags(m_mgr.GetFlags() ^ flag);
    }

    m_mgr.Update();
}

void MainFrame::OnNotebookFlag(wxCommandEvent& event)
{
    int id = event.GetId();

    if(id == ID_NotebookNoCloseButton || id == ID_NotebookCloseButton || id == ID_NotebookCloseButtonAll ||
       id == ID_NotebookCloseButtonActive) {
        m_notebook_style &= ~(wxAUI_NB_CLOSE_BUTTON | wxAUI_NB_CLOSE_ON_ACTIVE_TAB | wxAUI_NB_CLOSE_ON_ALL_TABS);

        switch(id) {
        case ID_NotebookNoCloseButton:
            break;
        case ID_NotebookCloseButton:
            m_notebook_style |= wxAUI_NB_CLOSE_BUTTON;
            break;
        case ID_NotebookCloseButtonAll:
            m_notebook_style |= wxAUI_NB_CLOSE_ON_ALL_TABS;
            break;
        case ID_NotebookCloseButtonActive:
            m_notebook_style |= wxAUI_NB_CLOSE_ON_ACTIVE_TAB;
            break;
        }
    }

    if(id == ID_NotebookAllowTabMove) {
        m_notebook_style ^= wxAUI_NB_TAB_MOVE;
    }
    if(id == ID_NotebookAllowTabExternalMove) {
        m_notebook_style ^= wxAUI_NB_TAB_EXTERNAL_MOVE;
    } else if(id == ID_NotebookAllowTabSplit) {
        m_notebook_style ^= wxAUI_NB_TAB_SPLIT;
    } else if(id == ID_NotebookWindowList) {
        m_notebook_style ^= wxAUI_NB_WINDOWLIST_BUTTON;
    } else if(id == ID_NotebookScrollButtons) {
        m_notebook_style ^= wxAUI_NB_SCROLL_BUTTONS;
    } else if(id == ID_NotebookTabFixedWidth) {
        m_notebook_style ^= wxAUI_NB_TAB_FIXED_WIDTH;
    }

    size_t i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for(i = 0, count = all_panes.GetCount(); i < count; ++i) {
        wxAuiPaneInfo& pane = all_panes.Item(i);
        if(pane.window->IsKindOf(CLASSINFO(wxAuiNotebook))) {
            wxAuiNotebook* nb = (wxAuiNotebook*)pane.window;

            if(id == ID_NotebookArtGloss) {
                nb->SetArtProvider(new wxAuiDefaultTabArt);
                m_notebook_theme = 0;
            } else if(id == ID_NotebookArtSimple) {
                nb->SetArtProvider(new wxAuiSimpleTabArt);
                m_notebook_theme = 1;
            }

            nb->SetWindowStyleFlag(m_notebook_style);
            nb->Refresh();
        }
    }
}


void MainFrame::OnUpdateUI(wxUpdateUIEvent& event)
{
    unsigned int flags = m_mgr.GetFlags();

    switch(event.GetId()) {
    case ID_NoGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_NONE);
        break;
    case ID_VerticalGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_VERTICAL);
        break;
    case ID_HorizontalGradient:
        event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_HORIZONTAL);
        break;
    case ID_AllowToolbarResizing: {
        wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
        const size_t count = all_panes.GetCount();
        for(size_t i = 0; i < count; ++i) {
            wxAuiToolBar* toolbar = wxDynamicCast(all_panes[i].window, wxAuiToolBar);
            if(toolbar) {
                event.Check(all_panes[i].IsResizable());
                break;
            }
        }
        break;
    }
    case ID_AllowFloating:
        event.Check((flags & wxAUI_MGR_ALLOW_FLOATING) != 0);
        break;
    case ID_TransparentDrag:
        event.Check((flags & wxAUI_MGR_TRANSPARENT_DRAG) != 0);
        break;
    case ID_TransparentHint:
        event.Check((flags & wxAUI_MGR_TRANSPARENT_HINT) != 0);
        break;
    case ID_LiveUpdate:
        event.Check((flags & wxAUI_MGR_LIVE_RESIZE) != 0);
        break;
    case ID_VenetianBlindsHint:
        event.Check((flags & wxAUI_MGR_VENETIAN_BLINDS_HINT) != 0);
        break;
    case ID_RectangleHint:
        event.Check((flags & wxAUI_MGR_RECTANGLE_HINT) != 0);
        break;
    case ID_NoHint:
        event.Check(
            ((wxAUI_MGR_TRANSPARENT_HINT | wxAUI_MGR_VENETIAN_BLINDS_HINT | wxAUI_MGR_RECTANGLE_HINT) & flags) == 0);
        break;
    case ID_HintFade:
        event.Check((flags & wxAUI_MGR_HINT_FADE) != 0);
        break;
    case ID_NoVenetianFade:
        event.Check((flags & wxAUI_MGR_NO_VENETIAN_BLINDS_FADE) != 0);
        break;

    case ID_NotebookNoCloseButton:
        event.Check((m_notebook_style &
                     (wxAUI_NB_CLOSE_BUTTON | wxAUI_NB_CLOSE_ON_ALL_TABS | wxAUI_NB_CLOSE_ON_ACTIVE_TAB)) != 0);
        break;
    case ID_NotebookCloseButton:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_BUTTON) != 0);
        break;
    case ID_NotebookCloseButtonAll:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ALL_TABS) != 0);
        break;
    case ID_NotebookCloseButtonActive:
        event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ACTIVE_TAB) != 0);
        break;
    case ID_NotebookAllowTabSplit:
        event.Check((m_notebook_style & wxAUI_NB_TAB_SPLIT) != 0);
        break;
    case ID_NotebookAllowTabMove:
        event.Check((m_notebook_style & wxAUI_NB_TAB_MOVE) != 0);
        break;
    case ID_NotebookAllowTabExternalMove:
        event.Check((m_notebook_style & wxAUI_NB_TAB_EXTERNAL_MOVE) != 0);
        break;
    case ID_NotebookScrollButtons:
        event.Check((m_notebook_style & wxAUI_NB_SCROLL_BUTTONS) != 0);
        break;
    case ID_NotebookWindowList:
        event.Check((m_notebook_style & wxAUI_NB_WINDOWLIST_BUTTON) != 0);
        break;
    case ID_NotebookTabFixedWidth:
        event.Check((m_notebook_style & wxAUI_NB_TAB_FIXED_WIDTH) != 0);
        break;
    case ID_NotebookArtGloss:
        event.Check(m_notebook_style == 0);
        break;
    case ID_NotebookArtSimple:
        event.Check(m_notebook_style == 1);
        break;
    }
}


void MainFrame::OnCreatePerspective(wxCommandEvent& WXUNUSED(event))
{
    wxTextEntryDialog dlg(this, wxT("Enter a name for the new layout:"), wxT("Save Layout"));

    dlg.SetValue(wxString::Format(wxT("layout. %u"), unsigned(m_perspectives.GetCount() + 1)));
    if(dlg.ShowModal() != wxID_OK)
        return;

    if(m_perspectives.GetCount() == 0) {
        m_perspectives_menu->AppendSeparator();
    }

    m_perspectives_menu->Append(ID_FirstPerspective + m_perspectives.GetCount(), dlg.GetValue());
    m_perspectives.Add(m_mgr.SavePerspective());
}

void MainFrame::OnCopyPerspectiveCode(wxCommandEvent& WXUNUSED(evt))
{
    wxString s = m_mgr.SavePerspective();

#if wxUSE_CLIPBOARD
    if(wxTheClipboard->Open()) {
        wxTheClipboard->SetData(new wxTextDataObject(s));
        wxTheClipboard->Close();
    }
#endif
}

void MainFrame::OnRestorePerspective(wxCommandEvent& evt)
{
    m_mgr.LoadPerspective(m_perspectives.Item(evt.GetId() - ID_FirstPerspective));
}

void MainFrame::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{
    wxAuiNotebook* ctrl = (wxAuiNotebook*)evt.GetEventObject();
    // if (ctrl->GetPage(evt.GetSelection())->IsKindOf(CLASSINFO(wxHtmlWindow)))
    if(GetActiveDocument()->GetModify()) {
        int res = wxMessageBox(wxT("Do you want to save before closing this file?"),
                               wxT("Save before closing?"),
                               wxYES_NO | wxCANCEL | wxICON_QUESTION,
                               this);

        // If Yes is clicked, then Save the File before closing.
        if(res == wxYES) {
            SaveActiveFile();
        }
        // wxNO Means Nothing should Happen

        // If Canceled is clicked, then abort closing the file
        else if(res == wxCANCEL)
            evt.Veto();
    }
}

void MainFrame::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{
    wxAuiNotebook* ctrl = (wxAuiNotebook*)evt.GetEventObject();

    // selection should always be a valid index
    wxASSERT_MSG(
        ctrl->GetSelection() < (int)ctrl->GetPageCount(),
        wxString::Format("Invalid selection %d, only %d pages left", ctrl->GetSelection(), (int)ctrl->GetPageCount()));

    evt.Skip();
}

void MainFrame::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
    // for the purpose of this test application, explicitly
    // allow all noteboko drag and drop events
    evt.Allow();
}

wxPoint MainFrame::GetStartPosition()
{
    static int x = 0;
    x += 20;
    wxPoint pt = ClientToScreen(wxPoint(0, 0));
    return wxPoint(pt.x + x, pt.y + x);
}

void MainFrame::OnDropDownToolbarItem(wxAuiToolBarEvent& evt)
{
    if(evt.IsDropDownClicked()) {
        wxAuiToolBar* tb = static_cast<wxAuiToolBar*>(evt.GetEventObject());

        tb->SetToolSticky(evt.GetId(), true);

        // create the popup menu
        wxMenu menuPopup;

        wxBitmap bmp = wxArtProvider::GetBitmap(wxART_QUESTION, wxART_OTHER, wxSize(16, 16));

        wxMenuItem* m1 = new wxMenuItem(&menuPopup, 10001, _("Drop Down Item 1"));
        m1->SetBitmap(bmp);
        menuPopup.Append(m1);

        wxMenuItem* m2 = new wxMenuItem(&menuPopup, 10002, _("Drop Down Item 2"));
        m2->SetBitmap(bmp);
        menuPopup.Append(m2);

        wxMenuItem* m3 = new wxMenuItem(&menuPopup, 10003, _("Drop Down Item 3"));
        m3->SetBitmap(bmp);
        menuPopup.Append(m3);

        wxMenuItem* m4 = new wxMenuItem(&menuPopup, 10004, _("Drop Down Item 4"));
        m4->SetBitmap(bmp);
        menuPopup.Append(m4);

        // line up our menu with the button
        wxRect rect = tb->GetToolRect(evt.GetId());
        wxPoint pt = tb->ClientToScreen(rect.GetBottomLeft());
        pt = ScreenToClient(pt);

        PopupMenu(&menuPopup, pt);

        // make sure the button is "un-stuck"
        tb->SetToolSticky(evt.GetId(), false);
    }
}

void MainFrame::OnTabAlignment(wxCommandEvent& evt)
{
    size_t i, count;
    wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
    for(i = 0, count = all_panes.GetCount(); i < count; ++i) {
        wxAuiPaneInfo& pane = all_panes.Item(i);
        if(pane.window->IsKindOf(CLASSINFO(wxAuiNotebook))) {
            wxAuiNotebook* nb = (wxAuiNotebook*)pane.window;

            long style = nb->GetWindowStyleFlag();
            style &= ~(wxAUI_NB_TOP | wxAUI_NB_BOTTOM);
            if(evt.GetId() == ID_NotebookAlignTop)
                style |= wxAUI_NB_TOP;
            else if(evt.GetId() == ID_NotebookAlignBottom)
                style |= wxAUI_NB_BOTTOM;
            nb->SetWindowStyleFlag(style);

            nb->Refresh();
        }
    }
}