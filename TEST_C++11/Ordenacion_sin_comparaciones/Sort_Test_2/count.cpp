/**
*
*    @file count.cpp
*    @Author Jesus Juan Aguilar
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
    double t_total =0 ;
    vector<int> vec_1(N), vec_copia(N);
    mt19937 generator;
    vec_Random(vec_1, 0, 65535, generator);
       
    for(int i = 0; i < R; i++){

        vec_copia = vec_1;
        
        clock_gettime(CLOCK_REALTIME, &t_1);
        CountSort(vec_copia, 65536);
        clock_gettime(CLOCK_REALTIME, &t_2);
        t_total += (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    }
    cout << t_total<< endl;
    //mostrarVector(vec_copia);
    return 0;
}

/**
* @brief Funcion vec_Random, Rellena un vector pasado por referencia con numeros aleatorios
*
* @param vec  Vector de enteros vacio.
* @param l_inf Cota inferior del rango en el cual se encuentran los enteros del vector datos.
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
* @brief Funcion CountSort OPTIMIZADO, implementa el algoritmo del mismo nombre que ordena un vector de enteros sin realizar comparaciones.
*
* @param datos  Vector de enteros desordenado.
* @param rango  Cota superior del rango en el cual se encuentran los enteros del vector datos.
*/
void CountSort(vector <int> &datos, int rango)
{    // Ordena el vector que se le pasa  
    vector <int> aux (rango ,0);
    vector <int> res (datos.size(),0);

    for(int i = 0; i < N;i+=5){
    aux[datos[i]]++;
    aux[datos[i+1]]++;
    aux[datos[i+2]]++;
    aux[datos[i+3]]++;
    aux[datos[i+4]]++;
    }

    for(int i = 1; i < rango; i += 5 ){
    aux[i] = aux[i] + aux[i-1];
    aux[i+1] = aux[i+1] + aux[i];
    aux[i+2] = aux[i+2] + aux[i+1];
    aux[i+3] = aux[i+3] + aux[i+2];
    aux[i+4] = aux[i+4] + aux[i+3];
    }

    for(int j = N-1; j >= 0; j-=5){
    aux[datos[j]]--;
    res[aux[datos[j]]] = datos[j];

    aux[datos[j-1]]--;
    res[aux[datos[j-1]]] = datos[j-1];

    aux[datos[j-2]]--;
    res[aux[datos[j-2]]] = datos[j-2];

    aux[datos[j-3]]--;
    res[aux[datos[j-3]]] = datos[j-3];

    aux[datos[j-4]]--;
    res[aux[datos[j-4]]] = datos[j-4];
    }

    datos =move(res);
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

