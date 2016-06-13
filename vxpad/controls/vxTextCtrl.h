#ifndef TEXTCTRL_H
#define TEXTCTRL_H

#include <wx/stc/stc.h>
#include <wx/textfile.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>


//The Main Text Control for the program
class vxTextCtrl : public wxStyledTextCtrl
{
    enum
    {
        MARGIN_LINE_NUMBERS,
        MARGIN_FOLD
    };

    enum
    {
        ID_Test,
    };
    

//Methods
public:

    vxTextCtrl(wxWindow* parent, wxString filePath);
    ~vxTextCtrl();

    void Save();
/*
    void Undo();
    void Redo();
    void Cut();
    void Copy();
    void Paste();
*/
    void ParseLexar();

    void SetLexarBase(wxStyledTextCtrl* text);
    void SetLexarAsC(wxStyledTextCtrl* text);
    void SetLexarAsCPP(wxStyledTextCtrl* text);
    void SetLexarAsCS(wxStyledTextCtrl* text);
    void SetLexarAsCSS(wxStyledTextCtrl* text);
    void SetLexarAsHLSL(wxStyledTextCtrl* text);
    void SetLexarAsHTML(wxStyledTextCtrl* text);
    void SetLexarAsJS(wxStyledTextCtrl* text);
    void SetLexarAsPHP(wxStyledTextCtrl* text);
    void SetLexarAsPython(wxStyledTextCtrl* text);

    // stc
    void OnMarginClick (wxStyledTextEvent &event);
    void OnCharAdded  (wxStyledTextEvent &event);
    void OnKey  (wxStyledTextEvent &event);

//Public Variables
public:
    wxString FilePath;
    wxString FileName;
    
    
    //A flag to trigger the "Save As" the first time the file is saved.
    bool IsNewFile = true;

    DECLARE_EVENT_TABLE();
};
#endif // TEXTCTRL_H
