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
DTProfesor::DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto)
    : DTUsuario(nickname, contrasenia, nombre, descripcion), instituto(instituto) {}
DTProfesor::~DTProfesor() {}

string DTProfesor::getInstituto() const {
    return instituto;
}
