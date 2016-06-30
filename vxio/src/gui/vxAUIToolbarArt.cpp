///////////////////////////////////////////////////////////////////////////////

// Name:        src/aui/auibar.cpp
// Purpose:     wxaui: wx advanced user interface - docking window manager
// Author:      Benjamin I. Williams
// Modified by:
// Created:     2005-05-17
// Copyright:   (C) Copyright 2005-2006, Kirix Corporation, All Rights Reserved
// Licence:     wxWindows Library Licence, Version 3.1
///////////////////////////////////////////////////////////////////////////////

// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "wx/statline.h"
#include "wx/dcbuffer.h"
#include "wx/sizer.h"
#include "wx/image.h"
#include "wx/settings.h"
#include "wx/menu.h"

#include "wx/aui/auibar.h"
#include "wx/aui/framemanager.h"

#ifdef __WXMAC__
#include "wx/osx/private.h"
#endif

#include "wx/arrimpl.cpp"

#include "../../include/gui/vxAUIToolbarArt.h"

// missing wxITEM_* items
enum
{
    wxITEM_CONTROL = wxITEM_MAX,
    wxITEM_LABEL,
    wxITEM_SPACER
};

const int BUTTON_DROPDOWN_WIDTH = 10;

wxBitmap wxAuiBitmapFromBits(const unsigned char bits[], int w, int h,
                             const wxColour& color);
                             
static wxColor GetBaseColor()
{

#if defined( __WXMAC__ ) && wxOSX_USE_COCOA_OR_CARBON
    wxColor baseColour = wxColour( wxMacCreateCGColorFromHITheme(kThemeBrushToolbarBackground));
#else
    wxColor baseColour = wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE);
#endif

    // the baseColour is too pale to use as our base colour,
    // so darken it a bit --
    if ((255-baseColour.Red()) +
            (255-baseColour.Green()) +
            (255-baseColour.Blue()) < 60)
    {
        baseColour = baseColour.ChangeLightness(35);
    }

    return baseColour;
}



class ToolbarCommandCapture : public wxEvtHandler
{
public:

    ToolbarCommandCapture()
    {
        m_lastId = 0;
    }
    int GetCommandId() const
    {
        return m_lastId;
    }

    bool ProcessEvent(wxEvent& evt)
    {
        if (evt.GetEventType() == wxEVT_COMMAND_MENU_SELECTED )
        {
            m_lastId = evt.GetId();
            return true;
        }

        if (GetNextHandler())
            return GetNextHandler()->ProcessEvent(evt);

        return false;
    }

private:
    int m_lastId;
};



static const unsigned char
DISABLED_TEXT_GREY_HUE = wxColour::AlphaBlend(0, 255, 0.4);
const wxColour DISABLED_TEXT_COLOR(DISABLED_TEXT_GREY_HUE,
                                   DISABLED_TEXT_GREY_HUE,
                                   DISABLED_TEXT_GREY_HUE);

vxAuiToolbarArt::vxAuiToolbarArt()
{
    m_baseColour = GetBaseColor();

    m_flags = 0;
    m_textOrientation = wxAUI_TBTOOL_TEXT_BOTTOM;

    m_highlightColour = wxColour(255,150,0);// wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT);

    m_separatorSize = 7;
    m_gripperSize = 7;
    m_overflowSize = 16;

    wxColor darker1Colour = m_baseColour.ChangeLightness(85);
    wxColor darker2Colour = m_baseColour.ChangeLightness(75);
    wxColor darker3Colour = m_baseColour.ChangeLightness(60);
    wxColor darker4Colour = m_baseColour.ChangeLightness(50);
    wxColor darker5Colour = m_baseColour.ChangeLightness(40);

    m_gripperPen1 = wxPen(darker5Colour);
    m_gripperPen2 = wxPen(darker3Colour);
    m_gripperPen3 = *wxWHITE_PEN;

    static const unsigned char buttonDropdownBits[] = { 0xe0, 0xf1, 0xfb };
    static const unsigned char overflowBits[] = { 0x80, 0xff, 0x80, 0xc1, 0xe3, 0xf7 };

    m_buttonDropDownBmp = wxAuiBitmapFromBits(buttonDropdownBits, 5, 3,
                          *wxBLACK);
    m_disabledButtonDropDownBmp = wxAuiBitmapFromBits(
                                      buttonDropdownBits, 5, 3,
                                      wxColor(128,128,128));
    m_overflowBmp = wxAuiBitmapFromBits(overflowBits, 7, 6, *wxBLACK);
    m_disabledOverflowBmp = wxAuiBitmapFromBits(overflowBits, 7, 6, wxColor(128,128,128));

    m_font = *wxNORMAL_FONT;
}

