//
// Created by martell on 4/8/24.
//

#include "TaskManager.h"
#include "FileHandler.h"


string TaskManager::refineData(vector<string> data, int id){
    return to_string(id)+ StringHandle::MakeString(data);
}


void TaskManager::LaodData() {
    LoadedDataBase = FileHandler::ReadFile();
}

void TaskManager::AssignTask(vector<string> data) {
    task.SetAllData(data);
    task.setId(FileHandler::GetLatestId());
    string line = refineData(data,task.getId());

    FileHandler::WriteFile(line);
}

string TaskManager::GetRemaningTime() const{
    return task.getRemainingDate().toString();
}

void TaskManager::DeleteTask(int taskId) const{
    FileHandler::DeleteDataById(taskId);
}

void TaskManager::CompeleteTask(int TaskId) const{
    FileHandler::UpdateData(TaskId, make_pair(3,"1"));
}

void TaskManager::EditTask(int TaskId , pair<int,string>taskmember) const{
    FileHandler::UpdateData(TaskId,std::move(taskmember));
}

vector<string> TaskManager::GetFullDataBase() const {
    return this->LoadedDataBase;
}

Task TaskManager::GetCurrentTask() const {
    return this->task;
}

vector<string> TaskManager::GetCurrentTaskById(int id) const{
    string data = FileHandler::GetDataById(id);
    return StringHandle::SplitString(data);
}
