#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Nota{
    string titulo;
    string texto;
public:
    Nota(string titulo = "", string texto = ""){
        this->titulo = titulo;
        this->texto = texto;
    }

    string toString(){

    }

    string getTitulo(){
        return this->titulo;
    }
    void setTitulo(string titulo){
        this->titulo = titulo;
    }
    string getTexto(){
        return this->texto;
    }
    void setTexto(string texto){
        this->texto = texto;
    }

};

class Usuario{
    string username;
    string password;
    vector<Nota> notas;
public:
    Usuario(string username = "", string password = ""){
        this->username = username;
        this->password = password;
    }
    bool addNote(Nota nota){
        for(auto note : notas)
            if(nota.getTitulo() == note.getTitulo())
                return false;
        notas.push_back(nota);
        return true;
    }
    string getName(){
        return this->username;
    }
    void setName(string username){
        this->username = username;
    }
    void


};

class Sistema{
    vector<Usuario> usuarios;

    Sistema(){

    }

    bool addUser(string username, string password){
        for(auto user : usuarios)
            if(username == user.getUsername())
                return false;
        usuarios.push_back(Usario(username, password));
        return true;
    }

    void showUsers(){
        for(auto name : usuarios)
            cout << " " << name.getName() << endl;

    }



};




int main()
{

}
