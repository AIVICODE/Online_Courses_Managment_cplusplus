#ifndef CONSULTAR_ESTADISTICAS_H
#define CONSULTAR_ESTADISTICAS_H

#include "../Negocio/Interfaces/IControlador.h"

#include <list>
#include <string>

class Consultar_Estadisticas {

private:
	IControlador* controlador;

public:
Consultar_Estadisticas();

void consultar_estadisticas();

~Consultar_Estadisticas();
};
#endif // CONSULTAR_ESTADISTICAS_H
