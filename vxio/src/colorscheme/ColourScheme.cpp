#include "ColourScheme.h"
#include <wx/filename.h>
#include <wx/dir.h>
#include <iostream>
#include <wx/string.h>

vxColour::vxColour()
{
    R = 255;
    G = 255;
    B = 255;
    A = 255;

    setClassName("vxColour");
    Register("R", &R);
    Register("G", &G);
    Register("B", &B);
    Register("A", &A);
    setVersion("1.0");
}

void vxColour::SetColour(wxColour Color)
{
    R = Color.Red();
    G = Color.Green();
    B = Color.Blue();
    A = Color.Alpha();
}

void vxColour::SetColour(float r, float g, float b, float a)
{
    R = r;
    G = g;
    B = b;
    A = a;
}

wxColor vxColour::TowxColour()
{
    return wxColor(R.value(), G.value(), B.value());
}

vxColour::~vxColour()
{
}

ColourScheme::ColourScheme()
{
    setClassName("ColourScheme");
    Register("Name", &Name);
    Register("Col_Main_Foreground", &Col_Main_Foreground);
    Register("Col_Main_Background", &Col_Main_Background);
    Register("Col_Main_CaretForeground", &Col_Main_CaretForeground);

    Register("Col_Main_BracketsGood", &Col_Main_BracketsGood);
    Register("Col_Main_BracketsBad", &Col_Main_BracketsBad);

    Register("Col_Margin_LineNum_Foreground", &Col_Margin_LineNum_Foreground);
    Register("Col_Margin_LineNum_Background", &Col_Margin_LineNum_Background);

    Register("Col_Margin_Fold_Background", &Col_Margin_Fold_Background);
    Register("Col_Margin_FoldArrow_Foreground", &Col_Margin_FoldArrow_Foreground);
    Register("Col_Margin_FoldArrow_Background", &Col_Margin_FoldArrow_Background);

    Register("Col_Sel_Foreground", &Col_Sel_Foreground);
    Register("Col_Sel_Background", &Col_Sel_Background);

    Register("Col_C_StringSingle", &Col_C_StringSingle);
    Register("Col_C_StringDouble", &Col_C_StringDouble);
    Register("Col_C_Preprocessor", &Col_C_Preprocessor);
    Register("Col_C_Number", &Col_C_Number);
    Register("Col_C_Char", &Col_C_Char);
    Register("Col_C_Comment", &Col_C_Comment);
    Register("Col_C_CommentLine", &Col_C_CommentLine);
    Register("Col_C_CommentDoc", &Col_C_CommentDoc);
    Register("Col_C_CommentDocKeyword", &Col_C_CommentDocKeyword);
    Register("Col_C_CommentDocKeywordError", &Col_C_CommentDocKeywordError);
    Register("Col_Main_Word", &Col_Main_Word);
    Register("Col_Main_Word2", &Col_Main_Word2);
    setVersion("1.0");

    // Set Default Name
    Name = "default";
    // FILENAME = wxT("schemes/ " + Name + ".xml");

    // Set Theme Options
    Name = "Default";
    Col_Main_Foreground.SetColour(225, 255, 255, 255);
    Col_Main_Foreground.Description = wxT("Text Foreground");

    Col_Main_Background.SetColour(39, 40, 34, 255);
    Col_Main_Background.Description = wxT("Text Background");

    Col_Main_CaretForeground.SetColour(225, 255, 255, 255);
    Col_Main_CaretForeground.Description = wxT("Caret");

    Col_Margin_LineNum_Foreground.SetColour(150, 150, 150, 255);
    Col_Margin_LineNum_Foreground.Description = wxT("Line Number Text");

    Col_Margin_LineNum_Background.SetColour(25, 25, 15, 255);
    Col_Margin_LineNum_Background.Description = wxT("Line Number Background");

    Col_Main_BracketsGood.SetColour(0, 204, 255, 255);
    Col_Main_BracketsGood.Description = wxT("Matching Brackets");

    Col_Main_BracketsBad.SetColour(255, 0, 0, 255);
    Col_Main_BracketsBad.Description = wxT("Mis-Matching Brackets");

    Col_Margin_Fold_Background.SetColour(75, 75, 75, 255);
    Col_Margin_Fold_Background.Description = wxT("Margin Fold Background");

    Col_Margin_FoldArrow_Foreground.SetColour(70, 70, 70, 255);
    Col_Margin_FoldArrow_Foreground.Description = wxT("Margin Fold Arrow");

    Col_Margin_FoldArrow_Background.SetColour(120, 120, 120, 255);
    Col_Margin_FoldArrow_Background.Description = wxT("Margin Fold Arrow Background");

    Col_Sel_Foreground.SetColour(45, 45, 45, 255);
    Col_Sel_Foreground.Description = wxT("Selection Foreground");

    Col_Sel_Background.SetColour(225, 151, 31, 255);
    Col_Sel_Background.Description = wxT("Selection Background");


    //Syntax Highliting
    Col_C_StringSingle.SetColour(230, 219, 116, 255);
    Col_C_StringSingle.Description = wxT("Single Strings");
        
    Col_C_StringDouble.SetColour(230, 219, 116, 255);
    Col_C_StringDouble.Description = wxT("Double Strings");
    
    Col_C_Preprocessor.SetColour(166, 226, 46, 255);
    Col_C_Preprocessor.Description = wxT("Preprocessors");
    
    Col_C_Number.SetColour(200, 0, 255, 255);
    Col_C_Number.Description = wxT("Numbers");
    
    Col_C_Char.SetColour(253, 151, 31, 255);
    Col_C_Char.Description = wxT("Characters");
    

    int cmnt = 115;
    Col_C_Comment.SetColour(cmnt, cmnt, cmnt, 255);
    Col_C_Comment.Description = wxT("Comment");
    
    Col_C_CommentLine.SetColour(cmnt, cmnt, cmnt, 255);
    Col_C_CommentLine.Description = wxT("Comment Line");
    
    Col_C_CommentDoc.SetColour(cmnt, cmnt, cmnt, 255);
    Col_C_CommentDoc.Description = wxT("Comment Documentation");
    
    Col_C_CommentDocKeyword.SetColour(cmnt, 255, cmnt, 255);
    Col_C_CommentDocKeyword.Description = wxT("Comment Documentation Keyword");
    
    Col_C_CommentDocKeywordError.SetColour(100, 0, 0, 255);
    Col_C_CommentDocKeywordError.Description = wxT("Comment Documentation Keyword Error");
    
    Col_Main_Word.SetColour(249, 38, 114, 255);
    Col_Main_Word.Description = wxT("Language Key Words - Set One");
    
    Col_Main_Word2.SetColour(102, 217, 239, 255);
    Col_Main_Word2.Description = wxT("Language Key Words - Set Two");
    

    SetColourList();
}

