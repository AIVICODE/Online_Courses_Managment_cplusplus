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
#include "../DT/DTEjercicio.h"
#include "../DT/DTLeccion.h"

#include <set>
#include <string>

class Controlador : public IControlador{

private:
	System* sistema;

public:

//fecha
void obtenerFechaActual(int &dia, int &mes, int &anio);
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
	void Crear_Curso(DTCurso* curso,string nickname);
	bool Verificar_Nombre_Curso(const string nombre);
	list <string> Listar_Cursos_Habiles();
	void Agregar_Idioma_Curso(string idioma);
	Idioma* Buscar_Idioma(string idioma);
	Curso* Buscar_Curso(const string nombreCurso);
	virtual ~Controlador();
	//hab curso
	void Habilitar_Curso(string nombreCurso);
	//altaidioma
	void Alta_Idioma(std::string el_idioma);
	//agregar ejercicio
	list<string> List_Lecciones(string nombreCurso);
	list <string> Listar_Cursos_No_Habiles();
	void Agregar_Ejercicio(string nombreCurso,string nombreLeccion,DTEjercicio* dtejercicio);
	list<string> Mostrar_Lecciones(string nombreCurso);
	bool Existe_Leccion(string nombreCurso,string nombreLeccion);
	list<string>  Mostrar_Ejercicios(string nombreCurso, string nombreLeccion);
	//fin
	
	//consutlar curso mariano
	DTConsulta_Curso* ConsultaCurso(string nombreCurso);
	//Eliminar curso
	list <string> Listar_Cursos();
	void Carga_Datos();
	
//ejercicio realizar
	void Ingresa_Ejercicio(string nickname);
	list<string> Muestra_Cursos_Pendientes(string nickname);
	list<string> Muestra_Ejercicios_Pendientes(string nickname,string nombreCurso);
	list<string> Cursos_Habiles_Estudiante(string nickname);
	void Inscribirse_a_Curso(string nickname, string nombreCurso);
	DTEjercicio * Muestro_ejercicio_a_realizar(string nombreCurso,string nombreejercicio);
	bool Verificar_Solucion(string nombreCurso,string nombreejercicio,DTEjercicio* solucion);
	void Agrega_Ejercicio_Correcto(string nombreCurso,string estudiante,string nombreejercicio);
	//agregarleccion
	void AgregaLeccion(string nombreCurso,DTLeccion * dtleccion);
	
	//eliminarcurso
	void Eliminar_Curso(string nombreCurso);
	void EliminarInscripcionesPorCurso(Curso* curso);
	void EliminarInscripcionDeEstudiante(Estudiante* estudiante, Curso* curso);
	
	//consulta curso
	list<DTLeccion*> Info_Lecciones(string nombreCurso);
	list<string> Mostrar_Descripcion_Ejercicios(string nombreCurso, string nombreLeccion);
	list<DTInscripcion*> Obtener_Inscipciones_Curso(string nombreCurso);
};

#endif /* LABFINAL_CONTROLADOR_CONTROLADOR_H_ */
