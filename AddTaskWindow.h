//
// Created by martell on 4/14/24.
//

#ifndef TO_DOLIST_ADDTASKWINDOW_H
#define TO_DOLIST_ADDTASKWINDOW_H
#include "Libs.h"
#include "TaskManager.h"
#include "wxHeaders.h"
//#include "MainGUI.h"
class Frame;

extern const wxEventType TASK_ADDED_EVENT;

class AddTaskWindow : public wxFrame{

public:
    AddTaskWindow(wxFrame* parent,const wxString& title ,const wxPoint& pos , const wxSize& size);


private:
    TaskManager taskmgr;
    vector<string> Data;
    wxTextCtrl* TaskText;
    Frame* ParentFrame;
    wxDatePickerCtrl* date;
    void OnCancel(wxCommandEvent& event);
    void Add(wxCommandEvent& event);


DECLARE_EVENT_TABLE();

};


#endif //TO_DOLIST_ADDTASKWINDOW_H
