/*
 * Controlador.cpp
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#include "../Interfaces/IControlador.h"
#include "Controlador.h"
#include "../headers/Usuario.h"
#include "../headers/Profesor.h"
#include "../headers/Estudiante.h"
#include "../headers/Tipo_Dificultad.h"
#include "../headers/Ejercicio.h"
#include "../headers/Ejercicio_Completar.h"
#include "../headers/Ejercicio_Traducir.h"
#include "../headers/Leccion.h"
#include "../headers/Inscripcion.h"

#include "../DT/DTUsuario.h"
#include "../DT/DTLeccion.h"
#include "../DT/DTProfesor.h"
#include "../DT/DTEstudiante.h"
#include "../DT/DTCurso.h"
#include "../DT/DTEjercicio.h"
#include "../DT/DTEjercicio_Completar.h"
#include "../DT/DTEjercicio_Traduccion.h"
#include "../DT/DTConsultaCurso.h"

#include "../System/System.h"

#include <set>

#include <iostream>
using namespace std;

#include <ctime>

// Función para obtener la fecha actual del sistema
void Controlador::obtenerFechaActual(int &dia, int &mes, int &anio) {
    // Obtener la fecha y hora actual del sistema
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    // Extraer el día, mes y año
    dia = now->tm_mday;
    mes = now->tm_mon + 1; // tm_mon es el número de meses desde enero, por lo que se añade 1
    anio = now->tm_year + 1900; // tm_year es el número de años desde 1900, por lo que se añade 1900
}

Controlador::Controlador() {
	//obtendo la unica instancia del Sistema
	this->sistema = System::Get_Instancia();
}
//Alta user
void Controlador::ingresarUsuario(DTUsuario* user) {
	cout << "Ingresando Usuario" << endl;

	if (DTProfesor* profesorDTO = dynamic_cast<DTProfesor*>(user)) {

	        // Creación del objeto Profesor
	        Profesor* profesor = new Profesor(
	            profesorDTO->getNickname(),
	            profesorDTO->getContrasenia(),
	            profesorDTO->getNombre(),
	            profesorDTO->getDescripcion(),
	            profesorDTO->getInstituto()
	        );
	        
	        list<string> nombresIdiomas=profesorDTO->getIdiomas();
	    for (const string& nombreIdioma : nombresIdiomas) {
        Idioma* idioma = Buscar_Idioma(nombreIdioma);
        if (idioma) {
            profesor->agregarIdioma(idioma);
        } 
    }
	        // Agregar el profesor al conjunto de usuarios
	        this->sistema->usuarios.insert(profesor);



	        } else if (DTEstudiante* estudianteDTO = dynamic_cast<DTEstudiante*>(user)) {

	        	Estudiante* estudiante = new Estudiante(
	        		            estudianteDTO->getNickname(),
	        		            estudianteDTO->getContrasenia(),
	        		            estudianteDTO->getNombre(),
	        		            estudianteDTO->getDescripcion(),
	        		            estudianteDTO->getPais(),
								estudianteDTO->getFecha()

	        		        );
		        this->sistema->usuarios.insert(estudiante);

	        } else {
	            cerr << "Error: Usuario no reconocido" << endl;
	        }
}

bool Controlador::Verificar_Nick(string nick) {
    // Recorro los usuarios del sistema
	bool result = false;

		set<Usuario*>::iterator it;

		for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
			if (nick == (*it)->Get_Nick()) {
				result = true;
				break;
			}
		}
		return result;
}

list<string> Controlador::Listar_Idiomas(){
//PARA PRUEBAS
	// Crear un nuevo idioma "inglés" y agregarlo al conjunto de idiomas
	    //Idioma* ingles = new Idioma("ingles");
	   // this->sistema->idiomas.insert(ingles);
//FIN PRUEBA
	    // Lista para almacenar los nombres de los idiomas
	    list<string> nombresIdiomas;

	    // Iterar sobre el conjunto de punteros a objetos Idioma
	    for (auto it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
	        // Obtener el nombre del idioma y agregarlo a la lista
	        nombresIdiomas.push_back((*it)->Get_Nombre()); // Suponiendo que GetNombre() devuelve el nombre del idioma
	    }

	    return nombresIdiomas;
}

void Controlador::Agregar_Especializacion(string idioma,string user){
	//Existe idioma?
	Idioma* enlaceIdioma = nullptr; // Inicializar el puntero a nullptr para indicar que aún no se ha encontrado el idioma

	for (auto it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
	    // Obtener el nombre del idioma y verificar si coincide con el idioma deseado
	    if (idioma == (*it)->Get_Nombre()) {
	        // Si se encuentra el idioma deseado, guardar el enlace al objeto Idioma
	        enlaceIdioma = *it;
	        // Salir del bucle si se ha encontrado el idioma
	        break;
	    }
	}

	//redundante pero quien sabe
	if (enlaceIdioma == nullptr)
	    // Si el idioma no existe, manejar el caso (por ejemplo, mostrar un mensaje de error)
	    cout << "El idioma seleccionado no existe." << endl;
cout<<"aca1";
	for (auto it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
	    // Verificar si el usuario es de tipo profesor
	    cout<<"aca2";
	    Profesor* profesor = dynamic_cast<Profesor*>(*it);
	    if (profesor != nullptr && user == profesor->Get_Nick()) {
			cout<<"aca3";
	        // El usuario es un profesor, así que podemos llamar a agregarIdioma()
	        profesor->agregarIdioma(enlaceIdioma);

	    }
	}

}

bool Controlador::Existe_Idioma(const string& nombreIdioma) {
    for (auto it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
        if (nombreIdioma == (*it)->Get_Nombre()) {
            return true; // Retornar el puntero al idioma encontrado
        }
    }
    return false; // Si no se encuentra, retornar nullptr
}
	//fin alta user

	//consultar estadistica
	list<string> Controlador::consultar_estadistica(string nickname){

	Usuario* user=Buscar_Usuario(nickname);

	Estudiante* estudiante = dynamic_cast<Estudiante*>(user);

	if (estudiante != nullptr) {//Es estudiante
		estudiante->dar_estadistica();
	}

	Profesor* profesor = dynamic_cast<Profesor*>(user);

	if (profesor != nullptr) {//Es profesor

}
}
//fin consultar estadistica
list<DTUsuario*> Controlador::Listar_Usuarios() {
    list<DTUsuario*> userlist;
    // Itera sobre la lista de usuarios
    for (Usuario* usuario : this->sistema->usuarios) {
        // Verifica si el usuario es un profesor
        if (Profesor* profesor = dynamic_cast<Profesor*>(usuario)) {
            list<Idioma*> idiomasDeProfesor = profesor->getIdiomas(); 
			list<string> nombres;

			for (Idioma* idioma : idiomasDeProfesor) {
    				if (idioma != nullptr) {
        				nombres.push_back(idioma->Get_Nombre());
    				}
				}
            
            DTProfesor* dtProfesor = new DTProfesor(usuario->Get_Nick(),usuario->Get_Nombre(),usuario->Get_Descripcion(),profesor->getInstituto(),nombres);
            userlist.push_back(dtProfesor);
        }
        // Verifica si el usuario es un estudiante
        else if (Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario)) {
            // Crea un DTEstudiante con solo el nickname y agrega a la lista
            DTEstudiante* dtEstudiante = new DTEstudiante(usuario->Get_Nick(),usuario->Get_Nombre(),usuario->Get_Descripcion(),estudiante->getPais());
            userlist.push_back(dtEstudiante);
        }
        // Si el usuario no es ni profesor ni estudiante, crea un DTUsuario genérico con solo el nickname
        else {
            cout<<"Error inesperado";
        }
    }

    return userlist;
}
// Hay que ponerla en privado
Usuario* Controlador::Buscar_Usuario(string nickname){


	for (auto it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); ++it) {
	        if ((*it)->Get_Nick() == nickname) {
	            return *it;
	        }
	    }
	    return nullptr; // Devuelve nullptr si no se encuentra el usuario

}
//Comienzo alta curso
void Controlador::Crear_Curso(DTCurso* dtcurso,string nickname){


	Tipo_Dificultad dificultad;

switch (dtcurso->getDificultad()) {
        case 1:
            dificultad = Tipo_Dificultad::Facil;
            break;
        case 2:
            dificultad = Tipo_Dificultad::Intermedia;
            break;
        case 3:
            dificultad = Tipo_Dificultad::Dificil;
            break;
        default:
            // Manejo de error si el valor de dificultad no es válido
            // Puedes lanzar una excepción, asignar un valor predeterminado, etc.
            break;
    }
    
	Curso* curso = new Curso(
		dtcurso->getNombre(),
		dtcurso->getDescripcion(),
		dificultad,
		0// setea el curso habilitado = false
		);
	
	curso->setIdioma(Buscar_Idioma(dtcurso->getIdioma()));
//agrego previas a curso
	list<string> strprevias=dtcurso->getPrevias();
	
	        if (curso != nullptr) {
				
            list<Curso*> nuevasPrevias;
            for (const auto& strprevia : strprevias) {
                Curso* previa = Buscar_Curso(strprevia);
                if (previa != nullptr) {
                    nuevasPrevias.push_back(previa);
                } 
            }
            curso->setPrevias(nuevasPrevias);

            }
            
    Usuario* user=Buscar_Usuario(nickname);
    if (Profesor* profesor = dynamic_cast<Profesor*>(user)) {
    curso->setProfesor(profesor);
    }

	this->sistema->cursos.insert(curso);

}

list<DTUsuario*> Controlador::Listar_Profesores(){
	list<DTUsuario*> userlist;

	    // Itera sobre la lista de usuarios
	    for (Usuario* usuario : this->sistema->usuarios) {
	        // Verifica si el usuario es un profesor
	        if (Profesor* profesor = dynamic_cast<Profesor*>(usuario)) {
	            // Crea un DTProfesor con solo el nickname y agrega a la lista
	            DTProfesor* dtProfesor = new DTProfesor(usuario->Get_Nick());
	            userlist.push_back(dtProfesor);
	        }
	    }
	return userlist;
}


bool Controlador::Verificar_Nombre_Curso(const string nombre) {
    // Recorro los cursos del sistema
    bool result = false;

    for (Curso* curso : this->sistema->cursos) {
        if (nombre == curso->getNombre()) {
            result = true;
            break;
        }
    }
    return result;
}
//Comienzo alta curso

list <string> Controlador::Listar_Cursos_Habiles(){
    list<string> cursosHabilitados;

    for (Curso* curso : this->sistema->cursos) {
        if (curso->isDisponible()) {
            cursosHabilitados.push_back(curso->getNombre());
        }
    }
    return cursosHabilitados;
}

list <string> Controlador::Listar_Cursos_No_Habiles(){
    list<string> cursosnoHabilitados;

    for (Curso* curso : this->sistema->cursos) {
        if (curso->isDisponible()==false) {
            cursosnoHabilitados.push_back(curso->getNombre());
        }
    }
    return cursosnoHabilitados;
}

list <string> Controlador::Listar_Cursos(){
	    list<string> cursoslist;

    for (Curso* curso : this->sistema->cursos) {
            cursoslist.push_back(curso->getNombre());

    }
    return cursoslist;
}

void Controlador::Agregar_Idioma_Curso(string idioma){


}
Idioma* Controlador::Buscar_Idioma(string idioma){


	for (auto it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); ++it) {
	        if ((*it)->Get_Nombre() == idioma) {
	            return *it;
	        }
	    }
	    return nullptr; // Devuelve nullptr si no se encuentra el usuario


}

Curso* Controlador::Buscar_Curso(const string nombreCurso) {
	for (auto it = this->sistema->cursos.begin(); it != this->sistema->cursos.end(); ++it) {
            if ((*it)->getNombre() == nombreCurso) {
                return *it;
            }
        }
        return nullptr; // Devuelve nullptr si no se encuentra el curso
	
    }
    
void Controlador::Habilitar_Curso(string nombreCurso){
    Curso* curso = Buscar_Curso(nombreCurso);
    if (curso) {
        curso->setDisponible(true);
    } 
    
    Listar_Cursos_Habiles();
}
Controlador::~Controlador() {
	// TODO Auto-generated destructor stub
}
//mariano consultar curso

//------------------------------------------------<MARIANO>-------------------------------------------------------
DTConsulta_Curso* Controlador::ConsultaCurso(string nombreCurso){
	Curso* curso = Buscar_Curso(nombreCurso);
	
	DTConsulta_Curso* consultaDTO=new DTConsulta_Curso((curso->getNombre()),(curso->getDescripcion()),(curso->getDificultadString()), (curso->getIdioma())->Get_Nombre() );
	return consultaDTO;
}

void Controlador::Alta_Idioma(std::string el_idioma){


	this->sistema->idiomas.insert(new Idioma(el_idioma));
	
}
list<string> Controlador::Mostrar_Lecciones(string nombreCurso){
    Curso* curso = Buscar_Curso(nombreCurso);
    list<string> nombresLecciones;

    if (curso) {
        for (Leccion* leccion : curso->getLecciones()) {
            nombresLecciones.push_back(leccion->Get_Nombre());
        }
    } else {
        // Manejar el caso en que el curso no sea encontrado
        cout << "Curso no encontrado." << endl;
    }

    return nombresLecciones;
}

void Controlador::Agregar_Ejercicio(string nombreCurso,string nombreLeccion,DTEjercicio* dtejercicio){

	Mostrar_Lecciones(nombreCurso);


        Curso* curso = Buscar_Curso(nombreCurso);

        Leccion* leccion = curso->buscarLeccion(nombreLeccion);

        if (DTCompletar* completarDTO = dynamic_cast<DTCompletar*>(dtejercicio)) {
        Completar* ejercicio = new Completar(
            completarDTO->Get_Nombre(),
            completarDTO->Get_Descripcion(),
            completarDTO->Get_Frase_Incompleta(),
            completarDTO->Get_Palabras_Faltantes()
        );

        leccion->Agregar_Ejercicio(ejercicio);
    } else if (DTTraducir* traducirDTO = dynamic_cast<DTTraducir*>(dtejercicio)) {
        Traducir* ejercicio = new Traducir(
            traducirDTO->Get_Nombre(),
            traducirDTO->Get_Descripcion(),
            traducirDTO->Get_Frase_Sin_Traducir(),
            traducirDTO->Get_Frase_Traducida()
        );
        leccion->Agregar_Ejercicio(ejercicio);
    }
	
}

//Existe leccion para curso
bool Controlador::Existe_Leccion(string nombreCurso,string nombreLeccion){
	    if (Curso* curso = Buscar_Curso(nombreCurso)) {
        if (curso->buscarLeccion(nombreLeccion)) {
            return true;
        }
    }
    return false;
}


list<string> Controlador::Mostrar_Ejercicios(string nombreCurso, string nombreLeccion) {
    Curso* curso = Buscar_Curso(nombreCurso);
    if (!curso) {
        cout << "Curso no encontrado: " << nombreCurso << endl;
        return {}; // Devolver lista vacía si el curso no se encuentra
    }

    Leccion* leccion = curso->buscarLeccion(nombreLeccion);
    if (!leccion) {
        cout << "Lección no encontrada: " << nombreLeccion << " en el curso " << nombreCurso << endl;
        return {}; // Devolver lista vacía si la lección no se encuentra en el curso
    }

    list<string> nombresEjercicios;
    const list<Ejercicio*>& ejercicios = leccion->Get_Ejercicios();
    for (Ejercicio* ejercicio : ejercicios) {
        nombresEjercicios.push_back(ejercicio->Get_Nombre()); // Suponiendo que Ejercicio tiene un método Get_Nombre()
    }

    return nombresEjercicios;
}



void Controlador::Ingresa_Ejercicio(string nickname){

	Usuario* user=Buscar_Usuario(nickname);

       
    
}

list<string> Controlador::Muestra_Cursos_Pendientes(string nickname){
			Usuario* user=Buscar_Usuario(nickname);
		    // Verificamos si un usuario existe y obtenemos el usuario
		    list<string> cursosPendientes;
    if (user) {
        // Intentamos convertirlo a Estudiante
        Estudiante* estudiante = dynamic_cast<Estudiante*>(user);
        if (estudiante) {
            cursosPendientes = estudiante->dar_cursos_pendientes();
        	}
        }
        return cursosPendientes;
        
}

list<string> Controlador::Muestra_Ejercicios_Pendientes(string nickname,string nombreCurso){
			Usuario* user=Buscar_Usuario(nickname);
			
			Curso* curso=Buscar_Curso(nombreCurso);
			
			    list<string> ejerciciosPendientes;

			
			const list<Leccion*>& leccionesCurso = curso->getLecciones();

    // Intentar castear el usuario a Estudiante
    Estudiante* estudiante = dynamic_cast<Estudiante*>(user);

    // Obtener las inscripciones del estudiante
    list<Inscripcion*> inscripciones = estudiante->getInscripciones();
    
        Inscripcion* inscripcionEnCurso = nullptr;
    for (Inscripcion* inscripcion : inscripciones) {
        if (inscripcion->getCurso() == curso) {
            inscripcionEnCurso = inscripcion;
            break;
        }
    }

    // Verificar si se encontró la inscripción para el curso
    if (!inscripcionEnCurso) {
        cout << "El estudiante no está inscrito en el curso '" << nombreCurso << "'." << endl;
        return ejerciciosPendientes;
    }

    // Encontrar la lección actual que no está aprobada
    Leccion* leccionActual = nullptr;
    bool encontrada = false;

    const list<Leccion*>& leccionesAprobadas = inscripcionEnCurso->getLeccionesAprobadas();

    for (Leccion* leccion : leccionesCurso) {
        bool estaAprobada = false;
        for (Leccion* aprobada : leccionesAprobadas) {
            if (aprobada == leccion) {
                estaAprobada = true;
                break;
            }
        }

        if (!estaAprobada) {
            leccionActual = leccion;
            encontrada = true;
            break;
        }
    }

    // Si se encontró una lección no aprobada, obtener los ejercicios pendientes
    if (encontrada && leccionActual) {
        const list<Ejercicio*>& ejerciciosCurso = leccionActual->Get_Ejercicios();
        const list<Ejercicio*>& ejerciciosAprobados = inscripcionEnCurso->getEjerciciosAprobados();

        for (Ejercicio* ejercicio : ejerciciosCurso) {
            bool estaAprobado = false;
            for (Ejercicio* aprobado : ejerciciosAprobados) {
                if (aprobado == ejercicio) {
                    estaAprobado = true;
                    break;
                }
            }

            if (!estaAprobado) {
                ejerciciosPendientes.push_back(ejercicio->Get_Nombre());
            }
        }
    } else {
        cout << "Todos los ejercicios del curso '" << nombreCurso << "' han sido aprobados." << endl;
    }

    return ejerciciosPendientes;
    

}

list<string> Controlador::List_Lecciones(string nombreCurso){
	    Curso* curso = Buscar_Curso(nombreCurso);
    if (!curso) {
        return list<string>(); // Devolver una lista vacía si el curso no se encuentra
    }

    list<string> nombresLecciones;
    // Recorrer las lecciones del curso y agregar sus nombres a la lista
    for (Leccion* leccion : curso->getLecciones()) {
        nombresLecciones.push_back(leccion->Get_Nombre());
    }

    return nombresLecciones;
}
// realizar inscripcion

list<string> Controlador::Cursos_Habiles_Estudiante(string nickname){
        Usuario* usuario = Buscar_Usuario(nickname);
        Estudiante* estudiante;
try {

        if (!usuario) {
            throw std::runtime_error("Usuario no encontrado");
        }

         estudiante = dynamic_cast<Estudiante*>(usuario);
        if (!estudiante) {
            throw std::runtime_error("Usuario no es un estudiante");
        }

        // Aquí agregarías la lógica para obtener los cursos habilitados

    } catch (const std::runtime_error& e) {
        // Captura la excepción y maneja el error de alguna manera
        std::cerr << "Error: " << e.what() << std::endl;
        return list<string>();
    }

    list<string> cursos_habiles = Listar_Cursos_Habiles();
    list<string> cursosPendientes = estudiante->dar_cursos_pendientes();

    list<string> cursosDisponibles;
    for (const string& curso : cursos_habiles) {
        bool estaPendiente = false;

        // Verificar que el estudiante no esté inscrito en el curso
        for (const string& cursoPendiente : cursosPendientes) {
            if (curso == cursoPendiente) {
                estaPendiente = true;
                break;
            }
        }

        if (!estaPendiente) {
            Curso* cursoObj = Buscar_Curso(curso);
            bool previosAprobados = true;

            // Obtener los nombres de los cursos previos
            list<string> nombresCursosPrevios;
            for (Curso* previo : cursoObj->getCursosPrevios()) {
                nombresCursosPrevios.push_back(previo->getNombre());
            }

            // Verificar los cursos previos
            for (const string& previo : nombresCursosPrevios) {
                bool previoPendiente = false;
                for (const string& cursoPendiente : cursosPendientes) {
                    if (previo == cursoPendiente) {
                        previoPendiente = true;
                        break;
                    }
                }
                if (previoPendiente) {
                    previosAprobados = false;
                    break;
                }
            }

            if (previosAprobados) {
                cursosDisponibles.push_back(curso);
            }
        }
    }

    return cursosDisponibles;
	
}

void Controlador::Inscribirse_a_Curso(string nickname, string nombreCurso){
    Usuario* usuario = Buscar_Usuario(nickname);
    Curso* curso = Buscar_Curso(nombreCurso);
    Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);


    int dia, mes, anio;
    obtenerFechaActual(dia, mes, anio);

    DTFecha fecha_actual(dia, mes, anio);
    Inscripcion* nuevaInscripcion = new Inscripcion(fecha_actual);
    nuevaInscripcion->setCurso(curso);

    // Agregar la inscripción al estudiante
    estudiante->setInscripcion(nuevaInscripcion);

}


void Controlador::AgregaLeccion(string nombreCurso,DTLeccion * dtleccion){
	    Curso* curso = Buscar_Curso(nombreCurso);
    if (curso) {
        Leccion* nuevaLeccion = new Leccion(dtleccion->Get_Nombre(), dtleccion->Get_Descripcion(), dtleccion->Get_Tema(), dtleccion->Get_Objetivo());
        curso->setLeccion(nuevaLeccion);
        cout << "Lección agregada al curso '" << nombreCurso << "' correctamente." << endl;
    } else {
        cout << "Curso no encontrado: '" << nombreCurso << "'. No se pudo agregar la lección." << endl;
    }
}



void Controlador::Carga_Datos(){
	Estudiante estudiante("pedro", "123", "nombre", "Le gusta el ingle", "Burkina", DTFecha(1, 1, 1940));
	this->sistema->usuarios.insert(new Estudiante(estudiante));

// Crear un profesor y agregarlo a usuarios
	Profesor profesor("prof", "contrasenia_prof", "nombre_prof", "descripcion_prof", "instituto_prof");
	this->sistema->usuarios.insert(new Profesor(profesor));

//alta idioma
	Idioma idioma("ing");
	this->sistema->idiomas.insert(new Idioma(idioma));
// Crear un curso y agregarlo a cursos

	Curso curso("fut", "Abajo del agua", Tipo_Dificultad::Facil, false);
	    Leccion* leccion1 = new Leccion("lec1");
	    curso.setIdioma(Buscar_Idioma("ing"));
    curso.setLeccion(leccion1);

	this->sistema->cursos.insert(new Curso(curso));

}

DTEjercicio * Controlador::Muestro_ejercicio_a_realizar(string nombreCurso,string nombreejercicio){
	    Curso* curso = Buscar_Curso(nombreCurso);
    if (!curso) {
        cout << "Curso no encontrado." << endl;
        return nullptr;
    }

    list<Leccion*> leccionesCurso = curso->getLecciones();
    for (Leccion* leccion : leccionesCurso) {
        list<Ejercicio*> ejerciciosLeccion = leccion->Get_Ejercicios();
        for (Ejercicio* ejercicio : ejerciciosLeccion) {
            if (ejercicio->Get_Nombre() == nombreejercicio) {
                if (Traducir* traducir = dynamic_cast<Traducir*>(ejercicio)) {
                    return new DTTraducir(traducir->Get_Nombre(), traducir->Get_Descripcion(), traducir->Get_FraseSinTraducir());
                } else if (Completar* completar = dynamic_cast<Completar*>(ejercicio)) {
					

                    return new DTCompletar(completar->Get_Nombre(), completar->Get_Descripcion(), completar->Get_FraseIncompleta());
                    
  
                    
                } else {
                    return new DTEjercicio(ejercicio->Get_Nombre(), ejercicio->Get_Descripcion());
                }
            }
        }
    }

    cout << "Ejercicio no encontrado." << endl;
    return nullptr;


}

bool Controlador::Verificar_Solucion(string nombreCurso,string nombreejercicio,DTEjercicio* solucion){
	    Curso* curso = Buscar_Curso(nombreCurso);
    if (!curso) {
        cout << "Curso no encontrado." << endl;
        return false;
    }





    list<Leccion*> leccionesCurso = curso->getLecciones();
    for (Leccion* leccion : leccionesCurso) {
        list<Ejercicio*> ejerciciosLeccion = leccion->Get_Ejercicios();
        for (Ejercicio* ejercicio : ejerciciosLeccion) {
            if (ejercicio->Get_Nombre() == nombreejercicio) {
                // Verificar si el ejercicio es de tipo Traducir
                if (Traducir* traducir = dynamic_cast<Traducir*>(ejercicio)) {
                    DTTraducir* solucionTraducir = dynamic_cast<DTTraducir*>(solucion);
                    if (solucionTraducir) {
                        return traducir->Get_FraseTraducida() == solucionTraducir->Get_Frase_Traducida();
                    }
                }
                // Verificar si el ejercicio es de tipo Completar
                else if (Completar* completar = dynamic_cast<Completar*>(ejercicio)) {
                    DTCompletar* solucionCompletar = dynamic_cast<DTCompletar*>(solucion);
                    if (solucionCompletar) {
                        return completar->Get_PalabrasFaltantes() == solucionCompletar->Get_Palabras_Faltantes();
                    }
                }
            }
        }
    }

    cout << "Ejercicio no encontrado." << endl;
    return false;
}

void Controlador::Agrega_Ejercicio_Correcto(string nombreCurso,string estudiante,string nombreejercicio){
Curso* curso = Buscar_Curso(nombreCurso);
    if (!curso) {
        return;
    }

    // Buscar al estudiante usando Buscar_Usuario
    Usuario* usuario = Buscar_Usuario(estudiante);
    if (!usuario) {
        return;
    }

    Estudiante* est = dynamic_cast<Estudiante*>(usuario);
    if (!est) {
        return;
    }

    // Buscar la inscripción del estudiante en el curso especificado
    Inscripcion* inscripcion = nullptr;
    for (Inscripcion* insc : est->getInscripciones()) {
        if (insc->getCurso() == curso) {
            inscripcion = insc;
            break;
        }
    }

    if (!inscripcion) {
        return;
    }

    // Buscar el ejercicio en el curso
    for (Leccion* leccion : curso->getLecciones()) {
        for (Ejercicio* ejercicio : leccion->Get_Ejercicios()) {
            if (ejercicio->Get_Nombre() == nombreejercicio) {
                // Agregar el ejercicio a la lista de ejercicios aprobados de la inscripción
                inscripcion->Agregar_Ejercicio_Resuelto(ejercicio);
                return;
            }
        }
    }

}


void Controlador::Eliminar_Curso(string nombreCurso) {
    // Buscar el curso a eliminar
Curso* cursoAEliminar = Buscar_Curso(nombreCurso);
    
    if (cursoAEliminar) {
		
		EliminarInscripcionesPorCurso(cursoAEliminar);
        // Eliminar el curso de la lista de cursos del sistema
        auto it = this->sistema->cursos.find(cursoAEliminar);
        if (it != this->sistema->cursos.end()) {
            this->sistema->cursos.erase(it);
        }

        // Liberar memoria del curso eliminado
        delete cursoAEliminar;
        cursoAEliminar = nullptr;  // Asignación nula para evitar referencias a memoria liberada

        // Iterar sobre todos los cursos en el sistema
        for (Curso* curso : this->sistema->cursos) {
            // Obtener la lista de cursos previos del curso actual
            const list<Curso*>& previas = curso->getCursosPrevios();

            // Iterar sobre la lista de previas para buscar y eliminar el curso a eliminar
            for (auto itPrevias = previas.begin(); itPrevias != previas.end(); ++itPrevias) {
                if (*itPrevias == cursoAEliminar) {
                    curso->eliminarPrevia(cursoAEliminar);
                    break;  // Salir del bucle una vez que se haya eliminado el curso
                }
            }
        }

        cout << "El curso '" << nombreCurso << "' ha sido eliminado exitosamente." << endl;
        }
}

void Controlador::EliminarInscripcionesPorCurso(Curso* curso) {
    // Iterar sobre todos los estudiantes y eliminar la inscripción al curso
    for (Usuario* usuario : this->sistema->usuarios) {
        Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);
        if (estudiante) {
            EliminarInscripcionDeEstudiante(estudiante, curso);
        }
    }
}

void Controlador::EliminarInscripcionDeEstudiante(Estudiante* estudiante, Curso* curso) {
    list<Inscripcion*> inscripciones = estudiante->getInscripciones();
    for (auto it = inscripciones.begin(); it != inscripciones.end(); ) {
        if ((*it)->getCurso() == curso) {
            delete *it;  // Liberar memoria de la inscripción
            it = inscripciones.erase(it);  // Eliminar la inscripción de la lista
        } else {
            ++it;
        }
    }
}

