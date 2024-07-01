/*
 * main.cpp
 *
 *  Created on: May 23, 2024
 *      Author: ivan
 */



#include "Presentacion/Alta_De_Usuario.h"
#include "Presentacion/Alta_De_Curso.h"
#include "Presentacion/Consultar_Estadisticas.h"
#include "Presentacion/Alta_Idioma.h"
#include "Presentacion/Consultar_Idiomas.h"
#include "Presentacion/Cargar_Datos.h"
#include "Presentacion/Habilitar_Curso.h"
#include "Presentacion/Agregar_Ejercicio.h"
#include "Presentacion/Consultar_Usuario.h"
#include "Presentacion/Eliminar_Curso.h"
#include "Presentacion/Inscribirse_A_Curso.h"
#include "Presentacion/Agregar_Leccion.h"
#include "Presentacion/ConsultarCurso.h"
#include "Presentacion/Realizar_Ejercicio.h"

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
            {
                Consultar_Usuario consulta;
                consulta.Imprimir();
                }
                break;
            case 3:
                //Alta_De_Idioma();
                {
                Alta_Idioma alta_idioma;
                alta_idioma.Hacer();
                }
                break;
            case 4:
                //Consultar_Idiomas();
                {
                Consultar_Idiomas consultar_idiomas;
                consultar_idiomas.Hacer();
                esperaEnter();
                }
                break;
            case 5: {
                Alta_De_Curso altaCurso;
                altaCurso.AltaCurso();
            }
            break;
            case 6:
            {
                Agregar_Leccion agregarleccion;
                agregarleccion.AgregaLeccion();
                }
                break;
            case 7:
            {
                Agregar_Ejercicio agregare_ejercicio;
                agregare_ejercicio.Agregar_Ejercicio_Curso();
                }
                break;
            case 8:
            {
                Habilitar_Curso habcurso;
                habcurso.habilitarCurso();
                }
                break;
            case 9:
            {//terminado pobremente testeado
                Eliminar_Curso eliminarc;
                eliminarc.EliminarCurso();
                }
                break;
            case 10:
            {//terminado
                Consultar_Curso consultacurso;
                consultacurso.Hacer();
                }
                break;
            case 11:
            	{
                Inscribirse_A_Curso inscripcion;
                inscripcion.Inscribirse();
                }
                break;
            case 12:
            {
                Realizar_Ejercicio realizarejercicio;
                realizarejercicio.RealizarEjercicio();
                break;
                }
            case 13: {
				//no terminado
                Consultar_Estadisticas estadistica;
                estadistica.consultar_estadisticas();
                esperaEnter();
            }
            break;
            case 14:
            	{
                Cargar_Datos carga;
                carga.cargarDatos();
                }
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
