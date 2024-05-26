//
// Created by martell on 4/14/24.
//

#include "AddTaskWindow.h"
//#include "MainGUI.h"

wxBEGIN_EVENT_TABLE(AddTaskWindow,wxFrame)
    EVT_BUTTON(CancleID,AddTaskWindow::OnCancel)
    EVT_BUTTON(AddID,AddTaskWindow::Add)
wxEND_EVENT_TABLE()

AddTaskWindow::AddTaskWindow(wxFrame* parent,const wxString& title ,const wxPoint& pos , const wxSize& size)
:wxFrame(parent, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER)){

    wxPanel* MainPanel = new wxPanel(this);

    wxStaticText* Label = new wxStaticText(MainPanel,wxID_ANY,"Task Text",wxPoint(50,30));
    this->TaskText = new wxTextCtrl(MainPanel,wxID_ANY,"",wxPoint(150,10),wxSize(400,50));

    wxStaticText* Label2 = new wxStaticText(MainPanel,wxID_ANY,"Task Date",wxPoint(50,120));
    this->date = new wxDatePickerCtrl(MainPanel,wxID_ANY,wxDefaultDateTime,wxPoint(150,120));

    Label->SetFont(wxFont(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD));
    Label2->SetFont(wxFont(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD));
    wxButton* Add = new wxButton(MainPanel,AddID,"Add",wxPoint(150,200));
    wxButton* Cancel = new wxButton(MainPanel,CancleID,"Cancel",wxPoint(400,200));
    this->ParentFrame = (Frame *)GetParent();




}

void AddTaskWindow::OnCancel(wxCommandEvent &event) {
    Close(true);
}

void AddTaskWindow::Add(wxCommandEvent &event) {
    string TaskT = this->TaskText->GetValue().ToStdString();
    wxDateTime TaskD = this->date->GetValue();
    string text = to_string(TaskD.GetDay())
            +"/"+
            to_string(TaskD.GetMonth()) + "/"+ to_string(TaskD.GetYear());


    Data.push_back(TaskT);
    Data.push_back(text);
    Data.push_back("0");
    taskmgr.AssignTask(Data);
    vector<string> Frontdata;
    Data.insert(Data.begin(),
                to_string(taskmgr.GetCurrentTask().getId()
                ));


    wxCommandEvent taskAddedEvent(TASK_ADDED_EVENT);
    taskAddedEvent.SetClientData(new vector<string>(Data));
    GetParent()->GetEventHandler()->ProcessEvent(taskAddedEvent);
    Close(true);


}




