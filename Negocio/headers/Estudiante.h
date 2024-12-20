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
#include "Inscripcion.h"
#include <list>
#include <string>

class Estudiante : public Usuario{
private:
string pais;
DTFecha fecha;

list<Inscripcion*> inscripto; 

public:
    // Constructor
    Estudiante();
    Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha fecha);
    // Destructor
    virtual ~Estudiante();
    string getPais() const;
    DTFecha getFecha() const;
    string Get_Nick();

    list<string> dar_estadistica();
	list<string> dar_cursos_pendientes();
	list<Inscripcion*> getInscripciones() const;
	void setInscripcion(Inscripcion* inscribe);
    void setInscripciones(const list<Inscripcion*>& nuevasInscripciones);

};

#endif /* ESTUDIANTE_H_ */
