//#include "Presentacion/Alta_Idioma.h"
#include "Alta_Idioma.h"

Alta_Idioma::Alta_Idioma(){
	
	this->ic = new Controlador();

}

void Alta_Idioma::Hacer(){

	std::string el_idioma;
	char opcion = 'o';

	do {
		std::cout << "Ingrese el idioma a ingresar:";
		std::cout << std::endl;
		std::cin >> el_idioma;

		if (this->ic->Existe_Idioma(el_idioma) ==true){
			std::cout << "Error: el idioma ingresado ya existe." << std::endl;
			std::cout << "¿Desea intentar de nuevo?(S/n): ";
			std::cout << std::endl;
			cin >> opcion;
			continue;
		}
		std::cout << "¿Desea ingresar el idioma '"<<el_idioma<<"'?(S/n): ";
		std::cout << std::endl;
		cin >>opcion;
		if (opcion != 'n'){
			std::cout << "Se ingreso el idioma: "<<el_idioma << std::endl;
			this->ic->Alta_Idioma(el_idioma);
	
		}
		else{
			std::cout << "No se ingreso el idioma: "<<el_idioma << std::endl;
		}
		std::cout << "¿Desea ingresar otro idioma?(S/n): ";
		std::cout << std::endl;
		cin >> opcion;
	} while (opcion != 'n');




}
