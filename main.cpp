// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <base.h>

#include <wx/window.h>
#include <wx/bitmap.h>
#include <wx/timer.h>

/*self define header*/
#include <SD_button.h>
#include <SD_colour.h>
#include <SD_panel.h>
#include "SD_enum.h"

enum 
{
    ID_Hello=0,
    ID_BUTTON_NEW,
    ID_BUTTON_SAVE,
    ID_BUTTON_MODE,
    ID_BASIC,
    ID_TITLE,
    ID_TIMER,
    ID_RACK,
    ID_TEXT,
    ID_PANEL_NEW,
    ID_PANEL_SAVE,
    ID_PANEL_MODE
};

//#include <wx/wxShapedWindow.h>

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    // wxImage BG;
    

private:
    //Set the event corresponding behavior
    wxTimer m_timer;
    wxBitmapBGPanel* panel_racks[2];
    
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);

    
    wxDECLARE_EVENT_TABLE();
};



//bind the ID number with the behavior
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_TIMER(ID_TIMER, MyFrame::OnTimer)
    EVT_PAINT(MyFrame::OnPaint)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    //[init image handlers]
    wxInitAllImageHandlers();
    //[load background]
    
    // HeapSize
    // HEAP_GROWABLE;
    

    MyFrame *frame = new MyFrame( "TDI", wxPoint(0, 0), wxSize(940, 580));
    frame->Show( true );

    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size),
        m_timer(this,ID_TIMER)
        
