/**
*
*    @file parte1-2.cpp
*    @Author Jesus Juan Aguilar
*    @date  14/11/2014.
*    @version 1.0
*    @brief: Practica 6 PROA. PARTE 1 y 2
*
*/

/* Icludes, namespace y constantes */
#include <iostream>
#include <vector>
#include <algorithm>
#include "lista.h"

using namespace std;

/* Definicion de funciones*/
template<typename T>
void mostrar(const T &begin, const T &end);

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
    vector<int> vec (6);
    Lista<int> lista;
    lista.push_front(8);
    lista.push_front(4);
    lista.push_front(2);
    lista.push_front(1);
    lista.push_front(2);
    lista.push_front(3);
  
  
    //Mostrar lista por pantalla pasandole begin y end de la lista.
    mostrar(lista.begin(), lista.end());

    //Copiar Lista a vector haciendo uso de la funcion copy();
    copy(lista.begin(), lista.end(), vec.begin());

    //Mostramos el vector!
    mostrar(vec.begin(), vec.end());
  
    return 0;
}

/**
* @brief mostrar, funcion que muestra cualquier contenedor a partir de sus iteradores begin y end.
*
* @param begin, Iterador que apunta al primer elemento del contenedor.
* @param end, Iterador que apunta al final del contenedor.
*/
template<typename T>
void mostrar(const T &begin, const T &end)
{
    for(T it = begin; it != end; ++it)
        cout << *it << " ";
    cout<< endl;
}