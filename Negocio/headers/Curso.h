/*
 * Curso.h
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#ifndef CLASES_CURSO_H_
#define CLASES_CURSO_H_

#include <string>
#include <list>


using namespace std;

class Curso {
    private:
        string nombre;
        string descripcion;
        //Nivel nivel;
        bool disponible;


    public:
        Curso();
        //Curso(string nombre, string descripcion, Nivel nivel, bool disponible);
       // Curso(string nombre, string descripcion, Nivel nivel, bool disponible, Idioma* idioma, Profesor* profesor, vector<Leccion*> lecciones);

        // Getters
        string Get_Nombre();
        string Get_Descripcion();
        //Nivel getNivel();
        bool Get_Disponible();
        list<string> evalua_progreso();
        ~Curso();
	};
#endif /* CLASES_CURSO_H_ */
