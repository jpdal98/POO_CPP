#ifndef CHAT_H
#define CHAT_H

#include <iostream>
#include <list>
#include <map>
#include "zap.h"
#include "registro.h"



using namespace std;
class User;

class Chat
{
    string chatId;
    list<Zap> lista_zap;
    map<string, Registro> lista_reg;

    bool enableInOutMsgs{false};
    string systemUsername;

public:
    Chat(string id = "", string sys = ""){
        this->chatId = id;
        this->systemUsername = sys;
    }

    bool addFirstUser(User* chatCreator);

    list<string> getUsers();

    void deliverZap(Zap zap);

    list<Zap> getUnread(string userId);

    int getUnreadCount(string userId);

    bool hasUser(string userId);
    bool getInOut();
    void setInOut(bool enableInOutMsgs);


    friend class User;
};

#endif // CHAT_H
