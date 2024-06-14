/*
 * DTUsuario.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "DTUsuario.h"


#include <string>
#include <iostream>

using namespace std;

DTUsuario::DTUsuario() {}


DTUsuario::DTUsuario(string nickname, string contrasenia, string nombre, string descripcion/*, int tipo*/) {
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;

}

// Getters

string DTUsuario::getNickname() const {
    return this->nickname;
}

string DTUsuario::getContrasenia() const {
    return this->contrasenia;
}

string DTUsuario::getNombre() const {
    return this->nombre;
}

string DTUsuario::getDescripcion() const {
    return this->descripcion;
}




// Destructor

DTUsuario::~DTUsuario() {}

