


#include <iostream>

using namespace std;

void imprimirMenu();
bool esNumero(const string& str);
void esperaEnter();
void imprimirMenu() {
    cout << "Menu de opciones:" << endl;
    cout << "1. Alta de Usuario" << endl;
    cout << "2. Consulta de Usuario" << endl;
    cout << "3. Alta de Idioma" << endl;
    cout << "4. Consultar Idiomas" << endl;
    cout << "5. Alta de Curso" << endl;
    cout << "6. Agregar Lección" << endl;
    cout << "7. Agregar Ejercicio" << endl;
    cout << "8. Habilitar Curso" << endl;
    cout << "9. Eliminar Curso" << endl;
    cout << "10. Consultar Curso" << endl;
    cout << "11. Inscribirse a Curso" << endl;
    cout << "12. Realizar Ejercicio" << endl;
    cout << "13. Consultar Estadísticas" << endl;
    cout << "14. Cargar Datos de Prueba" << endl;
    cout << "0. Salir" << endl;
}

bool esNumero(const string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

void esperaEnter() {
    std::cout << "Presione una enter para continuar...";
    std::string nosirve;
    std::getline(std::cin, nosirve);
}
