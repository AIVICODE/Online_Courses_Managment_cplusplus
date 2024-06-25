#include "DTLeccion.h"

// Constructor por defecto
DTLeccion::DTLeccion() {

}

// Cons
DTLeccion::DTLeccion(string nombre, string descripcion, string tema, string objetivo) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tema = tema;
    this->objetivo = objetivo;
}

// Getter 
string DTLeccion::Get_Nombre() const {
    return nombre;
}

// Getter 
string DTLeccion::Get_Descripcion() const {
    return descripcion;
}


string DTLeccion::Get_Tema() const {
    return tema;
}

string DTLeccion::Get_Objetivo() const {
    return objetivo;
}

// Destructor
DTLeccion::~DTLeccion() {

}