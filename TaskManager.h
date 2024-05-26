//
// Created by martell on 4/8/24.
//

#ifndef TO_DOLIST_TASKMANAGER_H
#define TO_DOLIST_TASKMANAGER_H
#include "Libs.h"
#include "Task.h"

class TaskManager {
private:
    [[maybe_unused]] vector<string> LoadedDataBase;
    string refineData(vector<string> data, int id);
    Task task;

public:

    void LaodData();

    void AssignTask(vector<string> data);

    void DeleteTask(int taskId) const;

    void CompeleteTask(int TaskId) const;

    void EditTask(int TaskId, pair<int, string> taskmember) const;
    [[nodiscard]] Task GetCurrentTask() const;
    vector<string> GetCurrentTaskById(int id) const;
    string GetRemaningTime() const;

    vector<string> GetFullDataBase() const;
};


#endif //TO_DOLIST_TASKMANAGER_H
