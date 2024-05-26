//
// Created by martell on 4/8/24.
//

#ifndef TO_DOLIST_STRINGHANDLE_H
#define TO_DOLIST_STRINGHANDLE_H

#include "Libs.h"

class StringHandle{
public:
    static string MakeString(vector<string> data , char del = ',');
    static vector<string> SplitString(string Data, char del = ',');
};


#endif //TO_DOLIST_STRINGHANDLE_H
