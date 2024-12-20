/*
 * Profesor.h
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#ifndef PROFESOR_H_
#define PROFESOR_H_

#include "Usuario.h"
#include "Idioma.h"

#include <list>
class Profesor : public Usuario {
private:
    list<Idioma*> idiomasDeProfesor;
	string instituto;
public:
    Profesor();
    Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
    //Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<Idioma*> idiomasDeProfesor);

    // Getters
    string getInstituto()const;
    string getNickname();
    void agregarIdioma(Idioma* idioma);
    
        list<Idioma*> getIdiomas() const; 



    ~Profesor();
};

#endif /* PROFESOR_H_ */
