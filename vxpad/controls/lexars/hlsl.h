void TextCtrl::SetLexarAsHLSL(wxStyledTextCtrl* text)
{

    SetLexarBase(text);
    text->SetLexer(wxSTC_LEX_CPP);

    text->StyleSetForeground (wxSTC_C_STRING,            wxColour(220,0, 220));
    text->StyleSetForeground (wxSTC_C_PREPROCESSOR,      wxColour(0,150,225));
    //text->StyleSetForeground (wxSTC_C_IDENTIFIER,        wxColour(40,0,60));
    text->StyleSetForeground (wxSTC_C_NUMBER,            wxColour(220,0,220));
    text->StyleSetForeground (wxSTC_C_CHARACTER,         wxColour(150,0,0));
    text->StyleSetForeground (wxSTC_C_WORD,              wxColour(255,128,0));
    text->StyleSetForeground (wxSTC_C_WORD2,             wxColour(0,190,190));
    text->StyleSetForeground (wxSTC_C_COMMENT,           wxColour(0,225,0));
    text->StyleSetForeground (wxSTC_C_COMMENTLINE,       wxColour(0,225,0));
    text->StyleSetForeground (wxSTC_C_COMMENTDOC,        wxColour(0,150,0));
    text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORD, wxColour(0,0,200));
    text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0,0,200));
    text->StyleSetBold(wxSTC_C_WORD, true);
    text->StyleSetBold(wxSTC_C_WORD2, true);
    text->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);
    text->SetCaretForeground(wxColour(225,225,225));
    text->SetSelBackground(true,wxColour(100,100,100));

    wxString CppWordlist1 = wxT("VertexShader PixelShader  vs_2_0 ps_2_0 vs_3_0 ps_3_0  vs_4_0 ps_4_0 float float2 float3 float4 float4x4 Texture MinFilter MagFilter MipFilter AddressV AddressU Linear Wrap POSITION0 NORMAL0 COLOR0 TEXCOORD0 TEXCOORD1 TEXCOORD2");

    wxString CppWordlist2 = wxT("compile struct return if else rgb a z w texture sampler technique pass BLENDWEIGHT transpose mul lerp tex2D dot saturate max");


    // a sample list of keywords, I haven't included them all to keep it short...
    text->SetKeyWords(0, CppWordlist1);
    text->SetKeyWords(1, CppWordlist2);
}
