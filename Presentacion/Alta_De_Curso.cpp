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
					CrearCurso(nickname);
					break;
				}
			}



		std::cout << "Presione Enter para continuar...";
	    cin.ignore(); // Limpiar el buffer
		    std::cin.get(); // Esperar a que el usuario presione Enter

}

void Alta_De_Curso::CrearCurso(string nickname){

    string nombreCurso, descripcion,idioma;
    idioma="";
    list<string> previas;
    int dificultad;


	while (true) {
	    cout << "Ingrese el nombre del curso: ";
	    cin >> nombreCurso;
			if (this->controlador->Verificar_Nombre_Curso(nombreCurso)) {
				cout << "El curso '" << nombreCurso << "' ya existe." << endl;
				cout << "¿Desea intentar de nuevo? (s/n): ";
				char opcion;
				cin >> opcion;
				if (opcion == 'n' || opcion == 'N') {
					return ; // cancelar
					}
				}
				else{
				break;
				}
			}
			
				Agregar_Descripcion(descripcion);
			    dificultad = seleccionarDificultad();
			    
				Agregar_Idioma(idioma);
				if(idioma==""){
					cout << "Debe ingresar un idioma para el curso"<<endl;
					return ;
				}
				
				char respuesta;
			    cout << "Desea agregar previas al curso? (s/n): ";
			    cin >> respuesta;
			    if(respuesta == 's' || respuesta == 'S'){
					
					
					Muestro_Cursos_Hab();
					previas=Agregar_Previa();
			
				}
	char deseaAgregarLeccion;
    char deseaAgregarEjercicio;

    do {
        std::cout << "¿Desea agregar una lección? (s/n): ";
        std::cin >> deseaAgregarLeccion;

        if (deseaAgregarLeccion == 's' || deseaAgregarLeccion == 'S') {
            //agregarLeccion();

            do {
                std::cout << "¿Desea agregar un ejercicio? (s/n): ";
                std::cin >> deseaAgregarEjercicio;

                if (deseaAgregarEjercicio == 's' || deseaAgregarEjercicio == 'S') {
                    //agregarEjercicio();
                }
            } while (deseaAgregarEjercicio == 's' || deseaAgregarEjercicio == 'S');
        }

    } while (deseaAgregarLeccion == 's' || deseaAgregarLeccion == 'S');
		    
		
	DTCurso* curso=new DTCurso(nombreCurso,descripcion,dificultad,idioma,previas);
	this->controlador->Crear_Curso(curso,nickname);
	
	
}



void Alta_De_Curso::Agregar_Descripcion(string& descripcion){
	cout << "Ingrese la Descripción: ";
	getline(cin, descripcion);

}
void Alta_De_Curso::Agregar_Idioma(string& idioma){
	 Muestro_Idiomas();
                    		    cin.ignore(); // Limpiar el buffer

	while (true) {
            cout << "Ingrese el Idioma (o 'salir' para terminar): ";
            getline(cin, idioma);
            if (idioma == "salir") {
                cout << "Saliendo." << endl;
                idioma = ""; // Limpiar el valor de idioma ya que el usuario decidió salir
                return;
            }
            if (!this->controlador->Existe_Idioma(idioma)) {
                cout << "Idioma no existe. ";
            } else {
                break;
            }
        }
}

list<string> Alta_De_Curso::Agregar_Previa(){
				char respuesta;
				respuesta='s';
			    list<string> previas;

			    while (respuesta == 's' || respuesta == 'S') {
					cin.ignore(); // Limpiar el buffer

			        string previa;
			        cout << "Ingrese el nombre del curso previo: ";
			        cin >> previa;

			        while (!this->controlador->Verificar_Nombre_Curso(previa)) { // existe el curso en cursos, falta controlar cursoprevio en curso
			        	cin.ignore(); // Limpiar el buffer

                    	cout << "El curso '" << previa << "' no existe. ";
                    	cout << "¿Desea intentar de nuevo? (s/n): ";
						char opcion;
						cin >> opcion;
						if (opcion == 'n' || opcion == 'N') {
							break; // cancelar
						}
									        	cin.ignore(); // Limpiar el buffer

                    	cout << "Ingrese el nombre del curso previo: ";
                    	getline(cin, previa);

               		 }
			        previas.push_back(previa);
					
			        cout << "Desea agregar otra previa al curso? (s/n): ";
			        cin >> respuesta;
			    }

			
			return previas;
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



        if (!cin) { // Verificar si la entrada es válida
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(10000, '\n'); // Descartar la entrada inválida
        } else if (opcion >= 1 && opcion <= 3) {
            return opcion; // Devolver la opción válida
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
        
            switch (opcion) {
                case 1:
                    return 1;
                case 2:
                    return 2;
                case 3:
                    return 3;
            }
        }
    
}
