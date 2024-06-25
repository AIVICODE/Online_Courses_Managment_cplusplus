#include <iostream>
#include <list>
#include <string>
#include "../Negocio/Controlador/Controlador.h"
#include "Agregar_Leccion.h"
#include "../Negocio/DT/DTLeccion.h"

using namespace std;


Agregar_Leccion::Agregar_Leccion(){
		this->controlador = new Controlador();
}

Agregar_Leccion::~Agregar_Leccion() {
	
	delete this->controlador;
}


void Agregar_Leccion::AgregaLeccion(){
	
	string nombreCurso;
		list<string> cursoshab = this->controlador->Listar_Cursos_No_Habiles();

    if (cursoshab.empty()) {
        cout << "No hay cursos no habilitados." << endl;
        return;
    }
    for (const string& cursoNombre : cursoshab) {
        cout << "Cursos No habilitados: " << cursoNombre << endl;
    }
    
    
    while (true) {
    cout << "Ingrese el nombre del curso: ";
    cin.ignore(); // Limpiar el buffer de entrada
    cin >> nombreCurso;

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
    
    while (true) {
        string nombre, descripcion, tema, objetivo;

        cout << "Ingrese el nombre de la lección: ";
        cin >> nombre;

        cout << "Ingrese la descripción de la lección: ";
        cin >> descripcion;

        cout << "Ingrese el tema de la lección: ";
        cin >> tema;

        cout << "Ingrese el objetivo de la lección: ";
       	cin >> objetivo;

        // Crear un objeto DTLeccion con los datos ingresados
        DTLeccion* nuevaLeccion = new DTLeccion(nombre, descripcion, tema, objetivo);


         controlador->AgregaLeccion(nombreCurso,nuevaLeccion);

        cout << "Lección ingresada correctamente." << endl;
        
char opcionAgregar;
        cout << "¿Desea agregar ejercicios a la lección '" << nombre << "' en el curso '" << nombreCurso << "'? (s/n): ";
        cin >> opcionAgregar;
        cin.ignore(); // Limpiar el buffer de entrada

        if (opcionAgregar == 's' || opcionAgregar == 'S') {
            // Verificar si la lección existe en el curso
            if (controlador->Existe_Leccion(nombreCurso, nombre)) {
                while (true) {
                    // Solicitar datos del ejercicio
                    DTEjercicio* dtejercicio = SolicitarDatosEjercicio();

                    // Agregar ejercicio usando el controlador
                    controlador->Agregar_Ejercicio(nombreCurso, nombre, dtejercicio);

                    // Preguntar si desea agregar otro ejercicio
                    cout << "¿Desea agregar otro ejercicio a la lección '" << nombre << "' en el curso '" << nombreCurso << "'? (s/n): ";
                    cin >> opcionAgregar;
                    cin.ignore(); // Limpiar el buffer de entrada

                    if (opcionAgregar == 'n' || opcionAgregar == 'N') {
                        break; // Salir del bucle de ejercicios
                    }
                }
            } else {
                cout << "No existe la lección '" << nombre << "' para el curso '" << nombreCurso << "'" << endl;
            }
        }
	list<string> ejercicios = controlador->Mostrar_Ejercicios(nombreCurso, nombre);
	
	    cout << "Ejercicios de la lección '" << nombre << "' en el curso '" << nombreCurso << "':" << endl;

	for (const string& ejer : ejercicios) {
        cout << ejer << endl;
    }

    
    
        // Preguntar al usuario si desea agregar otra lección
        cout << "¿Desea agregar otra lección? (s/n): ";
        char opcion;
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        if (opcion == 'n' || opcion == 'N') {
            break; // Salir del bucle si no se desea agregar más lecciones
        }
    }
    

}
   
   DTEjercicio* Agregar_Leccion::SolicitarDatosEjercicio() {
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
            getline(cin, fraseIncompleta);
            
            string palabra;
            while (true) {
        		cout << "Ingrese una palabra faltante (o 'fin' para terminar): ";
        		getline(cin, palabra);
        		if (palabra == "fin") {
            	break;
        		}
        		}
        	palabrasFaltantes.push_back(palabra);
            DTCompletar* completarDTO = new DTCompletar(nombre, descripcion, fraseIncompleta, palabrasFaltantes);
            return completarDTO;
        }
        case 2: {
            string fraseSinTraducir, fraseTraducida;
            cout << "Ingrese frase sin traducir: ";
            getline(cin, fraseSinTraducir);
            cout << "Ingrese frase traducida: ";
            getline(cin, fraseTraducida);
            DTTraducir* traducirDTO = new DTTraducir(nombre, descripcion, fraseSinTraducir, fraseTraducida);
            return traducirDTO;
        }
        default:
            cerr << "Opción inválida. No se pudo crear el ejercicio." << endl;
            return nullptr;
    }
    
}
    

