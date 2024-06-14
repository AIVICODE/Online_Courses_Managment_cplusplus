/*
 * IControlador.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_INTERFACES_ICONTROLADOR_H_
#define LABFINAL_INTERFACES_ICONTROLADOR_H_
#include "../DT/DTUsuario.h"
#include <string>

class IControlador {
public:

	virtual void ingresarUsuario(DTUsuario* user) = 0;

	virtual bool Verificar_Nick(string nick)=0;

	virtual ~IControlador()=default;
};

#endif /* LABFINAL_INTERFACES_ICONTROLADOR_H_ */
