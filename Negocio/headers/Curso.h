/*
 * Curso.h
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#ifndef CLASES_CURSO_H_
#define CLASES_CURSO_H_

#include <string>
#include <vector>


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
        //vector<Leccion*> getLecciones();

        //DTDataCurso* getDT();

        // Setters
        void Set_Nombre(string nombre);
        void Set_Descripcion(string descripcion);
        //void setNivel(Nivel nivel);
        void Set_Disponible(bool disponible);
        //vod setCursosPrevios(set<Curso*> cursosPrevios);

        // Ops
        //void agregarLeccion(Leccion* leccion);
        // void agregarCursoPrevio(Curso* cursoPrevio);
        float Get_Cant_Ejs_Total();
        float Calc_PromedioAvance();
        int Get_Cant_Lecciones();

        ~Curso();
	};
#endif /* CLASES_CURSO_H_ */
