#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <iostream>
#include <sstream>


using namespace std;


class Passageiro
{
    string cpf;

public:
    Passageiro(string cpf = "");

    string getCpf(){
        return this->cpf;
    }

    string toString(){
        stringstream ss;
        ss << "CPF: " << this->cpf;
        return ss.str();
    }
};

#endif // PASSAGEIRO_H
