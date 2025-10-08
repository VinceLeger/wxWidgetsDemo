//wxWidgets
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

// Define a new application; derive from wxApp
class MyApp : public wxApp
{
public:
    //implement OnInit
    virtual bool OnInit();
};

// Create a frame
class MyFrame : public wxFrame
{
public:
    // Constructor
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    // Event handlers
    void OnTest(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    // Event table declaration
    wxDECLARE_EVENT_TABLE();
};

// Event table for MyFrame
enum
{
    ID_TEST = 1
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_TEST, MyFrame::OnTest)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

// On Init method
bool MyApp::OnInit()
{
    // Create main frame
    MyFrame *frame = new MyFrame("Test Application", wxPoint(50, 50), wxSize(450, 340));
    // Show
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Create main menu
    wxMenuBar *menuBar = new wxMenuBar;
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_TEST, "&Test...\tCtrl-H", "Fancy...updates status text");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Hey there!!!");
}

// Implement event handlers
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is an example project for using wxWidgets with CMake and Ninja.",
                 "About Test Application", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnTest(wxCommandEvent& event)
{
    wxLogMessage("Some textbox message...");
}

// Implement the application entry point
wxIMPLEMENT_APP(MyApp);
