
#include "DTEjercicio_Completar.h"
#include "DTEjercicio.h"



// Constructor por defecto
DTCompletar::DTCompletar() : DTEjercicio(), frase_incompleta(""), palabras_faltantes() {}

// Constructor con parámetros
DTCompletar::DTCompletar(string nombre, string descripcion, string frase_incompleta, list<string> palabras_faltantes)
    : DTEjercicio(nombre, descripcion), frase_incompleta(frase_incompleta), palabras_faltantes(palabras_faltantes) {}
    
    
DTCompletar::DTCompletar(string nombre, string descripcion, string frase_incompleta)
    : DTEjercicio(nombre, descripcion), frase_incompleta(frase_incompleta) {}

// Destructor
DTCompletar::~DTCompletar() {}

// Implementación de los getters
string DTCompletar::Get_Frase_Incompleta() const {
    return frase_incompleta;
}

list<string> DTCompletar::Get_Palabras_Faltantes() const {
    return palabras_faltantes;
}