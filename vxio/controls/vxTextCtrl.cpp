#include "vxTextCtrl.h"

// -- lexars --
#include "lexars/base.h"
#include "lexars/clike.h"
#include "lexars/python.h"
#include "lexars/html.h"
#include "lexars/hlsl.h"
#include "lexars/web.h"

BEGIN_EVENT_TABLE(vxTextCtrl, wxStyledTextCtrl)
    EVT_STC_MARGINCLICK (wxID_ANY,     vxTextCtrl::OnMarginClick)
    EVT_STC_CHARADDED (wxID_ANY,       vxTextCtrl::OnCharAdded)
    EVT_STC_KEY( wxID_ANY , vxTextCtrl::OnKey )
END_EVENT_TABLE()

vxTextCtrl::vxTextCtrl(wxWindow* parent, wxString filePath) : wxStyledTextCtrl(parent, wxID_ANY)
{

    //Set the File Path
    FilePath = filePath;
    

    //Read In File
    if(FilePath != _(""))
    {
        //LoadFile(FilePath);
        wxString str;

        // open the file
        wxTextFile tfile;
        if(wxFileName::FileExists(FilePath))
        {
            LoadFile(FilePath);
             IsNewFile = false;
        }
    }
        else
            wxMessageBox(_("Could Not Open File '")+FilePath+_("'"));

   ParseLexar();


    FileName = filePath;
    SetFileName();
}


vxTextCtrl::~vxTextCtrl()
{

}


//This Method Parses out the File name from the Current File Path.
void vxTextCtrl::SetFileName()
{
    
#if defined(__WXMSW__)

    //Set File Name
    int StartIndex = FilePath.find_last_of(_("\\"),FilePath.length())+1;

        if(StartIndex != -1)
        {
            FileName = FilePath.substr(StartIndex,FilePath.length()-StartIndex);
        }
        else
        {
            StartIndex = FilePath.find_last_of('/',FilePath.length())+1;
           if(StartIndex != -1)
        {
            FileName = FilePath.substr(StartIndex,FilePath.length()-StartIndex);
        }
        }
        
        
#elif defined(__WXMAC__)
// Mac Specific Initilazations here
#elif defined(__UNIX__)

    //Set File Name
    int StartIndex = FilePath.find_last_of(_("/"),FilePath.length())+1;
    
    if(StartIndex != -1)
    {
        FileName = FilePath.substr(StartIndex,FilePath.length()-StartIndex);
    }    
#endif
}

/***********************************************************/

void vxTextCtrl::Save()
{

    SetFileName();
    
    IsNewFile = false;

    SaveFile(FilePath);

   ParseLexar();
}

void vxTextCtrl::OnMarginClick (wxStyledTextEvent &event)
{
    if (event.GetMargin() == 1)
        {
        int lineClick = LineFromPosition (event.GetPosition());
        int levelClick = GetFoldLevel (lineClick);
        if ((levelClick & wxSTC_FOLDLEVELHEADERFLAG) > 0)
        {
            ToggleFold (lineClick);
        }
    }
}

void vxTextCtrl::OnCharAdded (wxStyledTextEvent &event)
{
    event.Skip();
/*
    char chr = (char)event.GetKey();
    int currentLine = GetCurrentLine();

    // Change this if support for mac files with \r is needed
    if (chr == '\n')
        {
        int lineInd = 0;
        if (currentLine > 0)
        {
            lineInd = GetLineIndentation(currentLine - 1);
        }
        if (lineInd == 0) return;
        SetLineIndentation (currentLine, lineInd);
        GotoPos(PositionFromLine (currentLine) + lineInd);
    }*/
}

void vxTextCtrl::OnKey (wxStyledTextEvent &WXUNUSED(event))
{
    wxMessageBox(wxT("OnKey"));
}

void vxTextCtrl::ParseLexar()
{
     SetLexarBase(this);
    //Set Lexar Based off of Input
    int StartIndex = FilePath.find_last_of('.',FilePath.length())+1;

        if(StartIndex != -1)
        {
            wxString ext = FilePath.substr(StartIndex,FilePath.length()-StartIndex);

            //C
            if(ext == _("c"))
                SetLexarAsC(this);
                
            //C++
            if(ext == _("cpp") || ext == _("h"))
                SetLexarAsCPP(this);
            
            //C#
            if(ext == _("cs"))
                SetLexarAsCS(this);
            
            //CSS
            if(ext == _("css"))
                SetLexarAsCSS(this);             

            //HLSL for XAN Shader Language
            if(ext == _("fx"))
                SetLexarAsHLSL(this);
                                
            //Java Script
            if(ext == _("js"))
                SetLexarAsJS(this);

            //Python
            if(ext == _("py"))
                SetLexarAsPython(this);

            //HTML
            if(ext == _("html") || ext == _("htm"))
                SetLexarAsHTML(this);
        }
}
