#ifndef TREM_H
#define TREM_H
#include <iostream>
#include <vector>
#include "vagao.h"



using namespace std;


class Trem{
    vector<Vagao> vagoes;
    int maxVagoes;
    int idVagao{0};

public:
    Trem(int maxVagoes = 0);


    int getLotacao(){
        int i = 0;
        for(Vagao vagao : vagoes)
            i += vagao.getLotacao();
        return i;
    }

    int getCapacidade(){
        return this->maxVagoes;
    }

    bool addVagao(int capacidade){
        if(vagoes.size() < getCapacidade()){
            vagoes.push_back(Vagao(capacidade, idVagao));
            idVagao++;
        }else{
            throw string("Limite de vagões atingido!");
        }
    }

    void embarcar(Passageiro *passageiro){
           for(auto& vagao : vagoes){
               if(vagao.getLotacao() < vagao.getCapacidade()){
                   vagao.embarcarVagao(passageiro);
                   return;
               }
           }
           throw string("Poltronas indisponíveis!");
     }

    Passageiro* desembarcar(string cpf){
        Passageiro* pass_aux;
       for(auto& vagao : vagoes){
            pass_aux = vagao.desembarcarVagao(cpf);
            if(pass_aux != nullptr){
                return pass_aux;
            }
        }
        return nullptr;
    }

    Passageiro* search(string cpf){
        Passageiro* pass_aux;
        for(auto vagao : vagoes){
            pass_aux = vagao.search(cpf);
            if(pass_aux != nullptr){
                return pass_aux;
            }
        }
        return nullptr;
    }

    string toString(){
        stringstream ss;
       // ss << "maxV: " << maxVagoes << endl;
        for(auto vagao : vagoes){
            ss << vagao.toString();
        }
        ss << "\n";
        return ss.str();
    }
};

#endif // TREM_H