{
    
    //[default frame]
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Author\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "TDI sorts your To Do Items !" );
    
    
    //[create button]
    
    //panels
    //wxImage BG(wxT("C:/workspace/project0/pic/BackGround.png"), wxBITMAP_TYPE_PNG);
    //wxImage BG(wxT("C:/workspace/project0/pic/BGG_1.png"), wxBITMAP_TYPE_PNG);
    //BG.LoadFile(wxT("C:/workspace/project0/pic/BGG_1.png"), wxBITMAP_TYPE_PNG);
    //wxBitmap BG1(BG);
    
    
    wxImage rack(wxT("C:/workspace/project0/pic/rack_fit.png"), wxBITMAP_TYPE_PNG);
    

    //wxBitmapBGPanel* panel_racks[2];
    //buttons
    wxPanel* panel_BG = new wxPanel(this,wxID_ANY, wxPoint(100,100),wxSize(50,50),wxNO_BORDER,"123");
    panel_BG->SetBackgroundColour(SD_Orange);
    //wxBitmapBGPanel panel_BG1(this,BG,ID_BASIC,TYPE_NONE, wxPoint(100,100),wxSize(50,50),wxNO_BORDER,"123");
    
    //panel_BG.LoadBGImage(BG,TYPE_NONE);
    //wxPanel* panel_BG = new wxPanel(this,ID_BASIC, wxPoint(200,235),wxSize(300,25));

    wxPanel* panel_title = new wxPanel(panel_BG,ID_TITLE, wxPoint(200,235),wxSize(300,25));
    wxTextCtrl* textbox = new wxTextCtrl(panel_title,ID_TEXT,"13",wxPoint(0,0),wxSize(300,25));
    textbox->SetBackgroundColour(SD_Grey);

    
    
    
    // wxStaticText* label1 = new wxStaticText(panel_BG,wxID_ANY,"Title",wxPoint(80,300),wxSize(50,30));
    //55.559055118
    //212
    //wxBitmapBGPanel* panel_text = new wxBitmapBGPanel(panel_BG,detail,ID_BASIC,TYPE_NONE, wxPoint(55.559,214),wxSize(136,137),wxNO_BORDER,"123");

    //wxBitmapBGPanel* panel_text = new wxBitmapBGPanel(panel_BG,pic1,ID_BASIC,TYPE_NONE, wxPoint(55.559,214),wxSize(149,149),wxNO_BORDER,"123");

    wxPanel* panel_new = new wxPanel(panel_BG,ID_PANEL_NEW, wxPoint(765,350.5),wxSize(105,104));

    wxPanel* panel_save = new wxPanel(panel_BG,ID_PANEL_SAVE, wxPoint(765,225.4),wxSize(105,104),wxNO_BORDER,"123");

    wxPanel* panel_mode = new wxPanel(panel_BG,ID_PANEL_MODE, wxPoint(698.6,228.2),wxSize(59,97),wxNO_BORDER,"123");

    wxBitmapBGPanel* panel_rack_h = new wxBitmapBGPanel(panel_BG,rack,ID_RACK,TYPE_OPEN, wxPoint(57,45),wxSize(789,65),wxNO_BORDER,"123");

    wxBitmapBGPanel* panel_rack_l = new wxBitmapBGPanel(panel_BG,rack,ID_RACK,TYPE_FINISHED, wxPoint(57,129.6),wxSize(789,65),wxNO_BORDER,"123");

    panel_racks[0] = panel_rack_h;
    panel_racks[1] = panel_rack_l;

    panel_rack_h->RackRegister(panel_racks);
    panel_rack_l->RackRegister(panel_racks);
    
    //wxPanel* panel_ball10 = new wxPanel(panel_rack_h,ID_PanelBall_10, wxPoint(300,5),wxSize(59,58),wxNO_BORDER,"123");
    

    wxImage new_button(wxT("C:/workspace/project0/pic/N_button_drawn.png"), wxBITMAP_TYPE_PNG);
    
    wxImage new_button_c(wxT("C:/workspace/project0/pic/N_button_drawn.png"), wxBITMAP_TYPE_PNG);  
    // wxBitmap new_button_bm(new_button);
    // wxBitmap new_button_c_bm(new_button_c);

    wxImage mode_button_0(wxT("C:/workspace/project0/pic/flip_high.png"), wxBITMAP_TYPE_PNG);
    wxImage mode_button_1(wxT("C:/workspace/project0/pic/flip_middle.png"), wxBITMAP_TYPE_PNG);  
    wxImage mode_button_2(wxT("C:/workspace/project0/pic/flip_low.png"), wxBITMAP_TYPE_PNG);  

    wxImage save_button(wxT("C:/workspace/project0/pic/S_button_drawn.png"), wxBITMAP_TYPE_PNG);
    wxImage save_button_c(wxT("C:/workspace/project0/pic/S_button_drawn.png"), wxBITMAP_TYPE_PNG);  

   
    
    wxBitmappedButton* button_new = new wxBitmappedButton(panel_new,ID_BUTTON_NEW,TYPE_NEW,new_button,new_button_c,wxPoint(0,0),panel_racks);
    button_new->SetBackgroundColour(SD_Orange);
    
    wxBitmappedButton* button_save = new wxBitmappedButton(panel_save,ID_BUTTON_SAVE,TYPE_SAVE,save_button,save_button_c,wxPoint(0,0),panel_racks);
    button_save->SetBackgroundColour(SD_Orange);

    wxBitmappedButton* button_mode = new wxBitmappedButton(panel_mode,ID_BUTTON_MODE,TYPE_SORT,mode_button_0,mode_button_1,mode_button_2,wxPoint(0,0));
    button_mode->SetBackgroundColour(SD_Orange);

    
    
    
    m_timer.Start(500,wxTIMER_CONTINUOUS);
    //wxBitmappedButton* item_b1 = new wxBitmappedButton(panel_ball10,ID_Button_Ball10,0,ImageBall10,ImageBall10_c,wxPoint(0,0));
    //loop for ball position swifting
    // for(int time_index = 0;time_index<1000;time_index++){
    //     if(time_index == 999)
    //     {
    //         panel_racks[0]->RefreshBallPosition();
    //         panel_racks[1]->RefreshBallPosition();
    //         time_index =0;
    //     }
    // }

}

//action taken
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("A little help from Alexander");
}

void MyFrame::OnTimer(wxTimerEvent& event)
{
    panel_racks[0]->RefreshBallPosition();
    panel_racks[1]->RefreshBallPosition();
    
    // wxMessageBox( "This is a wxWidgets' Hello world sample",
    //             "About Hello World", wxOK | wxICON_INFORMATION );
    
}



