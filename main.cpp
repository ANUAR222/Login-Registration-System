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
    bool esta= true;

    cout<<"introduzca si quiere registrar";
    cin>>esta;
    UserList lista( "C:\\Users\\anuar\\OneDrive\\Escritorio\\untitled32\\users.txt");
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
        }if(esta==false){
            cout<<"Gracias por usar nuestro servicio"<<endl;
        }
        lista.dump("C:\\Users\\anuar\\OneDrive\\Escritorio\\untitled32\\users.txt");
        cout<<"introduzca si quiere iniciar sesion";
        cin>>esta;
        while (esta){
            cout << "Ingrese su email: ";
            cin>>email;
            int id=lista.searchUser_by_email(email);
            if(id==-1){
                cout<<"Usuario no encontrado"<<endl;
            }else{
                cout << "Ingrese su contraseña: ";
                cin>>password;
                if(lista.getList()[id]->getConteaseña()==password){
                    cout<<"Bienvenido"<<endl;
                }else{
                    cout<<"Contraseña incorrecta"<<endl;
                }
            }
            cout << "Desea iniciar sesion? 1: si 0: no: ";
            cin>>esta;
        }if(esta==false){
            cout<<"Gracias por usar nuestro servicio"<<endl;
        }
    lista.alphabetical_sort();

    return 0;
}


