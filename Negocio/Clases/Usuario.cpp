/*
 * Usuario.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#include "../headers/Usuario.h"

Usuario::Usuario() {
	// TODO Auto-generated constructor stub

}

Usuario::Usuario(string nickname, string contrasenia, string nombre, string descripcion/*, int tipo*/) {
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;

}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

string Usuario::Get_Nick() {
	return nickname;
}

        string Usuario::Get_Nombre(){
			return nombre;
		}
        string Usuario::Get_Descripcion(){
			return descripcion;
		}