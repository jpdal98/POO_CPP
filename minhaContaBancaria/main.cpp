#include <iostream>
#include <vector>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;

}

struct Operacao{
    string descricao;
    float valor;
    float saldoResidual;

    Operacao(string descricao = "", float valor = 0.0, float saldoResidual = 0.0){
        this->descricao = descricao;
        this->valor = valor;
        this->saldoResidual = saldoResidual;
    }

};

class Conta{
public:
    int numero;
    float saldo{0};
    vector<Operacao> extrato;

    Conta(int numero = 0){
        this->numero = numero;
    }

public:

    int getNumero(){
        return this->numero;
    }

    float getSaldo(){
        return this->saldo;
    }

    void setNumero(float numero){
        this->numero = numero;
    }
    int sacar(float valor){
        if(this->saldo < valor){
            return -1;
        }
        else if(valor < 0){
            return -2;
        }
        else{
        this->saldo -= valor;    
        this->extrato.push_back(Operacao("Saque ", -valor, this->saldo));
        return 1;
        }
    }

    bool depositar(float valor){
        if(valor < 0)
            return false;
        this->saldo += valor;
        this->extrato.push_back(Operacao("Depósito ", valor, this->saldo));
        return true;
    }

    vector<Operacao> getExtrato(){
        return this->extrato;
    }

    vector<Operacao> getExtratoN(int qtd){
        int indMax = extrato.size();
        int indice = (extrato.size() - qtd);
        vector<Operacao> extratoN;
        for(int i = indice; i < indMax; i++){
            extratoN.push_back(extrato[i]);
        }
        return extratoN;
    }


};

void inicializar(Conta& conta){
    conta = Conta(4531);
    conta.depositar(100);
    conta.sacar(70);
}

void interacaoUsuario(Conta& conta){
    string op;
    cout << "Digite comando ou help" << endl;
    while(op != "fim"){
        cin >> op;

        if(op == "help"){
            cout << "iniciar $numero" << endl
                 << "saldo"           << endl
                 << "saque $valor"    << endl
                 << "deposito $valor" << endl
                 << "extrato"         << endl
                 << "extratoN $qtd"   << endl
                 << "fim"             << endl;

        }
        if(op == "iniciar")
            conta = Conta(read<int>());

        if(op == "saldo")
            cout << conta.getSaldo() << endl;

        if(op == "deposito")
            cout << (conta.depositar(read<float>())? "Deposito realizado" : "Erro") << endl;

        if(op == "saque"){
            float value = read<float>();
            int resultado = conta.sacar(value);
            switch (resultado){
            case -1:
                cout << "Erro - saldo insuficiente" << endl;
                break;

            case -2:
                cout << "Erro - valor inválido" << endl;
                break;
            default:
                cout << "Sacado R$ " << value << endl;
                break;
            }
        }
        if(op == "extrato"){
            for(auto operacao : conta.getExtrato()){
                cout << operacao.descricao << operacao.valor << " Saldo R$" <<  operacao.saldoResidual << endl;
            }
        }
        if(op == "extratoN"){
            for(auto operacao : conta.getExtratoN(read<int>())){
                cout << operacao.descricao << operacao.valor << " Saldo R$" <<  operacao.saldoResidual << endl;
            }
        }
        if(op == "fim"){
        }


    }

}


int main(){
    Conta conta;
    inicializar(conta);
    interacaoUsuario(conta);

}
