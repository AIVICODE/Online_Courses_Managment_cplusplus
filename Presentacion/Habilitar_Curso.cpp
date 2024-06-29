#include "Habilitar_Curso.h"

#include "../Negocio/Controlador/Controlador.h"

#include <iostream>
#include <string>
#include <list>

Habilitar_Curso::Habilitar_Curso() {
	this->controlador = new Controlador();
}

void Habilitar_Curso::habilitarCurso() {
	Mostrar_Cursos_No_Hab();
	    string nombreCurso;
    cout << "Ingrese el nombre del curso que desea habilitar: ";
    cin >> nombreCurso;  
    
    if(this->controlador->Buscar_Curso(nombreCurso)!=NULL){
		this->controlador->Habilitar_Curso(nombreCurso);
		cout<< "Curso:"<<nombreCurso<<" Ha sido habilitado";
	}
	else{
		cout << "El curso que mencionas no se encuentra en el sistema"<<endl;
	}
}


void Habilitar_Curso::Mostrar_Cursos_No_Hab(){
	list<string> cursoshab = this->controlador->Listar_Cursos_No_Habiles();

    for (const string& cursoNombre : cursoshab) {
        cout << "Cursos no habilitados: " << cursoNombre << endl;
    }
}