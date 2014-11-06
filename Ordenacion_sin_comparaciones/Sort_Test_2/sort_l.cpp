/**
*
*    @file sort_l.cpp
*    @Author Jesus Juan Aguilar y Humberto Huapaya Leon.
*    @date  27/10/2014.
*    @version 1.0
*    @brief: Practica 1 PROA.
*    
*    + Compilar: make
*    + Ejecutar: ./exe
*
*/

/**< Icludes, namespace y constantes*/
#include <iostream>
#include <vector>
#include <list> 
#include <random>
#include <math.h> 
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;

const int N = 10000; /**< Tamaño de los Vectores*/
const int R = 1000; 

/**< Definicion de funciones */
void mostrarLista(list <int> &lista);
void list_Random(list<int> &lista, int l_inf, int l_sup,  mt19937 &generator);


/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
   struct timespec t_1, t_2;
    double t_total =0;
    list <int> list_1, list_2;
    mt19937 generator; 

    list_Random(list_2, 0, 255, generator);
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(int i = 0; i < R; i++) {

        list_1 = list_2;
        list_2.sort();
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << t_total<< endl;
    return 0;
}


/**
* @brief Funcion list_Random, Rellena una lista pasada por referencia con numeros aleatorios
*
* @param lista  Lista de enteros vacia.
* @param l_inf  Cota inferior del rango en el cual se encuentran los enteros del vector datos.
* @param l_sup  Cota superior del rango en el cual se encuentran los enteros del vector datos.
* @param generator  Motor de numeros aleatorios.
*/
void list_Random(list<int> &lista, int l_inf, int l_sup,  mt19937 &generator)
{
    uniform_int_distribution<int> dist(l_inf, l_sup);
    for(unsigned i = 0; i < N; i++)
        lista.push_front(dist(generator));
}

/**
* @brief Funcion mostrarLista, Muestra la lista pasada por referencia.
*
* @param lista :> Lista de enteros.
*/
void mostrarLista(list <int> &lista)
{

    for(auto value : lista)
        cout<< value << " ";
    cout << endl;
}