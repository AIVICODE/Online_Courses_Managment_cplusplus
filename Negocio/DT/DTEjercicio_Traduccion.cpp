

#include "DTEjercicio_Traduccion.h"
#include "DTEjercicio.h"



// Constructor por defecto
DTTraducir::DTTraducir() : DTEjercicio(), frase_sin_traducir(""), frase_traducida("") {}

// Constructor con parámetros
DTTraducir::DTTraducir(string nombre, string descripcion, string frase_sin_traducir, string frase_traducida)
    : DTEjercicio(nombre, descripcion), frase_sin_traducir(frase_sin_traducir), frase_traducida(frase_traducida) {}
    
DTTraducir::DTTraducir(string nombre, string descripcion, string frase_sin_traducir)
    : DTEjercicio(nombre, descripcion), frase_sin_traducir(frase_sin_traducir) {}


string DTTraducir::Get_Frase_Sin_Traducir() const {
    return frase_sin_traducir;
}

// Getter para frase_traducida
string DTTraducir::Get_Frase_Traducida() const {
    return frase_traducida;
}

// Destructor
DTTraducir::~DTTraducir() {}