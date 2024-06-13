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

class Controlador : public IControlador{

private:
	System* sistema;

public:

	void ingresarUsuario(DTUsuario* user);

	Controlador();
	virtual ~Controlador();
};

#endif /* LABFINAL_CONTROLADOR_CONTROLADOR_H_ */
