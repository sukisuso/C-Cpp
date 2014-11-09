/** 
*   @file previo.cpp
*	@Author Jesus Juan Aguilar.
*	@date  14/10/2014. 
*   @version 1.0
*
*	+ Descripcion: Previo practica 1 PROA--> Funcion CountSort.
*  	+ Compilar: g++ -std=c++0x previo.cpp -o exe
*	+ Ejecutar: ./exe
*
*/

/**< Icludes y namespace */
#include <iostream>
#include <vector>
using namespace std;

/**< Definicion de funciones */
vector<int> CountSort(vector <int> datos, int rango);

/***********************************************
 *  MAIN
 ***********************************************/
int main (int argc, char *argv[])
{
    vector<int> mi_vector;      /**< Inicializacion del vector de prueba desordenado */
    mi_vector.push_back(4);     /**< Añadimos valores al vector */
    mi_vector.push_back(2);
    mi_vector.push_back(5);
    mi_vector.push_back(4);
    mi_vector.push_back(9);
    mi_vector.push_back(5);
    mi_vector.push_back(5);
    mi_vector.push_back(4);
    mi_vector.push_back(9);
    mi_vector.push_back(5);
    mi_vector.push_back(5);
    mi_vector.push_back(3);
    mi_vector.push_back(1);
    mi_vector.push_back(3);
    mi_vector.push_back(7);


   vector<int> res = CountSort(mi_vector, 10);   /**< Ejecutamos el algoritmo de ordenacion CountSort */
   for(auto y : res){                            /**< Mostramos el resultado de la operacion tras ordenarlo */
            cout<< y << endl;
    }

  return 0;
}

/** 
 * Funcion CountSort, implementa el algoritmo del mismo nombre que ordena
 * un vector de enteros sin realizar comparaciones.
 *
 * @param datos :> Vector de enteros desordenado.
 * @param rango :> Cota superior del rango en el cual se encuentran los enteros del vector datos.
 */
vector<int> CountSort(vector <int> datos, int rango){
        
        vector <int> aux (rango,0);
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

    return res;
}