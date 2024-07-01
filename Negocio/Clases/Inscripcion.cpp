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
    const list<Leccion*>& leccionesCurso = curso->getLecciones();
    
    // Si la lista de lecciones aprobadas está vacía, la inscripción no está aprobada
    if (aprobadas.empty()) {
        return false;
    }

    // Verificar que todas las lecciones del curso estén aprobadas
    for (Leccion* leccionCurso : leccionesCurso) {
        bool encontrada = false;

        for (Leccion* leccionAprobada : aprobadas) {
            if (leccionAprobada == leccionCurso) {
                encontrada = true;
                break;
            }
        }

        // Si alguna lección del curso no está aprobada, la inscripción no está aprobada
        if (!encontrada) {
            return false;
        }
    }

    // Si todas las lecciones del curso están aprobadas, la inscripción está aprobada
    return true;
}
void Inscripcion::Agregar_Ejercicio_Resuelto(Ejercicio* ejercicio) {
    ejaprobados.push_back(ejercicio);
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

    void Inscripcion::setCurso(Curso* curso){
		this->curso=curso;
	}
	
	
	Inscripcion::~Inscripcion() {
    // Liberar memoria de la lista de Lecciones aprobadas
    for (auto it = aprobadas.begin(); it != aprobadas.end(); ++it) {
        delete *it;
    }
    aprobadas.clear();  // Limpiar la lista después de liberar la memoria

    // Liberar memoria de la lista de Ejercicios aprobados
    for (auto it = ejaprobados.begin(); it != ejaprobados.end(); ++it) {
        delete *it;
    }
    ejaprobados.clear();  // Limpiar la lista después de liberar la memoria
}