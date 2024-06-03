#include "System.h"


System *System::instance = NULL;


System::System() {

}


System *System::Get_Instancia() {
    if (instance == NULL) {
        instance = new System();
    }
    return instance;
}
