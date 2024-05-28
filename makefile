CXX = g++
CXXFLAGS = -std=c++11 -Wall
HEADERS= headers/
IMPLEMENT= implement/
CONTROLADOR= Controlador/
INTERFACE= Interfaces/
DT= DT/
OBJS = main.o Curso.o Usuario.o Estudiante.o Profesor.o Lecciones.o Ejercicio.o Controlador.o
BINARIO = programa

all: programa

programa: $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(BINARIO) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
	
	  
Curso.o: $(IMPLEMENT)Curso.cpp $(HEADERS)Curso.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Curso.cpp
	
Usuario.o: $(IMPLEMENT)Usuario.cpp $(HEADERS)Usuario.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Usuario.cpp
	
Estudiante.o: $(IMPLEMENT)Estudiante.cpp $(HEADERS)Estudiante.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Estudiante.cpp
	
Profesor.o: $(IMPLEMENT)Profesor.cpp $(HEADERS)Profesor.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Profesor.cpp

Lecciones.o: $(IMPLEMENT)Lecciones.cpp $(HEADERS)Lecciones.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Lecciones.cpp
	
Ejercicio.o: $(IMPLEMENT)Ejercicio.cpp $(HEADERS)Ejercicio.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Ejercicio.cpp

Controlador.o: $(CONTROLADOR)Controlador.cpp $(CONTROLADOR)Controlador.h
	$(CXX) $(CXXFLAGS) -c $(CONTROLADOR)Controlador.cpp
	
IControlador.o: $(INTERFACE)IControlador.cpp $(INTERFACE)IControlador.h
	$(CXX) $(CXXFLAGS) -c $(INTERFACE)IControlador.cpp
	
clean:
	rm -f $(BINARIO) $(OBJS)
