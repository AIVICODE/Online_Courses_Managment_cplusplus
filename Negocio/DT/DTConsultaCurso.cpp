/*
 * DTConsultaCurso.cpp
 *
 *  Created on: 27 jun. 2024
 *      Author: topo
 */

#include "DTConsultaCurso.h"
#include <string>
#include <iostream>
#include <list>
using namespace std;

DTConsulta_Curso::DTConsulta_Curso() {}

DTConsulta_Curso::DTConsulta_Curso(string nombre, string descripcion, string dificultad, string idioma/*, string nickname*/)
    : nombre(nombre), descripcion(descripcion), dificultad(dificultad), idioma(idioma)/*, nickname(nickname)*/ {}


// Getters
string DTConsulta_Curso::getNombre() const {
    return nombre;
}

string DTConsulta_Curso::getDescripcion() const {
    return descripcion;
}

string DTConsulta_Curso::getDificultad() const {
    return dificultad;
}

string DTConsulta_Curso::getIdioma() const {
    return idioma;
}

/*string DTConsulta_Curso::getNickname() const {
    return nickname;
}*/


DTConsulta_Curso::~DTConsulta_Curso() {
	// TODO Auto-generated destructor stub
}

