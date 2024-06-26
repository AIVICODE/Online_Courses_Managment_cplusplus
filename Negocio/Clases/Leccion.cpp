/*
 * Lecciones.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "../headers/Leccion.h"

Leccion::Leccion() {
	// TODO Auto-generated constructor stub

}
Leccion::Leccion(string nombre) : nombre(nombre) {}

string Leccion::Get_Nombre(){
	return nombre;
}
Leccion::~Leccion() {
    // Liberar memoria de todos los ejercicios
    for (auto ejercicio : ejercicios) {
        delete ejercicio;
    }
    ejercicios.clear();  // Limpiar la lista después de eliminar los ejercicios
}

string Leccion::Get_Nombre() const {
    return nombre;
}

void Leccion::Agregar_Ejercicio(Ejercicio* ejercicio) {
    ejercicios.push_back(ejercicio);
}

const list<Ejercicio*>& Leccion::Get_Ejercicios() {
    return ejercicios;
}

	    Leccion::Leccion(string nombre,string descripcion,string tema,string objetivo){
			this->nombre=nombre;
			this->descripcion=descripcion;
			this->tema=tema;
			this->objetivo=objetivo;
			
		}
