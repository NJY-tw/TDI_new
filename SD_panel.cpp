#include "SD_panel.h"


BEGIN_EVENT_TABLE(wxBitmapBGPanel, wxPanel)
EVT_PAINT(wxBitmapBGPanel::OnPaint)
END_EVENT_TABLE()


wxBitmapBGPanel::wxBitmapBGPanel(wxWindow *parent, wxBitmap Background, wxWindowID winid = wxID_ANY,RACK_TYPE typeN = TYPE_NONE, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER, const wxString& name = wxASCII_STR(wxPanelNameStr)):
            wxPanel(parent, winid , pos, size, style, name), 
            SD_Background(Background),type(typeN),BallList(nullptr),BallList_start(nullptr),ball_count(0)
{

}



void wxBitmapBGPanel::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);
	dc.DrawBitmap(SD_Background,0,0,false);
}


int wxBitmapBGPanel::GetBallCount()
{
    return ball_count;
}

int wxBitmapBGPanel::GetTotalBallCount()
{
    return total_ball_count;
}



void wxBitmapBGPanel::BallCount(int action,wxBallButton* ball){
    if (action!=0)
    {
        ball_count+=1;
        if(action==2)
            total_ball_count+=1;
        if(BallList==nullptr){
            BallList = new ball_node;
            BallList->parent = nullptr;
            BallList->next = nullptr;
            BallList->ball = ball;
            BallList_start = BallList;
        }
        else{
            BallList->next = new ball_node;
            //BallList->parent = BallList;
            BallList->next->parent = BallList;
            BallList = BallList->next;
            BallList->next = nullptr;
            BallList->ball = ball;
        }
    }
    else
    {
        ball_count-=1;

        if(ball_count==0){
            BallList_start = nullptr;
            BallList = nullptr;
        }
        else{
            ball_node* ptr = BallList_start;
            while((ptr->ball)!=ball){
                ptr = ptr->next;
            }

            if(ptr==BallList_start){
                BallList_start = ptr->next;
                ptr->next->parent = nullptr;
            }
            if(ptr==BallList)
            {
                BallList = ptr->parent;
            }
                    
            if(ptr->parent!=nullptr)
                ptr->parent->next = ptr->next;
            if(ptr->next!=nullptr)
                ptr->next->parent = ptr->parent;
            
        }

        
    }
        

    
}

void wxBitmapBGPanel::RackRegister(wxBitmapBGPanel* panels[2])
{
    rack_panels[0] = panels[0];
    rack_panels[1] = panels[1];
}

void wxBitmapBGPanel::RefreshBallPosition()
{

    ball_node* ptr = BallList_start;
    int number =0;

    if(type==TYPE_OPEN)
    {
        while(ptr!=nullptr)
        {
            if((ptr->ball->StateFinished()))
            {
                ptr->ball->ball_panel->Reparent(rack_panels[1]);
                
                rack_panels[1]->BallCount(1,ptr->ball);
                BallCount(0,ptr->ball);
                //ptr->ball->SetFinishedState();
            }
            else
            {
                (ptr->ball)->ball_panel->SetPosition(wxPoint(709-(60*number),3));
                number+=1;
            }
            ptr = ptr->next;
        }  
        
        //(ptr->ball)->ball_panel->Reparent(rack_panels[1]);
    }
    
    if(type==TYPE_FINISHED)
    {
        while(ptr!=nullptr)
        {
            if(!(ptr->ball->StateFinished()))
            {
                ptr->ball->ball_panel->Reparent(rack_panels[0]);
                
                rack_panels[0]->BallCount(1,ptr->ball);
                BallCount(0,ptr->ball);
                //ptr->ball->SetFinishedState();
            }
            else
            {
                (ptr->ball)->ball_panel->SetPosition(wxPoint(709-(60*number),3));
                number+=1;
            }
            ptr = ptr->next;
        }
    }
        
}