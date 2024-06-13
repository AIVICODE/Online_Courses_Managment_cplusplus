#include "System.h"

#include "../DT/DTUsuario.h"
#include <iostream>
using namespace std;

System *System::instance = NULL;


System::System() {

}


System *System::Get_Instancia() {
    if (instance == NULL) {
        instance = new System();
    }
    return instance;
}

System::~System() {

}
