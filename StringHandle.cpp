//
// Created by martell on 4/8/24.
//

#include "StringHandle.h"

vector<string> StringHandle::SplitString(std::string Data, char del) {
    stringstream ss(Data);
    string member;
    vector<string> result;

    while(getline(ss,member,del)){
        result.push_back(member);
    }
    return result;
}

string StringHandle::MakeString(vector<string> data , char del){
    string line ="";
    if(data.size() == 3) line+=',';
    for(const auto x : data){
        line += x;
        line += ',';
    }
    line.pop_back();
    return line;
}
