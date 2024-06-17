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


//Alta user
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
//PARA PRUEBAS
	// Crear un nuevo idioma "inglés" y agregarlo al conjunto de idiomas
	    //Idioma* ingles = new Idioma("ingles");
	   // this->sistema->idiomas.insert(ingles);
//FIN PRUEBA
	    // Lista para almacenar los nombres de los idiomas
	    list<string> nombresIdiomas;

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

//redundante pero quien sabe
	if (enlaceIdioma == nullptr)
	    // Si el idioma no existe, manejar el caso (por ejemplo, mostrar un mensaje de error)
	    cout << "El idioma seleccionado no existe." << endl;


	for (auto it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
	    // Verificar si el usuario es de tipo profesor
	    Profesor* profesor = dynamic_cast<Profesor*>(*it);
	    if (profesor != nullptr && user == profesor->Get_Nick()) {
	        // El usuario es un profesor, así que podemos llamar a agregarIdioma()
	        profesor->agregarIdioma(enlaceIdioma);

	    }
	}

}

Idioma* Controlador::Existe_Idioma(const string& nombreIdioma) {
    for (auto it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
        if (nombreIdioma == (*it)->Get_Nombre()) {
            return *it; // Retornar el puntero al idioma encontrado
        }
    }
    return nullptr; // Si no se encuentra, retornar nullptr
}
//fin alta user

//consultar estadistica
list<string> Controlador::consultar_estadistica(string nickname){

Usuario* user=Buscar_Usuario(nickname);

Estudiante* estudiante = dynamic_cast<Estudiante*>(user);

if (estudiante != nullptr) {//Es estudiante
	estudiante->dar_estadistica();
}

Profesor* profesor = dynamic_cast<Profesor*>(user);

if (profesor != nullptr) {//Es profesor

}


}
//fin consultar estadistica

list<DTUsuario*> Controlador::Listar_Usuarios() {
    list<DTUsuario*> userlist;

    // Itera sobre la lista de usuarios
    for (Usuario* usuario : this->sistema->usuarios) {
        // Verifica si el usuario es un profesor
        if (Profesor* profesor = dynamic_cast<Profesor*>(usuario)) {
            // Crea un DTProfesor con solo el nickname y agrega a la lista
            DTProfesor* dtProfesor = new DTProfesor(usuario->Get_Nick());
            userlist.push_back(dtProfesor);
        }
        // Verifica si el usuario es un estudiante
        else if (Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario)) {
            // Crea un DTEstudiante con solo el nickname y agrega a la lista
            DTEstudiante* dtEstudiante = new DTEstudiante(usuario->Get_Nick());
            userlist.push_back(dtEstudiante);
        }
        // Si el usuario no es ni profesor ni estudiante, crea un DTUsuario genérico con solo el nickname
        else {
            cout<<"Error inesperado";
        }
    }

    return userlist;
}

Usuario* Controlador::Buscar_Usuario(string nickname){

	for (auto it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); ++it) {
	        if ((*it)->Get_Nick() == nickname) {
	            return *it;
	        }
	    }
	    return nullptr; // Devuelve nullptr si no se encuentra el usuario


}
Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}

