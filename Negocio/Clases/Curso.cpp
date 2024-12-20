/*
 * Curso.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */
#include "../headers/Curso.h"


Curso::Curso() {
	// TODO Auto-generated constructor stub

}

Curso::~Curso() {
	// TODO Auto-generated destructor stub
}

Curso::Curso(std::string nombre, std::string descripcion, Tipo_Dificultad dificultad, bool disponible)
    : nombre(nombre), descripcion(descripcion), dificultad(dificultad), disponible(disponible) {}

std::string Curso::getNombre() const {
    return nombre;
}

std::string Curso::getDescripcion() const {
    return descripcion;
}

Tipo_Dificultad Curso::getDificultad() const {
    return dificultad;
}

std::string Curso::getDificultadString() const {
    return toString(dificultad);
}



bool Curso::isDisponible() const {
    return disponible;
}

void Curso::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Curso::setDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

void Curso::setDificultad(Tipo_Dificultad dificultad) {
    this->dificultad = dificultad;
}

void Curso::setDisponible(bool disponible) {
    this->disponible = disponible;
}
void Curso::setIdioma(Idioma* idioma) {
    this->idiomacurso = idioma;
}
Idioma* Curso::getIdioma() const {
    return idiomacurso;
}

list<Leccion*> Curso::getLecciones() const {
    return leccionescurso;
}

list<Curso*> Curso::getCursosPrevios() const{
	return previas;
}
    void Curso::setPrevias(const list<Curso*>& nuevasPrevias) {
        previas = nuevasPrevias;
    }
    
void Curso::setLeccion(Leccion* nuevaLeccion) {
    leccionescurso.push_back(nuevaLeccion);
}
Profesor* Curso::getProfesor() const {
    return profesor;
}
void Curso::setProfesor(Profesor* profesor) {
    this->profesor = profesor;
}
    Leccion* Curso::buscarLeccion(const string& nombreLeccion) {
        for (Leccion* leccion : leccionescurso) {
            if (leccion->Get_Nombre() == nombreLeccion) {
                return leccion;
            }
        }
        return nullptr; // Retorna nullptr si no se encuentra la lección
    }
    void Curso::eliminarPrevia(Curso* cursoEliminar) {
        previas.remove(cursoEliminar);
    }

list<string> Curso::evalua_progreso(){
// RECORRO LECCIONES
// A CADA UNA ENVIO dar_ejercicios_pendientes(//paso los ejercicios realizados)//Esta operacion va a trabajar con los ejercicios de la leccion en el loop;

}
