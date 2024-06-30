#ifndef REALIZAR_EJERCICIO_H
#define REALIZAR_EJERCICIO_H

#include <string>
#include "../Negocio/Interfaces/IControlador.h"
#include "../Negocio/DT/DTEjercicio.h"
#include "../Negocio/DT/DTEjercicio_Completar.h"
#include "../Negocio/DT/DTEjercicio_Traduccion.h"

class Realizar_Ejercicio {
private:
    IControlador* controlador;

public:
    Realizar_Ejercicio();
    
	void RealizarEjercicio();
};

#endif // HABILITAR_CURSO_H