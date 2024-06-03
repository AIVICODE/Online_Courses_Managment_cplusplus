#ifndef LABFINAL_SYSTEM_SYSTEM_H_
#define LABFINAL_SYSTEM_SYSTEM_H_



#include "../Interfaces/IControlador.h"
#include "../"
using namespace std;


class System {
	private:
	       static System *instance;
	       System();
	       static IControlador *controlador;
	    public:
	        static System *Get_Instancia();
	        ~System();
	};
#endif /* LABFINAL_SYSTEM_ICONTROLADOR_H_ */
