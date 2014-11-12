/**
*
*    @file sort_test.cpp
*    @Author Jesus Juan Aguilar
*    @date  18/10/2014.
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
using namespace std;

const int N = 20; /**< Tamaño de los Vectores*/

/**< Definicion de funciones */
void mostrarVector(vector <int> &vec);
void CountSort(vector <int> &datos, int rango);
void RadixSort(vector<int> &vec, int rango);
void RadixSort_list(list<int> &lista, int rango);
void vec_Random(vector<int> &vec, int l_inf, int l_sup, mt19937 generator );
int digito(int value, int pos);
void concatenar(vector<int> &vec, vector <list <int>> bucket);
void mostrarLista(list <int> &lista);
void list_Random(list<int> &lista, int l_inf, int l_sup,  mt19937 generator);
void concatenar(list<int> &lista, vector <list <int>> bucket);

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
    vector<int> vec_1(N), vec_2(N), vec_3(N), vec_4(N);
    list <int> list_1, list_2;
    mt19937 generator; 

    vec_Random(vec_1,0,255, generator);
    vec_Random(vec_2,0,65535, generator);
    vec_Random(vec_3,0,255, generator);
    vec_Random(vec_4,0,65535, generator);

    list_Random(list_1, 0, 255, generator);
    list_Random(list_2, 0, 65535, generator);

    /**< Ordenación por CountSort */
    cout << "Ordenación por CountSort"<<endl;	
    CountSort(vec_1, 256);
    mostrarVector(vec_1);
    CountSort(vec_2, 65536);
    mostrarVector(vec_2);

    /**< Ordenación por RadixSort */
    cout <<endl<< "Ordenación por RadixSort"<<endl;
    RadixSort(vec_3, 256);
    mostrarVector(vec_3);
    RadixSort(vec_4, 65536);
    mostrarVector(vec_2);

    /**< Ordenacion Listas por RadixSort */
    cout <<endl<< "Ordenacion Listas por RadixSort"<<endl;
    RadixSort_list(list_1, 256);
    mostrarLista(list_1);
    RadixSort_list(list_2, 65536);
    mostrarLista(list_2);

    return 0;
}

/**
* @brief Funcion vec_Random, Rellena un vector pasado por referencia con numeros aleatorios
*
* @param vec :> Vector de enteros vacio.
* @param l_inf :> Cota inferior del rango en el cual se encuentran los enteros del vector datos.
* @param l_sup :> Cota superior del rango en el cual se encuentran los enteros del vector datos.
* @param generator :> Motor de numeros aleatorios.
*/
void vec_Random(vector<int> &vec, int l_inf, int l_sup, mt19937 generator ){
    uniform_int_distribution<int> dist(l_inf, l_sup);
    for(unsigned i = 0; i < vec.size(); i++)
        vec.at(i) = dist(generator);
}

/**
* @brief Funcion CountSort, implementa el algoritmo del mismo nombre que ordena un vector de enteros sin realizar comparaciones.
*
* @param datos :> Vector de enteros desordenado.
* @param rango :> Cota superior del rango en el cual se encuentran los enteros del vector datos.
*/
void CountSort(vector <int> &datos, int rango){    // Ordena el vector que se le pasa  
    vector <int> aux (rango ,0);
    vector <int> res (datos.size(),0);

    for(auto x : datos){
	aux[x]++;
    }

    for(int i = 1; i < rango; i ++ ){
	aux[i] = aux[i] + aux[i-1];
    }

    for(int j = datos.size()-1; j >= 0; j--){
	aux[datos[j]]--;
	res[aux[datos[j]]] = datos[j];
    }

    datos = res;
}

/**
* @brief Funcion mostrarVector, simplemente muestra por pantalla el vector que se le pasa como parametro de entrada.
*
* @param vec :> Vector de elementos a mostrar.
*/
void mostrarVector(vector <int> &vec){
    for(auto value : vec)
        cout<< value << " ";
    cout << endl;
}

