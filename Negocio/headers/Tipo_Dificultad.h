#ifndef TIPO_DIFICULTAD_H
#define TIPO_DIFICULTAD_H

#include <string>

#include <iostream>
using namespace std;
enum class Tipo_Dificultad {
    Facil,
    Intermedia,
    Dificil
};

string toString(Tipo_Dificultad dificultad);

#endif // TIPO_DIFICULTAD_H
