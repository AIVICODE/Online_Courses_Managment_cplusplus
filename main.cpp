/*
 * main.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */



#include "Presentacion/Alta_De_Usuario.h"
#include "Presentacion/Consultar_Estadisticas.h"

#include <iostream>
#include "General/Includes.cpp"

using namespace std;



int main() {
	bool quiereContinuar = true;

	    // Inicializar sistema


	    do {
	       imprimirMenu();

	        int num;
	            cout << "Ingrese una opción: ";
	            cin >> num;

	        switch (num) {
	            case 1:
	            	{
	                AltaUsuario altaUsuario;
	                altaUsuario.altaUsuario();
	            	}
	                break;
	            case 2:
	                //Consulta_De_Usuario();
	                break;
	            case 3:
	                //Alta_De_Idioma();
	                break;
	            case 4:
	                //Consultar_Idiomas();
	                break;
	            case 5:
	                //altaDeCurso();
	                break;
	            case 6:
	                //sistema ->agregarLeccion();
	                break;
	            case 7:
	                //agregarEjercicio();
	                break;
	            case 8:
	                //habilitarCurso();
	                break;
	            case 9:
	                //eliminarCurso();
	                break;
	            case 10:
	                //consultarCurso();
	                break;
	            case 11:
	                //inscribirseACurso();
	                break;
	            case 12:
	                //realizarEjercicio();
	                break;
	            case 13:
	            	{
	            	Consultar_Estadisticas estadistica;
	            	estadistica.consultar_estadisticas();
	            	}
	                break;

	            case 14:
	                //cargarDatosdePrueba();
	                break;
	            case 0:
	                quiereContinuar = false;
	                break;
	        }


	    } while (quiereContinuar);

	return 0;
}