vxAuiToolbarArt::~vxAuiToolbarArt()
{
    //m_font = *wxNORMAL_FONT;
}

//
//Added Methods
//

//Resets the colours to the default value
void vxAuiToolbarArt::ResetToDefault()
{
    m_baseColour = GetBaseColor();

    m_flags = 0;
    m_textOrientation = wxAUI_TBTOOL_TEXT_BOTTOM;

    m_highlightColour = wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT);

    m_separatorSize = 7;
    m_gripperSize = 7;
    m_overflowSize = 16;

    wxColor darker1Colour = m_baseColour.ChangeLightness(85);
    wxColor darker2Colour = m_baseColour.ChangeLightness(75);
    wxColor darker3Colour = m_baseColour.ChangeLightness(60);
    wxColor darker4Colour = m_baseColour.ChangeLightness(50);
    wxColor darker5Colour = m_baseColour.ChangeLightness(40);

    m_gripperPen1 = wxPen(darker5Colour);
    m_gripperPen2 = wxPen(darker3Colour);
    m_gripperPen3 = *wxWHITE_PEN;

    static const unsigned char buttonDropdownBits[] = { 0xe0, 0xf1, 0xfb };
    static const unsigned char overflowBits[] = { 0x80, 0xff, 0x80, 0xc1, 0xe3, 0xf7 };

    m_buttonDropDownBmp = wxAuiBitmapFromBits(buttonDropdownBits, 5, 3,
                          *wxBLACK);
    m_disabledButtonDropDownBmp = wxAuiBitmapFromBits(
                                      buttonDropdownBits, 5, 3,
                                      wxColor(128,128,128));
    m_overflowBmp = wxAuiBitmapFromBits(overflowBits, 7, 6, *wxBLACK);
    m_disabledOverflowBmp = wxAuiBitmapFromBits(overflowBits, 7, 6, wxColor(128,128,128));

    m_font = *wxNORMAL_FONT;
}

//Set Tool Bar Base colour
void vxAuiToolbarArt::SetToolBarBaseColour(wxColour baseColour)
{
    m_baseColour = baseColour;
}


//Set Highlite colour of the button
void vxAuiToolbarArt::SetButtonHighliteColour(wxColour buttonHighliteColour)
{
    m_highlightColour = buttonHighliteColour;
}






//
//Original Code from axAuiDefaultToolbarArt
//


wxAuiToolBarArt* vxAuiToolbarArt::Clone()
{
    return static_cast<wxAuiToolBarArt*>(new wxAuiDefaultToolBarArt);
}

void vxAuiToolbarArt::SetFlags(unsigned int flags)
{
    m_flags = flags;
}

void vxAuiToolbarArt::SetFont(const wxFont& font)
{
    m_font = font;
}

void vxAuiToolbarArt::SetTextOrientation(int orientation)
{
    m_textOrientation = orientation;
}

unsigned int vxAuiToolbarArt::GetFlags()
{
    return m_flags;
}

wxFont vxAuiToolbarArt::GetFont()
{
    return m_font;
}

