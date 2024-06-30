/*
 * Ejercicio.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "../headers/Ejercicio.h"


Ejercicio::Ejercicio() {
	// TODO Auto-generated constructor stub

}
Ejercicio::Ejercicio(string nombre, string descripcion){
	this->nombre=nombre;
	this->descripcion=descripcion;
}

Ejercicio::~Ejercicio() {
	// TODO Auto-generated destructor stub
}


string Ejercicio::Get_Nombre(){
	return nombre;
}



string Ejercicio::Get_Descripcion() const {
    return descripcion;
}