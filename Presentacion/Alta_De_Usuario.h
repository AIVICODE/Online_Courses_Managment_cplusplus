#ifndef PRESENTACION_ALTAUSUARIO_H_
#define PRESENTACION_ALTAUSUARIO_H_
#include "../Negocio/Interfaces/IControlador.h"
//#include "../Negocio/DT/DTOProfesor.h"
//#include "../Negocio/DT/DTOEstudiante.h"
#include <string>
#include <list>
class AltaUsuario {
private:
	IControlador* controlador;

public:
	AltaUsuario();
	virtual ~AltaUsuario();
	void altaUsuario();
	DTUsuario* Ingresar_Usuario();
		DTUsuario* Ingresar_Profesor();
		DTUsuario* Ingresar_Estudiante();
		bool IngresarNickname(string& nickname);
	void Listar_Idiomas(const list<string>& listaIdiomas);
	bool Agregar_Especializacion(string user);
	//DTOEstudiante* ingresarEstudiante(string nick);
	//DTOProfesor* ingresarProfesor(string nick);
	//set<string> seleccionarIdiomas();
};

#endif /* PRESENTACION_ALTAUSUARIO_H_ */
