#ifndef ELIMINAR_CURSO_H
#define ELIMINAR_CURSO_H

#include <string>
#include "../Negocio/Interfaces/IControlador.h"


class Eliminar_Curso {
private:
    IControlador* controlador;

public:
    Eliminar_Curso();
    
    void EliminarCurso();
    
    void Muestro_Cursos();
};

#endif // HABILITAR_CURSO_H