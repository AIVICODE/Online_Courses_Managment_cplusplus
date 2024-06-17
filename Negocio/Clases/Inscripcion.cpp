#include "../headers/Inscripcion.h"
#include "../headers/Usuario.h"
#include <iostream>
#include <list>
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
