
#include <iostream>
#include <set>

#include "Alta_De_Usuario.h"
#include "../Negocio/DT/DTEstudiante.h"
#include "../Negocio/DT/DTProfesor.h"
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

	int opcion;
	    cout << "Ingrese 1 si es profesor o 2 si es estudiante: ";
	    cin >> opcion;

	    if (opcion == 1) {
	        // Ingreso de datos para DTProfesor
	        string nickname, contrasenia, nombre, descripcion, instituto;

	        while (true) {
	               cout << "Ingrese el nickname: ";
	               cin >> nickname;
	               if (this->controlador->Verificar_Nick(nickname)) {
	                   cout << "El nickname '" << nickname << "' ya está en uso." << endl;
	                   cout << "¿Desea intentar de nuevo? (s/n): ";
	                   char opcion;
	                   cin >> opcion;
	                   if (opcion == 'n' || opcion == 'N') {
	                       cout << "Operación cancelada." << endl;
	                       return; // cancelar
	                   }
	               } else {
	                   break; // Sale
	               }
	           }
	        cout << "Ingrese la contrasenia: ";
	        cin >> contrasenia;
	        cout << "Ingrese el nombre: ";
	        cin >> nombre;
	        cout << "Ingrese la descripcion: ";
	        cin >> descripcion;
	        cout << "Ingrese el instituto: ";
	        cin >> instituto;

	        // Creación del objeto DTProfesor
	        DTProfesor* profesor=new DTProfesor(nickname, contrasenia, nombre, descripcion, instituto);
	        cout << "Profesor creado con éxito!" << endl;
	        cout << "Instituto: " << profesor->getInstituto() << endl;
            this->controlador->ingresarUsuario(profesor);


	    } else if (opcion == 2) {
	        // Ingreso de datos para DTEstudiante
	        string nickname, contrasenia, nombre, descripcion, pais;
	        int dia, mes, anio;
	        while (true) {
	        					cin.clear();
	        	               cout << "Ingrese el nickname: ";
	        	               cin >> nickname;
	        	               cin.clear();
	        	               if (this->controlador->Verificar_Nick(nickname)) {
	        	                   cout << "El nickname '" << nickname << "' ya está en uso." << endl;
	        	                   cout << "¿Desea intentar de nuevo? (s/n): ";
	        	                   char opcion;
	        	                   cin >> opcion;
	        	                   if (opcion == 'n' || opcion == 'N') {
	        	                       cout << "Operación cancelada." << endl;
	        	                       return; // cancelar
	        	                   }
	        	               } else {
	        	                   break; // Sale
	        	               }
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

	            // Creación del objeto DTEstudiante
	            DTEstudiante* estudiante = new DTEstudiante(nickname, contrasenia, nombre, descripcion, pais, fecha);	            cout << "Estudiante creado con éxito!" << endl;
	            cout << "Pais: " << estudiante->getPais() << endl;
	            cout << "Fecha de nacimiento: ";
	            // Paso el DT a el controlador.
	            estudiante->getFecha().imprimirFecha();
	            this->controlador->ingresarUsuario(estudiante);

	        } catch (const invalid_argument& e) {
	            cerr << "Error: " << e.what() << endl;
	        }

	    } else {
	        cerr << "Opción inválida!" << endl;
	    }


}
