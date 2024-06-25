/*
 * DTConsultaCurso.h
 *
 *  Created on: 27 jun. 2024
 *      Author: topo
 */

#ifndef NEGOCIO_DT_DTCONSULTACURSO_H_
#define NEGOCIO_DT_DTCONSULTACURSO_H_
#include <string>
#include <list>
using namespace std;

class DTConsulta_Curso {
private:
	string nombre;
	string descripcion;
	string dificultad;
	string idioma;
	//string nickname;

public:
	DTConsulta_Curso();
	DTConsulta_Curso(string nombre, string descripcion,string dificultad,string idioma/*, string nickname*/);
	string getNombre() const;
	string getDescripcion() const;
	string getDificultad() const;
	string getIdioma() const;
	//string getNickname() const;

	virtual ~DTConsulta_Curso();
};

#endif /* NEGOCIO_DT_DTCONSULTACURSO_H_ */
