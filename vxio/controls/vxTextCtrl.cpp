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
    EVT_CHAR( vxTextCtrl::OnKey )
END_EVENT_TABLE()

vxTextCtrl::vxTextCtrl(wxWindow* parent, wxString filePath, Settings* sttngs) : wxStyledTextCtrl(parent, wxID_ANY, wxDefaultPosition, wxSize(650,175))
{

        //this->AutoCompShow()
    //Set the File Path
    FilePath = filePath;
    
    //Set Settings
    m_settings = sttngs;

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
   
      words.push_back("private");
      words.push_back("public");
      words.push_back("float");
      words.push_back("protected");
      this->AutoComplete(words);

    
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
    //this->AutoCompShow(4, wxT("private  protected  public float"));
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

void vxTextCtrl::OnKey (wxKeyEvent &event)
{
        //std::cout<<event.GetKeyCode()<<std::endl;
        //event.GetKeyCode()
    //this->AutoCompSetSeparator(63);
    if (event.GetKeyCode() == 32 && event.ControlDown() && !this->AutoCompActive()) {
        //std::cout<<"Show"<<std::endl;
        this->AutoCompSetIgnoreCase(false);
        this->AutoCompShow(3, wxT("private float protected public int char string "));
    }
    else {
    event.Skip();
    }
    //wxMessageBox(wxT("OnKey"));
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
