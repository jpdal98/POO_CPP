#include <iostream>
#include <vector>

using namespace std;

class Usuario{
    string u_tipo;

    Usuario(string tipo = "cliente"){
        u_tipo = tipo;
    }
}
class Produto{
public:
    string p_nome;
    int p_qtd;
    float p_preco;

    Produto(string nome="Nome", int qtd = 0, float preco = 0.0){
        p_nome = nome;
        p_qtd = qtd;
        p_preco = preco;
    }
};


class JunkMach{
public:
    int m_espirais;
    float m_dinheiro{0.0};
    float saldoCliente{0.0};
    vector<Produto> maquina;

    JunkMach(int qtd_esp = 1){
        m_espirais = qtd_esp;
        maquina.resize(qtd_esp);
    }

    float darTroco(){
        if (m_dinheiro > 0) {
            float valor = m_dinheiro;
            m_dinheiro = 0.0;
            return valor;
        }
        return 0.0;
    }
    //nao permitir valor negativo
    bool inserirDin(float value){
        if (value > 0.0 ){
            m_dinheiro += value;
            return true;
        }
        return false;
    }

    float getSaldo(){
        return saldo;
    }

    JunkMach *iniciar(int numEsp){
        return new JunkMach(numEsp);
    }

 /*   void printEspirais(){
        for(Produto p: maquina){
            cout << "Nome: " << p.p_nome << " Qtd: " << p.p_qtd << " Preco: " << p.p_preco << endl;
        }
    }
    */
};
int main()
{
    int ESPIRAIS = 4;
    string comando, inst;

    JunkMach maq(ESPIRAIS);

    while(comando != "fim"){
        cin >> comando;

        if(comando == "help"){
            cout << "inserirDin _valor"                  << endl
                 << "saldo"                              << endl
                 << "pedirTroco"                         << endl
                 << "iniciar _qtd"                       << endl
                 << "alterarProd _ind _nome _qtd _valor" << endl
                 << "comprar _ind"                       << endl;
                 << "status"                             << endl;
                 << "fim"                                << endl;
        }

        if(comando == "iniciar"){
            conta = Conta(read<int>());
        }
        if(comando == "saldo"){
            cout << conta.getSaldo() << endl;
        }
        if(comando == "inserirDin"){
            cout << (conta.inserirDin(read<float>())? "sucesso" : "erro") << endl;
        }
        if(comando == "pedirTroco"){
            cout << (conta.darTroco(read<float>())? "sucesso" : "erro") << endl;
        }





    return 0;
}

