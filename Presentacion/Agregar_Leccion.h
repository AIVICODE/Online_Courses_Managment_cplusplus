#ifndef PRESENTACION_AGREGAR_LECCION_H_
#define PRESENTACION_AGREGAR_LECCION_H_

#include "../Negocio/Interfaces/IControlador.h"


//#include "../Negocio/DT/DTOProfesor.h"
//#include "../Negocio/DT/DTOEstudiante.h"
#include "../Negocio/DT/DTLeccion.h"
#include "../Negocio/DT/DTEjercicio.h"
#include "../Negocio/DT/DTEjercicio_Completar.h"
#include "../Negocio/DT/DTEjercicio_Traduccion.h"
#include <string>
#include <list>

class Agregar_Leccion{
private:
	IControlador* controlador;

public:
	Agregar_Leccion();
	
	void AgregaLeccion();
	virtual ~Agregar_Leccion();
	DTEjercicio* SolicitarDatosEjercicio();

};
#endif
