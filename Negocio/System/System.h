#ifndef LABFINAL_SYSTEM_SYSTEM_H_
#define LABFINAL_SYSTEM_SYSTEM_H_





using namespace std;


class System {
	private:
	       static System *instance;
	       System();
	       //static IControlador *controlador;
	    public:
	        static System *Get_Instancia();
	        ~System();
	        //void Alta_De_Usuario();
	};
#endif /* LABFINAL_SYSTEM_ICONTROLADOR_H_ */
