#include "ConsultarCurso.h"
#include "../Negocio/DT/DTConsultaCurso.h"
#include "../Negocio/DT/DTInscripcion.h"
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
		    cin >> nombreCurso;
		    if (this->c->Verificar_Nombre_Curso(nombreCurso)==false) {
		    				cout << "El curso '" << nombreCurso << "' no existe." << endl;
		    				cout << "¿Desea intentar de nuevo? (s/n): ";
		    				char opcion;
		    				cin >> opcion;
		    				if (opcion == 'n' || opcion == 'N') {
		    					return ; // cancelar
		    					}
		    				}
		    				else{
								DTConsulta_Curso* consulta;
								list<DTLeccion*> info_lecciones;

								consulta=this->c->ConsultaCurso(nombreCurso);
								info_lecciones=this->c->Info_Lecciones(nombreCurso);
								cout << endl<< "Nombre de curso '" << consulta->getNombre() << "'" << endl;
								cout << "Descripcion '" << consulta->getDescripcion() << "'" << endl;
								cout << "Dificultad '" << consulta->getDificultad()<< "'" << endl;
								cout << "Idioma '" << consulta->getIdioma()<< "'" << endl;
								cout << "Profesor asignado '" << consulta->getNickname()<< "'" << endl;
								cout << "Habilitado '" << consulta->getDisponible()<< "'" << endl<<endl;

								for(auto it = info_lecciones.begin(); it != info_lecciones.end(); ++it){
									DTLeccion* leccion = *it;
									cout << "---------------------------------------------"<<endl;
									cout << "Leccion "<<leccion->Get_Nombre()<<" "<<endl;
									cout << "	Tema '"<<leccion->Get_Tema()<<"' "<<endl;
									cout << "	Descripcion '"<<leccion->Get_Descripcion()<<"' "<<endl;
									cout << "	Objetivo '"<<leccion->Get_Objetivo()<<"' "<<endl;
									list<string> ejercicios=this->c->Mostrar_Ejercicios(nombreCurso, leccion->Get_Nombre());
									list<string> descripcion_ejercicios=this->c->Mostrar_Descripcion_Ejercicios(nombreCurso, leccion->Get_Nombre());
									auto it2 = descripcion_ejercicios.begin();
									for(auto it = ejercicios.begin(); it != ejercicios.end() && it2 != descripcion_ejercicios.end(); ++it, ++it2){
										string ejer=*it;
										string desc=*it2;
										cout << "Ejercicio '"<<ejer<<"' - Descripcion '"<<desc<<"' "<<endl;
										++it2;
									}

									cout << "---------------------------------------------"<<endl;
								}
								cout << "----------------------Alumnos inscriptos----------------------------"<< endl;
								cout << "--Nombre----------------Fecha------------"<< endl;
								list<DTInscripcion*> inscriptos=this->c->Obtener_Inscipciones_Curso(nombreCurso);
								for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
									DTInscripcion* alumno=*it;
									cout << alumno->getEstudiante()<<" ----------- '"<<alumno->getFecha()<<"' "<<endl<<endl;

								}
								
		    				break;
		    				}
	}
	
	

}





Consultar_Curso::~Consultar_Curso() {
	// TODO Auto-generated destructor stub
}