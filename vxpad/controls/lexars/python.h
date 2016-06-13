void vxTextCtrl::SetLexarAsPython(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_PYTHON);

    text->StyleSetForeground (wxSTC_P_WORD,         wxColour(0,170,170));
    text->StyleSetBold(wxSTC_P_WORD, true);

    text->StyleSetForeground (wxSTC_P_WORD2,        wxColour(255,128,0));
    text->StyleSetBold(wxSTC_P_WORD2, true);

    text->StyleSetForeground (wxSTC_P_CHARACTER,    wxColour(240,0,240));
    text->StyleSetForeground (wxSTC_P_STRING,       wxColour(240,0,240));

    text->StyleSetForeground (wxSTC_P_COMMENTLINE,  wxColour(0,255,0));
    text->StyleSetForeground (wxSTC_P_COMMENTBLOCK, wxColour(0,255,0));

    text->StyleSetForeground (wxSTC_P_NUMBER,       wxColour(0,210,210));


    text->SetKeyWords(0, wxT("import class def for yield self and del from not while as elif global or with")
                      _T("assert    else      if        pass      yield")
                      _T("break     except    import    print")
                      _T("class     exec      in        raise")
                      _T("continue  finally   is        return ")
                      _T("def       for       lambda    try"));
    text->SetKeyWords(1, wxT("print int double float string char bpart"));
}
