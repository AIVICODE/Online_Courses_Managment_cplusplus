#include "../Negocio/Controlador/Controlador.h"
#include <list>
#include <iostream>
#include <string>

class Inscribirse_A_Curso {
private:
	Controlador * c;
public:
	Inscribirse_A_Curso();
	void Inscribirse();
	virtual ~Inscribirse_A_Curso();
};


