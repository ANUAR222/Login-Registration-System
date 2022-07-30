//
// Created by anuar on 11/04/2022.
//


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


