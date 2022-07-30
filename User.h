//
// Created by anuar on 11/04/2022.
//

#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H


#include <iostream>
#include "Date.h"
using namespace std;
enum Gender {FEMALE, MALE, OTHER};
class User {
    int id;
    string name; // Nombre
    string surname; // Apellido/s
    string email; // Correo electrónico
    Date birthdate; // Fecha de nacimiento
    Gender gender; // Género
    string conteaseña;
    float funds; // Dinero disponible en la cuenta

    int max_games_library; // Tamaño del vector "library"
    int max_wished; // Tamaño del vector "wishlist"
    int max_reviews; // Tamaño del vector "reviews"
    int max_friends; // Tamaño del vector "friends"

    int num_games; // Número de juegos en "library"
    int num_wished; // Número de juegos en "wishlist"
    int num_reviews; // Número de análisis en "reviews"
    int num_friends; // Número de usuarios en "friends"



    User** friends; // Lista de amigos del usuario
public:
    User();
    User(int id2,string name2,string surname2,string email2,Date birthdate2, Gender gender2,string paswor);
    User(int maxFriends2, int max_games_library2, int numWished2, int numReviews2);
    int operator +=(int cant);
    int operator +(const User &usuario2);
    bool addFunds(float amount);
    bool addFriend(User* user);

    void setConteaseña(const string &conteaseña);

    bool removeFriend(User* user);
    //metods get
    int get_num_games();
    int get_num_wished();

    const string &getConteaseña() const;

    int get_num_reviews();
    int get_num_users();
    int get_funds();
    int getId() const;
    const string &getName() const;
    const string &getSurname() const;
    const string &getEmail() const;
    const Date &getBirthdate() const;
    Gender getGender() const;
    float getFunds() const;
    void setName(const string &name);
    void setSurname(const string &surname);
    void setEmail(const string &email);
    void setBirthdate(const Date &birthdate);
    void setGender(Gender gender);
    void setFunds(float funds);
    void setNumGames(int numGames);
    User **get_friends();
    ~User();
};
User::User(){
    id=0;
    name="  ";
    surname="  ";
    email="test@gmail.com";
    gender=OTHER;
    birthdate={0,0,0};
    num_games=0;
    num_wished=0;
    num_reviews=0;
    num_friends=0;
    max_games_library=0;
    max_wished=0;
    num_wished=0;

};
User::User(int id2,string name2,string surname2,string email2,Date birthdate2, Gender gender2,string paswor) {
    id=id2;
    name=name2;
    surname=surname2;
    email=email2;
    gender=gender2;
    birthdate=birthdate2;
    funds=0;
    conteaseña=paswor;
    num_wished=0;
    num_games=0;
    num_reviews=0;
    num_friends=0;
    max_wished=4;
    max_games_library=4;
    max_friends=4;
    max_reviews=4;
}
int User::operator+=(int cant) {
    funds+=cant;
    return funds;
};
int User::operator +(const User &usuario2){
    return this->funds+usuario2.funds;
};

int User::get_num_games(){
    return num_games;
};
int User::get_num_wished(){
    return num_wished;
};
int User::get_num_reviews(){
    return num_reviews;
};
int User::get_num_users(){
    return id;
};
int User::get_funds(){
    return funds;
};

User **User::get_friends(){
    return friends;
};
bool User::addFunds(float amount) {
    if (amount>0){
        funds=funds+amount;
        return true;
    }
    else{
        return false;
    }
};



bool User::addFriend(User* user){
    *friends=user;
    return true;
};
bool User::removeFriend(User* user){
    bool x;
    for (int i = 0; i < max_friends; ++i) {
        if(friends[i]==user){
            friends=NULL;
            x=true;
        }else{
            x=false;
        }
    }
    return x;
}


void User::setName(const string &name) {
    User::name = name;
}

void User::setSurname(const string &surname) {
    User::surname = surname;
}

void User::setEmail(const string &email) {
    User::email = email;
}

void User::setBirthdate(const Date &birthdate) {
    User::birthdate = birthdate;
}

void User::setGender(Gender gender) {
    User::gender = gender;
}

void User::setFunds(float funds) {
    User::funds = funds;
}

void User::setNumGames(int numGames) {
    num_games = numGames;
}

int User::getId() const {
    return id;
}

const string &User::getName() const {
    return name;
}

const string &User::getSurname() const {
    return surname;
}

const string &User::getEmail() const {
    return email;
}

const Date &User::getBirthdate() const {
    return birthdate;
}

Gender User::getGender() const {
    return gender;
}

float User::getFunds() const {
    return funds;
}

const string &User::getConteaseña() const {
    return conteaseña;
}

void User::setConteaseña(const string &conteaseña) {
    User::conteaseña = conteaseña;
}

#endif //MAIN_CPP_USER_H
