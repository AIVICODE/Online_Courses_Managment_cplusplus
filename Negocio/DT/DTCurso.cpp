/*
 * DTCurso.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "DTCurso.h"


#include <string>
#include <iostream>

using namespace std;

DTCurso::DTCurso() {}


DTCurso::DTCurso(string nombre, string descripcion,int dificultad) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad=dificultad;
}
string DTCurso::getNombre() const {
    return nombre;
}

string DTCurso::getDescripcion() const {
    return descripcion;
}

int DTCurso::getDificultad() const {
    return dificultad;
}
// Destructor

DTCurso::~DTCurso() {}
