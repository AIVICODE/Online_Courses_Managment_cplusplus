/*
 * DTUsuario.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "DTUsuario.h"

#include "DTProfesor.h"

#include <string>
#include <iostream>

using namespace std;

DTProfesor::DTProfesor() {}
DTProfesor::DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto,list<string> idiomas)
    : DTUsuario(nickname, contrasenia, nombre, descripcion), instituto(instituto),idiomas(idiomas) {}
DTProfesor::~DTProfesor() {}

DTProfesor::DTProfesor(string nickname, string nombre, string descripcion, string instituto, list<string> idiomas)
    : DTUsuario(nickname, "", nombre, descripcion), instituto(instituto), idiomas(idiomas) {}

string DTProfesor::getInstituto() const {
    return instituto;
}


list<string> DTProfesor::getIdiomas() const {
    return idiomas;
}

void DTProfesor::setIdiomas(const list<string>& nuevosIdiomas) {
    idiomas = nuevosIdiomas;
}
DTProfesor::DTProfesor(string nickname)
    : DTUsuario(nickname) {} // Llamar al constructor de DTUsuario
