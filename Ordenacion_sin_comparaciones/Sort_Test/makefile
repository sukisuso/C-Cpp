todo: exe


sort_test.o: sort_test.cpp
	g++ -c -std=c++11 sort_test.cpp -Wall

exe: sort_test.o
	g++ -std=c++11 sort_test.o -o exe -Wall

limpiar:
	rm sort_test.o
	rm exe