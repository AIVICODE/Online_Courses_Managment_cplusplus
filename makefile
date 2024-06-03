CXX = g++
CXXFLAGS = -std=c++11 -Wall
HEADERS= headers/
IMPLEMENT= implement/
CONTROLADOR= Controlador/
INTERFACE= Interfaces/
EXE = programa
DT= DT/
OBJS = main.o Curso.o Usuario.o Estudiante.o Profesor.o Lecciones.o Ejercicio.o Controlador.o DTUsuario.o 
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
	
	
#CONTROLADORES
Controlador.o: $(CONTROLADOR)Controlador.cpp $(CONTROLADOR)Controlador.h
	$(CXX) $(CXXFLAGS) -c $(CONTROLADOR)Controlador.cpp
	
IControlador.o: $(INTERFACE)IControlador.h

#DATATYPES
DTUsuario.o: $(DT)DTUsuario.cpp $(DT)DTUsuario.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTUsuario.cpp

build: $(EXE)
	
clean:
	rm -f $(BINARIO) $(OBJS)
	
run: $(EXE)
	@clear
	@./$(EXE)	
