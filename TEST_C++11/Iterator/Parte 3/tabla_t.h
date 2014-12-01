/**
 * Clase para Tabla
 * Curso 2014/2015
 *    @file tabla_t.h
 *    @Author Jesus Juan Aguilar
 *    @date  20/11/2014.
 *    @version 1.0
*/

#ifndef _TABLA_H
#define _TABLA_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<typename T, typename T1>
class TablaIterator;

template <typename T1, typename T2>
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
    TablaIterator<Tabla<T1,T2>, Celda> begin();
    TablaIterator<Tabla<T1,T2>, Celda> end();

    typedef Celda value_type;
    typedef TablaIterator<Tabla<T1, T2>, Celda> iterator;
    friend TablaIterator<Tabla<T1, T2>, Celda>;

private:
    typedef vector<Celda> ListaDatos; 
    vector<ListaDatos> t;
};

/**
 * Constructor Tabla.
 * Genera una tabla de tamaño tam.
 * @param tam tamaño de la tabla.
*/
template <typename T1, typename T2>
Tabla<T1,T2>::Tabla(unsigned tam)
{
    t.resize(tam);
}

/**
 * Funcion insertar un elemento en la Tabla.
 * Inserta un nuevo elemento en la tabla.
 * @param elem clave por la que insertar un nuevo elemento.
 * @param valor elemento a insertar.
*/
template <typename T1, typename T2>
void Tabla<T1,T2>::insertar(T1 elem, const T2 & valor)
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
template <typename T1, typename T2>
bool Tabla<T1,T2>::buscar(T1 elem, T2 & valor) 
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
template <typename T1, typename T2>
unsigned Tabla<T1,T2>::hash(T1 elem) const
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
template <typename T1, typename T2>
void Tabla<T1,T2>::mostrar(ostream & sal) const
{
    for(unsigned i = 0; i < t.size(); i++)
    {
        sal << i << ":" ;
        for(unsigned j = 0; j < t[i].size(); j++)
            sal << t[i][j].dato << " -> ";
        sal << endl;
    }
}

/**
 * Funcion que devuelve un iterador apuntando al inicio de la lista.
 * @return TablaIteratorm que punta al inicio de la lista.
*/
template <typename T1, typename T2>
typename Tabla<T1, T2>::iterator Tabla<T1,T2>::begin()
{
    int x;
    for(x = 0; x < t.size(); x++)
        if(t[x].size()!=0)
            break;

    Tabla<T1, T2>::iterator it(*this, x,0);
    return it;
}

/**
 * Funcion que devuelve un iterador apuntando al final de la lista.
 * @return TablaIteratorm que punta al inicio de la lista.
*/
template <typename T1, typename T2>
typename Tabla<T1, T2>::iterator Tabla<T1,T2>::end()
{
    Tabla<T1, T2>::iterator it(*this, -1,-1);
    return it;
}

/*
* Clase Iterador. Para recorrer la clase Tabla apunta a nodos de la misma.
* @param T Tipo de la tabla
* @param TC Tipo celda
*/
template<typename T, typename TC>
class TablaIterator: public iterator<forward_iterator_tag , T> //random_access_iterator_tag
{
    // Puntero a un nodo.
    T& tabla;
    int x,y;

    public:
        /**
        * @brief Constructor de la clase TablaIterator.
        *
        * @param tabla_1, referencia a la tabla a recorrer.
        * @param x_1, direccion de la tabla
        * @param y_1, direccion de la tabla
        */
        TablaIterator(T& tabla_1, unsigned x_1, unsigned y_1): tabla(tabla_1), x(x_1), y(y_1) {}
    
        /**
        * @brief operator==, Funcion que devuelve si un iterador es igual a otro.
        *
        * @param l_it, Iterador a comparar
        * @return bool, comparacion entre los dos iteradores.
        */
        bool operator==(const TablaIterator t_it)
        {
            return ((x == t_it.x) && (y == t_it.y));
        }

        /**
        * @brief operator!=, Funcion que devuelve si un iterador es distinto a otro.
        *
        * @param l_it, Iterador a comparar
        * @return bool, comparacion entre los dos iteradores.
        */
        bool operator!=(const TablaIterator t_it)
        {
            return ((x != t_it.x) && (y != t_it.y));
        }
      
        /**
        * @brief operator++, Funcion que incrementa en uno la posicion del iterador 
        *
        * @return this, El mismo elemento incrementado.
        */
        TablaIterator& operator++()
        {
            y++;
            if(tabla.t[x].size() == y)
            {
                x++;
                y = 0;

                while(tabla.t[x].size() == 0){
                    x++;
                }

                if(tabla.t.size() <= x){
                    x = -1;
                    y = -1;
                }
            }
            return *this;
        }

        /**
        * @brief operator++, Funcion que incrementa en uno la posicion del iterador 
        *
        * @param int, flag para diferenciar del otro ++.
        * @return tmp, Devuelve el valor antes de incrementar.
        */
        TablaIterator operator++(int)
        {
            TablaIterator tmp(*this); 
            operator++();
            return tmp; 
        }
        
        /**
        * @brief operator*, funcion que devuelbe un el elemento de la tabla al que apunta el iterador.
        *
        * @return tabla.t[x][y], celda del elemento al que apunta el iterador.
        */
        TC& operator*()
        {
            return tabla.t[x][y];
        }

};
#endif
