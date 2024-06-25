
#include "../Negocio/Interfaces/IControlador.h"

#include <list>
#include <iostream>
#include <string>

class Consultar_Curso {
	private:
			IControlador * c;
	public:
		Consultar_Curso();
		void Hacer();
		virtual ~Consultar_Curso();
};

