/*
 * DTCurso.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "DTCurso.h"


#include <string>
#include <iostream>
#include <list>

using namespace std;

DTCurso::DTCurso() {}


DTCurso::DTCurso(string nombre, string descripcion, int dificultad, string idioma, list<string> previas)
    : nombre(nombre), descripcion(descripcion), dificultad(dificultad), idioma(idioma), previas(previas) {}

// Getters
string DTCurso::getNombre() const {
    return nombre;
}

string DTCurso::getDescripcion() const {
    return descripcion;
}

int DTCurso::getDificultad() const {
    return dificultad;
}

string DTCurso::getIdioma() const {
    return idioma;
}
list<string> DTCurso::getPrevias() const {
    return previas;
}
// Destructor

DTCurso::~DTCurso() {}
