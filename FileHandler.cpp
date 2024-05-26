//
// Created by martell on 4/8/24.
//

#include "FileHandler.h"

const string FileHandler::CURRENTPATH = "tasks.txt";

vector<string> FileHandler::ReadFile(){
    vector<string> Lines;
    ifstream File;
    File.open(CURRENTPATH,ios::in);

    if(File.is_open()&&File.good()) {
        while (!File.eof()) {
            string line = "";
            getline(File,line);
            Lines.push_back(line);
        }
        File.close();
    }
    else throw runtime_error("File Not Found Or Damaged");
    return Lines;
}
void FileHandler::WriteFile(const string& dataline , bool append) {
    ofstream File;
    auto mode = std::ios::out | (append ? std::ios::app : std::ios::trunc);
    File.open(CURRENTPATH,mode);
    if (File.is_open() && File.good()){
        if(filesystem::file_size(CURRENTPATH) == 0){
            File << dataline << flush;
        }
        else File << "\n" << dataline  << flush;
    }
    else throw runtime_error("File Not Found Or Damaged");
    File.close();
}

int FileHandler::GetLatestId(){
    vector<string> readedData = ReadFile();
    if(filesystem::file_size(CURRENTPATH) == 0) return 0;
    else {
        string LastLine = readedData[readedData.size() - 1];
        int pos = LastLine.find(',');
        int id = stoi(LastLine.substr(0, pos));
        return ++id;
    }
}

string FileHandler::GetDataById(int dataId) {
    vector<string> readedData = ReadFile();
    string dataLine;
    for(const string & line : readedData){
        int pos = line.find(',');
        int id = stoi(line.substr(0,pos));
        if(dataId == id){
            dataLine = line;
        }
    }
    if(dataLine.size() !=0) return dataLine;
    else throw logic_error("No data with that id found...");
}

void FileHandler::DeleteDataById(int dataId) {
    std::string DataLine = GetDataById(dataId);
    std::vector<std::string> AllData = ReadFile();

    auto itr = std::find(AllData.begin(), AllData.end(), DataLine);
    if (itr != AllData.end()) {
        AllData.erase(itr);

        // Open the file in trunc mode to clear its contents
        std::ofstream File(CURRENTPATH, std::ios::out | std::ios::trunc);
        if (File.is_open() && File.good()) {
            for (size_t i = 0; i < AllData.size(); ++i) {
                File << AllData[i];
                if (i != AllData.size() - 1) {
                    File << "\n";
                }
            }
            File.close();
        } else {
            throw std::runtime_error("File Not Found Or Damaged");
        }
    } else {
        throw std::logic_error("Data not found for deletion");
    }
}

void FileHandler::UpdateData(int Id, pair<int,string> NewData) {
    // pair will send the name of the attribute i want to modifiey and the new value;
    vector<string> AllData = ReadFile();
    string currentData = GetDataById(Id);
    vector<string> data = StringHandle::SplitString(currentData);
    data[NewData.first] = NewData.second;

    string newData = StringHandle::MakeString(data);
    bool flag = true;

    int pos = newData.find(',');
    int NewDataId = stoi(newData.substr(0,pos));
    for(auto line : AllData){
        int CurrentDataId = stoi(line.substr(0,(line.find(','))));
        if(CurrentDataId == NewDataId){
            line = newData;
        }
        if(flag) {
            WriteFile(line, false);
            flag = false;
        }else{
            WriteFile(line, true);

        }

    }
}
