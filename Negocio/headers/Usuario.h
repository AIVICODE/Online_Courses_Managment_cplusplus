/*
 * Usuario.h
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */

#ifndef LABFINAL_USUARIO_H_
#define LABFINAL_USUARIO_H_

#include <string>
#include <vector>


using namespace std;

/* Class Abstracta*/
class Usuario {
    private:

        string nickname;
        string contrasenia;
        string nombre;
        string descripcion;

    public:
        Usuario();
        Usuario(string nickname, string contrasenia, string nombre, string descripcion);

        // Get_ters
        string Get_Nick();
        /* virtual string Get_Contrasenia();
        virtual string Get_Nombre();
        virtual string Get_Descripcion();

        //virtual DTUsuario* Get_DT() = 0;

        // Set_ters
        virtual void Set_Nickname(string nickname);
        virtual void Set_Contrasenia(string contrasenia);
        virtual void Set_Nombre(string nombre);
        virtual void Set_Descripcion(string descripcion);

        // Operaciones
        virtual bool esProfesor() = 0;
        virtual bool esEstudiante() = 0;
*/
        virtual ~Usuario();
    };

#endif /* LABFINAL_USUARIO_H_ */
