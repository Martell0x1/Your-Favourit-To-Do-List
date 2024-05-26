//
// Created by martell on 4/8/24.
//

#ifndef TO_DOLIST_MAINGUI_H
#define TO_DOLIST_MAINGUI_H

#include <wx/wx.h>
#include "FileHandler.h"
#include "Task.h"
#include "TaskManager.h"
#include "StringHandle.h"
//#include "wxHeaders.h"
#include "AddTaskWindow.h"
#include "EditTask.h"



class MainGUI : public wxApp{
public:
    virtual bool OnInit() override;
    void ReloadTasks();


};

class Frame : public wxFrame{
public:
    Frame(const wxString& title ,const wxPoint& pos , const wxSize& size);
    void LoadAllTasks(wxScrolledWindow* Parent, wxSizer* ParentSizer);
    void OnTasKAdded(wxCommandEvent& event);


    void SetLastTask(wxScrolledWindow* TaskContainer);
    wxScrolledWindow* GetLastTask() const;




private:
     TaskManager taskmgr;
    AddTaskWindow* TaskWindow;
     wxScrolledWindow * TasksWindow;
     wxBoxSizer * TasksSizer;
     wxScrolledWindow* lastTask;
    void AddTask(wxCommandEvent& event);
    void DeleteTask(wxCommandEvent& event);
    void ModefyTask(wxCommandEvent& event);
    void MarkComplete(wxCommandEvent& event);

    DECLARE_EVENT_TABLE();
};




#endif //TO_DOLIST_MAINGUI_H
