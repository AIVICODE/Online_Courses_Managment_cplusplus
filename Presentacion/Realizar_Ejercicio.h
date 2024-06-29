#ifndef REALIZAR_EJERCICIO_H
#define REALIZAR_EJERCICIO_H

#include <string>
#include "../Negocio/Interfaces/IControlador.h"


class Realizar_Ejercicio {
private:
    IControlador* controlador;

public:
    Realizar_Ejercicio();
    
	void RealizarEjercicio();
};

#endif // HABILITAR_CURSO_H