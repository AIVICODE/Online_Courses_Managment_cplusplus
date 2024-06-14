/*
 * Estudiante.h
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_
#include "Usuario.h"

#include "../DT/DTFecha.h"

class Estudiante : public Usuario{
private:
string pais;
DTFecha fecha;

public:
    // Constructor
    Estudiante();
    Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha fecha);
    // Destructor
    virtual ~Estudiante();
    string getPais() const;
    DTFecha getFecha() const;

};

#endif /* ESTUDIANTE_H_ */
