#include <base.h>
#include <wx/bitmap.h>
#include "SD_panel.h"
#include "SD_enum.h"






class wxBitmappedButton : public wxButton
{
	wxBitmap pic_one;
	wxBitmap pic_two;
	wxBitmap pic_three;
	wxCoord pos_x;
	wxCoord pos_y;
	
	
public:
	wxBitmappedButton(wxWindow * parent, wxWindowID winid, BUTTON_TYPE typeN,
		wxBitmap normal, wxBitmap pushed, wxPoint pos, wxBitmapBGPanel* panels_c[2]);

	wxBitmappedButton(wxWindow * parent, wxWindowID winid, BUTTON_TYPE typeN,
		wxBitmap pic_one, wxBitmap pic_two,wxBitmap pic_three, wxPoint pos);
	DECLARE_EVENT_TABLE()

	void OnMouseDown(wxMouseEvent & event);
	void OnMouseUp(wxMouseEvent & event);
	void OnPaint(wxPaintEvent & event);
	void OnDoubleClick(wxMouseEvent & event);
	void Motion(wxMouseEvent & event);
	void BallCreate();

	
	
	

protected :
	//int dist_board;
	// int dist_x=60;
    
	int clicked_flag;
	bool motion_flag;
	BUTTON_TYPE type;
	wxBitmapBGPanel* cling_panels[2];
	

};





