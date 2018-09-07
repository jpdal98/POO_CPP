#ifndef TWEETGENERATOR_H
#define TWEETGENERATOR_H
#include "repository.h"
#include "tweet.h"

using namespace std;

class TweetGenerator
{
    int nextId;
    Repository<Tweet>* r_tw;

public:
    TweetGenerator(Repository<Tweet> * r_tw){
        this->r_tw = r_tw;
    }

    Tweet* create(string username, string msg){
        int id = nextId++;
        return r_tw->add(to_string(id),  Tweet(id, username, msg));

    }

};

#endif // TWEETGENERATOR_H
