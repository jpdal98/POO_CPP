#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

class Transacao{
    int id;
    string cliente;
    float valor;

public:
    Transacao(int id = 0, string cliente = "" , float valor = 0.0){
        this->cliente = cliente;
        this->valor = valor;
        this->id = id;
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
    vector<Transacao> transacoes;
    float balanco{0.0};

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
        if(valor == 0)
            return -1;

       // Transacao transacao;
        if((valor < 0.0) && (balanco < -valor)){
           return -2;
        }

        transacoes.push_back(Transacao(getNextId(), nome, valor));
        setNextId(getNextId()+1);
        setBalanco(getBalanco()+valor);
        return 1;
    }

    string showTran(){
        stringstream ss;
        ss << "Lista de Transacoes:" << endl;

        for(auto tran : transacoes){
              ss << "[ " << tran.getId() << " ]" << " "
                 << "[ " << tran.getClienteName() << " ]" << " "
                 << "[ " << tran.getValor() << " ]" << endl;
        }
            return ss.str();
    }

    bool rmTran(int id){
        if((id < 0) || (id >= transacoes.size())){
            return false;
        }
        setBalanco(getBalanco()-transacoes.at(id).getValor());
        transacoes.erase(transacoes.begin()+id);

        return true;
    }

    string showCli(string nome){
        float saldo = 0.0;
        stringstream ss;
        ss << "Lista de Transacoes de " << nome << ": " << endl;

        for(auto tran : transacoes){
            if(tran.getClienteName() == nome){
                ss << "[ " << tran.getId() << " ]" << " "
                   << "[ " << tran.getClienteName() << " ]" << " "
                   << "[ " << tran.getValor() << " ]" << endl;

                saldo += tran.getValor();
            }
        }
        ss << "Saldo: " << saldo << endl;
        return ss.str();
    }

    float fazerBalanco(){
        return balanco;
    }

    int sizeTran(){
        return transacoes.size();
    }

    int contarCli(){
        vector<string> clientes;
        int flag = 1;

        //clientes.push_back(transacoes.at(0).getClienteName());

        for(auto cli : transacoes){
            flag = 1;
            for(auto name : clientes){
                if(cli.getClienteName() == name){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                 clientes.push_back(cli.getClienteName());
            }
        }
        return clientes.size();
    }
};

void iniciarSistema(Sistema& sistema, float valor){
    int tamTran = sistema.sizeTran();    
    for(int id = 0; id < tamTran; id++){
        sistema.rmTran(0);
    }
    sistema.setBalanco(valor);
    sistema.setNextId(0);
}

void inicializarSistema(Sistema& sistema){
    sistema.addTran("Andre", -500);
    sistema.addTran("Pupilo", -200);
    sistema.addTran("Fernandes", -1000);
    sistema.addTran("Andre", 300);
}
void interacaoUsuario(Sistema& sistema){
    string op = "";
    cout << "Digite help ou comando:" << endl;

    while(op != "fim"){
        cin >> op;
        if(op == "help"){
        cout << "iniciar $valor" << endl
        << "addTran $nome $valor" << endl
        << "rmTran $id" << endl
        << "showTran" << endl
        << "showCli $nome" << endl
        << "balanco" << endl
        << "contarCli" << endl
        << "fim" << endl;
    }

    if(op == "iniciar"){
        float valor = read<float>();
        iniciarSistema(sistema, valor);
        cout << "Sistema iniciado com valor: " << valor << endl;
    }
    if(op == "addTran"){
        string nome = read<string>();
        float valor = read<float>();
        int op = sistema.addTran(nome, valor);
        switch (op){
        case -1:
            cout << "Não é possível realizar operação com 0 reais" << endl;
            break;
        case -2:
            cout << "Não há dinheiro suficiente para empréstimo." << endl;
            break;
        case 1:
            cout << "Transacao " << sistema.getNextId() - 1 << " adicionada" << endl;
            break;
        default:
            break;
        }



    }
    if(op == "rmTran"){
        cout << (sistema.rmTran(read<int>())? "Trasação removida" : "Transação não encontrada") << endl;
    }
    if(op == "showTran"){
        cout << sistema.showTran() << endl;
    }
    if(op == "showCli"){
        cout << sistema.showCli(read<string>()) << endl;
    }
    if(op == "balanco"){
        cout << "Balanço: " << sistema.fazerBalanco() << endl;
    }

    if(op == "contarCli"){
        cout << "Existem " << sistema.contarCli() << " clientes diferentes no sistema" << endl;
    }
    if(op == "fim"){

    }

    }
}


int main()
{
    Sistema sistema;
    sistema.setBalanco(2000);
    inicializarSistema(sistema);
    interacaoUsuario(sistema);
}
