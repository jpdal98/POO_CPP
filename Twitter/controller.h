#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "repository.h"
#include "tweet.h"
#include "user.h"
#include "tweetgenerator.h"
#include "split.h"

using namespace std;


class Controller{
    Repository<User> r_user;
    Repository<Tweet> r_tw;
    TweetGenerator twGen;

    Controller() : r_user(), r_tw(), twGen(&r_tw){

    }

    string process(string line){
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help")
            return "users                           \n"
                    "addUser    _nome               \n"
                    "seguir     _nome _outro        \n"
                    "twittar    _nome _(mensagem com varias palavras)   \n"
                    "like       _nome               \n"
                    "seguidores _nome               \n"
                    "seguidos   _nome               \n"
                    "timeline   _nome               \n"
                    "myTweets   _nome               \n"
                    "unread     _nome               \n";
        else if(cmd == "addUser\n"){
            auto user = new User (ui[1]);
            this->r_user.add((ui[1]), *user);
        }
        else if(cmd == "users")
            return "usuarios\n[" + join(r_user.key(), " ") + "]";
        else if(cmd == "seguir\n")
            this->r_user.get(ui[1])->seguir(this->r_user.get(ui[2]));
        else if(cmd == "twittar\n")


        else if(cmd == "seguidores\n")

        else if(cmd == "seguidos\n")

        else if(cmd == "timeline\n")

        else if(cmd == "unread\n")

        else if(cmd == "myTweets\n")

        else if(cmd == "like\n")

        else
            return "comando invalido";
        return "done";
    }


    void commandLine(){
        string line = "";
        while(line != "fim"){
            cout << "\nDigite help ou comando" << endl;
            getline(cin, line);
            if(line == "")
                continue;
            try{
                cout << process(line) << endl;
            }
            catch(const string& erro){
                cout << erro << endl;
            }
        }


    }


};

#endif // CONTROLLER_H

