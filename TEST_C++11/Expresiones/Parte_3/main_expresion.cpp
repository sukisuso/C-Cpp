/**
*
*    @file main_expresion.cpp
*    @Author Jesus Juan Aguilar
*    @date  1/12/2014.
*    @version 1.0
*    @brief: Practica 7 PROA. PARTE 1
*
*/

/* Icludes, namespace y constantes */
#include <iostream>
#include "expresion.h"
#include "sarray2.h"
using namespace std;

const unsigned TAM = 1000000;
const unsigned REP = 100;


/***********************************************
*  MAIN
***********************************************/
int main()
{
    SArray2 <double> x_S(TAM), y_S(TAM);
    Array<double> x(TAM), y(TAM);
    struct timespec t_1, t_2;
    double t_total =0 ;

  
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(unsigned i = 0; i < REP; i++){
	for(unsigned i = 0; i < TAM; i++)
	{
            x[i] = 2;
            y[i] = 3;
	}
        x = (1.2+x) * y + ((2.0*y)^2.0);
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << "Tiempo Array: " << t_total<<endl;
    
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(unsigned i = 0; i < REP; i++){
	for(unsigned i = 0; i < TAM; i++)
	{
            x_S[i] = 2;
            y_S[i] = 3;
	}
        x_S = (1.2+x_S) * y_S + ((2.0*y_S)^2.0);
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << "Tiempo SArray2: " << t_total<<endl;
    
return 0;
} 
