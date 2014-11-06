/**
*
*    @file sort_v.cpp
*    @Author Jesus Juan Aguilar y Humberto Huapaya Leon.
*    @date  21/10/2014.
*    @version 1.0
*    @brief: Practica 2 PROA.
*
*/

/**< Icludes, namespace y constantes*/
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <ratio>
#include <chrono>
#include <algorithm>

using namespace std;

const int N = 10000; /**< Tamaño de los Vectores*/
const int R = 1000;  /**< Numero de repeticiones*/

/**< Definicion de funciones */
void mostrarVector(vector <int> &vec);
void CountSort(vector <int> &datos, int rango);
void vec_Random(vector<int> &vec, int l_inf, int l_sup, mt19937 &generator );

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
    struct timespec t_1, t_2;
    double t_total =0;
    vector<int> vec_1(N), vec_copia(N);
   mt19937 generator;
    vec_Random(vec_1, 0, 255, generator);
       
    for(int i = 0; i < R; i++) {

        vec_copia = vec_1;
        
        clock_gettime(CLOCK_REALTIME, &t_1);
        sort(vec_copia.begin(), vec_copia.end());
        clock_gettime(CLOCK_REALTIME, &t_2);
        t_total += (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    }
    cout << t_total<< endl;
   // mostrarVector(vec_1);
    return 0;
}

/**
* @brief Funcion vec_Random, Rellena un vector pasado por referencia con numeros aleatorios
*
* @param vec  Vector de enteros vacio.
* @param l_inf  Cota inferior del rango en el cual se encuentran los enteros del vector datos.
* @param l_sup Cota superior del rango en el cual se encuentran los enteros del vector datos.
* @param generator Motor de numeros aleatorios.
*/
void vec_Random(vector<int> &vec, int l_inf, int l_sup, mt19937 &generator )
{
    uniform_int_distribution<int> dist(l_inf, l_sup);
    for(unsigned i = 0; i < vec.size(); i++)
        vec.at(i) = dist(generator);
}



/**
* @brief Funcion mostrarVector, simplemente muestra por pantalla el vector que se le pasa como parametro de entrada.
*
* @param vec  Vector de elementos a mostrar.
*/
void mostrarVector(vector <int> &vec)
{
    for(auto value : vec)
        cout<< value << " ";
    cout << endl;
}

