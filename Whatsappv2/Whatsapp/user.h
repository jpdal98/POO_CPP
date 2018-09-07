#ifndef USER_H
#define USER_H

#include <iostream>
#include <map>
#include "chat.h"
#include "registro.h"
#include <list>
#include <sstream>

using namespace std;
class Chat;

class User{
    string UserId;
    map<string, Chat*> lista_chat;


public:
    User(string id = ""){
        this->UserId = id;
    }

    string getUserId(){
        return UserId;
    }

    list<string> getChats(){
        list<string> chats;
        for(auto chat: lista_chat){
            chats.push_back(chat.first);
        }

        return chats;
    }

    string getOverview(){
        stringstream ss;
        ss << "[ ";
        for(auto chat: lista_chat){
            ss << chat.first;
            if(chat.second->getUnreadCount(UserId)){
                ss << "(";
                ss << chat.second->getUnreadCount(UserId);
                ss << ")";
            }
            ss << " ";
        }
        ss << "]";
        return ss.str();
    }

    void assertChat(string chatId){
        if(lista_chat.find(chatId) == lista_chat.end()){
            throw string("Chat não encontrado!");
        }
    }
    void invite(string chatId, User* user){
        assertChat(chatId);
        Chat* chat = lista_chat[chatId];

        if(chat->hasUser(user->getUserId())){
            return;
        }

        chat->lista_reg[user->getUserId()] = Registro(user);// .insert((user->getUserId(), Registro(user)));
        user->lista_chat[chat->chatId] = chat; //.insert(lista_chat(chat->chatId,chat))

        if(chat->getInOut()){
            string msg = "system: " + user->getUserId() + " foi adicionado";
            sendZap(msg, chatId);
        }
    }

    void leave(string chatId){

        if(lista_chat.find(chatId) == lista_chat.end()){
            throw string("Chat não encontrado.");
        }

        Chat *chat = lista_chat[chatId];
        chat->lista_reg.erase(this->UserId);
        this->lista_chat.erase(chatId);

        if(chat->getInOut()){
            string msg = "system: " + this->UserId + " saiu";
            sendZap(msg, chatId);
        }
    }

    void sendZap(string msg, string chatId){
        assertChat(chatId);

        Zap zap(this->UserId, msg);

        Chat *chat = lista_chat[chatId];
        chat->lista_zap.push_back(zap);

        chat->deliverZap(zap);

    }

    string toString(){
        return this->UserId;
    }

};

#endif // USER_H
