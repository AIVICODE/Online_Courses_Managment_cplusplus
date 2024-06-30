/*
 * Ejercicio.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_EJERCICIO_TRADUCIR_H_
#define LABFINAL_EJERCICIO_TRADUCIR_H_
#include "Ejercicio.h"

#include <string>
#include <list>
using namespace std;

class Traducir : public Ejercicio {
private:
	string frase_sin_traducir;
	string frase_traducida;
	
public:
	Traducir();
    Traducir(string nombre, string descripcion, string frase_sin_traducir, string frase_traducida);
	~Traducir();
	string Get_FraseSinTraducir() const;
	string Get_FraseTraducida() const ;
};

#endif 