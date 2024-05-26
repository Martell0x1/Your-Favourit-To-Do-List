//
// Created by martell on 5/23/24.
//

#include "EditTask.h"

const int OK_ID = wxID_ANY + 1;
const int CANCLE_ID = wxID_ANY + 2;

wxBEGIN_EVENT_TABLE(EditTask,wxFrame)
                EVT_BUTTON(OK_ID,EditTask::OnSave)
                EVT_BUTTON(CANCLE_ID,EditTask::OnCancle)
                wxEND_EVENT_TABLE()

EditTask::EditTask(wxFrame *Parent, wxPoint Pos, wxSize size,vector<string> Data)
:wxFrame(Parent,wxID_ANY,"Task "+Data[0],Pos,size,wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER)){
    wxPanel* MainPanel = new wxPanel(this);
    wxStaticText* Label = new wxStaticText(MainPanel,wxID_ANY,"Task Text",wxPoint(50,40));
    this->TaskText = new wxTextCtrl(MainPanel,wxID_ANY,Data[1],wxPoint(150,10),wxSize(400,60));

    wxStaticText* Label2 = new wxStaticText(MainPanel,wxID_ANY,"Task Date",wxPoint(50,130));
    string date = Data[2];
    vector<int> lol(3);
    for(int x = 0 ; x < lol.size() ; x++){
        int pos = date.find('/');
        int num = stoi(date.substr(0,pos));
        lol[x] = num;
        if(pos == -1) break;
        else
            date.erase(0,pos+1);
    }

    wxDateTime datetext;
    wxDateTime::Month monthEnum = static_cast<wxDateTime::Month>(lol[1]-1);
    datetext.Set(lol[0],monthEnum,lol[2]);
    this->TaskDate = new wxDatePickerCtrl(MainPanel,wxID_ANY,datetext,wxPoint(150,130));
    wxButton* ok = new wxButton(MainPanel,OK_ID,"Save",wxPoint(200,210));
    wxButton* Cancle = new wxButton(MainPanel,CANCLE_ID,"Cancle",wxPoint(300,210));
    this->Data = Data;

}

void EditTask::OnSave(wxCommandEvent &event) {
    wxDateTime TaskD = this->TaskDate->GetValue();
    string text = to_string(TaskD.GetDay())
                  +"/"+
                  to_string(TaskD.GetMonth()) + "/"+ to_string(TaskD.GetYear());
    this->taskmgr.EditTask(stoi(this->Data[0]), make_pair(1,this->TaskText->GetValue().ToStdString()));
    this->taskmgr.EditTask(stoi(this->Data[0]), make_pair(2,text));
    wxMessageBox("Please Reload the Program to see the Changes");
    this->Close(true);
}

void EditTask::OnCancle(wxCommandEvent &event) {
    this->Close(true);
}
