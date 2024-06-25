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
	bool Existe_Idioma(const std::string& nombreIdioma);
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
	bool Verificar_Nombre_Curso(const std::string& nombre);
	list <string> Listar_Cursos_Habiles();
	void Agregar_Idioma_Curso(string idioma);
	Idioma* Buscar_Idioma(string idioma);
	Curso* Buscar_Curso(const string nombreCurso);
	virtual ~Controlador();
	//hab curso
	void Habilitar_Curso(string nombreCurso);
	//altaidioma
	void Alta_Idioma(std::string el_idioma);
	
	void Carga_Datos();
};

#endif /* LABFINAL_CONTROLADOR_CONTROLADOR_H_ */
