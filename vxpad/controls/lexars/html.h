void vxTextCtrl::SetLexarAsHTML(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_HTML);
        text->StyleSetForeground (wxSTC_H_DOUBLESTRING,     wxColour(255,0,0));
        text->StyleSetForeground (wxSTC_H_SINGLESTRING,     wxColour(255,0,0));
        text->StyleSetForeground (wxSTC_H_ENTITY,           wxColour(255,0,0));
        text->StyleSetForeground (wxSTC_H_TAG,              wxColour(0,150,0));
        text->StyleSetForeground (wxSTC_H_TAGUNKNOWN,       wxColour(0,150,0));
        text->StyleSetForeground (wxSTC_H_ATTRIBUTE,        wxColour(0,0,150));
        text->StyleSetForeground (wxSTC_H_ATTRIBUTEUNKNOWN, wxColour(0,0,150));
        text->StyleSetForeground (wxSTC_H_COMMENT,          wxColour(150,150,150));
}
