void vxTextCtrl::SetLexarAsHLSL(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_CPP);

    text->StyleSetForeground (wxSTC_C_STRING,                       m_settings->CurColSchm.Col_C_StringDouble.TowxColour());
    text->StyleSetForeground (wxSTC_C_PREPROCESSOR,      m_settings->CurColSchm.Col_C_Preprocessor.TowxColour());
    text->StyleSetForeground (wxSTC_C_NUMBER,                     m_settings->CurColSchm.Col_C_Number.TowxColour());
    text->StyleSetForeground (wxSTC_C_CHARACTER,              m_settings->CurColSchm.Col_C_StringSingle.TowxColour());
    text->StyleSetForeground (wxSTC_C_WORD,                         m_settings->CurColSchm.Col_Main_Word.TowxColour());
    text->StyleSetForeground (wxSTC_C_WORD2,                       m_settings->CurColSchm.Col_Main_Word2.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENT,                  m_settings->CurColSchm.Col_C_Comment.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENTLINE,         m_settings->CurColSchm.Col_C_CommentLine.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENTDOC,        m_settings->CurColSchm.Col_C_CommentDoc.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORD, m_settings->CurColSchm.Col_C_CommentDocKeyword.TowxColour());
    text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORDERROR, m_settings->CurColSchm.Col_C_CommentDocKeywordError.TowxColour());
    text->StyleSetBold(wxSTC_C_WORD, true);
    text->StyleSetBold(wxSTC_C_WORD2, true);
    text->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);

    wxString CppWordlist1 = wxT("VertexShader PixelShader  vs_2_0 ps_2_0 vs_3_0 ps_3_0  vs_4_0 ps_4_0 float float2 float3 float4 float4x4 Texture MinFilter MagFilter MipFilter AddressV AddressU Linear Wrap POSITION0 NORMAL0 COLOR0 TEXCOORD0 TEXCOORD1 TEXCOORD2");

    wxString CppWordlist2 = wxT("compile struct return if else rgb a z w texture sampler technique pass BLENDWEIGHT transpose mul lerp tex2D dot saturate max");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    text->SetKeyWords(1, CppWordlist2);
}
