#include <iostream>
#include <map>
#include <ctype.h>
#include <vector>
#include <sstream>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

class Telefone{
    string foneid;
    string number;

public:
    Telefone(string descricao = "", string fone = ""){
        this->foneid = descricao;
        this->number = fone;
    }

    string getNumber(){
        return number;
    }
    void setNumber(string number){
        this->number = number;
    }
    string getDescricao(){
        return foneid;
    }
    void setDescricao(string descricao){
        this->foneid = descricao;
    }

    bool validate(string numero){
        for(char s : numero){
            if(!isdigit(s)){
                return false;
            }
        }
        return true;
    }
};

class Contato{
    string nome;
    vector<Telefone> telefones;
    bool isFavorited{false};

public:
    Contato(string nome = ""){
        this->nome = nome;
    }

    string getNome(){
        return nome;
    }
    void setNome(string nome){
        this->nome = nome;
    }

    vector<Telefone> getTelefones(){
        return telefones;
    }

    bool getFavorited(){
        return isFavorited;
    }
    void setFavorited(bool value){
        isFavorited = value;
    }

    bool addTelefone(string foneid, string numero){
        for(auto fones: telefones){
            if(fones.getDescricao() == foneid){
                return false;
            }
        }
        Telefone fone(foneid);
        if(fone.validate(numero)){
            fone.setNumber(numero);
            telefones.push_back(fone);
            return true;

        }
        return false;
    }

    bool rmTelefone(string foneid){
        for(unsigned int cont = 0; cont < telefones.size(); cont++){
            if(telefones[cont].getDescricao() == foneid){
              telefones.erase(telefones.begin()+cont);
              return true;
            }
        }

        return false;
    }
};



class Agenda{
    map<string,Contato> contatos;
    map<string,Contato> favoritos;

public:
    Agenda(){}

    bool addContato(string nome){
        auto it = contatos.find(nome);
        if(it != contatos.end())
            return false;

        contatos[nome] = Contato(nome);
        return true;

    }

    Contato * getContato(string nome){
        auto it = contatos.find(nome);
        return((it != contatos.end()) ? (&it->second) : nullptr);
    }


    bool rmContato(string nome){
        auto it = contatos.find(nome);
        if(it == contatos.end())
            return false;

        if(it->second.getFavorited()){
            favoritos.erase(nome);

        }
        contatos.erase(nome);
        return true;
    }

    string showAllContacts(){
        stringstream ss;

        for(auto contato : contatos){
            if(contato.second.getFavorited())
                ss << "@ ";
            else
                ss << "- ";

            ss << contato.second.getNome();

            for(auto telefone : contato.second.getTelefones()){
                ss << " [" << telefone.getDescricao() << " " << telefone.getNumber() << "] ";
            }
            ss << endl;
        }

       ss << endl;
       return ss.str();
    }

    string showAllFavorites(){
        stringstream ss;

        for(auto favorito : favoritos){
            ss << "@ ";
            ss << favorito.second.getNome();

            for(auto telefone : favorito.second.getTelefones()){
                ss << " [" << telefone.getNumber() << " " << telefone.getDescricao() << "] ";
            }
            ss << endl;
        }

       ss << endl;
       return ss.str();
    }

    string toString(Contato contato){
        stringstream ss;
        if(contato.getFavorited())
            ss << "@ ";
        else
            ss << "- ";

        ss << contato.getNome();

        for(auto telefone : contato.getTelefones()){

            ss << " [" << telefone.getDescricao() << " " << telefone.getNumber() << "] ";
        }
       ss << endl;
       return ss.str();
    }



    bool favoritar(string nome){
        auto cont = contatos.find(nome);

        if(cont == contatos.end()){
            return false;
        }

        if(cont->second.getFavorited() == false){
            cont->second.setFavorited(true);
            favoritos[nome] = cont->second;
            return true;
        }

        return false;   //já está favoritado
    }

