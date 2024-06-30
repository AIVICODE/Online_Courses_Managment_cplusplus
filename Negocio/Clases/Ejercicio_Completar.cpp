
#include "../headers/Ejercicio_Completar.h"
#include "../headers/Ejercicio.h"



Completar::Completar() {
    // Implementación del constructor por defecto
}

Completar::Completar(string nombre, string descripcion, string frase_incompleta, list<string> palabras_faltantes)
    : Ejercicio(nombre, descripcion) {
    this->frase_incompleta = frase_incompleta;
    this->palabras_faltantes = palabras_faltantes;
}


string Completar::Get_FraseIncompleta() const {
    return frase_incompleta;
}

list<string> Completar::Get_PalabrasFaltantes() const {
    return palabras_faltantes;
}


Completar::~Completar() {
    // Implementación del destructor
}