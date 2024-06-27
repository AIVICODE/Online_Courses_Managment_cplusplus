

#include "../headers/Ejercicio_Traducir.h"
#include "../headers/Ejercicio.h"



Traducir::Traducir() {
    // Implementación del constructor por defecto
}


Traducir::Traducir(string nombre, string descripcion, string frase_sin_traducir, string frase_traducida)
    : Ejercicio(nombre, descripcion) {
    this->frase_sin_traducir = frase_sin_traducir;
    this->frase_traducida = frase_traducida;
}

Traducir::~Traducir() {}