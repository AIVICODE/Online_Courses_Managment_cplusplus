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


list<string> Estudiante::dar_estadistica(){
	 list<string> estadisticas;

	    for (Inscripcion* inscripcion : inscripto) {
	        estadisticas=inscripcion->evalua_progreso();

	    }

	    //return estadisticas;
}

string Estudiante::Get_Nick(){
	return Get_Nick();
}

list<string> Estudiante::dar_cursos_pendientes() {
    list<string> cursosPendientes;

    for (Inscripcion* inscripcion : inscripto) {
        if (!inscripcion->estaAprobado()) {
            cursosPendientes.push_back(inscripcion->getCurso()->getNombre());
        }
    }

    return cursosPendientes;
}


list<Inscripcion*> Estudiante::getInscripciones() const {
    return inscripto;
}