int vxAuiToolbarArt::GetTextOrientation()
{
    return m_textOrientation;
}

void vxAuiToolbarArt::DrawBackground(
    wxDC& dc,
    wxWindow* WXUNUSED(wnd),
    const wxRect& _rect)
{

    wxRect rect = _rect;
    rect.height++;
    
    wxColour startColour = m_baseColour.ChangeLightness(105);
    wxColour endColour = m_baseColour.ChangeLightness(80);
    dc.GradientFillLinear(rect, startColour, endColour, wxSOUTH);
}

void vxAuiToolbarArt::DrawPlainBackground(wxDC& dc,
        wxWindow* WXUNUSED(wnd),
        const wxRect& _rect)
{
    wxRect rect = _rect;
    rect.height++;

    dc.SetBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));

    dc.DrawRectangle(rect.GetX() - 1, rect.GetY() - 1,
                     rect.GetWidth() + 2, rect.GetHeight() + 1);
}

void vxAuiToolbarArt::DrawLabel(
    wxDC& dc,
    wxWindow* WXUNUSED(wnd),
    const wxAuiToolBarItem& item,
    const wxRect& rect)
{
    dc.SetFont(m_font);
    dc.SetTextForeground(*wxBLACK);

    // we only care about the text height here since the text
    // will get cropped based on the width of the item
    int textWidth = 0, textHeight = 0;
    dc.GetTextExtent(wxT("ABCDHgj"), &textWidth, &textHeight);

    // set the clipping region
    wxRect clipRect = rect;
    clipRect.width -= 1;
    dc.SetClippingRegion(clipRect);

    int textX, textY;
    textX = rect.x + 1;
    textY = rect.y + (rect.height-textHeight)/2;
    dc.DrawText(item.GetLabel(), textX, textY);
    dc.DestroyClippingRegion();
}


void vxAuiToolbarArt::DrawButton(
    wxDC& dc,
    wxWindow* WXUNUSED(wnd),
    const wxAuiToolBarItem& item,
    const wxRect& rect)
{
    int textWidth = 0, textHeight = 0;

    if (m_flags & wxAUI_TB_TEXT)
    {
        dc.SetFont(m_font);

        int tx, ty;

        dc.GetTextExtent(wxT("ABCDHgj"), &tx, &textHeight);
        textWidth = 0;
        dc.GetTextExtent(item.GetLabel(), &textWidth, &ty);
    }

    int bmpX = 0, bmpY = 0;
    int textX = 0, textY = 0;

    if (m_textOrientation == wxAUI_TBTOOL_TEXT_BOTTOM)
    {
        bmpX = rect.x +
               (rect.width/2) -
               (item.GetBitmap().GetWidth()/2);

        bmpY = rect.y +
               ((rect.height-textHeight)/2) -
               (item.GetBitmap().GetHeight()/2);

        textX = rect.x + (rect.width/2) - (textWidth/2) + 1;
        textY = rect.y + rect.height - textHeight - 1;
    }
    else if (m_textOrientation == wxAUI_TBTOOL_TEXT_RIGHT)
    {
        bmpX = rect.x + 3;

        bmpY = rect.y +
               (rect.height/2) -
               (item.GetBitmap().GetHeight()/2);

        textX = bmpX + 3 + item.GetBitmap().GetWidth();
        textY = rect.y +
                (rect.height/2) -
                (textHeight/2);
    }


    if (!(item.GetState() & wxAUI_BUTTON_STATE_DISABLED))
    {
        if (item.GetState() & wxAUI_BUTTON_STATE_PRESSED)
        {
            dc.SetPen(wxPen(m_highlightColour));
            dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(150)));
            dc.DrawRectangle(rect);
        }
        else if ((item.GetState() & wxAUI_BUTTON_STATE_HOVER) || item.IsSticky())
        {
            dc.SetPen(wxPen(m_highlightColour));
            dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(100)));//original 170

            // draw an even lighter background for checked item hovers (since
            // the hover background is the same color as the check background)
            if (item.GetState() & wxAUI_BUTTON_STATE_CHECKED)
                dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(180)));

            dc.DrawRectangle(rect);
        }
        else if (item.GetState() & wxAUI_BUTTON_STATE_CHECKED)
        {
            // it's important to put this code in an else statement after the
            // hover, otherwise hovers won't draw properly for checked items
            dc.SetPen(wxPen(m_highlightColour));
            dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(170)));
            dc.DrawRectangle(rect);
        }
    }

    wxBitmap bmp;
    if (item.GetState() & wxAUI_BUTTON_STATE_DISABLED)
        bmp = item.GetDisabledBitmap();
    else
        bmp = item.GetBitmap();

    if ( bmp.IsOk() )
        dc.DrawBitmap(bmp, bmpX, bmpY, true);

    // set the item's text color based on if it is disabled
    dc.SetTextForeground(*wxBLACK);
    if (item.GetState() & wxAUI_BUTTON_STATE_DISABLED)
        dc.SetTextForeground(DISABLED_TEXT_COLOR);

    if ( (m_flags & wxAUI_TB_TEXT) && !item.GetLabel().empty() )
    {
        dc.DrawText(item.GetLabel(), textX, textY);
    }
}


