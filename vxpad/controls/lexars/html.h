void vxTextCtrl::SetLexarAsHTML(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_HTML);
        text->StyleSetForeground (wxSTC_H_DOUBLESTRING,      wxColour(220,0, 220));
        text->StyleSetForeground (wxSTC_H_SINGLESTRING,        wxColour(220,0, 220));
        text->StyleSetForeground (wxSTC_H_ENTITY,          wxColour(0,190,190));
        text->StyleSetForeground (wxSTC_H_TAG,               wxColour(255,128,0));
        text->StyleSetForeground (wxSTC_H_TAGUNKNOWN,        wxColour(255,128,0));
        text->StyleSetForeground (wxSTC_H_ATTRIBUTE,        wxColour(0,190,190));
        text->StyleSetForeground (wxSTC_H_ATTRIBUTEUNKNOWN, wxColour(0,190,255));
        text->StyleSetForeground (wxSTC_H_COMMENT,            wxColour(0,225,0));
}
