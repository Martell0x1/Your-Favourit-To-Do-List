//
// Created by martell on 4/8/24.
//

#ifndef TO_DOLIST_FILEHANDLER_H
#define TO_DOLIST_FILEHANDLER_H

#include "StringHandle.h"
class FileHandler {
private:
    const static string CURRENTPATH;
public:
    static void Check_File();
    static vector<string> ReadFile();

    static void WriteFile(const string &dataline, bool append = true);

    static int GetLatestId();

    static string GetDataById(int dataId);

    static void DeleteDataById(int dataId);

    static void UpdateData(int Id, pair<int, string> NewData);
};


#endif //TO_DOLIST_FILEHANDLER_H
