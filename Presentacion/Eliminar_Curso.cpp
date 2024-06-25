#include "Eliminar_Curso.h"

#include "../Negocio/Controlador/Controlador.h"

#include <iostream>
#include <string>
#include <list>

Eliminar_Curso::Eliminar_Curso() {
	this->controlador = new Controlador();
}

void Eliminar_Curso::EliminarCurso(){
	Muestro_Cursos();
	
	string nombreCurso;
	cout <<"Ingrese el nombre del curso a eliminar:"<<endl;
	cin>>nombreCurso;
	
	
	
}


void Eliminar_Curso::Muestro_Cursos(){
    std::list<string> cursoshab = controlador->Listar_Cursos();

    for (const string& cursoNombre : cursoshab) {
        cout << "Cursos habilitados: " << cursoNombre << endl;
    }
}