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
const unsigned NODO = 0;
const float MIN = 0.5;
const float MAX = 5.0;

/* Declaración de funciones*/
vector<vector <float>> floyd (Grafo <float, TAM> &g, vector<vector <unsigned>> &caminos);
template <typename T>
void ShowMatrix(const vector<vector <T>> &aux);
void ShowCamino(unsigned origen, unsigned destino, vector<vector <unsigned>> &caminos);

/***********************************************
*  MAIN
***********************************************/
int main()
{
    cout<< "-- Floyd 2 --" <<endl;        
    vector<vector <unsigned>> caminos (TAM, vector<unsigned>(TAM));

    Grafo<float, TAM> g;    // Declaramos el grafo.
    g.init(MIN, MAX);	// Inicializamos la matriz de adyacencia.
    floyd (g, caminos); 	// Calculamos Floyd.

    //ShowMatrix(caminos);
    for(unsigned i = 0; i < TAM; i++)
        ShowCamino(NODO, i, caminos);
    
return 0;
} 
 
/**
* @brief Funcion que implementa el algoritmo de floyd devolviendo ademas los caminos.
*
* @param g, grafo con los caminos
* @param caminos, estructura para almacenar caminos.
* @return vector<vector <float>>, matriz resultado del algoritmo de floyd. 
*/
vector<vector <float>> floyd (Grafo <float, TAM> &g, vector<vector <unsigned>> &caminos)
{
    unsigned tam = g.size();
    vector<vector <float>> aux(TAM, vector<float>(TAM));

    for(unsigned i = 0; i < tam ; i++)
        for(unsigned j = 0; j < tam; j++){
            aux[i][j] = g(i,j);
            caminos[i][j] = i;
        }

    for(unsigned k = 0; k < tam; k++)
        for(unsigned i = 0; i < tam; i++)
            for(unsigned j = 0; j < tam; j++)
                if(aux[i][j] > (aux[i][k] + aux[k][j]) ){
                    aux[i][j] = aux[i][k] + aux[k][j];
                    caminos[i][j] = k;
                }
    return aux;
}

/**
* @brief Funcion que muestra una matriz de tamaño TAM
*
* @param aux, matriz a mostrar.
*/
template <typename T> 
void ShowMatrix(const vector<vector <T>> &aux)
{
    for(unsigned i = 0; i < TAM ; i++){
         for(unsigned j = 0; j < TAM; j++)
             cout << aux[i][j] << "  __  ";
         cout << endl;
    }
} 

/**
* @brief Funcion mostrar camino que muestra el camino de un nodo a otro .
*
* @param origen, Nodo origen.
* @param destino, Nodo destino.
* @param destino, Estructura con los caminos.
*/
void ShowCamino(unsigned origen, unsigned destino, vector<vector <unsigned>> &caminos)
{
    cout << "Como ir del nodo "<< origen << " a " << destino ;
    cout << "_:: " << origen << " ";
    while(origen != destino){
        cout << ">> " << caminos[destino][origen] << " ";
        origen = caminos[destino][origen];
    }
    cout << endl;
} 

