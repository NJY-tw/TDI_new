#pragma once

#include <base.h>
#include <wx/bitmap.h>
#include <string.h>
#include "SD_enum.h"


// #ifndef (_BALL_BUTTON_DEFINITION_)
// #define (_BALL_BUTTON_DEFINITION_)

class wxBallButton : public wxButton
{
	
	
	
public:
	wxBallButton(wxWindow * parent, BALL_NUM winid,
		wxBitmap normal, wxBitmap pushed, wxPoint pos,wxPanel* panel);

	

	void OnMouseDown(wxMouseEvent & event);
	void OnMouseUp(wxMouseEvent & event);
	void OnPaint(wxPaintEvent & event);
	void OnDoubleClick(wxMouseEvent & event);
	void Motion(wxMouseEvent & event);
	bool StateFinished();
	void SetFinishedState();
	
	int priority;
	int deadline;
	// string title;
	// string content;
	wxPanel* ball_panel;
    wxBitmap pic_one;
	wxBitmap pic_two;
	wxCoord pos_x;
	wxCoord pos_y;
    int index; 
	DECLARE_EVENT_TABLE()
	//as the ball number of picture
    // string title;
    // string content;

private :
	//int dist_board;
	// int dist_x=60;
    
	int clicked_flag;
	bool motion_flag;
    bool finished;
};
//#endif