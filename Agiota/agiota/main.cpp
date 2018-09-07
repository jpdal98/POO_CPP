#include <iostream>
#include <vector>

using namespace std;

class Transacao{
    int id{0};
    string cliente;
    float valor;

public:
    Transacao(string cliente = "" , float valor = 0.0){
        this->cliente = cliente;
        this->valor = valor;
    }

    string getClienteName(){
        return this->cliente;
    }

    int getId(){
        return this->id;
    }

    float getValor(){
        return this->valor;
    }

    void setClienteName(string cliente){
        this->cliente = cliente;
    }

    void setId(int id){
        this->id = id;
    }

    void setValor(float valor){
        this->valor = valor;
    }

};

class Sistema{
    int nextId{0};
    float balanco{0.0};
    vector<Transacao> transacoes;

public:
    Sistema(){

    }

    int getNextId(){
        return this->nextId;
    }

    float getBalanco(){
        return this->balanco;
    }

    void setNextId(int nextId){
        this->nextId = nextId;
    }

    void setBalanco(float balanco){
        this->balanco = balanco;
    }

    int addTran(string nome, float valor){
        Transacao transacao;
        if(valor == 0)
            return -1;
        transacoes.push_back(transacao);


    }


};

void iniciarSistema(Sistema& sistema){
    sistema.setBalanco(1000);
    sistema.transacoes.erase(0, sistema.transacoes.size());
}



int main()
{
}
