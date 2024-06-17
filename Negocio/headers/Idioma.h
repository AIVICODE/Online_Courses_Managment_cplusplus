#ifndef IDIOMA_H
#define IDIOMA_H

#include <string>
#include <set>
using namespace std;
class Idioma {
private:
    string nombre;

public:
    // Constructor
    Idioma(const string& nombre);
    string Get_Nombre()const;

};
#endif
