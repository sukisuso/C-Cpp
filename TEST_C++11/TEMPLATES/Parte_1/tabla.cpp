/**
 * Clase para Tabla
 * Curso 2014/2015
 *    @file tabla.cpp
 *    @Author Jesus Juan Aguilar
 *    @date  20/11/2014.
 *    @version 1.0
*/
#include <cstdlib>
#include "tabla.h"

using namespace std;

/**
 * Constructor Tabla.
 * Genera una tabla de tamaño tam.
 * @param tam tamaño de la tabla.
*/
Tabla::Tabla(unsigned tam)
{
    t.resize(tam);
}

/**
 * Funcion insertar un elemento en la Tabla.
 * Inserta un nuevo elemento en la tabla.
 * @param elem clave por la que insertar un nuevo elemento.
 * @param valor elemento a insertar.
*/
void Tabla::insertar(TipoClave elem, const TipoDato & valor)
{
    unsigned i;
    i = hash(elem);
    t[i].push_back(Celda{elem,valor} );
}

/**
 * Funcion buscar un elemento en la Tabla.
 * Busca un elemento de la tabla.
 * @param elem clave por la que buscar un elemento.
 * @param valor elemento que se devuelve.
 * @return bool true/false dependiendo si lo ha encontrado o no.
*/
bool Tabla::buscar(TipoClave elem, TipoDato & valor) 
{
    unsigned i;
    i = hash(elem);
    for(unsigned j=0; j < t[i].size(); j++)
    {
       if(t[i][j].clave == elem) 
       {
           valor = t[i][j].dato;
           return true;
       }
    }
    return false;
}

/**
 * Funcion hash de la Tabla.
 * Genera una clave hash para cada elemento de la tabla.
 * @param elem clave por la cual se genera la clave hash del elemento.
*/
unsigned Tabla::hash(TipoClave elem) const
{
    unsigned long h = 5381;
    
    // Solo valido para strings
    for(unsigned i = 0; i < elem.size(); i++)
        h = ((h << 5) + h) + elem[i];
        
    return h % t.size();
}

/**
 * Funcion mostrar la Tabla.
 * Muestra toda la tabla por pantalla.
 * @param sal operador con el cual mostrar la tabla.
*/
void Tabla::mostrar(ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        for(unsigned j = 0; j < t[i].size(); j++)
            sal << t[i][j].dato << " -> ";
        sal << endl;
    }
}
