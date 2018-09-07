#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include "user.h"


using namespace std;
class User;



class Registro{
    User *user;
    int unreadCount{0};
public:
    Registro(User* user){
        this->user = user;
    }
    friend class User;

    int getUnreadCount(){
        return unreadCount;
    }

    void setUnreadCount(int unreadCount){
        this->unreadCount = unreadCount;
    }

};



#endif // REGISTRO_H
