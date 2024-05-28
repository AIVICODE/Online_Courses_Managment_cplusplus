/*
 * main.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */


#include "Interfaces/IControlador.h"
#include "Controlador/Controlador.h"

#include <iostream>
using namespace std;
int main() {

    IControlador* instanciaControlador = Controlador::Get_Instancia();
	return 0;
}

