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

	if (DTProfesor* profesorDTO = dynamic_cast<DTProfesor*>(user)) {

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



	        } else if (DTEstudiante* estudianteDTO = dynamic_cast<DTEstudiante*>(user)) {

	        	Estudiante* estudiante = new Estudiante(
	        		            estudianteDTO->getNickname(),
	        		            estudianteDTO->getContrasenia(),
	        		            estudianteDTO->getNombre(),
	        		            estudianteDTO->getDescripcion(),
	        		            estudianteDTO->getPais(),
								estudianteDTO->getFecha()

	        		        );
		        this->sistema->usuarios.insert(estudiante);

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

list<string> Controlador::Listar_Idiomas(){

	// Crear un nuevo idioma "inglés" y agregarlo al conjunto de idiomas
	    Idioma* ingles = new Idioma("ingles");
	    this->sistema->idiomas.insert(ingles);

	    // Lista para almacenar los nombres de los idiomas
	    std::list<std::string> nombresIdiomas;

	    // Iterar sobre el conjunto de punteros a objetos Idioma
	    for (auto it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
	        // Obtener el nombre del idioma y agregarlo a la lista
	        nombresIdiomas.push_back((*it)->Get_Nombre()); // Suponiendo que GetNombre() devuelve el nombre del idioma
	    }

	    return nombresIdiomas;
}

void Controlador::Agregar_Especializacion(string idioma,string user){
//Existe idioma?
	Idioma* enlaceIdioma = nullptr; // Inicializar el puntero a nullptr para indicar que aún no se ha encontrado el idioma

	for (auto it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
	    // Obtener el nombre del idioma y verificar si coincide con el idioma deseado
	    if (idioma == (*it)->Get_Nombre()) {
	        // Si se encuentra el idioma deseado, guardar el enlace al objeto Idioma
	        enlaceIdioma = *it;
	        // Salir del bucle si se ha encontrado el idioma
	        break;
	    }
	}


	for (auto it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
	    // Verificar si el usuario es de tipo profesor
	    Profesor* profesor = dynamic_cast<Profesor*>(*it);
	    if (profesor != nullptr && user == profesor->Get_Nick()) {
	        // El usuario es un profesor, así que podemos llamar a agregarIdioma()
	        profesor->agregarIdioma(enlaceIdioma);

	    }
	}

}

Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}

