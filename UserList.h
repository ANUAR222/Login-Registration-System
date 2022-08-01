//
// Created by anuar on 17/05/2022.
//

#ifndef DATE_H_USERLIST_H
#define DATE_H_USERLIST_H
const int MAX_USERS=1000;
const int MAX_REVIEWS=2000;
#include "User.h"
#include "Date.h"
#include "iostream"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class UserList {
     int current_size;
     User* list[MAX_USERS];
     int number_of_reviews;
public:
    UserList();
    UserList(string users_file_path);
    bool dump(string users_file_path);
    void addUser(User *user);
    string searchUser(int id);
    int medianAge();
    int searchUser_by_email(string email);
    void removeUser(User *user);
    int numero_de_filas(string file_path);
    int getCurrentSize() const;
    void alphabetical_sort();
    bool essubcade(string cadena, string subcadena);
    User *const *getList() const;

    int getNumberOfReviews() const;

    void setCurrentSize(int currentSize);

    void setNumberOfReviews(int numberOfReviews);

};
UserList::UserList(string users_file_path){
    int n1=1,n2,id;
    User *usuario;
    string nombre,apellid,email,tag ,text,genero;
    Gender gner;
    bool like;
    int current_ize=0;
    Date cumple;
    char temp[100];
    string nombreArchivo = users_file_path;
    ifstream archivo(nombreArchivo);
    string linea;
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            n1++;
        }
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    archivo.close();
    archivo.open(nombreArchivo);
        for (int i = 0; i < n1; ++i) {
            getline(archivo, linea, ';');
            id= atoi(temp);
            archivo.getline(temp,100,';');
            nombre=temp;
            archivo.getline(temp,100,';');
            apellid=temp;
            archivo.getline(temp,100,';');
            email=temp;
            archivo.getline(temp,100,'/');
            cumple.setDia(atoi(temp));
            archivo.getline(temp,100,'/');
            cumple.setMes(atoi(temp));
            archivo.getline(temp,100,';');
            cumple.setAnio(atoi(temp));
            archivo.getline(temp,100,';');
            tag=temp;
            archivo.getline(temp,100,'\n');
            text=temp;
            id=i;
            usuario=new User(id,nombre,apellid,email,cumple,gner,text);

            current_size=i;
            list[i]=usuario;
        }

    archivo.close();
}
int UserList::medianAge() {
    int ages[current_size];
    for (int i = 0; i < current_size; ++i) {
        ages[i]=list[i]->getBirthdate().getEdad();
    }
    int mediana=ages[current_size/2];
    return mediana;

}
void UserList::removeUser(User *user){
    for (int i = 0; i < current_size; ++i) {
        if(list[i]->getId()==user->getId()){
            list[i]=NULL;
            current_size--;
            break;
        }
    }
}
int UserList::searchUser_by_email(string email){
    for (int i = 0; i < current_size; ++i) {
        if(list[i]->getEmail()==email){
            return list[i]->getId();
        }
    }
    return -1;
}
string UserList::searchUser(int id){
    //bianary search
    int left=0,right=current_size-1,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(list[mid]->getId()==id){
            return list[mid]->getName();
        }else if(list[mid]->getId()<id){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return "";
}
void UserList::alphabetical_sort(){
    User *aux;
    for (int i = 0; i < current_size; ++i) {
        for (int j = 0; j < current_size-1; ++j) {
            if(list[j]->getName()[0]>list[j+1]->getName()[0]){
                aux=list[j];
                list[j]=list[j+1];
                list[j+1]=aux;
            }

        }
    }
};
bool UserList::essubcade(string cadena, string subcadena){
    int i,j,k;
    i=0;
    j=0;
    k=0;
    while (i<cadena.length()){
        if (cadena[i]==subcadena[j]){
            j++;
            if (j==subcadena.length()){
                return true;
            }
        }
        else{
            j=0;
        }
        i++;
    }
    return false;
};
int UserList::numero_de_filas(string file_path){
    string nombreArchivo = file_path;
    ifstream archivo(nombreArchivo);
    string linea;
    int n1;
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            n1++;
        }
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    return n1;
};
void UserList::addUser(User *user){
    list[current_size]=user;
    current_size++;
};
bool UserList::dump(string users_file_path){
    string nombreArchivo = users_file_path;
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < current_size; ++i) {
            archivo << list[i]->getId() << ';' << list[i]->getName() << ';' << list[i]->getSurname() << ';' << list[i]->getEmail() << ';' << list[i]->getBirthdate().getDia() << '/' << list[i]->getBirthdate().getMes() << '/' << list[i]->getBirthdate().getAnio() << ';' << list[i]->getGender()<<';'<<list[i]->getConteaseña() << '\n';
        }
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    archivo.close();
    return true;
}
int UserList::getCurrentSize() const {
    return current_size;
}
User *const *UserList::getList() const {
    return list;
}
int UserList::getNumberOfReviews() const {
    return number_of_reviews;
}
UserList::UserList(){
    this->current_size=0;
    *list=NULL;
    this->number_of_reviews=0;
}



void UserList::setCurrentSize(int currentSize) {
    current_size = currentSize;
}

void UserList::setNumberOfReviews(int numberOfReviews) {
    number_of_reviews = numberOfReviews;
};


#endif //DATE_H_USERLIST_H
