#ifndef PRESENTACION_AGREGAR_EJERCICIO_H_
#define PRESENTACION_AGREGAR_EJERCICIO_H_

#include "../Negocio/Interfaces/IControlador.h"


//#include "../Negocio/DT/DTOProfesor.h"
//#include "../Negocio/DT/DTOEstudiante.h"
#include "../Negocio/DT/DTEjercicio.h"
#include <string>
#include <list>

class Agregar_Ejercicio{
private:
	IControlador* controlador;

public:
	Agregar_Ejercicio();
	void Agregar_Ejercicio_Curso();
	virtual ~Agregar_Ejercicio();
	DTEjercicio* SolicitarDatosEjercicio();


	void Mostrar_Cursos_No_Hab();
};
#endif
