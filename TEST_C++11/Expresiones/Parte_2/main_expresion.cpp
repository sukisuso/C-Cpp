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


/***********************************************
*  MAIN
***********************************************/
int main()
{
    SArray2 <double> x(TAM), y(TAM);

    for(unsigned i = 0; i < TAM; i++)
    {
        x[i] = 2;
        y[i] = 3;
    }
    

    x = (1.2+x) * y + ((2.0*y)^2.0);


    for(unsigned i = 0; i < 5; i++)
    {
        cout << x[i] << endl;
    }
    cout << endl;
} 