ColourScheme::~ColourScheme()
{
}

void ColourScheme::SetColourList()
{
    Colours.clear();

    Colours.push_back(&Col_Main_Foreground);
    Colours.push_back(&Col_Main_Background);
    Colours.push_back(&Col_Main_CaretForeground);
    Colours.push_back(&Col_Margin_LineNum_Foreground);
    Colours.push_back(&Col_Margin_LineNum_Background);
    Colours.push_back(&Col_Main_BracketsGood);
    Colours.push_back(&Col_Main_BracketsBad);
    Colours.push_back(&Col_Margin_Fold_Background);
    Colours.push_back(&Col_Margin_FoldArrow_Foreground);
    Colours.push_back(&Col_Margin_FoldArrow_Background);
    Colours.push_back(&Col_Sel_Foreground);
    Colours.push_back(&Col_Sel_Background);
    
    
    Colours.push_back(&Col_Main_Word);
    Colours.push_back(&Col_Main_Word2);
    
    Colours.push_back(&Col_C_StringSingle);
    Colours.push_back(&Col_C_StringDouble);
    Colours.push_back(&Col_C_Preprocessor);
    Colours.push_back(&Col_C_Number);
    Colours.push_back(&Col_C_Char);
    
    Colours.push_back(&Col_C_Comment);
    Colours.push_back(&Col_C_CommentLine);
    Colours.push_back(&Col_C_CommentDoc);
    Colours.push_back(&Col_C_CommentDocKeyword);
    Colours.push_back(&Col_C_CommentDocKeywordError);
}

void ColourScheme::Load(wxString fileName)
{
    FILENAME = fileName; // wxT("schemes/") + Name.value() + wxT(".xml");
    FILENAME.LowerCase();

    // Check if File Exits
    if(wxFileName::Exists(FILENAME)) {
        cout << "Loading Color Scheme...";
        file.Open(FILENAME);

        string tempFile = "";

        for(int i = 0; i < file.GetLineCount(); i++) {
            tempFile += file.GetLine(i);
        }

        if(Serializable::fromXML(tempFile, this)) {
            cout << "Done!" << endl;
        }
        file.Close();

        // Now Rebuild the Colour List
        //SetColourList();

    } else {
        // Check to see if the config Directory exists
        if(wxDir::Exists("schemes") == false) {
            wxDir::Make("schemes");
        }

        // Alert in the debug which file was not found
        cout << "File '" << FILENAME << "' Not Found!" << endl;

        // Now create the settings xml file in the config directory
        cout << "Creating Theme File...";
        file.Create(FILENAME);
        cout << "Done!" << endl;

        Save();
        Load(FILENAME);
    }
}

void ColourScheme::Save()
{
    // Firse Set the File Name
    FILENAME = wxT("schemes/") + Name.value() + wxT(".xml");
    FILENAME.LowerCase();

    // Check if File Exits
    if(wxFileName::Exists(FILENAME)) {
        cout << "Saving Color Scheme File '" << FILENAME << "'...";

        file.Open(FILENAME);

        // first clear it so that it's a clean save file we're dealing with
        file.Clear();

        // Add XML in
        file.AddLine(this->toXML());

        // Write the contents to the file
        file.Write();

        // Close the file writer
        file.Close();
    } else { // Check to see if the config Directory exists
        if(wxDir::Exists("schemes") == false) {
            wxDir::Make("schemes");
        }

        // Alert in the debug which file was not found
        cout << "File '" << FILENAME << "' Not Found!" << endl;

        // Now create the settings xml file in the config directory
        cout << "Creating Theme File...";
        file.Create(FILENAME);
        cout << "Done!" << endl;

        Save();
    }

    cout << "Done!" << endl;
}
