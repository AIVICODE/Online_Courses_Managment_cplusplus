#include "Cargar_Datos.h"

// Constructor
Cargar_Datos::Cargar_Datos() {
    // Aquí podrías inicializar el controlador si es necesario
    this->controlador = new Controlador(); // Por ejemplo, inicializamos a nullptr por ahora
}

// Método para cargar datos
void Cargar_Datos::cargarDatos() {
	this->controlador->Carga_Datos();
}