void vxAuiToolbarArt::DrawDropDownButton(
    wxDC& dc,
    wxWindow* WXUNUSED(wnd),
    const wxAuiToolBarItem& item,
    const wxRect& rect)
{
    int textWidth = 0, textHeight = 0, textX = 0, textY = 0;
    int bmpX = 0, bmpY = 0, dropBmpX = 0, dropBmpY = 0;

    wxRect buttonRect = wxRect(rect.x,
                               rect.y,
                               rect.width-BUTTON_DROPDOWN_WIDTH,
                               rect.height);
    wxRect dropDownRect = wxRect(rect.x+rect.width-BUTTON_DROPDOWN_WIDTH-1,
                                 rect.y,
                                 BUTTON_DROPDOWN_WIDTH+1,
                                 rect.height);

    if (m_flags & wxAUI_TB_TEXT)
    {
        dc.SetFont(m_font);

        int tx, ty;
        if (m_flags & wxAUI_TB_TEXT)
        {
            dc.GetTextExtent(wxT("ABCDHgj"), &tx, &textHeight);
            textWidth = 0;
        }

        dc.GetTextExtent(item.GetLabel(), &textWidth, &ty);
    }



    dropBmpX = dropDownRect.x +
               (dropDownRect.width/2) -
               (m_buttonDropDownBmp.GetWidth()/2);
    dropBmpY = dropDownRect.y +
               (dropDownRect.height/2) -
               (m_buttonDropDownBmp.GetHeight()/2);


    if (m_textOrientation == wxAUI_TBTOOL_TEXT_BOTTOM)
    {
        bmpX = buttonRect.x +
               (buttonRect.width/2) -
               (item.GetBitmap().GetWidth()/2);
        bmpY = buttonRect.y +
               ((buttonRect.height-textHeight)/2) -
               (item.GetBitmap().GetHeight()/2);

        textX = rect.x + (rect.width/2) - (textWidth/2) + 1;
        textY = rect.y + rect.height - textHeight - 1;
    }
    else if (m_textOrientation == wxAUI_TBTOOL_TEXT_RIGHT)
    {
        bmpX = rect.x + 3;

        bmpY = rect.y +
               (rect.height/2) -
               (item.GetBitmap().GetHeight()/2);

        textX = bmpX + 3 + item.GetBitmap().GetWidth();
        textY = rect.y +
                (rect.height/2) -
                (textHeight/2);
    }


    if (item.GetState() & wxAUI_BUTTON_STATE_PRESSED)
    {
        dc.SetPen(wxPen(m_highlightColour));
        dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(140)));
        dc.DrawRectangle(buttonRect);

        dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(170)));
        dc.DrawRectangle(dropDownRect);
    }
    else if (item.GetState() & wxAUI_BUTTON_STATE_HOVER ||
             item.IsSticky())
    {
        dc.SetPen(wxPen(m_highlightColour));
        dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(100)));
        dc.DrawRectangle(buttonRect);
        dc.DrawRectangle(dropDownRect);
    }
    else if (item.GetState() & wxAUI_BUTTON_STATE_CHECKED)
    {
        // Notice that this branch must come after the hover one to ensure the
        // correct appearance when the mouse hovers over a checked item.m_
        dc.SetPen(wxPen(m_highlightColour));
        dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(170)));
        dc.DrawRectangle(buttonRect);
        dc.DrawRectangle(dropDownRect);
    }

    wxBitmap bmp;
    wxBitmap dropbmp;
    if (item.GetState() & wxAUI_BUTTON_STATE_DISABLED)
    {
        bmp = item.GetDisabledBitmap();
        dropbmp = m_disabledButtonDropDownBmp;
    }
    else
    {
        bmp = item.GetBitmap();
        dropbmp = m_buttonDropDownBmp;
    }

    if (!bmp.IsOk())
        return;

    dc.DrawBitmap(bmp, bmpX, bmpY, true);
    dc.DrawBitmap(dropbmp, dropBmpX, dropBmpY, true);

    // set the item's text color based on if it is disabled
    dc.SetTextForeground(*wxBLACK);
    if (item.GetState() & wxAUI_BUTTON_STATE_DISABLED)
        dc.SetTextForeground(DISABLED_TEXT_COLOR);

    if ( (m_flags & wxAUI_TB_TEXT) && !item.GetLabel().empty() )
    {
        dc.DrawText(item.GetLabel(), textX, textY);
    }
}

