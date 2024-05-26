//
// Created by martell on 4/8/24.
//

#ifndef TO_DOLIST_TASK_H
#define TO_DOLIST_TASK_H


#include "Libs.h"


class Task {
private:

    int id{};
    std::string text;
    std::string expiredDate;
    std::string remiaingTime;
    struct ExpireDate{
        [[nodiscard]] const int getYear() const;

        [[nodiscard]] const int getMonth() const;

        [[nodiscard]] const int getDay() const;

        [[nodiscard]] const string toString() const;

        int year;
        int month;
        int day;
    };
    struct RemainingDate{
        int year;
        int month;
        int day;



        [[nodiscard]] const string toString() const;

    };
    ExpireDate expiredate;
    RemainingDate remainingdate;
    int taskState{};
public:
    Task(const string &text, const string &expiredDate, const string& remaingTime,bool tasksState);
    Task(const vector<string> data);
    Task();

    int getId() const;

    void SetAllData(vector<string> data);

    [[nodiscard]] const string &getText() const;

    void setText(const string &text);

    void setExpiredDate(string &expiredDate);

    const ExpireDate getExpiredate() const;

    void setRemainingDate();
    const RemainingDate getRemainingDate() const;

    [[nodiscard]] int getTaskState() const;

    void setTaskState(int taskState);

    void setId(int value);
};


#endif //TO_DOLIST_TASK_H
