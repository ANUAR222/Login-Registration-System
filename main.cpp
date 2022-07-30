#include <iostream>
#include "UserList.h"
using namespace std;
int main() {
    string email;
    string nombre;
    string apellido;
    Date cumple(24,1,2002);
    Gender genro;
    string password;
    bool registro;
    bool esta= true;
    UserList lista( "users.txt");
        while (esta){
            cout << "Ingrese su email: ";
            cin>>email;
            cout << "Ingrese su nombre: ";
            cin>>nombre;
            cout << "Ingrese su apellido: ";
            cin>>apellido;
            cout << "Ingrese su contraseña: ";
            cin>>password;
            User *usuario = new User(0,nombre,apellido,email,cumple,genro,password);
            lista.addUser(usuario);
            cout << "Desea ingresar otro usuario? 1: si 0: no: ";
            cin>>esta;
        }
    for (int i = 0; i < lista.getCurrentSize(); ++i) {
        if(lista.getList()[i]->getEmail()==email){
            cout<<"el usuario existe"<<endl;
            break;
         } else{
            if(i==lista.getCurrentSize()-1){
                cout<<"el usuario no existe"<<endl;
            }

         }
        if (lista.getList()[i]->getConteaseña()==password){
        cout<<"el cotar existe"<<endl;
        break;
        } else{
            if(i==lista.getCurrentSize()-1){
                cout<<"el usuario no existe"<<endl;
            }
    }}

    lista.dump("users.txt");
    return 0;
}


