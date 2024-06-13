
#include <iostream>
#include <set>

#include "Alta_De_Usuario.h"
#include "../Negocio/Controlador/Controlador.h"

//#include "../negocio/dto/DTOEstudiante.h"
//#include "../negocio/dto/DTOProfesor.h"

using namespace std;



AltaUsuario::AltaUsuario() {
	//TODO pendiente de usar una fabrica
	this->controlador = new Controlador();
}

AltaUsuario::~AltaUsuario() {
	//El controlador solo dura lo que dura el caso de uso
	delete this->controlador;
}

void AltaUsuario::altaUsuario() {

	cout << "Ingrese nick:"<< endl;
	//etc

}
