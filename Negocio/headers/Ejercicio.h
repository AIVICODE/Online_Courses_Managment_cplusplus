/*
 * Ejercicio.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_EJERCICIO_H_
#define LABFINAL_EJERCICIO_H_

#include <string>
#include <list>

using namespace std;

class Ejercicio {
private:
        string nombre;
        string descripcion;
    public:
        Ejercicio();
        Ejercicio(string nombre, string descripcion);



        virtual ~Ejercicio();
};

#endif /* LABFINAL_EJERCICIO_H_ */
