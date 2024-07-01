/*
 * Profesor.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#include "../headers/Profesor.h"

Profesor::Profesor() : Usuario(){
	// TODO Auto-generated constructor stub

}
Profesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto)
    : Usuario(nickname, contrasenia, nombre, descripcion), instituto(instituto) {}
Profesor::~Profesor() {
	// TODO Auto-generated destructor stub
}

string Profesor::getInstituto() const{
	return instituto;
}

void Profesor::agregarIdioma(Idioma* idioma){
	idiomasDeProfesor.push_back(idioma);
}

string Profesor::getNickname(){
return Get_Nick();
}



list<Idioma*> Profesor::getIdiomas() const {
    return idiomasDeProfesor;
}