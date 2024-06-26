
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

void AltaUsuario::altaUsuario(){

DTUsuario* user=Ingresar_Usuario();
system("clear");

DTProfesor* profesor = dynamic_cast<DTProfesor*>(user);
if (profesor != nullptr) {
	
	if((profesor->getIdiomas()).empty()){
		cout<<"No ingreso ningun idioma para el usuario: finalizando"<<endl;
	}else{
	this->controlador->ingresarUsuario(user);
	}

	
}else{
	this->controlador->ingresarUsuario(user);
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


	list<string> nombresIdiomas;
    string nombreIdioma;
Listar_Idiomas(this->controlador->Listar_Idiomas());
    // Ingreso de idiomas
    cout << "Ingrese los nombres de los idiomas (escriba 'fin' para terminar):" << endl;
    while (true) {
        cout << "Idioma: ";
        cin >> nombreIdioma;
        if (nombreIdioma == "fin") {
            break;
        }
        if(controlador->Existe_Idioma(nombreIdioma)){
			    bool encontrado = false;

    // Verificar si el nombreIdioma ya está en la lista
    for (const string& idioma : nombresIdiomas) {
        if (idioma == nombreIdioma) {
            encontrado = true;
            break;
        }
    }
			
			if(encontrado==false){
        	nombresIdiomas.push_back(nombreIdioma);
        	}else{
				cout<<"El idioma " << nombreIdioma<< " Ya fue ingresado"<<endl;
			}
        }else
        {
			cout<<"No existe el idioma ingresado, intente nuevamente:"<<endl;
		}
    }


    DTProfesor* profesor = new DTProfesor(nickname, contrasenia, nombre, descripcion, instituto,nombresIdiomas);

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
/*void AltaUsuario::Agregar_Especializacion(Profesor& profesor) {
    list<string> nombresIdiomas;
    string nombreIdioma;

    // Ingreso de idiomas
    cout << "Ingrese los nombres de los idiomas (escriba 'fin' para terminar):" << endl;
    while (true) {
        cout << "Idioma: ";
        cin >> nombreIdioma;
        if (nombreIdioma == "fin") {
            break;
        }
        nombresIdiomas.push_back(nombreIdioma);
    }

    // Agregar los idiomas al profesor
    for (const string& nombre : nombresIdiomas) {
        Idioma* enlaceIdioma = Buscar_Idioma(nombre);
        if (enlaceIdioma == nullptr) {
            cout << "El idioma " << nombre << " no existe." << endl;

        }else{
        profesor.agregarIdioma(enlaceIdioma);
        }
    }
}*/



