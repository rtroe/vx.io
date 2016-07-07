

void vxTextCtrl::SetMainFont(wxString fontName, int fontSize)
{
        wxFont m_codeFont(fontSize, wxFONTFAMILY_DEFAULT,
         wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName);
    {
        int Nr;
        for (Nr = 0; Nr < wxSTC_STYLE_LASTPREDEFINED; Nr++)
            StyleSetFont (Nr, m_codeFont);
    }
}

void vxTextCtrl::SetLexarBase(wxStyledTextCtrl* text)
{
StyleClearAll();

    //wxFont m_codeFont(9, wxFONTFAMILY_ROMAN  , wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    SetMainFont(m_settings->FontName.value(), m_settings->FontSize.value());

    text->SetCaretForeground(m_settings->CurColSchm.Col_Main_CaretForeground.TowxColour());
    
    text->SetSelForeground(true, m_settings->CurColSchm.Col_Sel_Foreground.TowxColour());
    text->SetSelBackground(true, m_settings->CurColSchm.Col_Sel_Background.TowxColour());

    SetMarginWidth (MARGIN_LINE_NUMBERS, 50);
    StyleSetForeground (wxSTC_STYLE_LINENUMBER,m_settings->CurColSchm.Col_Margin_LineNum_Foreground.TowxColour());
    StyleSetBackground (wxSTC_STYLE_LINENUMBER, m_settings->CurColSchm.Col_Margin_LineNum_Background.TowxColour());
    SetMarginType (MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);

    
    // ---- Enable code folding
    SetMarginType (MARGIN_FOLD, wxSTC_MARGIN_SYMBOL);
    SetMarginWidth(MARGIN_FOLD, 15);
    SetMarginMask (MARGIN_FOLD, wxSTC_MASK_FOLDERS);
    StyleSetBackground(MARGIN_FOLD, wxColor(20, 20, 20) );
    SetMarginSensitive(MARGIN_FOLD, true);
    
    

    // Properties found from http://www.scintilla.org/SciTEDoc.html
    SetProperty (wxT("fold"),         wxT("1") );
    SetProperty (wxT("fold.comment"), wxT("1") );
    SetProperty (wxT("fold.compact"), wxT("1") );
    SetProperty (wxT("fold.html"), wxT("1") );
    SetProperty (wxT("fold.preprocessor"), wxT("1") );
    

    wxColor grey( 100, 100, 100 );
    
    
    SetFoldMarginColour(true, m_settings->CurColSchm.Col_Margin_Fold_Background.TowxColour());
    SetFoldMarginHiColour(true,m_settings->CurColSchm.Col_Margin_Fold_Background.TowxColour());
    /*
    MarkerDefine (wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
    MarkerSetForeground (wxSTC_MARKNUM_FOLDER, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDER, grey);

    MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_BOXMINUS);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPEN, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPEN, grey);

    MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_VLINE);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDERSUB, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDERSUB, grey);

    MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_BOXPLUSCONNECTED);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDEREND, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDEREND, _T("WHITE"));

    MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUSCONNECTED);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPENMID, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPENMID, _T("WHITE"));

    MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_TCORNER);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);

    MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_LCORNER);
    MarkerSetForeground (wxSTC_MARKNUM_FOLDERTAIL, grey);
    MarkerSetBackground (wxSTC_MARKNUM_FOLDERTAIL, grey);
    // ---- End of code folding part
    */
    wxColor foldFore = m_settings->CurColSchm.Col_Margin_FoldArrow_Foreground.TowxColour();
    wxColor foldBack = m_settings->CurColSchm.Col_Margin_FoldArrow_Background.TowxColour();

        // markers
    MarkerDefine (wxSTC_MARKNUM_FOLDER,                    wxSTC_MARK_BOXPLUS, foldFore, foldBack);
    MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,         wxSTC_MARK_BOXMINUS, foldFore, foldBack);
    MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,            wxSTC_MARK_VLINE,     foldBack, foldBack);
    MarkerDefine (wxSTC_MARKNUM_FOLDEREND,            wxSTC_MARK_BOXPLUSCONNECTED, foldFore, foldBack);
    MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUSCONNECTED, foldFore, foldBack);
    MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_TCORNER,     foldBack, foldBack);
    MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_LCORNER,     foldBack, foldBack);

    //MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BACKGROUND, wxColor(255,255,255, 255), wxColor(0,0,0,255));
    
    SetFoldFlags(wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);
    SetWrapMode (wxSTC_WRAP_WORD); // other choice is wxSCI_WRAP_NONE

    for (int Nr = 0; Nr < wxSTC_STYLE_MAX; Nr++)
    {
        
        StyleSetForeground (Nr, m_settings->CurColSchm.Col_Main_Foreground.TowxColour());
        StyleSetBackground (Nr, m_settings->CurColSchm.Col_Main_Background.TowxColour());
    }

// setup the colors and bold font
StyleSetBackground(wxSTC_STYLE_BRACELIGHT,  m_settings->CurColSchm.Col_Main_BracketsGood.TowxColour());//wxColour(0xff, 0xcc, 0x00));        // brace highlight
StyleSetBackground(wxSTC_STYLE_BRACEBAD,  m_settings->CurColSchm.Col_Main_BracketsBad.TowxColour());//wxColour(0xff, 0x33, 0x33));        // brace bad highlight
StyleSetBold(wxSTC_STYLE_BRACELIGHT, TRUE);
StyleSetBold(wxSTC_STYLE_BRACEBAD, TRUE);
    
    StyleSetForeground (wxSTC_STYLE_LINENUMBER, m_settings->CurColSchm.Col_Margin_LineNum_Foreground.TowxColour());
    StyleSetBackground (wxSTC_STYLE_LINENUMBER, m_settings->CurColSchm.Col_Margin_LineNum_Background.TowxColour());
}

