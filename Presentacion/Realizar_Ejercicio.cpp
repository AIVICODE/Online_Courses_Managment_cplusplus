#include "Realizar_Ejercicio.h"

#include "../Negocio/Controlador/Controlador.h"
#include "../Negocio/DT/DTEstudiante.h"
#include "../Negocio/DT/DTProfesor.h"
#include "../Negocio/DT/DTUsuario.h"
#include <iostream>
#include <string>
#include <list>

Realizar_Ejercicio::Realizar_Ejercicio() {
	this->controlador = new Controlador();
}


void Realizar_Ejercicio::RealizarEjercicio(){
    string estudiante;


    list<DTUsuario*> usuarios = controlador->Listar_Usuarios();

    // Mostrar los usuarios obtenidos
    for (DTUsuario* usuario : usuarios) {
        if (DTEstudiante* estudiante = dynamic_cast<DTEstudiante*>(usuario)) {
            cout << "Estudiante - Nickname: " << usuario->getNickname() << endl;
        }
    }
    cout << "Ingresa nombre estudiante:" << endl;
    cin >> estudiante;
    list<string> cursospendientes = this->controlador->Muestra_Cursos_Pendientes(estudiante);

    cout << "Cursos pendientes del estudiante " << estudiante << ":" << endl;
    for (const string& curso : cursospendientes) {
        cout << curso << endl;
    }

    string nombreCurso;
    cout << "Seleccione un curso pendiente:" << endl;
    cin >> nombreCurso;
	if(this->controlador->Buscar_Curso(nombreCurso)==NULL){
	 cout<< "El curso no existe"<<endl;
		return;
	}
    list<string> ejercicios = this->controlador->Muestra_Ejercicios_Pendientes(estudiante, nombreCurso);

    cout << "Ejercicios pendientes del estudiante " << estudiante << ":" << endl;
    for (const string& ejercicio : ejercicios) {
        cout << ejercicio << endl;
    }

    string nombreejercicio;
    cout << "Seleccione un ejercicio a realizar:" << endl;
    cin >> nombreejercicio;

    DTEjercicio* ejer = this->controlador->Muestro_ejercicio_a_realizar(nombreCurso, nombreejercicio);

    if (ejer) {
        cout << "Nombre: " << ejer->Get_Nombre() << endl;
        cout << "Descripción: " << ejer->Get_Descripcion() << endl;

        DTEjercicio* ejercicioResuelto = nullptr;

        DTTraducir* traducir = dynamic_cast<DTTraducir*>(ejer);
        if (traducir) {
            cout << "Frase sin traducir: " << traducir->Get_Frase_Sin_Traducir() << endl;

            string solucion;
            cout << "Ingrese la traducción:" << endl;
            cin.ignore(); // Clear the input buffer
            cin >> solucion;

            ejercicioResuelto = new DTTraducir(ejer->Get_Nombre(), ejer->Get_Descripcion(), traducir->Get_Frase_Sin_Traducir(), solucion);
        }

        DTCompletar* completar = dynamic_cast<DTCompletar*>(ejer);
        if (completar) {
            cout << "Frase incompleta: " << completar->Get_Frase_Incompleta() << endl;

            list<string> soluciones;

            cout << "Ingrese las palabras faltantes en orden (escribe 'salir' para terminar):" << endl;
            string palabra;
            while (true) {
                cout << "Ingrese la palabra (o 'salir' para terminar): ";
                cin >> palabra;
                if (palabra == "salir") {
                    break;
                }else{
                soluciones.push_back(palabra);
                }
			}
            ejercicioResuelto = new DTCompletar(ejer->Get_Nombre(), ejer->Get_Descripcion(), completar->Get_Frase_Incompleta(), soluciones);
        }

        if (ejercicioResuelto) {
            // Aquí se envía la solución al controlador
            bool resultado = this->controlador->Verificar_Solucion(nombreCurso, nombreejercicio, ejercicioResuelto);

            if (resultado) {
                cout << "Solución correcta." << endl;
                this->controlador->Agrega_Ejercicio_Correcto(nombreCurso,estudiante,nombreejercicio);
                
            } else {
                cout << "Solución incorrecta." << endl;
            }

            delete ejercicioResuelto; // Liberar memoria del ejercicio resuelto
        }

        delete ejer; // Liberar memoria del ejercicio original
    } else {
        cout << "Ejercicio no encontrado." << endl;
    }

	
	
	
	
}