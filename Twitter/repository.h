#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <map>
#include <vector>


using namespace std;


template <class T>
class Repository
{
    map<string, T> _map;
    string nomeTipo;

public:
    Repository(string nomeTipo = ""){
        this->nomeTipo = nomeTipo;
    }

    T* add(string key, T t){
        if(_map.count(key) == 1)
            throw nomeTipo + " " + key + " ja existe";
        _map[key] = t;
        return &_map[key];
    }

    T * get(string key){
        if(_map.count(key) == 0)
            throw nomeTipo + " " + key + " nao existe";
        return &_map[key];
    }


    bool exist(string key){
        return _mapa.count(key);
    }

    void rm(string key){
        if(!_map.erase(key))
            throw nomeTipo + " " + key + " nao existe";
    }

    vector<T> key(){
        vector<T> vet;
        for(auto &par : _map)
            vet.push_back(par.first);
        return vet;
    }

    vector<T> getAll(){
        vector<T> vet;
        for(auto &par : _map)
            vet.push_back(par.second);
        return vet;
    }

};

#endif // REPOSITORY_H
