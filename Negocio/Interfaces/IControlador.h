/*
 * IControlador.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_INTERFACES_ICONTROLADOR_H_
#define LABFINAL_INTERFACES_ICONTROLADOR_H_
#include "../DT/DTUsuario.h"
#include "../DT/DTCurso.h"
#include "../DT/DTEjercicio.h"
#include "../headers/Usuario.h"
#include "../headers/Idioma.h"
#include "../headers/Curso.h"
#include "../DT/DTConsultaCurso.h"
#include <string>
#include <list>

class IControlador {
public:
//extras

//fecha
virtual void obtenerFechaActual(int &dia, int &mes, int &anio)=0;
//
	virtual list<DTUsuario*> Listar_Usuarios()=0;
	virtual list<DTUsuario*> Listar_Profesores()=0;
	//fin
	virtual void ingresarUsuario(DTUsuario* user) = 0;

	virtual bool Verificar_Nick(string nick)=0;

	virtual list<string> Listar_Idiomas()=0;

	virtual bool Existe_Idioma(const std::string& nombreIdioma)=0;
	//fin alta user

	//consultar estadistica
	virtual list<string> consultar_estadistica(string nickname)=0;
	virtual Usuario* Buscar_Usuario(string nickname)=0;

	//fin
	virtual ~IControlador()=default;

	virtual void Agregar_Especializacion(string idioma,string user)=0;


	// Alta Curso
	void virtual Agregar_Idioma_Curso(string idioma)=0;
	virtual list <string> Listar_Cursos_Habiles()=0;
	virtual bool Verificar_Nombre_Curso(const std::string& nombre)=0;
	virtual void Crear_Curso(DTCurso* curso)=0;
	virtual Idioma* Buscar_Idioma(string idioma)=0;
	virtual Curso* Buscar_Curso(const string nombreCurso)=0;
	//habilitar curso
	virtual void Habilitar_Curso(string nombreCurso)=0;
	
	//alta idioma
	virtual void Alta_Idioma(string el_idioma) = 0;
	
	//agregar ejerccio
	virtual list <string> Listar_Cursos_No_Habiles()=0;
	virtual void Agregar_Ejercicio(string nombreCurso,string nombreLeccion,DTEjercicio* dtejercicio)=0;
	virtual list<string> Mostrar_Lecciones(string nombreCurso)=0;
	virtual bool Existe_Leccion(string nombreCurso,string nombreLeccion)=0;
	//
	//REalizar ejercicio 
	virtual list<string>  Mostrar_Ejercicios(string nombreCurso, string nombreLeccion)=0;
	//fin
	
	//Eliminar curso 
	virtual list <string> Listar_Cursos()=0;
	virtual void Carga_Datos()=0;
	
	// ejer
	virtual void Ingresa_Ejercicio(string nickname)=0;
	virtual list<string> Muestra_Cursos_Pendientes(string nickname)=0;
	virtual list<string> Muestra_Ejercicios_Pendientes(string nickname,string nombreCurso)=0;
	virtual DTConsulta_Curso* ConsultaCurso(string nombreCurso)=0;
	virtual list<string> Cursos_Habiles_Estudiante(string nickname)=0;
	virtual void Inscribirse_a_Curso(string nickname, string nombreCurso)=0;
};

#endif /* LABFINAL_INTERFACES_ICONTROLADOR_H_ */
