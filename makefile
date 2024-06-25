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
OBJS = main.o Curso.o Usuario.o Tipo_Dificultad.o Inscripcion.o Estudiante.o Profesor.o Idioma.o Leccion.o Ejercicio.o Ejercicio_Completar.o Ejercicio_Traducir.o Controlador.o DTUsuario.o DTProfesor.o DTEjercicio.o DTEjercicio_Traduccion.o DTEjercicio_Completar.o DTEstudiante.o DTFecha.o DTCurso.o System.o Alta_De_Curso.o Alta_Idioma.o Cargar_Datos.o Consultar_Estadisticas.o Consultar_Usuario.o Consultar_Idiomas.o Eliminar_Curso.o Agregar_Ejercicio.o Habilitar_Curso.o Alta_De_Usuario.o
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
	
Ejercicio_Completar.o: $(IMPLEMENT)Ejercicio_Completar.cpp $(HEADERS)Ejercicio_Completar.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Ejercicio_Completar.cpp
	
Ejercicio_Traducir.o: $(IMPLEMENT)Ejercicio_Traducir.cpp $(HEADERS)Ejercicio_Traducir.h
	$(CXX) $(CXXFLAGS) -c $(IMPLEMENT)Ejercicio_Traducir.cpp
	
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
	
DTEjercicio.o: $(DT)DTEjercicio.cpp $(DT)DTEjercicio.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTEjercicio.cpp

DTEjercicio_Completar.o: $(DT)DTEjercicio_Completar.cpp $(DT)DTEjercicio_Completar.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTEjercicio_Completar.cpp

DTEjercicio_Traduccion.o: $(DT)DTEjercicio_Traduccion.cpp $(DT)DTEjercicio_Traduccion.h
	$(CXX) $(CXXFLAGS) -c $(DT)DTEjercicio_Traduccion.cpp
	
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
	
Habilitar_Curso.o: $(PRESENT)Habilitar_Curso.cpp $(PRESENT)Habilitar_Curso.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Habilitar_Curso.cpp		

Agregar_Ejercicio.o: $(PRESENT)Agregar_Ejercicio.cpp $(PRESENT)Agregar_Ejercicio.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Agregar_Ejercicio.cpp	
	
Consultar_Usuario.o: $(PRESENT)Consultar_Usuario.cpp $(PRESENT)Consultar_Usuario.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Consultar_Usuario.cpp
	
	
Eliminar_Curso.o: $(PRESENT)Eliminar_Curso.cpp $(PRESENT)Eliminar_Curso.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Eliminar_Curso.cpp		
	
Cargar_Datos.o: $(PRESENT)Cargar_Datos.cpp $(PRESENT)Cargar_Datos.h
	$(CXX) $(CXXFLAGS) -c $(PRESENT)Cargar_Datos.cpp	
	
build: $(EXE)
	
clean:
	rm -f $(BINARIO) $(OBJS)
	
run: $(EXE)
	@clear
	@./$(EXE)	
