/*
 * main.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */



#include "System/System.h"

#include <iostream>
using namespace std;
int main() {
	bool quiereContinuar = true;

	    // Inicializar sistema
	    System *sistema = System::Get_Instancia();

	    do {
	        //imprimirMenu();

	        int num;
	            cout << "Ingrese una opción: ";
	            cin >> num;

	        switch (num) {
	            case 1:
	                sistema->Alta_De_Usuario();
	                break;
	            case 2:
	                //sistema->Consulta_De_Usuario();
	                break;
	            case 3:
	                //sistema->Alta_De_Idioma();
	                break;
	            case 4:
	                //sistema->Consultar_Idiomas();
	                break;
	            case 5:
	                //sistema->altaDeCurso();
	                break;
	            case 6:
	                //sistema ->agregarLeccion();
	                break;
	            case 7:
	                //sistema->agregarEjercicio();
	                break;
	            case 8:
	                //sistema->habilitarCurso();
	                break;
	            case 9:
	                //sistema->eliminarCurso();
	                break;
	            case 10:
	                //sistema->consultarCurso();
	                break;
	            case 11:
	                //sistema->inscribirseACurso();
	                break;
	            case 12:
	                //sistema->realizarEjercicio();
	                break;
	            case 13:
	                //sistema ->consultarEstadisticas();
	                break;
	            case 14:
	                //sistema ->cargarDatosdePrueba();
	                break;
	            case 0:
	                quiereContinuar = false;
	                break;
	        }


	    } while (quiereContinuar);

	    delete sistema;
	return 0;
}

