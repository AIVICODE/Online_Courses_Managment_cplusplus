#include "ConsultarCurso.h"
#include "../Negocio/DT/DTConsultaCurso.h"
#include "../Negocio/Controlador/Controlador.h"
#include <string>
#include <iostream>


Consultar_Curso::Consultar_Curso() {
	this->c = new Controlador();
}

void Consultar_Curso::Hacer(){
	string nombreCurso;
	list<string> los_cursos = this->c->Listar_Cursos();

	std::cout << "Los cursos registrados son: " << std::endl;

	for (const auto& un_curso : los_cursos ){
		std::cout << un_curso	<< std::endl;
	}
	while (true) {
		    cout << "Ingrese el nombre del curso: ";
		    cin.ignore(); // Limpiar el buffer
		    getline(cin, nombreCurso);
		    if (!(this->c->Verificar_Nombre_Curso(nombreCurso))) {
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
	DTConsulta_Curso* consulta;

	consulta=this->c->ConsultaCurso(nombreCurso);
	cout << "Nombre de curso '" << consulta->getNombre() << "'" << endl;
	cout << "Descripcion '" << consulta->getDescripcion() << "'" << endl;
	cout << "Dificultad '" << consulta->getDificultad()<< "'" << endl;
	cout << "Idioma '" << consulta->getIdioma()<< "'" << endl;

	std::cin.ignore();
}





Consultar_Curso::~Consultar_Curso() {
	// TODO Auto-generated destructor stub
}

