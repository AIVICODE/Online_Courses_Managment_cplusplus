/*
 * Lecciones.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_LECCIONES_H_
#define LABFINAL_LECCIONES_H_

#include <list>
#include <string>
#include "Ejercicio.h"
using namespace std;
class Leccion {
private:
		string nombre;
		string descripcion;
       string tema;
        string objetivo;
        list<Ejercicio*> ejercicios;
    public:
       Leccion();

	    Leccion(string nombre);
	    Leccion(string nombre,string descripcion,string tema,string objetivo);

		string Get_Nombre();
		
		string Get_Nombre() const;
		
    void Agregar_Ejercicio(Ejercicio* ejercicio);
    
    const list<Ejercicio*>& Get_Ejercicios() ; 
        string Get_Descripcion() const ;

string Get_Tema() const;


string Get_Objetivo() const;
        ~Leccion();
};

#endif /* LABFINAL_LECCIONES_H_ */
