/*
 * main.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */



#include "Presentacion/Alta_De_Usuario.h"
#include "Presentacion/Alta_De_Curso.h"
#include "Presentacion/Consultar_Estadisticas.h"

#include <iostream>
#include "General/Includes.cpp"

using namespace std;



int main() {
    bool quiereContinuar = true;

    // Inicializar sistema

    do {
        imprimirMenu();

        string entrada;
        int num;

        while (true) {
            cout << "Ingrese una opción: ";
            cin >> entrada;

            // Verificar si la entrada es un número válido
            if (esNumero(entrada)) {
                num = stoi(entrada);
                break;
            } else {
                cout << "Entrada inválida. Por favor, ingrese un número." << endl;
            }
        }

        switch (num) {
            case 1: {
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
            case 5: {
                Alta_De_Curso altaCurso;
                altaCurso.AltaCurso();
            }
            break;
            case 6:
                //sistema->agregarLeccion();
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
            case 13: {
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
            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
                break;
        }


    } while (quiereContinuar);

    return 0;
}
