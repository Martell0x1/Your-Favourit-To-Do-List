#include "MainGUI.h"

bool MainGUI::OnInit(){
    Frame* frame = new Frame("Your Favourit Task List",wxDefaultPosition,wxSize(1000,500));
    frame->Show();
    SetTopWindow(frame);
    return true;
}
BEGIN_EVENT_TABLE(Frame,wxFrame)
                EVT_BUTTON(ADD_ID,Frame::AddTask)
                EVT_BUTTON(DEL_ID,Frame::DeleteTask)
                EVT_BUTTON(EDIT_ID,Frame::ModefyTask)
                EVT_BUTTON(COMP_ID,Frame::MarkComplete)
                EVT_COMMAND(wxID_ANY, TASK_ADDED_EVENT, Frame::OnTasKAdded)
END_EVENT_TABLE()

const wxEventType TASK_ADDED_EVENT = wxNewEventType();
string teststr;
Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER)) {


    wxPanel* MainWindow = new wxPanel(this,wxID_ANY);
    this->TasksWindow = new wxScrolledWindow(MainWindow,wxID_ANY,wxDefaultPosition,wxSize(900,500),wxVSCROLL);

    wxButton * AddTasks = new wxButton(MainWindow,ADD_ID,"Add");

    wxBoxSizer * MainSizer = new wxBoxSizer(wxHORIZONTAL);
    this->TasksSizer = new wxBoxSizer(wxVERTICAL);

    MainSizer->Add(AddTasks, 0, wxEXPAND | wxALL, 5);
    MainSizer->Add(TasksWindow, 1, wxEXPAND | wxALL, 5);

    MainWindow->SetSizerAndFit(MainSizer);

    Frame::LoadAllTasks(this->TasksWindow,this->TasksSizer);
    TasksWindow->SetSizerAndFit(TasksSizer);

    TasksWindow->SetScrollbars(0, 20, 0, 25);

    MainWindow->SetBackgroundColour(wxColor(236, 240, 241));



}

void Frame::LoadAllTasks(wxScrolledWindow* Parent, wxSizer* ParentSizer) {
    taskmgr.LaodData();
    vector<string> AllData = taskmgr.GetFullDataBase();
    wxScrolledWindow* TempContainer = new wxScrolledWindow(Parent, wxID_ANY,wxDefaultPosition,wxSize(900, 120));
    teststr = AllData[0];
    if(teststr == ""){
        wxTextCtrl* Text = new wxTextCtrl(TempContainer, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(900, 120), wxTE_MULTILINE | wxTE_READONLY);

        Text->AppendText("Empty ... Try Add Some Tasks");
        Text->SetBackgroundColour(wxColour(230, 230, 250));
        Text->SetForegroundColour(wxColour(0,0,0));


        ParentSizer->Add(TempContainer, 0, wxEXPAND | wxALL, 5);
        this->SetLastTask(TempContainer);

    }else {
        teststr = "some dummy string";
        for (int x = 0; x < AllData.size(); x++) {
            vector<string> TaskData = StringHandle::SplitString(AllData[x]);
            wxScrolledWindow *Container = new wxScrolledWindow(Parent, wxID_ANY, wxDefaultPosition, wxSize(900, 120));
            wxTextCtrl *Text = new wxTextCtrl(Container, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(900, 120),
                                              wxTE_MULTILINE | wxTE_READONLY);

            wxButton *Delete = new wxButton(Container, DEL_ID, _T("❌"), wxPoint(785, 0));
            wxButton *Edit = new wxButton(Container, EDIT_ID, _T("⚙\uFE0F"), wxPoint(690, 0));


            Text->AppendText("      Task Number: " + _(TaskData[0] + _("\n")));
            Text->AppendText("      Task: " + _(TaskData[1] + _("\n")));
            Text->AppendText("      Expire Date: " + _(TaskData[2] + _("\n")));
            //        Text->AppendText("Remaining Date: "+_(taskmgr.GetRemaningTime())+_("\n"));
            Text->AppendText("      Status: " +
                             [=]() -> wxString {
                                 if (TaskData[3] == "0") {
                                     wxButton *MarkComplete = new wxButton(Container, COMP_ID, _T("✅"),
                                                                           wxPoint(590, 0));
                                     return _("Incompelete");
                                 } else {
                                     return _("Completed");
                                 }
                             }()
            );

            Text->SetBackgroundColour(wxColour(255, 112, 67));
            Text->SetForegroundColour(wxColour(0, 0, 0));


            ParentSizer->Add(Container, 0, wxEXPAND | wxALL, 5);
            this->SetLastTask(Container);
        }
        TempContainer->Destroy();
        TasksSizer->Detach(TempContainer);
        TasksSizer->Layout();
//        TaskWindow->FitInside();
    }
}

void Frame::SetLastTask(wxScrolledWindow *TaskContainer) {
    this->lastTask = TaskContainer;
}

wxScrolledWindow* Frame::GetLastTask() const{
    return this->lastTask;
}

