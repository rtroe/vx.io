void vxTextCtrl::SetLexarAsHTML(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_HTML);
        text->StyleSetForeground (wxSTC_H_DOUBLESTRING,      m_settings->CurColSchm.Col_C_StringDouble.TowxColour());
        text->StyleSetForeground (wxSTC_H_SINGLESTRING,        m_settings->CurColSchm.Col_C_StringSingle.TowxColour());
        text->StyleSetForeground (wxSTC_H_ENTITY,          m_settings->CurColSchm.Col_C_Number.TowxColour());
        text->StyleSetForeground (wxSTC_H_TAG,               m_settings->CurColSchm.Col_Main_Word.TowxColour());
        text->StyleSetForeground (wxSTC_H_TAGUNKNOWN,        m_settings->CurColSchm.Col_Main_Word.TowxColour());
        text->StyleSetForeground (wxSTC_H_ATTRIBUTE,        m_settings->CurColSchm.Col_Main_Word2.TowxColour());
        text->StyleSetForeground (wxSTC_H_ATTRIBUTEUNKNOWN, m_settings->CurColSchm.Col_Main_Word2.TowxColour());
        text->StyleSetForeground (wxSTC_H_COMMENT,           m_settings->CurColSchm.Col_C_Comment.TowxColour());        
        text->StyleSetForeground (wxSTC_H_SCRIPT,           m_settings->CurColSchm.Col_C_Comment.TowxColour());
}
