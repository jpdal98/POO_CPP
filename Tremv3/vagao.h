#ifndef VAGAO_H
#define VAGAO_H
#include <iostream>
#include <vector>
#include "passageiro.h"


using namespace std;



class Vagao
{
    vector<Passageiro*> cadeiras;
    int capacidade;
    int idVagao;

public:
    Vagao(int capacidade = 0, int idVagao = 0) :
        cadeiras(capacidade, nullptr)
    {
        this->capacidade = capacidade;
        this->idVagao = idVagao;
    }


    void embarcarVagao(Passageiro* passageiro){
        for(auto cadeira : cadeiras){
            if((cadeira != nullptr) && (cadeira->getCpf() == passageiro->getCpf())){
                throw string("  CPF " + passageiro->getCpf() + "  já embarcado");
                //return;
            }
        }
        for(auto& cadeira : cadeiras){
            if(cadeira == nullptr){
                cadeira = passageiro;
                return;
            }
        }


    }

    Passageiro* desembarcarVagao(string cpf){
        Passageiro *pass_aux;
        for(int i = 0; i < capacidade; i++){
            if((cadeiras[i] != nullptr) && (cadeiras[i]->getCpf() == cpf)){
                pass_aux = cadeiras[i];
                cadeiras[i] = nullptr;
                return pass_aux;
            }
        }
        return nullptr;
    }


    Passageiro* search(string cpf){
        for(int i = 0; i < capacidade; i++){
            if(cadeiras[i]->getCpf() == cpf){
                return cadeiras[i];
            }
        }
        return nullptr;
    }

    int getCapacidade(){
        return this->capacidade;
    }

    int getLotacao(){
        int cont = 0;
        for(auto cadeira : cadeiras)
            if(cadeira != nullptr)
                cont++;
        return cont;
    }

    string toString(){
         stringstream ss;
         ss /*<< "ID: " << idVagao << "\nCapacidade: " << capacidade << "\nLotacao: " << getLotacao()*/ << "[ ";

         for(int i = 0;i < capacidade;i++){
             if(cadeiras[i] != nullptr){
                 ss << cadeiras[i]->getCpf() << " ";
             }else{
                 ss << " - ";
             }

         }
         ss << " ] ";
         return ss.str();
     }

};

#endif // VAGAO_H
