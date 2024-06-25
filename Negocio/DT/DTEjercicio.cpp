/*
 * Ejercicio.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "DTEjercicio.h"


DTEjercicio::DTEjercicio() {
	// TODO Auto-generated constructor stub

}
DTEjercicio::DTEjercicio(string nombre, string descripcion){
	this->nombre=nombre;
	this->descripcion=descripcion;
}

DTEjercicio::~DTEjercicio() {
	// TODO Auto-generated destructor stub
}

string DTEjercicio::Get_Nombre() const {
    return nombre;
}

string DTEjercicio::Get_Descripcion() const {
    return descripcion;
}