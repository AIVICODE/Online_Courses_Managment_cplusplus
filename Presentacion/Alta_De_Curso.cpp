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
	    cin.ignore(); // Limpiar el buffer
		    std::cin.get(); // Esperar a que el usuario presione Enter

}

void Alta_De_Curso::CrearCurso(){

    string nombreCurso, descripcion,idioma;
    int dificultad;


	while (true) {
	    cout << "Ingrese el nombre del curso: ";
	    cin.ignore(); // Limpiar el buffer
	    getline(cin, nombreCurso);
			if (this->controlador->Verificar_Nombre_Curso(nombreCurso)) {
				cout << "El curso '" << nombreCurso << "' ya existe." << endl;
				cout << "¿Desea intentar de nuevo? (s/n): ";
				char opcion;
				cin >> opcion;
				if (opcion == 'n' || opcion == 'N') {
					return ; // cancelar
				}
			} else {
			    cout << "Ingrese la descripción del curso: ";
			    getline(cin, descripcion);

			    dificultad = seleccionarDificultad();


			   // this->controlador->Crear_Curso(curso);
			    Muestro_Idiomas();
			    cout << "Ingrese el Idioma: ";
			    			    getline(cin, idioma);


			    Muestro_Cursos_Hab();

			    char respuesta;
			    cout << "Desea agregar previas al curso? (s/n): ";
			    cin >> respuesta;
			    cin.ignore(); // Limpiar el buffer de entrada

			    list<string> previas;

			    while (respuesta == 's' || respuesta == 'S') {
			        string previa;
			        cout << "Ingrese el nombre del curso previo: ";
			        getline(cin, previa);
			        previas.push_back(previa);

			        cout << "Desea agregar otra previa al curso? (s/n): ";
			        cin >> respuesta;
			        cin.ignore(); // Limpiar el buffer de entrada
			    }

			    DTCurso* curso=new DTCurso(nombreCurso,descripcion,dificultad,idioma,previas);
				break;
			}
		}


}

void Alta_De_Curso::Muestro_Cursos_Hab(){
    std::list<string> cursoshab = controlador->Listar_Cursos_Habiles();

    for (const string& cursoNombre : cursoshab) {
        cout << "Cursos habilitados: " << cursoNombre << endl;
    }
}
void Alta_De_Curso::Muestro_Idiomas(){
	list<string> idiomas = this->controlador->Listar_Idiomas();
				    cout << "Idiomas disponibles:" << endl;
				    for (const auto& idioma : idiomas) {
				        cout << idioma << endl;
				    }
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
