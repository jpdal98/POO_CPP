#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int numeroConta = 1;

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
    bool ativa;

    Conta(int numero = 0, bool ativa = false){
        this->numero = numero;
        this->ativa = ativa;
    }

public:

    void setEstado(bool ativa){
        this->ativa = ativa;
    }

    bool getEstado(){
        return this->ativa;
    }

    int getNumero(){
        return this->numero;
    }

    float getSaldo(){
        return this->saldo;
    }

    void setNumero(int numero){
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

//   int transferir(Conta other, float valor){

//   }



};

class Cliente{
    string cpf;
    vector<Conta> contas;

public:
    Cliente(string cpf){
        this->cpf = cpf;
    }

    vector<Conta> getContas(){
        return this->contas;
    }


    void setCpf(string cpf){
        this->cpf = cpf;
    }

    string getCpf(){
        return this->cpf;
    }
    vector<Conta>& getConta(){
        return contas;
    }

    void showConta(){
        for(auto c : contas){
            cout << c.getNumero() << ' ' << c.ativa << endl;
        }
    }


    bool addConta(Conta conta){
        contas.push_back(conta);
        return true;
    }



    int encerrarConta(int numero){
        for(auto conta : contas){
            if(conta.getNumero() == numero){
                if(conta.getEstado() == true){
                    if(conta.getSaldo() == 0){
                        conta.setEstado(false);
                        return 1;
                    }
                    else
                        return -1;
                }
                else
                    return -2;
            }

        }
        return -3;

    }

    string showDados(){
        stringstream ss;
        float total = 0;
        ss << "Cliente: " << getCpf() << endl;
        for(auto conta : contas){
            total += conta.getSaldo();
            ss << "Conta: " << conta.getNumero() << ", Saldo: " << conta.getSaldo() << ", Status: " << conta.getEstado() << endl;

        }
        ss << "Saldo total: " << total << endl;
        return ss.str();
    }



};

class Agencia{
    vector<Cliente> clientes;

public:
    Agencia(){

    }

    bool addCliente(string cpf){
        for(auto cli : clientes){
            if(cli.getCpf() == cpf)
                return false;
        }
        clientes.push_back(Cliente(cpf));
        abrirConta(cpf);
        return true;
    }


    int abrirConta(string cpf){
        for(auto cli : clientes){
            if(cli.getCpf() == cpf){
                vector<Conta>& conta = cli.getConta();
                if(conta.size() >= 2){
                    return -2;
                }else{
                    cli.addConta(Conta(numeroConta, true));
                    //conta.push_back(Conta(numeroConta, true));
                    numeroConta++;
                    return 1;
                }
            }
        }
        return -1;
    }

//    int encerrarConta(int numero){
//        for(auto cli : clientes){
//            vector<Conta>& conta = cli.getConta();
//            for(auto cc : conta){
//               if(cc.getNumero() == numero){
//                    cc.ativa = false;
//                    return
//               }
//            }
//        }
//    }

    string showAllCli(){
        stringstream ss;
        for(auto cli : clientes){
            ss << cli.getCpf() << " [";
            for(auto conta : cli.getContas())
                ss << conta.getNumero() << " ";
            ss << " ]" << endl;
        }

        return ss.str();
    }

    Cliente* getClienteCpf(string cpf){
        for(auto& cli : clientes)
            if(cli.getCpf() == cpf)
                return &cli;
           return nullptr;
    }

    Cliente* getClienteNumero(int numero){
        for(auto& cli : clientes)
            for(auto& conta : cli.getConta()){
                if(conta.getNumero() == numero)
                    return &cli;
                return nullptr;
           }
    }


};


void inicializar(Conta& conta){
    conta = Conta(4531);
    conta.depositar(100);
    conta.sacar(70);
}

void interacaoUsuario(Agencia& agencia){
    string op;
    Cliente * cliente = nullptr;
    Conta conta;
    cout << "Digite comando ou help" << endl;
    while(op != "fim"){
        cin >> op;

        if(op == "help"){
            cout << " " << endl
                 << "iniciar $numero" << endl
                 << "saldo"           << endl
                 << "saque $valor"    << endl
                 << "deposito $valor" << endl
                 << "extrato"         << endl
                 << "extratoN $qtd"   << endl
                 << "fim"             << endl;

        }
        if(op == "login"){
            if(cliente == nullptr){
                string cpf;
                cin >> cpf;
                cliente = agencia.getClienteCpf(cpf);
                if(cliente == nullptr)
                    cout << "Erro | cpf inválido" << endl;
                else
                    cout << "ok" << endl;
            }
            else
                cout << "Já há uma pessoa logada" << endl;

        }
        if(op == "logout"){
            if(cliente != nullptr){
                cliente = nullptr;
                cout << "ok" << endl;
            }else{
                cout << "Erro | nenhum cliente logado" << endl;
            }

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
    Agencia agencia;
    //inicializar(agencia);
    interacaoUsuario(agencia);

}
