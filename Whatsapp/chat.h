#ifndef CHAT_H
#define CHAT_H

#include <iostream>
#include "user.h"
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
        chatId = id;
        systemUsername = sys;
    }

    bool addFirstUser(User* chatCreator){
        if(lista_reg.size() != 0){
            throw string("Já possui usuário");
        }
    this->lista_reg.insert(chatCreator->getUserId(), chatCreator);
    this->lista_reg[chatCreator->getUserId()] = Registro(chatCreator);
    chatCreator->lista_chat[chatId] = this;

    }

    list<string> getUsers(){

    }

    void deliverZap(Zap zap){

    }

    list<Zap> getUnread(string userId){

    }

    int getUnreadCount(string userId){

    }

    bool hasUser(string userId){

    }
    bool getInOut(){
        return enableInOutMsgs;
    }
    void setInOut(bool enableInOutMsgs){
        this->enableInOutMsgs = enableInOutMsgs;
    }


    friend class User;
};

#endif // CHAT_H
