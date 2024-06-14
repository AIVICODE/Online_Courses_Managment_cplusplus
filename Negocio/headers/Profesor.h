/*
 * Profesor.h
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#ifndef PROFESOR_H_
#define PROFESOR_H_

#include "Usuario.h"

class Profesor : public Usuario {
private:
    //set<Idioma*> idiomasDeProfesor;
	string instituto;
public:
    Profesor();
    Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
    //Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<Idioma*> idiomasDeProfesor);

    // Getters
    string getInstituto()const;

    //bool esProfesor();
    //bool esEstudiante();

   // DTUsuario* getDT();

    // Setters
    //void setInstituto(string instituto);

    // Operaciones
    //set<string> obtenerIdiomas();
    //void agregarAIdiomasDeProfesor();
    //set<DTDataCursoProfesor> getCursosProfesor();

    //set<Idioma*> getIdiomas();


    ~Profesor();
};

#endif /* PROFESOR_H_ */
