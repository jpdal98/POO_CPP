#ifndef REGISTROPASSAGEIROS_H
#define REGISTROPASSAGEIROS_H
#include <iostream>
#include <vector>
#include "passageiro.h"
#include <sstream>
#include <algorithm>


using namespace std;


bool comparaCpf(Passageiro a, Passageiro b){
        return a.getCpf() <= b.getCpf();
}


class RegistroPassageiros
{
    vector<Passageiro> passageiros;

public:
    RegistroPassageiros()
    {

    }

    void addPass(Passageiro passageiro){

        passageiros.push_back(passageiro);

    }

    vector<Passageiro> getAllPass(){
        return this->passageiros;
    }

    string toString(){
        sort(passageiros.begin(),passageiros.end(), comparaCpf);
        stringstream ss;
        for(Passageiro pass : passageiros){
            ss << pass.toString() << endl;
        }
        return ss.str();
    }


};

#endif // REGISTROPASSAGEIROS_H
