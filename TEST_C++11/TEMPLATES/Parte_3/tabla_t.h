/**
 * Clase para Tabla Template y contenedor Template
 * Curso 2014/2015
 *    @file tabla.h
 *    @Author Jesus Juan Aguilar 
 *    @date  20/11/2014.
 *    @version 1.0
*/
#ifndef _TABLA_H
#define _TABLA_H

#include <string>
#include <vector>
#include <iostream>
#include "alumno.h"

using namespace std;

/*Compatible contenedor con: Vector, Lista y Deque*/
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT = std::vector>
class Tabla
{
public:
    struct Celda {
        T1 clave;
        T2 dato;
    };
        
    Tabla(unsigned); 
    bool buscar(T1, T2&) ; 
    void insertar(T1, const T2&); 
    unsigned hash(T1) const;
    void mostrar(ostream & sal) const;

private:
    typedef CONT<Celda> ListaDatos; 
    vector<ListaDatos> t;
};

/**
 * Constructor Tabla.
 * Genera una tabla de tamaño tam.
 * @param tam tamaño de la tabla.
*/
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT>
Tabla<T1,T2,CONT>::Tabla(unsigned tam)
{
    t.resize(tam);
}

/**
 * Funcion insertar un elemento en la Tabla.
 * Inserta un nuevo elemento en la tabla.
 * @param elem clave por la que insertar un nuevo elemento.
 * @param valor elemento a insertar.
*/
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT>
void Tabla<T1,T2,CONT>::insertar(T1 elem, const T2 & valor)
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
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT>
bool Tabla<T1,T2,CONT>::buscar(T1 elem, T2 & valor) 
{
    unsigned i;
    i = hash(elem);
    for(auto &x : t[i])
    {
       if(x.clave == elem) 
       {
           valor = x.dato;
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
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT>
unsigned Tabla<T1,T2,CONT>::hash(T1 elem) const
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
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT>
void Tabla<T1,T2,CONT>::mostrar(ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        for(auto x : t[i])
            sal << x.dato << " -> ";
        sal << endl;
    }
}


#endif
