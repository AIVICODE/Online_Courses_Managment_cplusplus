#include "../headers/Inscripcion.h"
#include "../headers/Usuario.h"
#include <iostream>
#include <list>

using namespace std;
Inscripcion::Inscripcion(const DTFecha& fecha) : fecha(fecha) {}

list<string> Inscripcion::evalua_progreso() {
	//this->curso->evalua_progreso();
    // Implementación del método Evalua_Progreso
    std::cout << "Falta implementar..." << std::endl;
}

void Inscripcion::Pendiente() {
    // Implementación del método Pendiente
    std::cout << "Falta implementar..." << std::endl;
}

void Inscripcion::Agregar_Ejercicio_Resuelto() {
    // Implementación del método Agregar_Ejercicio_Resuelto
    std::cout << "Falta implementar..." << std::endl;
}

DTFecha Inscripcion::getFecha() const {
    return fecha;
}

bool Inscripcion::estaAprobado() const {
    if (!curso) return false;

    const list<Leccion*>& leccionesCurso = curso->getLecciones();
    for (Leccion* leccionCurso : leccionesCurso) {
        bool encontrada = false;
        for (Leccion* leccionAprobada : aprobadas) {
            if (leccionAprobada == leccionCurso) {
                encontrada = true;
                break;
            }
        }
        if (!encontrada) {
            return false;
        }
    }
    return true;
}

Curso* Inscripcion::getCurso() const {
    return curso;
}

list<Leccion*> Inscripcion::getLeccionesAprobadas() const {
    return aprobadas;
}

list<Ejercicio*> Inscripcion::getEjerciciosAprobados() const{
	return ejaprobados;
}