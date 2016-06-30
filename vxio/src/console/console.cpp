#include "MainFrame.h"
#include <string>
#include <sstream>


void MainFrame::CreateConsole()
{
    ctrl_console = CreateStyleTextCtrl(_("Console"));
    
    for (int Nr = 0; Nr < wxSTC_STYLE_MAX; Nr++)
    {
    ctrl_console->StyleSetForeground (Nr,  wxColour(225,225,225));
    ctrl_console->StyleSetBackground (Nr, wxColour(25, 25, 50));
    }
    
ctrl_console->SetLexer(wxSTC_LEX_PYTHON);

    ctrl_console->StyleSetForeground (wxSTC_P_WORD,         wxColour(0,170,170));
    ctrl_console->StyleSetBold(wxSTC_P_WORD, true);

    ctrl_console->StyleSetForeground (wxSTC_P_WORD2,        wxColour(255,128,0));
    ctrl_console->StyleSetBold(wxSTC_P_WORD2, true);

    ctrl_console->StyleSetForeground (wxSTC_P_CHARACTER,    wxColour(240,0,240));
    ctrl_console->StyleSetForeground (wxSTC_P_STRING,       wxColour(240,0,240));

    ctrl_console->StyleSetForeground (wxSTC_P_COMMENTLINE,  wxColour(0,255,0));
    ctrl_console->StyleSetForeground (wxSTC_P_COMMENTBLOCK, wxColour(0,255,0));

    ctrl_console->StyleSetForeground (wxSTC_P_NUMBER,       wxColour(0,210,210));
    
    

    
    ctrl_console->SetKeyWords(0, wxT("GetFileName SetViewToCorner ZoomIn ZoomOut print create")
                    _T("class def for yield self and del from not while as elif global or with")
                      _T("assert    else      if        pass      yield")
                      _T("break     except    import ")
                      _T("class     exec      in        raise")
                      _T("continue  finally   is        return ")
                      _T("def       for       lambda    try vx IO io Bamboo"));
                      
                      ctrl_console->SetKeyWords(1, wxT(" New Open Save  activeFile Base activeEnvr"));
                      /*
    ctrl_console->SetKeyWords(1, wxT("iris GetCurrentDoc Add Delete Show Hide create New Open Save SaveAs SaveAll Finish Import Export Select ")
                              _T("set view front back left right top bottom iso zoom in out fit ")
                              _T("ienvr open  pyCMD")
                              _T("print int double float string char"));
                              */
                              //vxIris
    m_mgr.AddPane(ctrl_console, wxAuiPaneInfo().
                  Name(wxT("ctrl_console")).Caption(wxT("console")).
                  Bottom().Position(1).
                  CloseButton(true).PinButton(true));
}


void MainFrame::OnToggleConsole(wxCommandEvent& evt)
{
        if(m_mgr.GetPane(wxT("ctrl_console")).IsShown())
    {
        tb_system->ToggleTool(ID_ToggleConsole, false);
        view_menu->Check(ID_ToggleConsole, false);
        //m_mgr.GetPane(wxT("PropertyGrid")).Hide();
        m_mgr.GetPane(wxT("ctrl_console")).Hide();
    }
    else
    {
        tb_system->ToggleTool(ID_ToggleConsole, true);
        view_menu->Check(ID_ToggleConsole, true);
        m_mgr.GetPane(wxT("ctrl_console")).Show();
        //m_mgr.GetPane(wxT("PropertyGrid")).Show();
    }

    m_mgr.Update();
}

void MainFrame::ConsoleWriteLine(wxString input)
{
    std::string result;

std::istringstream iss(input.ToStdString());

for (std::string line; std::getline(iss, line); )
{
    result += ">>" + line;
}

    std::cout<<GetActiveDocument()->FileName<<" : "<<result<<std::endl;

    if(ctrl_console!=NULL)
    {
        ctrl_console->AppendText(result + "\n");
        ctrl_console->ScrollToEnd();
    }
}