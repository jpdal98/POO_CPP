#ifndef USER_H
#define USER_H
#include <iostream>
#include <list>
#include "tweet.h"


using namespace std;

class User
{
    string username;
    list<User*> seguidores;
    list<User*> seguidos;
    list<Tweet*> myTweets;
    list<Tweet*> timeline;
    int unreadCount{0};


public:
    User(string username = ""){
        this->username = username;
    }

    string getUsername(){
        return this->username;
    }

    list<User*> getSeguidores(){
     return this->seguidores;
    }
    list<User*> getSeguidos(){
     return this->seguidos;
    }
    list<Tweet*> getTimeline(){
     return this->timeline;
    }

    list<Tweet*> getMyTweets(){
     return this->myTweets;
    }
    string toString(){
       stringstream ss;
       for(auto tl: timeline){
            ss << tl->toString() << endl;
       }
       ss << endl;
       return ss.str();
    }

    void seguir(User* user){
        seguidos.push_back(user);
        user->seguidores.push_back(this);
    }

    void twittar(Tweet* tweet){
        myTweets.push_front(tweet);
        for(auto seguidor : seguidores){
            seguidor->timeline.push_front(tweet);
            seguidor->unreadCount++;
        }

    }

    list<Tweet*> getUnread(){
        list<Tweet*> naolidos;

        for(auto it = timeline.begin(); unreadCount > 0; unreadCount--, it++){
            naolidos.push_back(*it);
        }
        return naolidos;
    }


};

#endif // USER_H
