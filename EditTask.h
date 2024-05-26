//
// Created by martell on 5/23/24.
//

#ifndef TO_DOLIST_EDITTASK_H
#define TO_DOLIST_EDITTASK_H
#include "Libs.h"
#include <wx/wx.h>
#include "TaskManager.h"
#include <wx/datectrl.h>
class EditTask : public wxFrame{
wxDECLARE_EVENT_TABLE();
public:
    EditTask(wxFrame* Parent, wxPoint Pos , wxSize size,vector<string> Data);
private:
    wxTextCtrl* TaskText;
    wxDatePickerCtrl* TaskDate;
    TaskManager taskmgr;
    vector<string> Data;
    void OnSave(wxCommandEvent& event);
    void OnCancle(wxCommandEvent& event);
};


#endif //TO_DOLIST_EDITTASK_H
