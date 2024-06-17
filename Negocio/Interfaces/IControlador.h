/*
 * IControlador.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_INTERFACES_ICONTROLADOR_H_
#define LABFINAL_INTERFACES_ICONTROLADOR_H_
#include "../DT/DTUsuario.h"
#include "../headers/Idioma.h"
#include <string>
#include <list>

class IControlador {
public:

	virtual void ingresarUsuario(DTUsuario* user) = 0;

	virtual bool Verificar_Nick(string nick)=0;

	virtual list<string> Listar_Idiomas()=0;

	virtual Idioma* Existe_Idioma(const std::string& nombreIdioma)=0;

	virtual ~IControlador()=default;

	virtual void Agregar_Especializacion(string idioma,string user)=0;
};

#endif /* LABFINAL_INTERFACES_ICONTROLADOR_H_ */
