/*
 * Ejercicio.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_EJERCICIO_COMPLETAR_H_
#define LABFINAL_EJERCICIO_COMPLETAR_H_
#include "Ejercicio.h"

#include <string>
#include <list>
using namespace std;

class Completar : public Ejercicio {
private:
	string frase_incompleta;
	list<string> palabras_faltantes;
	
public:
	Completar();
    Completar(string nombre, string descripcion, string frase_incompleta, list<string> palabras_faltantes);
	~Completar();
};

#endif 