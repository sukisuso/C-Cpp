all: part1 

tabla.o: tabla.h tabla.cpp
	g++ -std=c++0x -c tabla.cpp  -Wall -O2

alumno.o: alumno.h alumno.cpp
	g++ -std=c++0x -c alumno.cpp  -Wall -O2

part1: test_tabla.cpp tabla.o alumno.o
	g++ -std=c++0x test_tabla.cpp tabla.o alumno.o -o part1 -O2 -Wall

limpiar:
	rm *.o
	rm part1	