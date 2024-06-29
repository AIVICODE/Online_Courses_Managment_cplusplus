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
#include "Tipo_Dificultad.h"
#include "Idioma.h"
#include "Leccion.h"
#include "Curso.h"

using namespace std;

class Curso {
private:
	string nombre;
	string descripcion;
	Tipo_Dificultad dificultad;
	bool disponible;
	Idioma* idiomacurso;
	list <Leccion*> leccionescurso;
	list <Curso*> previas;

public:
	Curso();
	Curso(std::string nombre, std::string descripcion,
			Tipo_Dificultad dificultad, bool disponible); // Constructor actualizado

	std::string getNombre() const;
	std::string getDescripcion() const;
	Tipo_Dificultad getDificultad() const;
	std::string getDificultadString() const;
	bool isDisponible() const;

    Idioma* getIdioma() const;

    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setDificultad(Tipo_Dificultad dificultad);
    void setIdioma(Idioma* idioma);
	void setDisponible(bool disponible);
	void setPrevias(const list<Curso*>& nuevasPrevias);
	list<Leccion*> getLecciones() const;
    void setLeccion(Leccion* nuevaLeccion);
    Leccion* buscarLeccion(const string& nombreLeccion);
    list<Curso*> getCursosPrevios() const;

	
	list<string> evalua_progreso();
	~Curso();
};
#endif /* CLASES_CURSO_H_ */
