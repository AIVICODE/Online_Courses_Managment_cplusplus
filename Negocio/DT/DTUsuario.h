/*
 * DTUsuario.h
 *
 *  Created on: May 27, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_DT_DTUSUARIO_H_
#define LABFINAL_DT_DTUSUARIO_H_
#include <string>
#include <vector>


using namespace std;
class DTUsuario {
private:
    string nickname;
    string contrasenia;
    string nombre;
    string descripcion;

public:

    // Constructor
    DTUsuario();
    DTUsuario(string nickname, string contrasenia, string nombre, string descripcion);
    DTUsuario(string nickname);

    // Getters
    string getNickname() const;
    string getContrasenia() const;
    string getNombre() const;
    string getDescripcion() const;

    // Destructor
    virtual ~DTUsuario();
};

#endif /* LABFINAL_DT_DTUSUARIO_H_ */
