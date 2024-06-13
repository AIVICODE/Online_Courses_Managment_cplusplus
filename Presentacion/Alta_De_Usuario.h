#ifndef PRESENTACION_ALTAUSUARIO_H_
#define PRESENTACION_ALTAUSUARIO_H_
#include "../Negocio/Interfaces/IControlador.h"
//#include "../Negocio/DT/DTOProfesor.h"
//#include "../Negocio/DT/DTOEstudiante.h"


class AltaUsuario {
private:
	IControlador* controlador;

public:
	AltaUsuario();
	virtual ~AltaUsuario();
	void altaUsuario();
	//DTOEstudiante* ingresarEstudiante(string nick);
	//DTOProfesor* ingresarProfesor(string nick);
	//set<string> seleccionarIdiomas();
};

#endif /* PRESENTACION_ALTAUSUARIO_H_ */
