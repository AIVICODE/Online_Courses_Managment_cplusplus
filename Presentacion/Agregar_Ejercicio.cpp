#include <iostream>
#include <list>
#include <string>
#include "../Negocio/Controlador/Controlador.h"
#include "Agregar_Ejercicio.h"
using namespace std;


Agregar_Ejercicio::Agregar_Ejercicio(){
		this->controlador = new Controlador();
}

Agregar_Ejercicio::~Agregar_Ejercicio() {
	//El controlador solo dura lo que dura el caso de uso
	delete this->controlador;
}

void Agregar_Ejercicio::Agregar_Ejercicio_Curso(){
	string nombreCurso;
	cout << "Cursos no habilitados: "<<endl;
	Mostrar_Cursos_No_Hab();
	
	
		while (true) {
	    cout << "Ingrese el nombre del curso: ";
	    cin.ignore(); // Limpiar el buffer
	    getline(cin, nombreCurso);
			if (this->controlador->Verificar_Nombre_Curso(nombreCurso)==false) {
				cout << "El curso '" << nombreCurso << "' no existe." << endl;
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
		
	
	
}


void Agregar_Ejercicio::Mostrar_Cursos_No_Hab(){
	list<string> cursoshab = this->controlador->Listar_Cursos_No_Habiles();

    for (const string& cursoNombre : cursoshab) {
        cout << "Cursos habilitados: " << cursoNombre << endl;
    }
}