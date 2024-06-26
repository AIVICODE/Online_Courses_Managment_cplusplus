/*
 * DTInscripcion.h
 *
 *  Created on: 30 jun. 2024
 *      Author: topo
 */

#ifndef NEGOCIO_DT_DTINSCRIPCION_H_
#define NEGOCIO_DT_DTINSCRIPCION_H_
#include <string>
#include "../DT/DTFecha.h"
#include <list>
using namespace std;
class DTInscripcion {
private:
    string fecha;
    string curso;
    string estudiante;

public:
	DTInscripcion();
	DTInscripcion(string estudiante, string curso, string fecha);
	virtual ~DTInscripcion();
	string getFecha() const;
	string getCurso() const;
	string getEstudiante() const;
};

#endif /* NEGOCIO_DT_DTINSCRIPCION_H_ */
