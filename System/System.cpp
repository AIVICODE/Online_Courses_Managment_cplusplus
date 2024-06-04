#include "System.h"

#include "../DT/DTUsuario.h"
#include <iostream>
using namespace std;

System *System::instance = NULL;


System::System() {

}


System *System::Get_Instancia() {
    if (instance == NULL) {
        instance = new System();
    }
    return instance;
}

void System::Alta_De_Usuario() {
    IControlador* instanciaControlador = Controlador::Get_Instancia();

	DTUsuario* u = new DTUsuario("nickname", "contrasenia", "nombre", "descripcion");
	instanciaControlador->ingresarUsuario(u);
}

System::~System() {

}
