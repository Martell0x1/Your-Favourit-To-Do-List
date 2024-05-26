//
// Created by martell on 4/8/24.
//

#include "Task.h"

Task::Task(const string& text , const string & expiredDate  ,const string& remaingTime, bool tasksState):
text(text),expiredDate(expiredDate),remiaingTime(remaingTime),taskState(tasksState){
}

Task::Task(const vector<string> data){
    Task::SetAllData(data);
}
Task::Task(){}

int Task::getId() const {
    return id;
}

void Task::SetAllData(vector<string> data) {
    if(data.size() >= 3){
        this->text = data[0];
        this->expiredDate = data[1];
        this->taskState = stoi(data[2]);
    }else throw runtime_error("UnCompleted Providec Data Set");
}

[[nodiscard]] const string &Task::getText() const {
    return text;
}

void Task::setText(const string &text) {
    this->text = text;
}


const int Task::ExpireDate::getYear() const {
    return year;
}

const int Task::ExpireDate::getMonth() const {
    return month;
}

const int Task::ExpireDate::getDay() const {
    return day;
}

const string Task::ExpireDate::toString() const {
    stringstream str;
    str << day << "/" << month << "/" << year;
    return str.str();
}

void Task::setExpiredDate(string &Date) {
    //12/11/2004
    int pos = expiredDate.find('/');
    expiredate.day = stoi(Date.substr(0,pos));
    expiredDate = expiredDate.substr(pos+1);

    pos = expiredDate.find('/');
    expiredate.month = stoi(Date.substr(0,pos));
    expiredDate = expiredDate.substr(pos+1);

    expiredate.year = stoi(Date);

}


const string Task::RemainingDate::toString() const {
    stringstream str;
    str << day << "/" << month << "/" << year;
    return str.str();
}

void Task::setRemainingDate() {
    ExpireDate expr = expiredate;
    auto CurrentTime = chrono::system_clock::now();
    time_t temp = chrono::system_clock::to_time_t(CurrentTime);
    tm finalTime = *localtime(&temp);

    int currentYear = finalTime.tm_year + 1900;
    int currentMonth = finalTime.tm_mon;
    int currentDay = finalTime.tm_mday;

    this->remainingdate.year = currentYear - expr.getYear();
    this->remainingdate.month = currentMonth - expr.getMonth();
    this->remainingdate.day = currentDay - expr.getDay();


}

const Task::RemainingDate Task::getRemainingDate() const{
    return this->remainingdate;
}

[[nodiscard]] int Task::getTaskState() const {
    return taskState;
}

void Task::setTaskState(int taskState) {
    this->taskState = taskState;
}

void Task::setId(int value){
    this->id = value;
}

const Task::ExpireDate Task::getExpiredate() const {
    return expiredate;
}
