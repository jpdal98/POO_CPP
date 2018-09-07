#ifndef TWEET_H
#define TWEET_H
#include <list>
#include <string>
#include  <sstream>

using namespace std;

class Tweet
{
    int idTw;
    string username;
    string msg;
    list<string> likes;

public:
    Tweet(int idTw = 0, string username = "", string msg = ""){
        this->idTw = idTw;
        this->username = username;
        this->msg = msg;
    }

    void addLike(string username){
        for(auto like : likes){
            if(like == username)
                return;

        }
        likes.push_back(username);
    }

    int getId(){
        return this->idTw;
    }

    string toString(){
          stringstream ss;
          ss << idTw << " " << username << ": " << msg << " { ";
          for(auto like : likes)
              ss << like << " " ;
          ss << "}" << endl;
          return ss.str();
    }

};


#endif // TWEET_H
