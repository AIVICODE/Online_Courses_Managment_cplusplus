/*
 * DTEstudiante.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "DTEstudiante.h"
#include "DTFecha.h"

#include "DTUsuario.h"
#include <string>
#include <iostream>

using namespace std;

DTEstudiante::DTEstudiante() {}

DTEstudiante::DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha fecha)
    : DTUsuario(nickname, contrasenia, nombre, descripcion), pais(pais), fecha(fecha) {}
    
DTEstudiante::~DTEstudiante() {}

DTEstudiante::DTEstudiante(string nickname, string nombre, string descripcion, string pais)
    : DTUsuario(nickname, "", nombre, descripcion), pais(pais) {}

string DTEstudiante::getPais() const {
    return pais;
}

DTFecha DTEstudiante::getFecha() const {
    return fecha;
}
