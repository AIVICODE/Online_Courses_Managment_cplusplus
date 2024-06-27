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

using namespace std;
class Leccion {
private:
		string nombre;
       // string tema;
        //string objetivo;
        //list<Ejercicio*> ejercicios;
    public:
       Leccion();
        //Leccion(string descripcion);
        //Leccion(string tema, string objetivo);
        //Leccion(string tema,string objetivo,set<Ejercicio*>);
		string Get_Nombre();
        // Getters
        //string getTema();
        //string getObjetivo();
        //set<Ejercicio*> getEjercicios();
        //int getCantEj();

        // Setters
        //void setTema(string tema);
        //void setObjetivo(string objetivo);

        // Operaciones
        //void crearEjercicioYAgregarlo(string desc);


        ~Leccion();
};

#endif /* LABFINAL_LECCIONES_H_ */
