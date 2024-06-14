#ifndef LABFINAL_DT_DTFECHA_H_
#define LABFINAL_DT_DTFECHA_H_
#include <string>
#include <vector>


using namespace std;
class DTFecha {
private:
    int dia;
    int mes;
    int anio;
	bool esFechaValida(int d, int m, int a) const;
public:
	DTFecha();
	DTFecha(int d, int m, int a);

	int getDia() const;
	int getMes() const;
	int getAnio() const;

	void imprimirFecha() const;

};

#endif /* LABFINAL_DT_DTFECHA_H_ */
