#include <iostream>
#include <set>
#include <list>

#include "Alta_De_Curso.h"
#include "../Negocio/DT/DTEstudiante.h"
#include "../Negocio/DT/DTProfesor.h"
#include "../Negocio/DT/DTUsuario.h"
#include "../Negocio/Controlador/Controlador.h"
#include "Alta_De_Usuario.h"
//#include "../negocio/dto/DTOEstudiante.h"
//#include "../negocio/dto/DTOProfesor.h"

using namespace std;


Alta_De_Curso::Alta_De_Curso() {
	//TODO pendiente de usar una fabrica
	this->controlador = new Controlador();
}

Alta_De_Curso::~Alta_De_Curso() {
	//El controlador solo dura lo que dura el caso de uso
	delete this->controlador;
}

void Alta_De_Curso::AltaCurso(){

	list<DTUsuario*> userlist;

		userlist=this->controlador->Listar_Profesores();

		for (DTUsuario* user : userlist) {
		    // Intentar convertir el usuario a un DTProfesor
		    if (DTProfesor* profesor = dynamic_cast<DTProfesor*>(user)) {
		        std::cout << "Profesor - Nickname: " << user->getNickname() << std::endl;
		    }
		}
		AltaUsuario altaUsuario;

string nickname;
		while (true) {
				cout << "Ingrese un nickname de la lista: ";
				cin >> nickname;
				if (!this->controlador->Verificar_Nick(nickname)) {
					cout << "El nickname '" << nickname << "' no existe." << endl;
					cout << "¿Desea intentar de nuevo? (s/n): ";
					char opcion;
					cin >> opcion;
					if (opcion == 'n' || opcion == 'N') {
						return ; // cancelar
					}
				} else {
					// FUNCION QUE CONTINUA CON USUARIO VALIDO
					CrearCurso();
					break;
				}
			}



		std::cout << "Presione Enter para continuar...";
		std::cin.get();//Borra buffer \n
		    std::cin.get(); // Esperar a que el usuario presione Enter

}

void Alta_De_Curso::CrearCurso(){

    string nombreCurso, descripcion;
    int dificultad;

    cout << "Ingrese el nombre del curso: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, nombreCurso);

    cout << "Ingrese la descripción del curso: ";
    getline(cin, descripcion);

    dificultad = seleccionarDificultad();


}

int Alta_De_Curso::seleccionarDificultad() {
    int opcion;
    while (true) {
        cout << "Seleccione la dificultad del curso:" << endl;
        cout << "1. Facil" << endl;
        cout << "2. Intermedia" << endl;
        cout << "3. Dificil" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}
