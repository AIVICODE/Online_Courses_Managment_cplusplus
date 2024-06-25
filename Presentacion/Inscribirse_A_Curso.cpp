#include "Inscribirse_A_Curso.h"
#include <iostream>
#include <set>
#include <list>
#include <string>
#include "../Negocio/Controlador/Controlador.h"
#include "../Negocio/DT/DTEstudiante.h"
#include "../Negocio/DT/DTProfesor.h"
#include "../Negocio/DT/DTUsuario.h"
Inscribirse_A_Curso::Inscribirse_A_Curso() {
	this->c = new Controlador();
}

void Inscribirse_A_Curso::Inscribirse() {
    string nickname;
    string nombre_curso;


list<DTUsuario*> usuarios = c->Listar_Usuarios();

    // Mostrar los usuarios obtenidos
    for (DTUsuario* usuario : usuarios) {
        // Intentar convertir el usuario a un DTProfesor

        // Intentar convertir el usuario a un DTEstudiante
        if (DTEstudiante* estudiante = dynamic_cast<DTEstudiante*>(usuario)) {
            cout << "Estudiante - Nickname: " << usuario->getNickname() << endl;
            // Aquí puedes mostrar más detalles si los tienes en DTEstudiante
        }

    }
		
	
		    cout << "Ingrese un nickname: ";
    cin >> nickname;
	if(this->c->Buscar_Usuario(nickname)==NULL){
		cout<< "Usuario no existe";
	}
	else{
		

    list<string> cursos_disponibles = this->c->Cursos_Habiles_Estudiante(nickname); // Devuelve list<string> con nombre de cursos habilitados para ese estudiante

    if (cursos_disponibles.empty()) {
        cout << "No hay cursos disponibles para inscribirse." << endl;
        return;
    }

    cout << "Cursos Disponibles:" << endl;
    for (const auto& curso : cursos_disponibles) {
        cout << curso << endl;
    }

    bool curso_encontrado = false;
    do {
        cout << "Ingrese Nombre de curso a inscribirse: ";
        cin >> nombre_curso;

        for (const auto& curso : cursos_disponibles) {
            if (curso == nombre_curso) {
                curso_encontrado = true;
                break;
            }
        }

        if (!curso_encontrado) {
            cout << "Curso no encontrado. Por favor, ingrese un nombre de curso válido." << endl;
        }
    } while (!curso_encontrado);

    // Llamar a la función para inscribirse en el curso
    this->c->Inscribirse_a_Curso(nickname, nombre_curso);

    cout << "Inscripción realizada con éxito." << endl;
    cout << "Presione Enter para continuar...";
    cin.ignore(); // Limpiar el buffer
    cin.get(); // Esperar a que el usuario presione Enter
    }
}

Inscribirse_A_Curso::~Inscribirse_A_Curso() {
}

