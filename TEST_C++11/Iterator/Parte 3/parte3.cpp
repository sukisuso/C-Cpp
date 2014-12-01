/**
*
*    @file parte1-2.cpp
*    @Author Jesus Juan Aguilar
*    @date  14/11/2014.
*    @version 1.0
*    @brief: Practica 6 PROA. PARTE 3
*
*/

/* Icludes, namespace y constantes */
#include <iostream>
#include <vector>
#include <algorithm>
#include "tabla_t.h"

using namespace std;

/* Definicion de funciones*/
template<typename T>
void mostrar(const T &begin, const T &end);

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
    vector<Tabla<string, int>::Celda> vec (10);
    Tabla<string, int> tabla_1(20);
    tabla_1.insertar("Prueba", 25);
    tabla_1.insertar("Bonico", 21);
    tabla_1.insertar("Unico", 22);
    tabla_1.insertar("Otro", 23);
    tabla_1.insertar("Prueba", 23);
    tabla_1.insertar("Prueba", 38);
    tabla_1.insertar("Bonico", 66);
    tabla_1.insertar("Unico", 81);
    tabla_1.insertar("Otro", 29);
    tabla_1.insertar("Prueba", 79);
  


    //Mostrar lista por pantalla pasandole begin y end de la lista.
    mostrar(tabla_1.begin(), tabla_1.end());

    cout<<"---------"<<endl;
    //Copiar Lista a vector haciendo uso de la funcion copy();
    copy(tabla_1.begin(), tabla_1.end(), vec.begin());

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
    for(T it = begin; it != end; ++it){
        cout << (*it).clave << " - " << (*it).dato<<endl;
    }
}