void vxAuiToolbarArt::DrawControlLabel(
    wxDC& dc,
    wxWindow* WXUNUSED(wnd),
    const wxAuiToolBarItem& item,
    const wxRect& rect)
{
    if (!(m_flags & wxAUI_TB_TEXT))
        return;

    if (m_textOrientation != wxAUI_TBTOOL_TEXT_BOTTOM)
        return;

    int textX = 0, textY = 0;
    int textWidth = 0, textHeight = 0;

    dc.SetFont(m_font);

    int tx, ty;
    if (m_flags & wxAUI_TB_TEXT)
    {
        dc.GetTextExtent(wxT("ABCDHgj"), &tx, &textHeight);
        textWidth = 0;
    }

    dc.GetTextExtent(item.GetLabel(), &textWidth, &ty);

    // don't draw the label if it is wider than the item width
    if (textWidth > rect.width)
        return;

    // set the label's text color
    dc.SetTextForeground(*wxBLACK);

    textX = rect.x + (rect.width/2) - (textWidth/2) + 1;
    textY = rect.y + rect.height - textHeight - 1;

    if ( (m_flags & wxAUI_TB_TEXT) && !item.GetLabel().empty() )
    {
        dc.DrawText(item.GetLabel(), textX, textY);
    }
}

wxSize vxAuiToolbarArt::GetLabelSize(
    wxDC& dc,
    wxWindow* WXUNUSED(wnd),
    const wxAuiToolBarItem& item)
{
    dc.SetFont(m_font);

    // get label's height
    int width = 0, height = 0;
    dc.GetTextExtent(wxT("ABCDHgj"), &width, &height);

    // get item's width
    width = item.GetMinSize().GetWidth();

    if (width == -1)
    {
        // no width specified, measure the text ourselves
        width = dc.GetTextExtent(item.GetLabel()).GetX();
    }

    return wxSize(width, height);
}

