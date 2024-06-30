/*
 * Ejercicio.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_EJERCICIO_DTCOMPLETAR_H_
#define LABFINAL_EJERCICIO_DTCOMPLETAR_H_
#include "DTEjercicio.h"

#include <string>
#include <list>
using namespace std;

class DTCompletar : public DTEjercicio {
private:
	string frase_incompleta;
	list<string> palabras_faltantes;
	
public:
	DTCompletar();
    DTCompletar(string nombre, string descripcion, string frase_incompleta, list<string> palabras_faltantes);
    DTCompletar(string nombre, string descripcion, string frase_incompleta);
	~DTCompletar();
	string Get_Frase_Incompleta() const;
    list<string> Get_Palabras_Faltantes() const;
};

#endif 