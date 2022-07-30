//
// Created by anuar on 11/04/2022.
//

#ifndef MAIN_CPP_DATE_H
#define MAIN_CPP_DATE_H


class Date {
    int dia;
    int mes;
    int anio;
public:
    Date();

    Date(int dia, int mes, int anio);

    void setDia(int dia);

    void setMes(int mes);

    void setAnio(int anio);

    int getDia() const;

    int getMes() const;

    int getAnio() const;

};
Date::Date(){
    dia=0;
    mes=0;
    anio=0;
}
Date::Date(int dia, int mes, int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}
int Date::getDia() const {
    return dia;
}

int Date::getMes() const {
    return mes;
}

int Date::getAnio() const {
    return anio;
}

void Date::setDia(int dia) {
    Date::dia = dia;
}

void Date::setMes(int mes) {
    Date::mes = mes;
}

void Date::setAnio(int anio) {
    Date::anio = anio;
}





#endif //MAIN_CPP_DATE_H
