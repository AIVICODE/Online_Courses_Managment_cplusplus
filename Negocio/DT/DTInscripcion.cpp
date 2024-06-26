/*
 * DTInscripcion.cpp
 *
 *  Created on: 30 jun. 2024
 *      Author: topo
 */

#include "DTInscripcion.h"
#include <string>
#include <iostream>
#include <list>
using namespace std;

DTInscripcion::DTInscripcion() {}
DTInscripcion::DTInscripcion(string estudiante, string curso, string fecha)
    : estudiante(estudiante), curso(curso), fecha(fecha){}

DTInscripcion::~DTInscripcion() {
	// TODO Auto-generated destructor stub
}
// Getters
string DTInscripcion::getEstudiante() const {
    return estudiante;
}

string DTInscripcion::getCurso() const {
    return curso;
}

string DTInscripcion::getFecha() const {

	return fecha;
}
