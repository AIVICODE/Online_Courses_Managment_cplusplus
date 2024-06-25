/*
 * Ejercicio.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_EJERCICIO_DTTRADUCIR_H_
#define LABFINAL_EJERCICIO_DTTRADUCIR_H_
#include "DTEjercicio.h"

#include <string>
#include <list>
using namespace std;

class DTTraducir : public DTEjercicio {
private:
	string frase_sin_traducir;
	string frase_traducida;
	
public:
	DTTraducir();
    DTTraducir(string nombre, string descripcion, string frase_sin_traducir, string frase_traducida);
	~DTTraducir();
	
	string Get_Frase_Sin_Traducir() const;
    string Get_Frase_Traducida() const;

};

#endif 