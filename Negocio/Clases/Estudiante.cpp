/*
 * Estudiante.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#include "../headers/Estudiante.h"
#include "../headers/Usuario.h"
#include "../DT/DTFecha.h"
#include <string>
#include <iostream>

using namespace std;

Estudiante::Estudiante() {}

Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha fecha)
    : Usuario(nickname, contrasenia, nombre, descripcion), pais(pais), fecha(fecha) {}

Estudiante::~Estudiante() {}

string Estudiante::getPais() const {
    return pais;
}

DTFecha Estudiante::getFecha() const {
    return fecha;
}
