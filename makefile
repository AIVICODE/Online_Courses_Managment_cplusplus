CXX = g++
CXXFLAGS = -std=c++11 -Wall
HEADERS= headers/
IMPLEMENT= implement/
DT= DT/
OBJS = main.o Curso.o Usuario.o
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
	
clean:
	rm -f $(BINARIO) $(OBJS)
