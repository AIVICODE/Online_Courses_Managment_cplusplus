/*
 * Controlador.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "../Interfaces/IControlador.h"
#include "Controlador.h"
#include "../headers/Usuario.h"
#include "../headers/Profesor.h"
#include "../headers/Estudiante.h"

#include "../DT/DTUsuario.h"
#include "../DT/DTProfesor.h"
#include "../DT/DTEstudiante.h"

#include "../System/System.h"

#include <set>

#include <iostream>
using namespace std;


Controlador::Controlador() {
	//obtendo la unica instancia del Sistema
	this->sistema = System::Get_Instancia();
}



void Controlador::ingresarUsuario(DTUsuario* user) {
	cout << "Ingresando Usuario" << endl;
	        // Casting dinámico para determinar el tipo de usuario
	if (DTProfesor* profesorDTO = dynamic_cast<DTProfesor*>(user)) {
	        //cout << "Es un profesor" << endl;
	        // Creación del objeto Profesor
	        Profesor* profesor = new Profesor(
	            profesorDTO->getNickname(),
	            profesorDTO->getContrasenia(),
	            profesorDTO->getNombre(),
	            profesorDTO->getDescripcion(),
	            profesorDTO->getInstituto()
	        );
	        // Agregar el profesor al conjunto de usuarios
	        this->sistema->usuarios.insert(profesor);

	         //this->sistema->mostrarProfesores();

	        } else if (DTEstudiante* estudianteDTO = dynamic_cast<DTEstudiante*>(user)) {
	           // cout << "Es un estudiante" << endl;
	        	Estudiante* estudiante = new Estudiante(
	        		            estudianteDTO->getNickname(),
	        		            estudianteDTO->getContrasenia(),
	        		            estudianteDTO->getNombre(),
	        		            estudianteDTO->getDescripcion(),
	        		            estudianteDTO->getPais(),
								estudianteDTO->getFecha()

	        		        );
		        this->sistema->usuarios.insert(estudiante);

	            // Agregar el estudiante al conjunto de usuarios
	            // Aquí debes tener acceso al conjunto de usuarios de System
	            // usuarios->insert(estudiante);
	        } else {
	            cerr << "Error: Usuario no reconocido" << endl;
	        }
}

bool Controlador::Verificar_Nick(string nick) {
    // Recorro los usuarios del sistema
	bool result = false;

		set<Usuario*>::iterator it;

		for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
			if (nick == (*it)->Get_Nick()) {
				result = true;
				break;
			}
		}
		return result;
}

Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}

