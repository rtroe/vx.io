#ifndef TEXTCTRL_H
#define TEXTCTRL_H

#include <wx/stc/stc.h>
#include <wx/textfile.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>


//The Main Text Control for the program
class TextCtrl : public wxStyledTextCtrl
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

    TextCtrl(wxWindow* parent, wxString filePath);
    ~TextCtrl();

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
    void SetLexarAsCPP(wxStyledTextCtrl* text);
    void SetLexarAsHLSL(wxStyledTextCtrl* text);
    void SetLexarAsHTML(wxStyledTextCtrl* text);
    void SetLexarAsNASTRAN(wxStyledTextCtrl* text);
    void SetLexarAsPython(wxStyledTextCtrl* text);

    // stc
    void OnMarginClick (wxStyledTextEvent &event);
    void OnCharAdded  (wxStyledTextEvent &event);
    void OnKey  (wxStyledTextEvent &event);

//Public Variables
public:
    wxString FilePath;
    wxString FileName;

    DECLARE_EVENT_TABLE();
};
#endif // TEXTCTRL_H
