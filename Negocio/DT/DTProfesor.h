/*
 * DTProfesor.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_DT_DTProfesor_H_
#define LABFINAL_DT_DTProfesor_H_
#include <string>
#include <vector>

#include "DTUsuario.h"

using namespace std;
class DTProfesor : public DTUsuario{
private:
string instituto;

public:


    DTProfesor();
    DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);

    string getInstituto() const;

    DTProfesor(string nickname);

    // Destructor
    virtual ~DTProfesor();
};

#endif /* LABFINAL_DT_DTProfesor_H_ */
