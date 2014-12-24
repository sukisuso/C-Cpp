all: floyd floyd2

floyd: floyd.cpp grafo.h
	g++ -std=c++0x floyd.cpp grafo.h -o floyd -O2 -Wall
	
floyd2: floyd2.cpp grafo.h
	g++ -std=c++0x floyd2.cpp grafo.h -o floyd_2 -O2 -Wall

limpiar:
	rm floyd