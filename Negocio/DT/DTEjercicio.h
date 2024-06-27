/*
 * Ejercicio.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_DTEJERCICIO_H_
#define LABFINAL_DTEJERCICIO_H_

#include <string>
#include <list>

using namespace std;

class DTEjercicio {
private:
        string nombre;
        string descripcion;
    public:
        DTEjercicio();
        DTEjercicio(string nombre, string descripcion);

		string Get_Nombre() const;
    	string Get_Descripcion() const;

        virtual ~DTEjercicio();
};

#endif /* LABFINAL_EJERCICIO_H_ */
