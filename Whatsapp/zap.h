#ifndef ZAP_H
#define ZAP_H

#include <iostream>

using namespace std;

class Zap
{
    string userId;
    string msg;

public:
    Zap(string userId="", string msg=""){
        this->userId = userId;
        this->msg = msg;
    }

string toString(){
    string ss = '[' + userId + ':' + msg + ']';
    return ss;
}

};

#endif // ZAP_H
