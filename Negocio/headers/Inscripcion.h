
#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "../DT/DTFecha.h"
#include "Curso.h"
#include "Idioma.h"
#include "Leccion.h"
#include "Ejercicio.h"
#include <string>
#include <list>
class Inscripcion {
private:
    DTFecha fecha;
    list<Leccion*> aprobadas;
    Curso* curso;
    list<Ejercicio*> ejaprobados;
public:
    Inscripcion(const DTFecha& fecha);
	~Inscripcion();
    // Métodos
    list<string> evalua_progreso();
    void Pendiente();
    void Agregar_Ejercicio_Resuelto();

    // Getter
    DTFecha getFecha() const;
    
    
    
    bool estaAprobado() const;
    Curso* getCurso() const;
    
    void setCurso(Curso* curso);
    
    list<Leccion*> getLeccionesAprobadas() const;
    list<Ejercicio*> getEjerciciosAprobados() const;
    
    void Agregar_Ejercicio_Resuelto(Ejercicio* ejercicio);
};

#endif // INSCRIPCION_H
