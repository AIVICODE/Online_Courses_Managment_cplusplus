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

#include "../DT/DTUsuario.h"
#include "../DT/DTProfesor.h"
#include "../DT/DTEstudiante.h"
#include "../DT/DTCurso.h"
#include "../DT/DTEjercicio.h"
#include "../DT/DTEjercicio_Completar.h"
#include "../DT/DTEjercicio_Traduccion.h"


#include "../System/System.h"

#include <set>

#include <iostream>
using namespace std;


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


	for (auto it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
	    // Verificar si el usuario es de tipo profesor
	    Profesor* profesor = dynamic_cast<Profesor*>(*it);
	    if (profesor != nullptr && user == profesor->Get_Nick()) {
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
            // Crea un DTProfesor con solo el nickname y agrega a la lista
            DTProfesor* dtProfesor = new DTProfesor(usuario->Get_Nick());
            userlist.push_back(dtProfesor);
        }
        // Verifica si el usuario es un estudiante
        else if (Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario)) {
            // Crea un DTEstudiante con solo el nickname y agrega a la lista
            DTEstudiante* dtEstudiante = new DTEstudiante(usuario->Get_Nick());
            userlist.push_back(dtEstudiante);
        }
        // Si el usuario no es ni profesor ni estudiante, crea un DTUsuario genérico con solo el nickname
        else {
            cout<<"Error inesperado";
        }
    }

    return userlist;
}


Usuario* Controlador::Buscar_Usuario(string nickname){


	for (auto it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); ++it) {
	        if ((*it)->Get_Nick() == nickname) {
	            return *it;
	        }
	    }
	    return nullptr; // Devuelve nullptr si no se encuentra el usuario

}

//fin alta user


//Comienzo alta curso
void Controlador::Crear_Curso(DTCurso* dtcurso){


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


bool Controlador::Verificar_Nombre_Curso(const std::string& nombre) {
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

void Controlador::Alta_Idioma(std::string el_idioma){


	this->sistema->idiomas.insert(new Idioma(el_idioma));
	
}
list<string> Controlador::Mostrar_Lecciones(string nombreCurso){
    Curso* curso = Buscar_Curso(nombreCurso);
    list<string> nombresLecciones;

    if (curso) {
        for (auto it = curso->getLecciones().begin(); it != curso->getLecciones().end(); ++it) {
            nombresLecciones.push_back((*it)->Get_Nombre());
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
        //leccion->Agregar_Ejercicio(ejercicio);
    } else if (DTTraducir* traducirDTO = dynamic_cast<DTTraducir*>(dtejercicio)) {
        Traducir* ejercicio = new Traducir(
            traducirDTO->Get_Nombre(),
            traducirDTO->Get_Descripcion(),
            traducirDTO->Get_Frase_Sin_Traducir(),
            traducirDTO->Get_Frase_Traducida()
        );
        //leccion->Agregar_Ejercicio(ejercicio);
    }
	
}





void Controlador::Carga_Datos(){
	Estudiante estudiante("pedro", "123", "nombre", "Le gusta el ingle", "Burkina", DTFecha(1, 1, 1940));
	this->sistema->usuarios.insert(new Estudiante(estudiante));

// Crear un profesor y agregarlo a usuarios
	Profesor profesor("prof", "contrasenia_prof", "nombre_prof", "descripcion_prof", "instituto_prof");
	this->sistema->usuarios.insert(new Profesor(profesor));

// Crear un curso y agregarlo a cursos
	Curso curso("Tenis", "Abajo del agua", Tipo_Dificultad::Facil, true);
	

	this->sistema->cursos.insert(new Curso(curso));

// Crear un idioma y agregarlo a idiomas
	Idioma idioma("Ingles");
	this->sistema->idiomas.insert(new Idioma(idioma));
}