/**
* @brief Funcion RadixSort, Implementa el algoritmo de ordenacion sin comparaciones
*
* @param vec :> Vector de elementos desordenados a ordenar.
* @param rango :> Cota superior del rango en el cual se encuentran los enteros del vector datos.
*/
void RadixSort(vector<int> &vec, int rango){
    vector <list <int>> bucket(10);
    int l10_rango = log10(rango) + 1; /**< +1 por que el log10de 255 por ejemplo seria 2 y como queremos q i empieze en 1 l10_rango seria 3  */
    int d = 0;

    for(int i = 1; i <= l10_rango; i++){
        for(auto &lista : bucket)
            lista = {};
        for(auto element : vec){	
            d = digito(element,i) ;
            bucket[d].push_back(element);
        }
        concatenar(vec, bucket);      
    }
}

/**
* @brief Funcion digito, Devuelve el valor del digito en la posición pos.
*
* @param value :> Valor del cual se desea saber el digito.
* @param pos :> Posición del digito.
* 
* @return value%10 :> Valor del digito en la posición pos.
*/
int digito(int value, int pos){
    while (--pos )
        value /= 10;
    return value % 10;
}

/**
* @brief Funcion concatenar, Concatena el bucket y se lo asign al vector.
*
* @param vec :> vector pasado por referencia al cual asignar el bucket concatenado.
* @param bucket :> Vector de listas que contiene los resultados de cada una de las iteraciones del RadixSort.
*/
void concatenar(vector<int> &vec, vector <list <int>> bucket){
    vector <int> neo_v;
    for(auto &list : bucket)
        for(auto &element : list)
            neo_v.push_back(element);
    vec = neo_v;
}

/**
* @brief Funcion list_Random, Rellena una lista pasada por referencia con numeros aleatorios
*
* @param lista :> Lista de enteros vacia.
* @param l_inf :> Cota inferior del rango en el cual se encuentran los enteros del vector datos.
* @param l_sup :> Cota superior del rango en el cual se encuentran los enteros del vector datos.
* @param generator :> Motor de numeros aleatorios.
*/
void list_Random(list<int> &lista, int l_inf, int l_sup,  mt19937 generator){
    uniform_int_distribution<int> dist(l_inf, l_sup);
    for(unsigned i = 0; i < N; i++)
        lista.push_front(dist(generator));
}

/**
* @brief Funcion mostrarLista, Muestra la lista pasada por referencia.
*
* @param lista :> Lista de enteros.
*/
void mostrarLista(list <int> &lista){

    for(auto value : lista)
        cout<< value << " ";
    cout << endl;
}

/**
* @brief Funcion RadixSort_list, Algoritmo de comparacion RadixSort para listas.
*
* @param lista :> Lista de elementos desordenados a ordenar.
* @param rango :> Cota superior del rango en el cual se encuentran los enteros del vector datos.
*/
void RadixSort_list(list<int> &lista, int rango){
    vector <list <int>> bucket(10);
    int l10_rango = log10(rango) + 1; /**< +1 por que el log10de 255 por ejemplo seria 2 y como queremos q i empieze en 1 l10_rango seria 3  */
    int d = 0;

    for(int i = 1; i <= l10_rango; i++){
        for(auto &lista : bucket)	  
            lista = {};
        for(auto element : lista){	
            d = digito(element,i) ;
            bucket[d].push_back(element);
        }
        concatenar(lista, bucket);
    }
}

/**
* @brief Funcion concatenar, Concatena el bucket y se lo asigna a la lista.
*
* @param lista :> Lista pasada por referencia al cual asignar el bucket concatenado.
* @param bucket :> Vector de listas que contiene los resultados de cada una de las iteraciones del RadixSort.
*/
void concatenar(list<int> &lista, vector <list <int>> bucket){
    list <int> neo_l;
    for(auto &list : bucket)
        for(auto &element : list)
            neo_l.push_back(element);
    lista = neo_l;
}
