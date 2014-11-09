all: exe 

intstring.o: intstring.h intstring.cpp
	g++ -std=c++11 -c intstring.cpp  -Wall -O2

exe: main.cpp intstring.o
	g++ -std=c++11 main.cpp intstring.o -o exe -O2 -Wall

limpiar:
	rm *.o
	rm exe	