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

Controlador* Controlador::instancia = NULL;


IControlador* Controlador::Get_Instancia() {
    if (instancia == NULL) {
        instancia = new Controlador();
    }
    return instancia;
}

void Controlador::ingresarUsuario(DTUsuario* user) {
	cout<<"Igresando Usuario"<<endl;
}


Controlador::Controlador() {
    // Inicialización específica de Controlador si es necesario
}
Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}

