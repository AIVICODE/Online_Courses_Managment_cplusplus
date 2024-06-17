#ifndef LABFINAL_SYSTEM_SYSTEM_H_
#define LABFINAL_SYSTEM_SYSTEM_H_




#include "../headers/Curso.h"
#include "../headers/Usuario.h"
#include "../headers/Profesor.h"
#include "../headers/Estudiante.h"
#include "../headers/Idioma.h"

#include <iostream>
#include <set>

using namespace std;


class System {
	private:
	       static System *instance;
	       System();


	       //static IControlador *controlador;
	    public:
	        static System *Get_Instancia();
	        ~System();

	        set<Usuario*> usuarios;
	        set<Idioma*> idiomas;

	        void mostrarProfesores() const {
	                for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
	                    Profesor* profesor = dynamic_cast<Profesor*>(*it);
	                    if (profesor != nullptr) {
	                    	cout<< profesor->Get_Nick();
	                    }
	                }
	            }
	        //void Alta_De_Usuario();
	};
#endif /* LABFINAL_SYSTEM_ICONTROLADOR_H_ */
