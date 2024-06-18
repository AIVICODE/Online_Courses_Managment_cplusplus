#include <iostream>
#include <set>
#include <list>
#include "../Negocio/Controlador/Controlador.h"

#include "Consultar_Estadisticas.h"
#include "../Negocio/DT/DTEstudiante.h"
#include "../Negocio/DT/DTProfesor.h"
#include "../Negocio/DT/DTUsuario.h"
using namespace std;

Consultar_Estadisticas::Consultar_Estadisticas() {
	this->controlador = new Controlador();

}


void Consultar_Estadisticas::consultar_estadisticas(){
	//muestro usuarios
	list<DTUsuario*> userlist;
cout<<"llega";
int opcion;
    cout << "Ingrese 1 si es profesor o 2 si es estudiante: ";
    cin >> opcion;
	userlist=this->controlador->Listar_Usuarios();

	for (DTUsuario* user : userlist) {
	    // Intentar convertir el usuario a un DTProfesor
	    if (DTProfesor* profesor = dynamic_cast<DTProfesor*>(user)) {
	        std::cout << "Profesor - Nickname: " << user->getNickname() << std::endl;
	    } else if (DTEstudiante* estudiante = dynamic_cast<DTEstudiante*>(user)) {
	        std::cout << "Estudiante - Nickname: " << user->getNickname() << std::endl;
	    } else {
	        std::cerr << "Error: Usuario no reconocido" << std::endl;
	    }
	}
	  for (DTUsuario* user : userlist) {
	        delete user;
	    }

}

Consultar_Estadisticas::~Consultar_Estadisticas() {
	//El controlador solo dura lo que dura el caso de uso
	delete this->controlador;
}
