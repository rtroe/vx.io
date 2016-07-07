void vxTextCtrl::SetLexarAsPython(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_PYTHON);

    text->StyleSetForeground (wxSTC_P_WORD,        m_settings->CurColSchm.Col_Main_Word.TowxColour());
    text->StyleSetBold(wxSTC_P_WORD, true);

    text->StyleSetForeground (wxSTC_P_WORD2,        m_settings->CurColSchm.Col_Main_Word2.TowxColour());
    text->StyleSetBold(wxSTC_P_WORD2, true);

    text->StyleSetForeground (wxSTC_P_CHARACTER,    m_settings->CurColSchm.Col_C_StringSingle.TowxColour());
    text->StyleSetForeground (wxSTC_P_STRING,       m_settings->CurColSchm.Col_C_StringDouble.TowxColour());

    text->StyleSetForeground (wxSTC_P_COMMENTLINE,  m_settings->CurColSchm.Col_C_CommentLine.TowxColour());
    text->StyleSetForeground (wxSTC_P_COMMENTBLOCK, m_settings->CurColSchm.Col_C_CommentDoc.TowxColour());
    text->StyleSetForeground (wxSTC_P_NUMBER,       m_settings->CurColSchm.Col_C_Number.TowxColour());


    text->SetKeyWords(0, wxT("import class def for yield self and del from not while as elif global or with")
                      _T("assert    else      if        pass      yield")
                      _T("break     except    import    print")
                      _T("class     exec      in        raise")
                      _T("continue  finally   is        return ")
                      _T("def       for       lambda    try"));
    text->SetKeyWords(1, wxT("print int double float string char bpart"));
}
