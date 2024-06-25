#include "Consultar_Usuario.h"

#include <iostream>
#include <list>

#include "../Negocio/DT/DTEstudiante.h"
#include "../Negocio/DT/DTProfesor.h"
#include "../Negocio/DT/DTUsuario.h"
#include "../Negocio/Controlador/Controlador.h"

Consultar_Usuario::Consultar_Usuario() {
    this->c = new Controlador();
}

Consultar_Usuario::~Consultar_Usuario() {
    delete c;  // Liberar el controlador en el destructor
}

void Consultar_Usuario::Imprimir() {
list<DTUsuario*> usuarios = c->Listar_Usuarios();

    // Mostrar los usuarios obtenidos
    for (DTUsuario* usuario : usuarios) {
        // Intentar convertir el usuario a un DTProfesor
        if (DTProfesor* profesor = dynamic_cast<DTProfesor*>(usuario)) {
            cout << "Profesor - Nickname: " << usuario->getNickname() << endl;
            // Aquí puedes mostrar más detalles si los tienes en DTProfesor
        }
        // Intentar convertir el usuario a un DTEstudiante
        else if (DTEstudiante* estudiante = dynamic_cast<DTEstudiante*>(usuario)) {
            cout << "Estudiante - Nickname: " << usuario->getNickname() << endl;
            // Aquí puedes mostrar más detalles si los tienes en DTEstudiante
        }
        // Manejo de caso inesperado (aunque según la implementación, no debería ocurrir)
        else {
            cerr << "Error: Usuario no reconocido como profesor ni estudiante." << endl;
        }
    }

    // Liberar memoria de los DTUsuario* creados dinámicamente
    for (DTUsuario* usuario : usuarios) {
        delete usuario;
    }
}