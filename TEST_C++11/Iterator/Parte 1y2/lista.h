 /**
 * Implementacion de una lista simplemente enlazada
 * Programación Avanzada
 * Curso 2014/2015
 * 
 * @author F. Barber
 */

#ifndef _LISTA_H
#define _LISTA_H

#include <iostream>
#include <iterator>
using namespace std;


template<typename T>
class ListaIterator;

/**
 * Lista simplemente enlazada
 * @param T Tipo de los elementos de la lista
 */
template<typename T>
class Lista
{
  friend class ListaIterator<T>;
  
    struct Nodo
    {
        T valor;
        Nodo * sig;
    };
    
    typedef Nodo * PtrNodo;
    PtrNodo ptr;

public:
    typedef T value_type;
    typedef ListaIterator<T> iterator;

    Lista():ptr(nullptr) {}
    void push_front(const T &);
    void mostrar() const;
    ListaIterator<T> begin();
    ListaIterator<T> end();
};

/**
 * Añadir elemento al inicio de la lista
 * @param x elemento a añadir
 */
template<typename T>
void Lista<T>::push_front(const T & x)
{
    PtrNodo aux = new Nodo;
    aux->valor = x;
    aux->sig = ptr;
    ptr = aux;
}

/**
 * Muestra la lista por pantalla
 */
template<typename T>
void Lista<T>::mostrar() const
{
    PtrNodo aux = ptr;
    
    while(aux != nullptr)
    {
        std::cout << aux->valor << " ";
        aux = aux->sig;
    }
}

/**
* @brief begin, funcion que devuelbe un iterador de la clase ListaIterator apuntando al inicio de la lista.
*
* @return it, Iterador que apunta al primer elemento del contenedor.
*/
template<typename T>
ListaIterator<T> Lista<T>::begin()
{
    ListaIterator<T> it(ptr);
    return it;
}

/**
* @brief mostrar, funcion que devuelbe un iterador de la clase ListaIterator apuntando al final de la lista.
*
* @return it, Iterador que apunta al final del contenedor.
*/
template<typename T>
ListaIterator<T> Lista<T>::end()
{
    ListaIterator<T> it(nullptr);
    return it;
  
}

/*
* Clase Iterador. Para recorrer la clase Lista apunta a nodos de la misma.
* @param T Tipo de los elementos de la lista
*/
template<typename T>
class ListaIterator: public iterator< forward_iterator_tag , T>
{
    // Puntero a un nodo.
    typename Lista<T>::Nodo * elem;

    public:
        /**
        * @brief Constructor de la clase ListaIterator.
        *
        * @param nod, puntero a un nodo de la lista.
        */
 	    ListaIterator(typename Lista<T>::Nodo * nod): elem(nod)	{}
	
        /**
        * @brief operator==, Funcion que devuelve si un iterador es igual a otro.
        *
        * @param l_it, Iterador a comparar
        * @return bool, comparacion entre los dos iteradores.
        */
    	bool operator==(const ListaIterator l_it)
    	{
    	    return elem == l_it.elem;
    	}

    	/**
        * @brief operator!=, Funcion que devuelve si un iterador es distinto a otro.
        *
        * @param l_it, Iterador a comparar
        * @return bool, comparacion entre los dos iteradores.
        */
        bool operator!=(const ListaIterator l_it)
    	{
    		return elem != l_it.elem;
    	}
      
        /**
        * @brief operator++, Funcion que incrementa en uno la posicion del iterador 
        *
        * @return this, El mismo elemento incrementado.
        */
    	ListaIterator& operator++()
        {
    	  
    	    elem = elem->sig;
    	    return *this;
    	
    	}

        /**
        * @brief operator++, Funcion que incrementa en uno la posicion del iterador 
        *
        * @param int, flag para diferenciar del otro ++.
        * @return tmp, Devuelve el valor antes de incrementar.
        */
    	ListaIterator operator++(int)
    	{
    	    ListaIterator tmp(*this); 
    	    operator++();
    	    return tmp;  
    	}
    	
        /**
        * @brief operator*, funcion que devuelbe un el elemento de la lista del nodo al que apunta el iterador.
        *
        * @return elem->valor, valor del elemento al que apunta el iterador.
        */
    	T& operator*()
    	{
    		return elem->valor;
    	}
};

#endif


