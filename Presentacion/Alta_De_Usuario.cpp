
#include <iostream>
#include <set>
#include <list>

#include "Alta_De_Usuario.h"
#include "../Negocio/DT/DTEstudiante.h"
#include "../Negocio/DT/DTProfesor.h"
#include "../Negocio/DT/DTUsuario.h"
#include "../Negocio/Controlador/Controlador.h"

//#include "../negocio/dto/DTOEstudiante.h"
//#include "../negocio/dto/DTOProfesor.h"

using namespace std;



AltaUsuario::AltaUsuario() {
	//TODO pendiente de usar una fabrica
	this->controlador = new Controlador();
}

AltaUsuario::~AltaUsuario() {
	//El controlador solo dura lo que dura el caso de uso
	delete this->controlador;
}

void AltaUsuario::altaUsuario() {

DTUsuario* user=Ingresar_Usuario();
system("clear");

DTProfesor* profesor = dynamic_cast<DTProfesor*>(user);
if (profesor != nullptr) {
	Listar_Idiomas(this->controlador->Listar_Idiomas());

	Agregar_Especializacion(user->getNickname());
}

}

void AltaUsuario::Listar_Idiomas(const list<string>& listaIdiomas) {
    cout << "Idiomas disponibles:" << endl;
    for (const auto& idioma : listaIdiomas) {
        cout << idioma << endl;
    }


}



DTUsuario* AltaUsuario::Ingresar_Usuario() {
    int opcion;
    cout << "Ingrese 1 si es profesor o 2 si es estudiante: ";
    cin >> opcion;

    if (opcion == 1) {
        return Ingresar_Profesor();
    } else if (opcion == 2) {
        return Ingresar_Estudiante();
    } else {
        cerr << "Opción inválida!" << endl;
        return nullptr;
    }
}

DTUsuario* AltaUsuario::Ingresar_Profesor() {
    string nickname, contrasenia, nombre, descripcion, instituto;

    if (!IngresarNickname(nickname)) {
        cout << "Operación cancelada." << endl;
        return nullptr;
    }

    cout << "Ingrese la contrasenia: ";
    cin >> contrasenia;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese la descripcion: ";
    cin >> descripcion;
    cout << "Ingrese el instituto: ";
    cin >> instituto;

    DTProfesor* profesor = new DTProfesor(nickname, contrasenia, nombre, descripcion, instituto);

    this->controlador->ingresarUsuario(profesor);
    return profesor;
}

DTUsuario* AltaUsuario::Ingresar_Estudiante() {
	string nickname, contrasenia, nombre, descripcion, pais;
	int dia, mes, anio;

	if (!IngresarNickname(nickname)) {
		cout << "Operación cancelada." << endl;
		return nullptr;
	}

	cout << "Ingrese la contrasenia: ";
	cin >> contrasenia;
	cout << "Ingrese el nombre: ";
	cin >> nombre;
	cout << "Ingrese la descripcion: ";
	cin >> descripcion;
	cout << "Ingrese el pais: ";
	cin >> pais;
	cout << "Ingrese la fecha de nacimiento (dia mes anio): ";
	cin >> dia >> mes >> anio;

	try {
		DTFecha fecha(dia, mes, anio);
		DTEstudiante* estudiante = new DTEstudiante(nickname, contrasenia,
				nombre, descripcion, pais, fecha);

		this->controlador->ingresarUsuario(estudiante);
		return estudiante;
	} catch (const invalid_argument &e) {
		cerr << "Error: " << e.what() << endl;
		return nullptr;
	}
}

bool AltaUsuario::IngresarNickname(string &nickname) {
	while (true) {
		cout << "Ingrese el nickname: ";
		cin >> nickname;
		if (this->controlador->Verificar_Nick(nickname)) {
			cout << "El nickname '" << nickname << "' ya está en uso." << endl;
			cout << "¿Desea intentar de nuevo? (s/n): ";
			char opcion;
			cin >> opcion;
			if (opcion == 'n' || opcion == 'N') {
				return false; // cancelar
			}
		} else {
			return true; // Sale
		}
	}
}

void AltaUsuario::Agregar_Especializacion(string user) {
    string idioma;
    while (true) {
        cout << "Seleccione idioma (case sensitive):" << endl;
        cin >> idioma;

        // Verificar si el idioma existe
        if (this->controlador->Existe_Idioma(idioma)) {
            // Agregar la especialización y salir del bucle
            this->controlador->Agregar_Especializacion(idioma, user);

            break; // Salir del bucle
        } else {
            cout << "El idioma '" << idioma << "' no existe." << endl;
            cout << "¿Desea intentar de nuevo? (s/n): ";
            char opcion;
            cin >> opcion;
            if (opcion == 'n' || opcion == 'N') {
                break; // Salir del bucle y de la función
            }
        }
    }
}


