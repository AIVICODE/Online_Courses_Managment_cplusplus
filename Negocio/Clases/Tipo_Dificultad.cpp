#include "../headers/Tipo_Dificultad.h"

#include <string>

#include <iostream>
using namespace std;
string toString(Tipo_Dificultad dificultad) {
    switch (dificultad) {
        case Tipo_Dificultad::Facil:
            return "Facil";
        case Tipo_Dificultad::Intermedia:
            return "Intermedia";
        case Tipo_Dificultad::Dificil:
            return "Dificil";
        default:
            return "Desconocida";
    }
}
