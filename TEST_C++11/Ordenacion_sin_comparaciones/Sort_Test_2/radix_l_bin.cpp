/**
*
*    @file radix_l.cpp
*    @Author Jesus Juan Aguilar
*    @date  21/10/2014.
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
void RadixSort_list(list<int> &lista, int rango);
int digito(int value, int pos);
void mostrarLista(list <int> &lista);
void list_Random(list<int> &lista, int l_inf, int l_sup,  mt19937 &generator);
void concatenar(list<int> &lista, vector <list <int>> &bucket);

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
   struct timespec t_1, t_2;
    double t_total =0;
    list <int> list_1, list_2;
    mt19937 generator; 

    list_Random(list_2, 0, 65535, generator);
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(int i = 0; i < R; i++) {

        list_1 = list_2;
        RadixSort_list(list_2, 65536); 
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
        t_total += (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
     cout << t_total<< endl;
    return 0;
}

/**
* @brief Funcion digito, Devuelve el valor del digito en la posición pos.
*
* @param value Valor del cual se desea saber el digito.
* @param pos Posición del digito.
* 
* @return value%10 :> Valor del digito en la posición pos.
*/
int digito(int value, int pos)
{
    
    return (value >> (pos*4))&15;
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
* @param lista Lista de enteros.
*/
void mostrarLista(list <int> &lista)
{

    for(auto value : lista)
        cout<< value << " ";
    cout << endl;
}

/**
* @brief Funcion RadixSort_list, Algoritmo de comparacion RadixSort para listas.
*
* @param lista  Lista de elementos desordenados a ordenar.
* @param rango  Cota superior del rango en el cual se encuentran los enteros del vector datos.
*/
void RadixSort_list(list<int> &lista, int rango)
{
    vector <list <int>> bucket(16);
    //int l10_rango = log10(rango) + 1; /**< +1 por que el log10de 255 por ejemplo seria 2 y como queremos q i empieze en 1 l10_rango seria 3  */
    int d = 0;

    for(int i = 0; i <5; i++){
        for(unsigned j = 0; j < bucket.size();j+=4) {	  
            bucket[j].clear();
            bucket[j+1].clear();
            bucket[j+2].clear();
            bucket[j+3].clear();
   
        }
        for(unsigned element : lista) {	
            d = digito(element,i) ;
            bucket[d].push_back(element);

        }
        //concatenar(lista, bucket);
        list <int> neo_l; 
        for(auto &list : bucket)
            for(auto &element : list)
                neo_l.push_back(element);
        lista = move(neo_l);
    }
}

/**
* @brief Funcion concatenar, Concatena el bucket y se lo asigna a la lista.
*
* @param lista  Lista pasada por referencia al cual asignar el bucket concatenado.
* @param bucket Vector de listas que contiene los resultados de cada una de las iteraciones del RadixSort.
*/
void concatenar(list<int> &lista, vector <list <int>> &bucket)
{
    list <int> neo_l; 
    for(auto &list : bucket)
        for(auto &element : list)
            neo_l.push_back(element);
    lista = move(neo_l);
}