wxSize vxAuiToolbarArt::GetToolSize(
    wxDC& dc,
    wxWindow* WXUNUSED(wnd),
    const wxAuiToolBarItem& item)
{
    if (!item.GetBitmap().IsOk() && !(m_flags & wxAUI_TB_TEXT))
        return wxSize(16,16);

    int width = item.GetBitmap().GetWidth();
    int height = item.GetBitmap().GetHeight();

    if (m_flags & wxAUI_TB_TEXT)
    {
        dc.SetFont(m_font);
        int tx, ty;

        if (m_textOrientation == wxAUI_TBTOOL_TEXT_BOTTOM)
        {
            dc.GetTextExtent(wxT("ABCDHgj"), &tx, &ty);
            height += ty;

            if ( !item.GetLabel().empty() )
            {
                dc.GetTextExtent(item.GetLabel(), &tx, &ty);
                width = wxMax(width, tx+6);
            }
        }
        else if ( m_textOrientation == wxAUI_TBTOOL_TEXT_RIGHT &&
                  !item.GetLabel().empty() )
        {
            width += 3; // space between left border and bitmap
            width += 3; // space between bitmap and text

            if ( !item.GetLabel().empty() )
            {
                dc.GetTextExtent(item.GetLabel(), &tx, &ty);
                width += tx;
                height = wxMax(height, ty);
            }
        }
    }

    // if the tool has a dropdown button, add it to the width
    if (item.HasDropDown())
        width += (BUTTON_DROPDOWN_WIDTH+4);

    return wxSize(width, height);
}

void vxAuiToolbarArt::DrawSeparator(
    wxDC& dc,
    wxWindow* WXUNUSED(wnd),
    const wxRect& _rect)
{
    bool horizontal = true;
    if (m_flags & wxAUI_TB_VERTICAL)
        horizontal = false;

    wxRect rect = _rect;

    if (horizontal)
    {
        rect.x += (rect.width/2);
        rect.width = 1;
        int new_height = (rect.height*3)/4;
        rect.y += (rect.height/2) - (new_height/2);
        rect.height = new_height;
    }
    else
    {
        rect.y += (rect.height/2);
        rect.height = 1;
        int new_width = (rect.width*3)/4;
        rect.x += (rect.width/2) - (new_width/2);
        rect.width = new_width;
    }

    wxColour startColour = m_baseColour.ChangeLightness(80);
    wxColour endColour = m_baseColour.ChangeLightness(80);
    dc.GradientFillLinear(rect, startColour, endColour, horizontal ? wxSOUTH : wxEAST);
}

void vxAuiToolbarArt::DrawGripper(wxDC& dc,
                                 wxWindow* WXUNUSED(wnd),
                                 const wxRect& rect)
{
    int i = 0;
    while (1)
    {
        int x, y;

        if (m_flags & wxAUI_TB_VERTICAL)
        {
            x = rect.x + (i*4) + 5;
            y = rect.y + 3;
            if (x > rect.GetWidth()-5)
                break;
        }
        else
        {
            x = rect.x + 3;
            y = rect.y + (i*4) + 5;
            if (y > rect.GetHeight()-5)
                break;
        }

        dc.SetPen(m_gripperPen1);
        dc.DrawPoint(x, y);
        dc.SetPen(m_gripperPen2);
        dc.DrawPoint(x, y+1);
        dc.DrawPoint(x+1, y);
        dc.SetPen(m_gripperPen3);
        dc.DrawPoint(x+2, y+1);
        dc.DrawPoint(x+2, y+2);
        dc.DrawPoint(x+1, y+2);

        i++;
    }

}

