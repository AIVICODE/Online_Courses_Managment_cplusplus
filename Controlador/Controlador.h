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

class Controlador : public IControlador{

private:
	static Controlador* instancia;
	Controlador();
public:
	static IControlador* Get_Instancia();

	void ingresarUsuario(DTUsuario* user);


	virtual ~Controlador();
};

#endif /* LABFINAL_CONTROLADOR_CONTROLADOR_H_ */
