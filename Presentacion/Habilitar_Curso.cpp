#include "Habilitar_Curso.h"
#include <iostream>
#include <string>

Habilitar_Curso::Habilitar_Curso() {
	this->controlador = new Controlador();
}

void Habilitar_Curso::habilitarCurso() {
	    string nombreCurso;
    cout << "Ingrese el nombre del curso que desea habilitar: ";
    cin >> nombreCurso;  
    
    if(this->controlador->Buscar_Curso(nombreCurso)!=NULL){
		this->controlador->Habilitar_Curso(nombreCurso);
	}
	else{
		cout << "El curso que mencionas no se encuentra en el sistema"<<endl;
	}
}