void vxAuiToolbarArt::DrawOverflowButton(wxDC& dc,
                                        wxWindow* /*wnd*/,
                                        const wxRect& rect,
                                        int state)
{
    if (state & wxAUI_BUTTON_STATE_HOVER ||
            state & wxAUI_BUTTON_STATE_PRESSED)
    {
        wxColor light_gray_bg = m_highlightColour.ChangeLightness(170);

        if (m_flags & wxAUI_TB_VERTICAL)
        {
            dc.SetPen(wxPen(m_highlightColour));
            dc.DrawLine(rect.x, rect.y, rect.x+rect.width, rect.y);
            dc.SetPen(wxPen(light_gray_bg));
            dc.SetBrush(wxBrush(light_gray_bg));
            dc.DrawRectangle(rect.x, rect.y+1, rect.width, rect.height);
        }
        else
        {
            dc.SetPen(wxPen(m_highlightColour));
            dc.DrawLine(rect.x, rect.y, rect.x, rect.y+rect.height);
            dc.SetPen(wxPen(light_gray_bg));
            dc.SetBrush(wxBrush(light_gray_bg));
            dc.DrawRectangle(rect.x+1, rect.y, rect.width, rect.height);
        }
    }

    int x = rect.x+1+(rect.width-m_overflowBmp.GetWidth())/2;
    int y = rect.y+1+(rect.height-m_overflowBmp.GetHeight())/2;
    dc.DrawBitmap(m_overflowBmp, x, y, true);
}

int vxAuiToolbarArt::GetElementSize(int element_id)
{
    switch (element_id)
    {
    case wxAUI_TBART_SEPARATOR_SIZE:
        return m_separatorSize;
    case wxAUI_TBART_GRIPPER_SIZE:
        return m_gripperSize;
    case wxAUI_TBART_OVERFLOW_SIZE:
        return m_overflowSize;
    default:
        return 0;
    }
}

void vxAuiToolbarArt::SetElementSize(int element_id, int size)
{
    switch (element_id)
    {
    case wxAUI_TBART_SEPARATOR_SIZE:
        m_separatorSize = size;
        break;
    case wxAUI_TBART_GRIPPER_SIZE:
        m_gripperSize = size;
        break;
    case wxAUI_TBART_OVERFLOW_SIZE:
        m_overflowSize = size;
        break;
    }
}

int vxAuiToolbarArt::ShowDropDown(wxWindow* wnd,
                                 const wxAuiToolBarItemArray& items)
{
    wxMenu menuPopup;

    size_t items_added = 0;

    size_t i, count = items.GetCount();
    for (i = 0; i < count; ++i)
    {
        wxAuiToolBarItem& item = items.Item(i);

        if (item.GetKind() == wxITEM_NORMAL)
        {
            wxString text = item.GetShortHelp();
            if (text.empty())
                text = item.GetLabel();

            if (text.empty())
                text = wxT(" ");

            wxMenuItem* m =  new wxMenuItem(&menuPopup, item.GetId(), text, item.GetShortHelp());

            m->SetBitmap(item.GetBitmap());
            menuPopup.Append(m);
            items_added++;
        }
        else if (item.GetKind() == wxITEM_SEPARATOR)
        {
            if (items_added > 0)
                menuPopup.AppendSeparator();
        }
    }

    // find out where to put the popup menu of window items
    wxPoint pt = ::wxGetMousePosition();
    pt = wnd->ScreenToClient(pt);

    // find out the screen coordinate at the bottom of the tab ctrl
    wxRect cli_rect = wnd->GetClientRect();
    pt.y = cli_rect.y + cli_rect.height;

    ToolbarCommandCapture* cc = new ToolbarCommandCapture;
    wnd->PushEventHandler(cc);
    wnd->PopupMenu(&menuPopup, pt);
    int command = cc->GetCommandId();
    wnd->PopEventHandler(true);

    return command;
}




static wxOrientation GetOrientation(long& style)
{
    switch (style & wxAUI_ORIENTATION_MASK)
    {
    case wxAUI_TB_HORIZONTAL:
        return wxHORIZONTAL;
    case wxAUI_TB_VERTICAL:
        return wxVERTICAL;
    default:
        wxFAIL_MSG("toolbar cannot be locked in both horizontal and vertical orientations (maybe no lock was intended?)");
    // fall through
    case 0:
        return wxBOTH;
    }
}
