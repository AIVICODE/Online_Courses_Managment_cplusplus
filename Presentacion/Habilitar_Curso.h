#ifndef HABILITAR_CURSO_H
#define HABILITAR_CURSO_H

#include <string>
#include "../Negocio/Interfaces/IControlador.h"
#include "../Negocio/Controlador/Controlador.h"


class Habilitar_Curso {
private:
    IControlador* controlador;

public:
    Habilitar_Curso();
    void habilitarCurso();
};

#endif // HABILITAR_CURSO_H