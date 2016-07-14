#ifndef COLOURSCHEME_H
#define COLOURSCHEME_H
#include <wx/textfile.h>

#include "../../lib/xmls/XMLSerialization.h"
#include <wx/colour.h>
#include <vector>

using namespace xmls;

class vxColour : public Serializable
{
public:
    vxColour();
    ~vxColour();
    
   void SetColour(float,float,float,float);
   void SetColour(wxColour);
   //Returns a wxColor object of this vxColor.
   wxColor TowxColour();
   
   //A Description of what this colour represents
   wxString Description;
    
    xFloat R;
	xFloat G;
	xFloat B;
	xFloat A;
};



class ColourScheme : public Serializable
{
public:
    ColourScheme();
    ~ColourScheme();
    
    wxTextFile file;
    void Save();
    void Load(wxString);
    
    //Collection of Colour Settings
     std::vector<vxColour*>  Colours;
     void SetColourList();
    
    xString Name;
    vxColour Col_Main_Background;
    vxColour Col_Main_Foreground;
    
    
    vxColour Col_Main_BracketsGood;
    vxColour Col_Main_BracketsBad;
    
    vxColour Col_Margin_LineNum_Foreground;
    vxColour Col_Margin_LineNum_Background;
    vxColour Col_Margin_Fold_Background;
    vxColour Col_Margin_FoldArrow_Foreground;
    vxColour Col_Margin_FoldArrow_Background;
    
    
    
    vxColour Col_Sel_Foreground;
    vxColour Col_Sel_Background;
    
    vxColour Col_Main_CaretForeground;
	vxColour Col_C_StringSingle;
	vxColour Col_C_StringDouble;
	vxColour Col_C_Preprocessor;
	vxColour Col_C_Number;
	vxColour Col_C_Char;
	vxColour Col_C_Comment;
	vxColour Col_C_CommentLine;
	vxColour Col_C_CommentDoc;
	vxColour Col_C_CommentDocKeyword;
	vxColour Col_C_CommentDocKeywordError;
	vxColour Col_Main_Word;
	vxColour Col_Main_Word2;

protected:
    wxString FILENAME;
};

#endif // COLOURSCHEME_H
