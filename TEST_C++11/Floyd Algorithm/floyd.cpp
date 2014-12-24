/**
*
*    @file floyd.cpp
*    @Author Jesus Juan Aguilar.
*    @date  11/12/2014.
*    @version 1.0
*    @brief: Practica 8 PROA. PARTE 1
*
*/

/* Icludes, namespace y constantes */
#include <iostream>
#include <vector>
#include "grafo.h"
using namespace std;

const unsigned TAM = 6;
const float MIN = 0.5;
const float MAX = 5.0;

/* Declaración de funciones*/
vector<vector <float>> floyd (Grafo <float, TAM> &g);
void ShowMatrix(const vector<vector <float>> aux);

/***********************************************
*  MAIN
***********************************************/
int main()
{
    cout<< "-- Floyd --" <<endl;   
    Grafo<float, TAM> g;    // Declaramos el grafo.
    g.init(MIN, MAX);	// Inicializamos la matriz de adyacencia.
    cout << "Matriz del grafo" << endl;
    g.p_matriz();
    cout<< endl;   
    cout << "Resultado Floyd" << endl;
    ShowMatrix(floyd (g)); 	// Calculamos Floyd.

return 0;
} 
 
/**
* @brief Funcion que implementa el algoritmo de Floyd.
*
* @param g, grafo de caminos.
* @return vector<vector <float>>, matriz resultado del algoritmo de floyd. 
*/
vector<vector <float>> floyd (Grafo <float, TAM> &g)
{ 
    unsigned tam = g.size();
    vector<vector <float>> aux(TAM, vector<float>(TAM));

    for(unsigned i = 0; i < tam ; i++)
        for(unsigned j = 0; j < tam; j++)
            aux[i][j] = g(i,j);

    for(unsigned k = 0; k < tam; k++)
        for(unsigned i = 0; i < tam; i++)
            for(unsigned j = 0; j < tam; j++)
                if(aux[i][j] > (aux[i][k] + aux[k][j]) )
                    aux[i][j] = aux[i][k] + aux[k][j];
    return aux;
}

/**
* @brief Funcion que muestra una matriz de tamaño TAM
*
* @param aux, matriz a mostrar.
*/
void ShowMatrix(const vector<vector <float>> aux)
{
    for(unsigned i = 0; i < TAM ; i++){
        for(unsigned j = 0; j < TAM; j++)
            cout << aux[i][j] << "  __  ";
        cout << endl;
    }
}