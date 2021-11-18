#pragma once

#include <base.h>
#include <wx/bitmap.h>
#include <string.h>
#include "SD_button_ball.h"
#include "SD_enum.h"





typedef struct BALL_NODE{
    wxBallButton* ball;
    BALL_NODE* parent;
    BALL_NODE* next;
}ball_node;


class wxBitmapBGPanel : public wxPanel
{
public:
    wxBitmap SD_Background;
    
	wxBitmapBGPanel(wxWindow *parent,
            wxBitmap Background,
            wxWindowID winid,
			RACK_TYPE type,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name);
    

    void OnPaint(wxPaintEvent & event);
    int GetBallCount();
    int GetTotalBallCount();
    void RefreshBallPosition();
	void BallCount(int action,wxBallButton* ball);
	void RackRegister(wxBitmapBGPanel* panels[2]);

	DECLARE_EVENT_TABLE();

private : 
	wxBitmapBGPanel* rack_panels[2];
    int ball_count;
    int total_ball_count;
    ball_node* BallList;
	ball_node* BallList_start;
	RACK_TYPE type;
};
