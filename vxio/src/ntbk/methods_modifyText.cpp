#include "MainFrame.h"



void MainFrame::OnEOLToggle(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->SetViewEOL(!(GetActiveDocument()->GetViewEOL()));
}

void MainFrame::OnChangeCase(wxCommandEvent& event)
{
    switch(event.GetId()) {
    case ID_CHANGELOWER: {
        GetActiveDocument()->CmdKeyExecute(wxSTC_CMD_LOWERCASE);
        break;
    }
    case ID_CHANGEUPPER: {
        GetActiveDocument()->CmdKeyExecute(wxSTC_CMD_UPPERCASE);
        break;
    }
    }
}

void MainFrame::OnConvertEOL(wxCommandEvent& event)
{
    int eolMode = GetActiveDocument()->GetEOLMode();
    switch(event.GetId()) {
    case ID_CONVERTCR: {
        eolMode = wxSTC_EOL_CR;
        break;
    }
    case ID_CONVERTCRLF: {
        eolMode = wxSTC_EOL_CRLF;
        break;
    }
    case ID_CONVERTLF: {
        eolMode = wxSTC_EOL_LF;
        break;
    }
    }
    GetActiveDocument()->ConvertEOLs(eolMode);
    GetActiveDocument()->SetEOLMode(eolMode);
}

void MainFrame::OnFoldToggle(wxCommandEvent& WXUNUSED(event))
{
    GetActiveDocument()->ToggleFold(GetActiveDocument()->GetFoldParent(GetActiveDocument()->GetCurrentLine()));
}