void Frame::AddTask(wxCommandEvent &event) {

    this->TaskWindow = new AddTaskWindow(this,"Add New Task",wxDefaultPosition,wxSize(600,300));
    TaskWindow->Show();


}
void Frame::OnTasKAdded(wxCommandEvent& event) {
    if(teststr == ""){
        wxMessageBox("The Empty Container well be remove after reloading the program.... mesh 3aref ashelha :)");
    }
    wxScrolledWindow* LastTask = this->GetLastTask();

    wxPoint position = LastTask->GetPosition();
    auto* TaskData = (vector<string>*)event.GetClientData();

    int yposition = position.y + 120;
    wxScrolledWindow *Container = new wxScrolledWindow(TasksWindow, wxID_ANY, wxPoint(position.x, yposition),
                                                       wxSize(900,120));
    wxTextCtrl *Text = new wxTextCtrl(Container, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(900, 120),
                                      wxTE_MULTILINE | wxTE_READONLY);
    wxButton *Delete = new wxButton(Container, DEL_ID, _T("❌"), wxPoint(785, 0));
    wxButton* Edit = new wxButton(Container , EDIT_ID,_T("⚙\uFE0F"),wxPoint(690,0));

    Text->AppendText("      Task Number: " + _(TaskData->at(0) + _("\n")));
    Text->AppendText("      Task: " + _(TaskData->at(1) + _("\n")));
    Text->AppendText("      Expire Date: " + _(TaskData->at(2) + _("\n")));

    Text->AppendText("      Status: " +
                     [=]() -> wxString {
                         wxButton *MarkComplete = new wxButton(Container, COMP_ID, _T("✅"), wxPoint(590, 0));
                         return _("Incompelete");
                     }()
    );
    Text->SetBackgroundColour(wxColour(255, 112, 67));
    Text->SetForegroundColour(wxColour(0, 0, 0));
    TasksSizer->Add(Container, 0, wxEXPAND | wxALL, 5);
    this->SetLastTask(Container);

    TasksSizer->Layout();
    TasksWindow->FitInside(); // ensure that the scrolled window is large enough to display the full content

    int maxHieght = TasksWindow->GetVirtualSize().GetHeight();
    TasksWindow->Scroll(0,maxHieght);

}

void Frame::DeleteTask(wxCommandEvent &event) {
    wxButton* deleteBtn = (wxButton*)event.GetEventObject();

    wxScrolledWindow* Container = (wxScrolledWindow*)deleteBtn->GetParent();

    wxString Value;
    wxWindowList childs = Container->GetChildren();
    for(wxWindowList::iterator itr = childs.begin() ; itr != childs.end() ; ++itr){
        wxWindow* child = *itr;
        if(wxTextCtrl* t = dynamic_cast<wxTextCtrl*>(child)){
            wxString value = t->GetValue();
            Value = value;
        }
    }
    int columnPos = Value.find(":");
    string TaskId = Value.substr(columnPos+2).ToStdString();
    taskmgr.DeleteTask(stoi(TaskId));

    TasksSizer->Detach(Container);
    Container->Destroy();
    TasksSizer->Layout();
    TasksWindow->FitInside();


}


void Frame::MarkComplete(wxCommandEvent &event) {
    wxButton* Markbtn = dynamic_cast<wxButton*>(event.GetEventObject());
    if (!Markbtn) return;

    wxScrolledWindow* container = dynamic_cast<wxScrolledWindow*>(Markbtn->GetParent());
    if (!container) return;

    wxTextCtrl* text = nullptr;
    wxButton * MarkCompbtn = nullptr;
    wxString Value;

    wxWindowList childs = container->GetChildren();
    for (auto child : childs) {
        text = dynamic_cast<wxTextCtrl*>(child);
        if (text) {
            Value = text->GetValue();
            break;
        }
    }
    for (auto child : childs) {
        MarkCompbtn = dynamic_cast<wxButton*>(child);
        if (MarkCompbtn && MarkCompbtn->GetId() == COMP_ID) {
            TasksSizer->Detach(MarkCompbtn);
            MarkCompbtn->Destroy();
            break;
        }
    }

    if (!text) return;

    int columnPos = Value.find(":");
    if (columnPos == wxString::npos) return;

    wxString TaskIdStr = Value.substr(columnPos + 2);
    int TAskId = stoi(TaskIdStr.ToStdString());

    taskmgr.EditTask(TAskId, std::make_pair(3, "1"));

    wxString word = "Incompelete";
    int pos = Value.find(word);
    if (pos == wxString::npos) return;

    wxString newStr = Value.substr(0, pos) + "Completed";
    text->Clear();
    text->AppendText(newStr);

    TasksSizer->Layout();
    TasksWindow->FitInside();
}

void Frame::ModefyTask(wxCommandEvent &event) {
    wxButton* Edit = dynamic_cast<wxButton*>(event.GetEventObject());
    wxScrolledWindow* Container = dynamic_cast<wxScrolledWindow*>(Edit->GetParent());
    wxWindowList childs = Container->GetChildren();
    wxTextCtrl* text;
    wxString Value;
    for (auto child : childs) {
        text = dynamic_cast<wxTextCtrl*>(child);
        if (text) {
            Value = text->GetValue();
            break;
        }
    }
    int columnPos = Value.find(":");
    if (columnPos == wxString::npos) return;

    wxString TaskIdStr = Value.substr(columnPos + 2);
    int TAskId = stoi(TaskIdStr.ToStdString());
    vector<string> data = taskmgr.GetCurrentTaskById(TAskId);

    EditTask* obj = new EditTask(this,wxDefaultPosition,wxSize(600,300),data);
    obj->Show();
}




