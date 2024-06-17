
#include "../headers/Idioma.h"


#include <string>
// Constructor
Idioma::Idioma(const string & nombre) : nombre(nombre){}


string Idioma::Get_Nombre()const{
return this->nombre;
}

