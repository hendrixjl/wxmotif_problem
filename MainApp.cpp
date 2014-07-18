
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <iostream>
using namespace std;

enum
{
    ZEROIZE_OK = 101,
    ZEROIZE_CANCEL
};

class Zeroize : public wxFrame
{
public:
    Zeroize()  : wxFrame(NULL,
           wxID_ANY, _T("Zeroize Data and Mission Keys"),
           wxDefaultPosition, wxDefaultSize,
           wxDEFAULT_FRAME_STYLE &
               ~(wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX) )
    {

        wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );

        topsizer->Add(new wxStaticText(this, wxID_ANY, _T("Warning")),
                      wxSizerFlags().Align(wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL));

         wxBoxSizer *button_box = new wxBoxSizer( wxHORIZONTAL );
         wxButton *okButton = new wxButton( this, ZEROIZE_OK, _T("Yes") );
         wxButton *cancelButton = new wxButton( this, ZEROIZE_CANCEL, _T("No"));
         okButton->SetEventHandler(this);
         cancelButton->SetEventHandler(this);

         button_box->Add(okButton,     wxSizerFlags().Border(wxALL, 7).Left());
         button_box->Add(cancelButton, wxSizerFlags().Border(wxALL, 7).Right());
         topsizer->Add(button_box, wxSizerFlags().Align(wxALIGN_CENTER| wxALIGN_CENTER_VERTICAL));
         this->SetSizer(topsizer);
         this->SetAutoLayout(true);
         topsizer->SetSizeHints( this );
    }

    void OnOK(wxCommandEvent& event) {
        cout << "OnOK!!!" << endl;
    }

    void OnCancel(wxCommandEvent& event) {
        cout << "OnCancel!!!" << endl;
        this->Close(true);
    }

private:

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(Zeroize, wxFrame)
    EVT_BUTTON(ZEROIZE_OK, Zeroize::OnOK)
    EVT_BUTTON(ZEROIZE_CANCEL, Zeroize::OnCancel)
END_EVENT_TABLE()


class MainApp: public wxApp
{
public:
    MainApp(){};
    bool OnInit() {
        wxTheApp->SetClassName("sgg");
        frame = new Zeroize();
        frame->Show(true);
        return true;
    }

private:
    Zeroize* frame;
};


wxAppConsole *wxCreateApp()                                                     
{
    wxAppConsole::CheckBuildOptions("2" "." "6"
    " (" "debug" "," "ANSI"
     ",compiler with C++ ABI " "1002"
     ",wx containers"
      ",compatible with 2.4"
     ")", "your program");
    return new MainApp;
}

wxAppInitializer wxTheAppInitializer((wxAppInitializerFunction) wxCreateApp);

MainApp& wxGetApp()
{ 
    return *(MainApp *)((wxApp *)wxApp::GetInstance()); 
}

int main(int argc, char **argv) 
{
    return wxEntry(argc, argv); 
}

