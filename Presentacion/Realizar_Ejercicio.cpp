#include "Realizar_Ejercicio.h"

#include "../Negocio/Controlador/Controlador.h"

#include <iostream>
#include <string>
#include <list>

Realizar_Ejercicio::Realizar_Ejercicio() {
	this->controlador = new Controlador();
}


void Realizar_Ejercicio::RealizarEjercicio(){
	string estudiante;
	cout<< "Ingresa nombre estudiante:"<<endl;
	cin >> estudiante;
	
	list<string> cursospendientes= this->controlador->Muestra_Cursos_Pendientes(estudiante);
	
	cout << "Cursos pendientes del estudiante " << estudiante << ":" << endl;
            for (const string& curso : cursospendientes) {
                cout << curso << endl;
            }
            
    string nombreCurso;
	cout << "Seleccion un curso pendiente:"<<endl;
	cin >> nombreCurso;
	
	
	
}