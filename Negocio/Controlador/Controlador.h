/*
 * Controlador.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_CONTROLADOR_CONTROLADOR_H_
#define LABFINAL_CONTROLADOR_CONTROLADOR_H_

#include "../Interfaces/IControlador.h"
#include "../DT/DTUsuario.h"
#include "../System/System.h"
#include <set>
#include <string>

class Controlador : public IControlador{

private:
	System* sistema;

public:
	//Alta user
	void ingresarUsuario(DTUsuario* user);
	list<string> Listar_Idiomas();
	bool Verificar_Nick(string nick);
	void Agregar_Especializacion(string idioma,string user);
	Idioma* Existe_Idioma(const std::string& nombreIdioma);
	//Fin alta user
	list<DTUsuario*> Listar_Usuarios();
	//consultar estadistica
	list<string> consultar_estadistica(string nickname);

	Usuario* Buscar_Usuario(string nickname);
	//fin consultar estadistica
	Controlador();
	//Alta curso
	list<DTUsuario*> Listar_Profesores();
	void Crear_Curso(DTCurso* curso);
	virtual ~Controlador();
};

#endif /* LABFINAL_CONTROLADOR_CONTROLADOR_H_ */
