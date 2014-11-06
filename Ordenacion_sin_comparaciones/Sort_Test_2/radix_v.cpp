/**
*
*    @file radix_v.cpp
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
#include <list>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;

const int N = 10000; /**< Tamaño de los Vectores*/
const int R = 1000;  /**< Numero de repeticiones*/

/**< Definicion de funciones */
void mostrarVector(vector <int> &vec);
void vec_Random(vector<int> &vec, int l_inf, int l_sup, mt19937 &generator );
void RadixSort(vector<int> &vec, int rango);
int digito(int value, int pos);
void concatenar(vector<int> &vec, vector <list <int>> &bucket);

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
    struct timespec t_1, t_2;
    double t_total =0;
    vector<int> vec_1(N), vec_copia(N);
    mt19937 generator;

    vec_Random(vec_1, 0, 65535, generator);
       
    for(int i = 0; i < R; i++) {

        vec_copia = vec_1;
        
        clock_gettime(CLOCK_REALTIME, &t_1);
        RadixSort(vec_copia, 65536);
        clock_gettime(CLOCK_REALTIME, &t_2);
        t_total += (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    }
    cout << t_total<< endl;
  //  mostrarVector(vec_copia);
    return 0;
}

/**
* @brief Funcion vec_Random, Rellena un vector pasado por referencia con numeros aleatorios
*
* @param vec  Vector de enteros vacio.
* @param l_inf  Cota inferior del rango en el cual se encuentran los enteros del vector datos.
* @param l_sup  Cota superior del rango en el cual se encuentran los enteros del vector datos.
* @param generator  Motor de numeros aleatorios.
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
* @param vec Vector de elementos a mostrar.
*/
void mostrarVector(vector <int> &vec)
{
    for(auto value : vec)
        cout<< value << " ";
    cout << endl;
}

/**
* @brief Funcion RadixSort, Implementa el algoritmo de ordenacion sin comparaciones
*
* @param vec  Vector de elementos desordenados a ordenar.
* @param rango  Cota superior del rango en el cual se encuentran los enteros del vector datos.
*/
void RadixSort(vector<int> &vec, int rango)
{
    vector <list <int>> bucket(10);
    int l10_rango = log10(rango) + 1; /**< +1 por que el log10de 255 por ejemplo seria 2 y como queremos q i empieze en 1 l10_rango seria 3  */
    int d = 0;

    for(int i = 1; i <= l10_rango; i++) {
      
        for(unsigned j = 0; j < bucket.size(); j+=5) {
            bucket[j].clear();
            bucket[j+1].clear();
            bucket[j+2].clear();
            bucket[j+3].clear();
            bucket[j+4].clear();
        }
            

        for(unsigned z = 0; z < vec.size(); z+=5) {  
            d = digito(vec[z],i) ;
            bucket[d].push_back(vec[z]);
            d = digito(vec[z+1],i) ;
            bucket[d].push_back(vec[z+1]);
            d = digito(vec[z+2],i) ;
            bucket[d].push_back(vec[z+2]);
            d = digito(vec[z+3],i) ;
            bucket[d].push_back(vec[z+3]);
            d = digito(vec[z+4],i) ;
            bucket[d].push_back(vec[z+4]);
        }
        
        vector <int> neo_v;
        for(auto &list : bucket)
            for(auto &element : list)
                neo_v.push_back(element);
        vec = move(neo_v);     
    }
}

/**
* @brief Funcion digito, Devuelve el valor del digito en la posición pos.
*
* @param value  Valor del cual se desea saber el digito.
* @param pos  Posición del digito.
* 
* @return value%10 Valor del digito en la posición pos.
*/
int digito(int value, int pos)
{
        while (--pos )
        value /= 10;
    return value % 10;
}

/**
* @brief Funcion concatenar, Concatena el bucket y se lo asign al vector.
*
* @param vec  vector pasado por referencia al cual asignar el bucket concatenado.
* @param bucket  Vector de listas que contiene los resultados de cada una de las iteraciones del RadixSort.
*/
void concatenar(vector<int> &vec, vector <list <int>> &bucket)
{
    vector <int> neo_v;
    for(auto &list : bucket)
        for(auto &element : list)
            neo_v.push_back(element);
    vec = move(neo_v);
}