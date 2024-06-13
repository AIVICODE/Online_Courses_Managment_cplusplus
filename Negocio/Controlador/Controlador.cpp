/*
 * Controlador.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "../Interfaces/IControlador.h"
#include "Controlador.h"

#include <iostream>
using namespace std;


Controlador::Controlador() {
	//obtendo la unica instancia del Sistema
	this->sistema = System::Get_Instancia();
}



void Controlador::ingresarUsuario(DTUsuario* user) {
	cout<<"Igresando Usuario"<<endl;
}


Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}

