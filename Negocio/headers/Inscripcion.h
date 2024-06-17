
#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "../DT/DTFecha.h"
#include "Curso.h"
#include "Idioma.h"
#include <string>
#include <list>
class Inscripcion {
private:
    DTFecha fecha;
    //leccion actual
    //list<lecciones*> aprobadas;
    Curso* curso;
public:
    Inscripcion(const DTFecha& fecha);

    // Métodos
    list<string> evalua_progreso();
    void Pendiente();
    void Agregar_Ejercicio_Resuelto();

    // Getter
    DTFecha getFecha() const;
};

#endif // INSCRIPCION_H
