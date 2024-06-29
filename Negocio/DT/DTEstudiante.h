/*
 * DTEstudiante.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_DT_DTEstudiante_H_
#define LABFINAL_DT_DTEstudiante_H_
#include <string>
#include <vector>
#include "DTUsuario.h"
#include "DTFecha.h"

using namespace std;
class DTEstudiante : public DTUsuario{
private:
string pais;
DTFecha fecha;

public:
    // Constructor
    DTEstudiante();
    DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha fecha);
    DTEstudiante(string nickname);
    // Destructor
    virtual ~DTEstudiante();
    string getPais() const;
    DTFecha getFecha() const;
    
    
};

#endif /* LABFINAL_DT_DTEstudiante_H_ */
