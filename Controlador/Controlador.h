/*
 * Controlador.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_CONTROLADOR_CONTROLADOR_H_
#define LABFINAL_CONTROLADOR_CONTROLADOR_H_

#include "../Interfaces/IControlador.h"

class Controlador : public IControlador{

private:
	static Controlador* instancia;
	Controlador();
public:
	static IControlador* Get_Instancia();


	virtual ~Controlador();
};

#endif /* LABFINAL_CONTROLADOR_CONTROLADOR_H_ */
