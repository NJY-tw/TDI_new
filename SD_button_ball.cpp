#include "SD_button_ball.h"



BEGIN_EVENT_TABLE(wxBallButton, wxButton)
EVT_LEFT_DOWN(wxBallButton::OnMouseDown)
EVT_LEFT_UP(wxBallButton::OnMouseUp)
EVT_LEFT_DCLICK(wxBallButton::OnDoubleClick)
EVT_ENTER_WINDOW(wxBallButton::Motion)
EVT_LEAVE_WINDOW(wxBallButton::Motion)
EVT_PAINT(wxBallButton::OnPaint)
END_EVENT_TABLE()



wxBallButton::wxBallButton(wxWindow * parent, BALL_NUM winid,
									 wxBitmap normal, wxBitmap pushed, wxPoint pos,wxPanel* panel)
									 : wxButton(parent, winid, wxEmptyString, pos),
									 clicked_flag(0),
									 motion_flag(false),
									 pic_one(normal), pic_two(pushed),
									 ball_panel(panel),
									 finished(false)							
{
	
	SetSize(pic_one.GetWidth(), pic_one.GetHeight());
	pos_x = pos.x;
	pos_y = pos.y;
}


void wxBallButton::OnMouseDown(wxMouseEvent & event)
{
	
	
	clicked_flag = (clicked_flag==1)?0:1;
	Refresh();
			
	
	
}

void wxBallButton::OnMouseUp(wxMouseEvent & event)
{
	
	//Refresh();
			
}

void wxBallButton::OnDoubleClick(wxMouseEvent & event)
{

	finished = (finished==true)?false:true;
	Refresh();
}

void wxBallButton::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	//m_IsPushed ? dc.DrawBitmap(m_Pushed,(nor_width-push_width)/2,(nor_height-push_height)/2,true):dc.DrawBitmap(m_Normal,0,0,true);
	//No Refresh should be used in OnPaint !!
	
	clicked_flag ? dc.DrawBitmap(pic_two,pos_x,pos_y,false):dc.DrawBitmap(pic_one,pos_x,pos_y,false);
	if(!clicked_flag){
		motion_flag ? dc.DrawBitmap(pic_two,pos_x,pos_y,false):dc.DrawBitmap(pic_one,pos_x,pos_y,false);
	}
			
			
	
}

void wxBallButton::Motion(wxMouseEvent & event)
{
	if(event.Entering())
		motion_flag = true;
	if(event.Leaving())
		motion_flag = false;
}	

bool wxBallButton::StateFinished()
{
	return finished;
}

void wxBallButton::SetFinishedState()
{
	finished = (finished==true)?false:true;
}