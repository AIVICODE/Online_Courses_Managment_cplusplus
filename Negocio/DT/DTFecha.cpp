#include "DTFecha.h"



#include <iostream>

using namespace std;

// Constructor por defecto
DTFecha::DTFecha(){}

// Constructor con parámetros
DTFecha::DTFecha(int d, int m, int a) {
    if (!esFechaValida(d, m, a)) {
        throw invalid_argument("Fecha no valida");
    }
    dia = d;
    mes = m;
    anio = a;
}

// Métodos de acceso (getters)
int DTFecha::getDia() const {
    return dia;
}

int DTFecha::getMes() const {
    return mes;
}

int DTFecha::getAnio() const {
    return anio;
}


bool DTFecha::esFechaValida(int d, int m, int a) const{
    if (a < 1 || m < 1 || m > 12 || d < 1) return false;
    int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Comprobar año bisiesto
    if (m == 2 && ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))) {
        diasEnMes[1] = 29;
    }

    return d <= diasEnMes[m - 1];
}


void DTFecha::imprimirFecha() const {
    cout << (dia < 10 ? "0" : "") << dia << "/"
         << (mes < 10 ? "0" : "") << mes << "/"
         << anio << endl;
}

