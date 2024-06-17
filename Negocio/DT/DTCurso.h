/*
 * DTCurso.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_DT_DTCURSO_H_
#define LABFINAL_DT_DTCURSO_H_
#include <string>
#include <vector>


using namespace std;
class DTCurso {
private:
    string nombre;
    string descripcion;
    int dificultad;

public:

    // Constructor
    DTCurso();
    DTCurso(string nombre, string descripcion,int dificultad);

    string getNombre() const;
    string getDescripcion() const;
    int getDificultad() const;
    // Destructor
    virtual ~DTCurso();
};

#endif /* LABFINAL_DT_DTCurso_H_ */
