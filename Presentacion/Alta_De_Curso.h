#ifndef PRESENTACION_ALTA_DE_CURSO_H_
#define PRESENTACION_ALTA_DE_CURSO_H_
#include "../Negocio/Interfaces/IControlador.h"
#include "Alta_De_Usuario.h"
//#include "../Negocio/DT/DTOProfesor.h"
//#include "../Negocio/DT/DTOEstudiante.h"
#include <string>
#include <list>
class Alta_De_Curso{
private:
	IControlador* controlador;

public:
	Alta_De_Curso();
	virtual ~Alta_De_Curso();

	void AltaCurso();

	void CrearCurso();
	int seleccionarDificultad();
};

#endif