#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include "user.h"


using namespace std;
class User;
class Chat;


class Registro{
    User *user;
    int unreadCount{0};
public:
    Registro(User* user){
        this->user = user;
    }
    friend class User;
};

#endif // REGISTRO_H
