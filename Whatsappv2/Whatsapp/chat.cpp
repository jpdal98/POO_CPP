#include "chat.h"
#include "user.h"


bool Chat::addFirstUser(User *chatCreator){
    if(lista_reg.size() != 0){
        throw string("Já possui usuário");
    }
    this->lista_reg[chatCreator->getUserId()] = chatCreator;
    chatCreator->lista_chat[chatId] = this;
    return true;
}

list<string> Chat::getUsers(){
    list<string> users;
    for(auto user : lista_reg){
        users.push_back(user.first);
    }
    return users;
}

void Chat::deliverZap(Zap zap){
    if(zap.userId != systemUsername){
        if(lista_reg.find(zap.userId) == lista_reg.end()){
            return;
        }
    }

    lista_zap.push_back(zap);
    for(auto user : lista_reg){
        if(user.first != zap.userId){
            user.second.setUnreadCount(user.second.getUnreadCount() + 1);
        }
    }

}

list<Zap> Chat::getUnread(string userId){
    auto it = lista_reg.find(userId);
    list<Zap> list_ret;
    int cont = it.second.getUnreadCount();
    if(lista_reg.find(userId) == lista_reg.end()){
        return list_ret;
    }

    if(count == 0){
        throw string ("Não há mensagens não lidas");
    }

    for(auto i = lista_zap.end() - 1; i != lista_zap.begin(); i--){
        if(count == 0){
            return list_ret;
        }

        if(i.first != userId){
            list_ret.push_back(i.second);
            cont --;
        }

    }

}

int Chat::getUnreadCount(string userId){
    auto it = lista_reg.find(userId);
    return it.second.getUnreadCount();

//    if(it == lista_reg.end()){

//    }

}

bool Chat::hasUser(string userId){
    if(lista_reg.find(userId) == lista_reg.end()){
        throw string("User não encontrado!");
    }
    return true;

}

bool Chat::getInOut(){
    return enableInOutMsgs;
}

void Chat::setInOut(bool enableInOutMsgs){
    this->enableInOutMsgs = enableInOutMsgs;
}
