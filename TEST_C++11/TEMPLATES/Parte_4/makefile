all: part4 

alumno.o: alumno.h alumno.cpp
	g++ -std=c++0x -c alumno.cpp  -Wall -O2

part4: test_tabla.cpp tabla_t.h alumno.o
	g++ -std=c++0x test_tabla.cpp tabla_t.h alumno.o -o part4 -O2 -Wall

limpiar:
	rm *.o
	rm part4	