CXX = g++
CXXFLAGS = -std=c++11 -Wall
HEADERS= Negocio/headers/
GENERAL= General/
IMPLEMENT= Negocio/Clases/
CONTROLADOR= Negocio/Controlador/
INTERFACE= Negocio/Interfaces/
EXE = programa
DT= Negocio/DT/
SYS= Negocio/System/
PRESENT= Presentacion/
OBJS = main.o Curso.o Usuario.o Tipo_Dificultad.o Inscripcion.o Estudiante.o Profesor.o Idioma.o Leccion.o Ejercicio.o Controlador.o DTUsuario.o DTProfesor.o DTEstudiante.o DTFecha.o DTCurso.o System.o Alta_De_Curso.o Alta_Idioma.o Consultar_Estadisticas.o Consultar_Idiomas.o Alta_De_Usuario.o
BINARIO = programa
INPUT = input.txt

all: programa

programa: $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(BINARIO) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
#Includes y menus
	
	  
Curso.o: $(IMPLEMENT)Curso.cpp $(HEADERS)Curso.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Curso.cpp
	
Usuario.o: $(IMPLEMENT)Usuario.cpp $(HEADERS)Usuario.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Usuario.cpp
	
Estudiante.o: $(IMPLEMENT)Estudiante.cpp $(HEADERS)Estudiante.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Estudiante.cpp

Idioma.o: $(IMPLEMENT)Idioma.cpp $(HEADERS)Idioma.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Idioma.cpp
	
Profesor.o: $(IMPLEMENT)Profesor.cpp $(HEADERS)Profesor.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Profesor.cpp

Leccion.o: $(IMPLEMENT)Leccion.cpp $(HEADERS)Leccion.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Leccion.cpp
	
Ejercicio.o: $(IMPLEMENT)Ejercicio.cpp $(HEADERS)Ejercicio.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Ejercicio.cpp
	
Inscripcion.o: $(IMPLEMENT)Inscripcion.cpp $(HEADERS)Inscripcion.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Inscripcion.cpp
	
Tipo_Dificultad.o: $(IMPLEMENT)Tipo_Dificultad.cpp $(HEADERS)Tipo_Dificultad.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Tipo_Dificultad.cpp
	
	
#CONTROLADORES
Controlador.o: $(CONTROLADOR)Controlador.cpp $(CONTROLADOR)Controlador.h
	$(CXX) $(CXXFLAGS) -c $(CONTROLADOR)Controlador.cpp
	
IControlador.o: $(INTERFACE)IControlador.h

#DATATYPES
DTUsuario.o: $(DT)DTUsuario.cpp $(DT)DTUsuario.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTUsuario.cpp
	
DTProfesor.o: $(DT)DTProfesor.cpp $(DT)DTProfesor.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTProfesor.cpp
	
DTEstudiante.o: $(DT)DTEstudiante.cpp $(DT)DTEstudiante.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTEstudiante.cpp
	
DTFecha.o: $(DT)DTFecha.cpp $(DT)DTFecha.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTFecha.cpp
	
DTCurso.o: $(DT)DTCurso.cpp $(DT)DTCurso.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTCurso.cpp
#SYSTEM
System.o: $(SYS)System.cpp $(SYS)System.h
	$(CXX) $(CXXFLAGS) -c $(SYS)System.cpp
	
#PRESENTACION
Alta_De_Usuario.o: $(PRESENT)Alta_De_Usuario.cpp $(PRESENT)Alta_De_Usuario.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Alta_De_Usuario.cpp

Alta_De_Curso.o: $(PRESENT)Alta_De_Curso.cpp $(PRESENT)Alta_De_Curso.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Alta_De_Curso.cpp
	
Consultar_Estadisticas.o: $(PRESENT)Consultar_Estadisticas.cpp $(PRESENT)Consultar_Estadisticas.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Consultar_Estadisticas.cpp
	
Alta_Idioma.o: $(PRESENT)Alta_Idioma.cpp $(PRESENT)Alta_Idioma.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Alta_Idioma.cpp	
	
Consultar_Idiomas.o: $(PRESENT)Consultar_Idiomas.cpp $(PRESENT)Consultar_Idiomas.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Consultar_Idiomas.cpp	
build: $(EXE)
	
clean:
	rm -f $(BINARIO) $(OBJS)
	
run: $(EXE)
	@clear
	@./$(EXE)	
