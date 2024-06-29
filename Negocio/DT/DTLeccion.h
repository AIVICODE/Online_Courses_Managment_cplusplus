/*
 * Ejercicio.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_DTLECCION_H_
#define LABFINAL_DTLECCION_H_

#include <string>
#include <list>

using namespace std;

class DTLeccion {
private:
        string nombre;
        string descripcion;
        string tema;
        string objetivo;
        
    public:
        DTLeccion();
        DTLeccion(string nombre, string descripcion,string tema,string objetivo);

		string Get_Nombre() const;
    	string Get_Descripcion() const;
    	string Get_Tema() const;
    	string Get_Objetivo() const;

        virtual ~DTLeccion();
};

#endif /* LABFINAL_EJERCICIO_H_ */
