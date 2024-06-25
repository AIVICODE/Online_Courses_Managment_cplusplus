#ifndef CARGAR_DATOS_H
#define CARGAR_DATOS_H

#include "../Negocio/Controlador/Controlador.h"

class Cargar_Datos {
	private:
		IControlador *controlador;
	public:
		Cargar_Datos();
		void cargarDatos();
};

#endif