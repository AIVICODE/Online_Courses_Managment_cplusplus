/*
 * main.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */


#include "Interfaces/IControlador.h"
#include "Controlador/Controlador.h"
#include "DT/DTUsuario.h"
#include <iostream>

#include <iostream>
using namespace std;
int main() {
    IControlador* instanciaControlador = Controlador::Get_Instancia();
    DTUsuario* u = new DTUsuario("nickname", "contrasenia", "nombre", "descripcion");

       // Asegúrate de liberar la memoria cuando ya no la necesites

    instanciaControlador->ingresarUsuario(u);
    delete u;
	return 0;
}

