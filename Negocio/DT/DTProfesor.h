/*
 * DTProfesor.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_DT_DTProfesor_H_
#define LABFINAL_DT_DTProfesor_H_
#include <string>
#include <list>

#include "DTUsuario.h"

using namespace std;
class DTProfesor : public DTUsuario{
	private:
		string instituto;
		list<string> idiomas;

public:


    DTProfesor();
    DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto,list<string> idiomas);
    
    DTProfesor(string nickname, string nombre, string descripcion, string instituto,list<string> idiomas);

    string getInstituto() const;

    DTProfesor(string nickname);

    // Destructor
    virtual ~DTProfesor();
    
        list<string> getIdiomas() const; // Getter para idiomas

    void setIdiomas(const list<string>& idiomas); // Setter para idiomas
};

#endif /* LABFINAL_DT_DTProfesor_H_ */
