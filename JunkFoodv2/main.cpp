#include <iostream>
#include <vector>


using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

struct Espiral{ //Espiral representa um produto
    string e_nome;
    int e_qtd;
    float e_value;
    int maxProdutos;


    Espiral(string nome="-------", int qtd = 0, float value = 0.0f){
        e_nome = nome;
        e_qtd = qtd;
        e_value = value;
    }

};

class Maquina{
public:
    vector<Espiral> espirais;   //Um vetor de espirais (produtos) representam a máquina
    float m_saldo{0.0};
    float m_lucro{0.0};

    Maquina(int qtd): espirais(qtd) {}

 //Função para inserir dinheiro na máquina
    bool inserirDin(float value){
        if(value <= 0){
            return false;
        }
        m_saldo += value;
        return true;
    }

//Função que retorna o saldo da máquina
    float mostrarSaldo(){
        return m_saldo;
    }

//Função que retorna o resto de dinheiro, pertencente ao usuário, que tem na máquina.
    void darTroco(){
        cout << "Voce retirou " << m_saldo << " Reais" << endl;
        m_saldo = 0.0;        
    }

//Função que reinicia a máquina com um determinado tamanho, setando todas as configurações para default.
    void iniciarMaquina(int qtd, int maxProdutos){
        this->espirais.resize(0);
        this->espirais.resize(qtd);
        for(auto& espiral : espirais){
            espiral.maxProdutos = maxProdutos;
        }

    }

//Função que altera as características de determinada espiral da máquina.
    bool alterarEspiral(int pos, string nome, int qtd, float value){
        if((pos < 0) || (pos >= espirais.size())){
            return false;
        }else if(qtd < 0){
            return false;
        }else if(value <= 0.0){
            return false;
        }else if(nome == ""){
            return false;
        }

        espirais.at(pos).e_nome = nome;
        espirais.at(pos).e_qtd = qtd;
        espirais.at(pos).e_value = value;

        return true;
    }

//Essa é a função usada para comprar produtos. Se a posição não existir ou não houver mais o produto no estoque,
//retornamos uma flag que indica esse tipo de erro. Se não houver dinheiro suficiente, retornamos outra flag que caracteriza esse erro.
//Se nenhum erro ocorrer, a compra é realizada com sucesso. Então decrementamos a qtd do produto, diminuimos o saldo e aumentamos o lucro.
    int comprarProduto(int pos){
        if((pos < 0) || (pos >= espirais.size())){
            return 0;
        }else if(espirais.at(pos).e_qtd <= 0){
            return 0;
        }else if((m_saldo < espirais.at(pos).e_value) || (m_saldo <= 0)){
            return 1;
        }

        espirais.at(pos).e_qtd -= 1;
        m_saldo -= espirais.at(pos).e_value;
        m_lucro += espirais.at(pos).e_value;

        return 2;
    }

 //Função que mostra a máquina.
    void mostrarStatus(){
        cout << "Saldo: " << m_saldo << endl;
        cout << "Lucro: " << m_lucro << endl;
        int ind = 0;

        for(Espiral esp: espirais){
            cout << "ind "     << ind << "\t" <<
                    ": Nome: " << esp.e_nome << "\t" <<
                    " Qtd: "   << esp.e_qtd << "\t" <<
                    " Valor: " << esp.e_value << endl;
            ind++;
        }
    }
};

void inicializarMaq(Maquina& maq){
    maq.espirais.at(0).e_nome = "Ruffles ";
    maq.espirais.at(0).e_qtd = 7;
    maq.espirais.at(0).e_value = 3.5;
    maq.espirais.at(1).e_nome = "KitKat ";
    maq.espirais.at(1).e_qtd = 10;
    maq.espirais.at(1).e_value = 2.5;
    maq.espirais.at(2).e_nome = "Fandangos ";
    maq.espirais.at(2).e_qtd = 4;
    maq.espirais.at(2).e_value = 2;
    maq.espirais.at(3).e_nome = "Disket ";
    maq.espirais.at(3).e_qtd = 6;
    maq.espirais.at(3).e_value = 1;
    maq.espirais.at(4).e_nome = "Sensações ";
    maq.espirais.at(4).e_qtd = 9;
    maq.espirais.at(4).e_value = 3.5;
    maq.espirais.at(5).e_nome = "Refrigerante ";
    maq.espirais.at(5).e_qtd = 5;
    maq.espirais.at(5).e_value = 3;
    maq.espirais.at(6).e_nome = "Cereal ";
    maq.espirais.at(6).e_qtd = 5;
    maq.espirais.at(6).e_value = 2.45;
    maq.espirais.at(7).e_nome = "Chicletes ";
    maq.espirais.at(7).e_qtd = 15;
    maq.espirais.at(7).e_value = 0.5;
}

void interacaoUsuario(Maquina maq){
    string comando, inst;
    cout << "Digite help" << endl;

    while(comando != "fim"){
           cin >> comando;

        if(comando == "help"){
           cout << "inserir _valor"                  << endl
                << "saldo"                              << endl
                << "pedirTroco"                         << endl
                << "iniciar _qtd"                       << endl
                << "alterarEspiral _ind _nome _qtd _valor" << endl
                << "comprar _ind"                       << endl
                << "status"                             << endl
                << "fim"                                << endl
                << "\n" << endl;
        }
        if(comando == "inserir"){
            if(maq.inserirDin(read<int>())){
                cout << "Sucesso" << endl;
            }else{
                cout << "Erro" << endl;
            }
        }
        if(comando == "saldo"){
            cout << maq.mostrarSaldo() << " Reais" << endl;
        }
        if(comando == "pedirTroco"){
            maq.darTroco();
        }
        if(comando == "iniciar"){
            maq.iniciarMaquina(read<int>());
            cout << "Sucesso" << endl;
        }
        if(comando == "alterarEspiral"){
            int ind, qtd;
            string nome;
            float valor;

            cin >> ind;
            cin >> nome;
            cin >> qtd;
            cin >> valor;
            if(maq.alterarEspiral(ind, nome, qtd, valor)){
                cout << "Sucesso" << endl;
            }else{
                cout << "Erro" << endl;
            }
        }
        if(comando == "comprar"){
            int pos = 0, res = 0;
            cin >> pos;

            res = maq.comprarProduto(pos);
            if(res == 0){
                cout << "erro(Produto não existe)" << endl;
            }else if(res == 1){
                cout << "erro(Saldo insuficiente)" << endl;
            }else{
                cout << "Ok\nVoce comprou um " << maq.espirais.at(pos).e_nome << endl;
            }
        }
        if(comando == "status"){
            maq.mostrarStatus();
        }

    }

}

int main()
{
    int ESPIRAIS = 10;
    Maquina maq(ESPIRAIS);
    inicializarMaq(maq);
    interacaoUsuario(maq);


    return 0;
}

