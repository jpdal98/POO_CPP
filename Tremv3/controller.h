#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "split.h"
#include "passageiro.h"
#include "vagao.h"
#include "registropassageiros.h"
#include "trem.h"



void inicializar(Trem trem){

}


class controller
{
    Trem trem;
    RegistroPassageiros registroPassageiros;

public:
    controller(){

    }
    string process(string line){
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help"){
            return         "  # comandos                                 \n"
                           "  iniciarTrem _qtdVagoes                     \n"
                           "  addVagao _capacidade                       \n"
                           "  embarcar _passCpf                          \n"
                           "  desembarcar _passCpf                       \n"
                           "  show                                       \n"
                           "  registro                                   \n"
                           "  fim                                        \n";
        }
        else if(cmd == "iniciarTrem"){
            trem = Trem(Int(ui[1]));
            return "";
        }
        else if(cmd == "addVagao"){
            trem.addVagao(Int(ui[1]));
            return "Vagao adicionado!";
        }
        else if(cmd == "embarcar"){
            Passageiro *newpass = new Passageiro(ui[1]);
            trem.embarcar(newpass);
            registroPassageiros.addPass(*newpass);
            return "Passageiro embarcado com sucesso!";
        }
        else if(cmd == "desembarcar"){
            Passageiro *oldpass = trem.desembarcar(ui[1]);
            if(oldpass == nullptr){
                         //Por que não dá certo chamar throw string(); aqui?
             throw string( "O passageiro não está no trem!");
            }else{

                delete(oldpass);
                return "Passageiro desembarcado!";
            }
        }
        else if(cmd == "show"){
            return trem.toString();
        }
        else if(cmd == "registro"){
            return registroPassageiros.toString();
        }
        else{
            throw string("Comando não encontrado!");
        }
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
            catch(string& erro){
                cout << erro << endl;
            }
        }


    }
};

#endif // CONTROLLER_H

