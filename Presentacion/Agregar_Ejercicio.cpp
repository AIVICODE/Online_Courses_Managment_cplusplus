#include <iostream>
#include <list>
#include <string>
#include "../Negocio/Controlador/Controlador.h"
#include "Agregar_Ejercicio.h"
#include "../Negocio/DT/DTEjercicio.h"
#include "../Negocio/DT/DTEjercicio_Traduccion.h"
#include "../Negocio/DT/DTEjercicio_Completar.h"
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
cout << "Cursos no habilitados:" << endl;
Mostrar_Cursos_No_Hab();

while (true) {
    cout << "Ingrese el nombre del curso: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nombreCurso);

    if (!controlador->Verificar_Nombre_Curso(nombreCurso)) {
        cout << "El curso '" << nombreCurso << "' no existe." << endl;
        cout << "¿Desea intentar de nuevo? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion == 'n' || opcion == 'N') {
            return; // Cancelar la operación
        }
    } else {
        break; // Salir del bucle si el curso existe
    }
}

string nombreLeccion;
cout << "Ingrese el nombre de la lección: ";
getline(cin, nombreLeccion);

	if(controlador->Existe_Leccion(nombreCurso,nombreLeccion)==true){

	DTEjercicio* dtejercicio = SolicitarDatosEjercicio(); 
 
	controlador->Agregar_Ejercicio(nombreCurso, nombreLeccion, dtejercicio);
	}else{
	cout<<"No existe la leccion para ese curso"<<endl;
	
	}

	list<string> ejercicios = controlador->Mostrar_Ejercicios(nombreCurso, nombreLeccion);
	
	    cout << "Ejercicios de la lección '" << nombreLeccion << "' en el curso '" << nombreCurso << "':" << endl;

	for (const string& ejer : ejercicios) {
        cout << ejer << endl;
    }
    // Mostrar los ejercicios en consola
    
	
}


void Agregar_Ejercicio::Mostrar_Cursos_No_Hab(){
	list<string> cursoshab = this->controlador->Listar_Cursos_No_Habiles();

    for (const string& cursoNombre : cursoshab) {
        cout << "Cursos habilitados: " << cursoNombre << endl;
    }
}


DTEjercicio* Agregar_Ejercicio::SolicitarDatosEjercicio() {
    string nombre, descripcion;
    int tipo;
    // Solicitar datos comunes a todos los ejercicios
    cout << "Ingrese nombre del ejercicio: ";
    getline(cin, nombre);
    cout << "Ingrese descripción del ejercicio: ";
    getline(cin, descripcion);

    // Solicitar tipo específico de ejercicio
    cout << "Seleccione tipo de ejercicio:" << endl;
    cout << "1. Completar" << endl;
    cout << "2. Traducir" << endl;
    cout << "Ingrese opción: ";
    cin >> tipo;
    cin.ignore(); // Limpiar el buffer de entrada

    switch (tipo) {
        case 1: {
            string fraseIncompleta;
            list<string> palabrasFaltantes;
            cout << "Ingrese frase incompleta: ";
            cin >> fraseIncompleta;
            
            string palabra;
            while (true) {
        		cout << "Ingrese una palabra faltante (o 'fin' para terminar): ";
        		cin >> palabra;
        		if (palabra == "fin") {
            	break;
        		}else{
					palabrasFaltantes.push_back(palabra);
					
					cout<<" PALABRA INGRESADA ES:"<<palabra;
				}
        		}

            DTCompletar* completarDTO = new DTCompletar(nombre, descripcion, fraseIncompleta, palabrasFaltantes);
            return completarDTO;
        }
        case 2: {
            string fraseSinTraducir, fraseTraducida;
            cout << "Ingrese frase sin traducir: ";
            cin >> fraseSinTraducir;
            cout << "Ingrese frase traducida: ";
            cin >> fraseTraducida;
            DTTraducir* traducirDTO = new DTTraducir(nombre, descripcion, fraseSinTraducir, fraseTraducida);
            return traducirDTO;
        }
        default:
            cerr << "Opción inválida. No se pudo crear el ejercicio." << endl;
            return nullptr;
    }
    
}




