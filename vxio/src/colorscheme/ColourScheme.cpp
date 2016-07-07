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
        
    //Set Default Name
    Name = "default";
    //FILENAME = wxT("schemes/ " + Name + ".xml");
}

ColourScheme::~ColourScheme()
{
    
}


void ColourScheme::Load(wxString fileName)
{    
    FILENAME = fileName;//wxT("schemes/") + Name.value() + wxT(".xml");
    FILENAME.LowerCase();
    
    //Check if File Exits
    if(wxFileName::Exists(FILENAME))
    {
        cout<<"Loading Color Scheme...";
        file.Open(FILENAME);
        
        string tempFile = "";
        
        for(int i = 0; i < file.GetLineCount(); i++)
        {
            tempFile += file.GetLine(i);
        }
        
     if (Serializable::fromXML(tempFile, this))
	{
        cout<<"Done!"<<endl;
    }
        file.Close();
    }
    else
    {
        //Check to see if the config Directory exists
        if(wxDir::Exists("schemes") == false)
        {
            wxDir::Make("schemes");
        }
        
        //Alert in the debug which file was not found
        cout<<"File '"<<FILENAME<<"' Not Found!"<<endl;
        
        //Now create the settings xml file in the config directory
        cout<<"Creating Theme File...";
        file.Create(FILENAME);
        cout<<"Done!"<<endl;
        
        Save();
        Load(FILENAME);
    }
}

void ColourScheme::Save()
{   
    // Firse Set the File Name
    FILENAME = wxT("schemes/") + Name.value() + wxT(".xml");
    FILENAME.LowerCase();
    
    //Check if File Exits
    if(wxFileName::Exists(FILENAME))
    {
    cout<<"Saving Color Scheme File '"<<FILENAME<<"'...";
    
        file.Open(FILENAME);
        
        //first clear it so that it's a clean save file we're dealing with
        file.Clear();
        
        //Add XML in
        file.AddLine(this->toXML());
        
        //Write the contents to the file
        file.Write();
        
        //Close the file writer
        file.Close();   
    }
    else
    {        //Check to see if the config Directory exists
        if(wxDir::Exists("schemes") == false)
        {
            wxDir::Make("schemes");
        }
        
        //Alert in the debug which file was not found
        cout<<"File '"<<FILENAME<<"' Not Found!"<<endl;
        
        //Now create the settings xml file in the config directory
        cout<<"Creating Theme File...";
        file.Create(FILENAME);
        cout<<"Done!"<<endl;
        
        Save();
    }
    
    cout<<"Done!"<<endl;
}