    bool desfavoritar(string nome){
        auto fav = favoritos.find(nome);
        if(fav == favoritos.end()){
            return false;
        }
        auto cont = contatos.find(nome);
        if(cont != contatos.end()){
            cont->second.setFavorited(false);
            favoritos.erase(nome);
            return true;
        }

        return false;
    }
    vector<Contato> search(string pattern){
        vector<Contato> resp;

        for(auto par: contatos){
            if(toString(par.second).find(pattern) != string::npos)
                resp.push_back(par.second);
        }
        return resp;
    }
//    vector<Contato> getFavorited(){
//        vector<Contato> resp;
//        for(auto favorito : favoritos){
//            resp.push_back(favorito.second);
//        }
//        return resp;
//    }

    Contato * getFavorited(string nome){
        auto it = favoritos.find(nome);
        return((it != favoritos.end()) ? (&it->second) : nullptr);
    }

};

void inicialization(Agenda &agenda){
    agenda.addContato("Marisa");
    agenda.getContato("Marisa")->addTelefone("tim", "49324902");
    agenda.getContato("Marisa")->addTelefone("oi", "3123534534");
    agenda.favoritar("Marisa");
    agenda.addContato("Marianna");
    agenda.getContato("Marianna")->addTelefone("tim", "32433332");
    agenda.addContato("Raynara");
    agenda.getContato("Raynara")->addTelefone("claro", "11111");
    agenda.addContato("Victoria");
    agenda.getContato("Victoria")->addTelefone("tim", "22222");
    agenda.addContato("Andre");
    agenda.getContato("Andre")->addTelefone("casa", "222122");
}

void Controller(Agenda &agenda){

    string op;
    while(op != "fim"){
        cout << "\nDigite help ou o comando\n" << endl;
        cin >> op;
        if(op == "help"){
            cout << "\naddContato $nome" << endl
                 << "rmContato $nome" << endl
                 << "addFone $nome $foneId $numero" << endl
                 << "rmFone $nome $foneId" << endl
                 << "showContatos" << endl
                 << "search $pattern" << endl
                 << "favContato $nome" << endl
                 << "desfavContato $nome" << endl
                 << "showFavoritos" << endl
                 << "fim" << endl;

        }
        if(op == "addContato"){
            if(agenda.addContato(read<string>()))
                cout << "Contato adicionado" << endl;
            else
                cout << "Erro! Contato já existe." << endl;

        }
        if(op == "rmContato"){
            if(agenda.rmContato(read<string>()))
                cout << "Contato removido" << endl;
            else
                cout << "Erro! Contato não existe." << endl;

        }
        if(op == "addFone"){
            string nome = read<string>();
            string foneId = read<string>();
            string numero = read<string>();
            auto contato = agenda.getContato(nome);


            if(!contato){
                cout << "Nome não existe" << endl;
                continue;
            }
            if(contato->addTelefone(foneId, numero)){
                cout << "Telefone adicionado" << endl;
                auto favorito = agenda.getFavorited(nome);
                if(!favorito){
                    continue;
                }
                else{
                    favorito->addTelefone(foneId, numero);
                }

            }
            else{
                cout << "Erro" << endl;
                continue;
            }




        }

        if(op == "rmFone"){
            string nome = read<string>();
            string foneId = read<string>();
            auto contato = agenda.getContato(nome);
            if(!contato){
                cout << "Nome não existe" << endl;
            }
            if(contato->rmTelefone(foneId)){

                cout << "Telefone removido" << endl;

                auto favorito = agenda.getFavorited(nome);
                if(!favorito){
                    continue;
                }
                else{
                    favorito->rmTelefone(foneId);
                }


            }
            else
                cout << "Erro" << endl;
        }
        if(op == "showContatos"){
           cout << agenda.showAllContacts() << endl;
        }

        if(op == "search"){
            string padrao = read<string>();
            auto contatos = agenda.search(padrao);
            for(auto contato : contatos){
               cout << agenda.toString(contato) << endl;
            }

        }
        if(op == "favContato"){
            if(agenda.favoritar(read<string>()))
                cout << "Contato favoritado" << endl;
            else
                cout << "Erro! Nome não encontrado" << endl;
        }
        if(op == "desfavContato"){
            if(agenda.desfavoritar(read<string>()))
                cout << "Contato desfavoritado" << endl;
            else
                cout << "Erro" << endl;
        }
        if(op == "showFavoritos"){
            cout << agenda.showAllFavorites() << endl;
        }


    }
}


int main()
{
    Agenda agenda;
    inicialization(agenda);
    Controller(agenda);

    return 0;
}
