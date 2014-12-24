#ifndef _GRAFO_H
#define _GRAFO_H

#include <iostream>
#define N_DEBUG
#include <assert.h>
#include <random>

using namespace std;
 /*
* Class GRAFO
*/
template<typename T , unsigned TAM>
class Grafo { 

    private:
    	T matriz[TAM][TAM];

    public:
        /**
        * @brief Funcion que devuelve el tamaño del grafo.
        */
        unsigned size()
        {
            return TAM;
         }

         /**
        * @brief Funcion que devuelve el tamaño del grafo.
        */
        void p_matriz()
        {
            for(int i = 0; i < TAM; i++){
                for(int j = 0; j < TAM; j++)    	
                    cout << matriz[i][j] << "   _   ";
                    cout << endl;
                }
        }

        /**
        * @brief Funcion que devuelve por referencia un elemento de la matriz del grafo.
        *
        * @param i, indice i.
        * @param j, indice j.
        */
        T& operator() (unsigned i, unsigned j)
        {
            assert((i < size()) && (i >= 0) && (j < size()) && (j >= 0));
            return matriz[i][j];
        }

        /**
        * @brief Funcion que devuelve por valor un elemento de la matriz del grafo.
        *
        * @param i, indice i.
        * @param j, indice j.
        */
        T operator() (unsigned i, unsigned j) const
        {
            assert((i < size()) && (i >= 0) && (j < size()) && (j >= 0));
            return matriz[i][j];
        }

        /**
        * @brief Funcion que inicializa el grafo.
        *
        * @param min, minimo de valores sobre los que inicializar.
        * @param max, maximo de valores sobre los que inicializar.
        */
        void init(float min, float max)
        {
            T ram;
            mt19937 generator (TAM); 
            uniform_real_distribution<float> dist(min, max);

            for(unsigned i = 0; i < TAM; i++)
                for(unsigned j = 0; j <= i ; j++){
                    ram = (T) dist(generator);
                    matriz[i][j] = ram;
                    matriz[j][i] = ram;
                 }

             for(unsigned z = 0; z < TAM; z++)
                 matriz[z][z]= 0.0;
             }
};
 
 #endif