/**
 * Clase para Tabla Template y con contenedor Template ademas permite pasar una clase hash.
 * Curso 2014/2015
 *    @file tabla.cpp
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

/*CLASES POLICY*/
/**
 * Clase que define dos funciones hash, una para enteros y otra para strings.
 * De esta forma el usuario podria pasarle a nuestra clase tabla una clase que 
 * defina una funcion hash que el considere. Y se utilizaria la de la nueva clase.
*/
class HashPolicy {
    public:
    /**
    * Funcion hash para enteros.
    * @param elem entero por el cual calculamos el hash.
    * @param size tamaño de la tabla.
    * @return valor del hash.
    */
    static unsigned hash (int elem, unsigned size) {
      
         unsigned long h = 5381;
         cout<< "Con Hash de enteros."<<endl;
         h = elem *h;
         return h % size;
    }

    /**
    * Funcion hash para strings.
    * @param elem string por el cual calculamos el hash.
    * @param size tamaño de la tabla.
    * @return valor del hash.
    */
    static unsigned hash (string elem, unsigned size) {
      
        unsigned long h = 5381;
	    cout<< "Con Hash de strings."<<endl;
        for(unsigned i = 0; i < elem.size(); i++)
            h = ((h << 5) + h) + elem[i];
        
        return h % size;
    }
};

/*Compatible contenedor con: Vector, Lista y Deque*/
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT = std::vector , typename Policy = HashPolicy>
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
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT, typename Policy>
Tabla<T1,T2,CONT, Policy>::Tabla(unsigned tam)
{
    t.resize(tam);
}

/**
 * Funcion insertar un elemento en la Tabla.
 * Inserta un nuevo elemento en la tabla.
 * @param elem clave por la que insertar un nuevo elemento.
 * @param valor elemento a insertar.
*/
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT, typename Policy>
void Tabla<T1,T2,CONT, Policy>::insertar(T1 elem, const T2 & valor)
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
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT, typename Policy>
bool Tabla<T1,T2,CONT, Policy>::buscar(T1 elem, T2 & valor) 
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
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT, typename Policy>
unsigned Tabla<T1,T2,CONT, Policy>::hash(T1 elem) const
{       
    return Policy::hash(elem, t.size());
}

/**
 * Funcion mostrar la Tabla.
 * Muestra toda la tabla por pantalla.
 * @param sal operador con el cual mostrar la tabla.
*/
template <typename T1, typename T2, template <typename ELEM, typename = std::allocator<ELEM>> class CONT, typename Policy>
void Tabla<T1,T2,CONT, Policy>::mostrar(ostream & sal) const
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
