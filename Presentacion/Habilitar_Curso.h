#ifndef HABILITAR_CURSO_H
#define HABILITAR_CURSO_H

#include <string>
#include "../Negocio/Interfaces/IControlador.h"


class Habilitar_Curso {
private:
    IControlador* controlador;

public:
    Habilitar_Curso();
    void habilitarCurso();
    void Mostrar_Cursos_No_Hab();
};

#endif // HABILITAR_CURSO_H