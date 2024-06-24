#include "Consultar_Idiomas.h"

Consultar_Idiomas::Consultar_Idiomas(){
	this->c = new Controlador();
};

void Consultar_Idiomas::Hacer(){

	list<string> los_idiomas = this->c->Listar_Idiomas();

	std::cout << "Los idiomas registrados son: " << std::endl;

	for (const auto& un_idioma : los_idiomas ){
		std::cout << un_idioma	<< std::endl;
	}

    	std::cin.ignore();
}
