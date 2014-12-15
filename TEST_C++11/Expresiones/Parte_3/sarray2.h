#ifndef _SARRAY2_H
#define _SARRAY2_H
 
#include <cstddef>
#include <math.h>
 /*
* Class SArray2 
*/
template<typename T>
class SArray2 {   // Simple Array
  T*     storage;       // storage of the elements
  size_t storage_size;  // number of elements
 
public:
  // create array with initial size
  explicit SArray2 (size_t s)
  : storage(new T[s]), storage_size(s) {
    init();
  }
 
  // copy constructor
  SArray2 (SArray2<T> const& orig)
  : storage(new T[orig.size()]), storage_size(orig.size()) {
    copy(orig);
  }
  ~SArray2() {
        delete[] storage;
    }
 
    SArray2<T>& operator= (SArray2<T> const& orig) {
        if (&orig != this) {
            copy(orig);
        }
        return *this;
    }
 
    size_t size() const {
        return storage_size;
    }
 
    T operator[] (size_t idx) const {
        return storage[idx];
    }
    T& operator[] (size_t idx) {
        return storage[idx];
    }
    protected:
    // init values with default constructor
    void init() {
        for (size_t idx = 0; idx<size(); ++idx) {
            storage[idx] = T();
        }
    }
 
    // copy values of another array
    void copy (SArray2<T> const& orig) {
        assert(size() == orig.size());
        for (size_t idx = 0; idx<size(); ++idx) {
            storage[idx] = orig.storage[idx];
        }
    }
     
    // operadores con diferentes tipos de operandos
    // Suma Array - Array
    template <typename TD>
    friend SArray2<TD> operator+ (SArray2<TD> const& array1, SArray2<TD> const& array2);
    
    // Suma Escalar - Array
    template <typename TD>
    friend SArray2<TD> operator+ (TD const& esc, SArray2<TD> const& array);
    
    // Multiplicacion Array - Array
    template <typename TD>
    friend SArray2<TD> operator+ (SArray2<TD> const& array1, SArray2<TD> const& array2);
    
    // Multiplicacion Escalar - Array
    template <typename TD>
    friend SArray2<TD> operator+ (TD const& esc, SArray2<TD> const& array);
    
    // POW Escalar - Array
    template <typename TD>
    friend SArray2<TD> operator^ (SArray2<TD> const& array, TD const& esc);
};
 
/**
* @brief operator+, operador para sumar Array - Array.
*
* @param array1, array 1 para sumar
* @param array2, array 2 para sumar
* @result aux, array de resultado
*/
template <typename TD>
SArray2<TD> operator+ (SArray2<TD> const& array1, SArray2<TD> const& array2)
{
    SArray2<TD> aux(array1.size());
    for(unsigned i = 0; i < array1.size(); i++)
        aux[i] = array1[i] + array2[i];   
    return aux;
}

/**
* @brief operator+, operador para sumar Escalar - Array.
*
* @param esc, escalar para sumar
* @param array, array para sumar
* @result aux, array de resultado
*/
template <typename TD>
SArray2<TD> operator+ (TD const& esc, SArray2<TD> const& array)
{
    SArray2<TD> aux(array.size());
    for(unsigned i = 0; i < array.size(); i++)
        aux[i] = esc + array[i];   
    return aux;  
}

/**
* @brief operator*, operador para multiplicar Array - Array.
*
* @param array1, array 1 para multiplicar
* @param array2, array 2 para multiplicar
* @result aux, array de resultado
*/
template <typename TD>
SArray2<TD> operator* (SArray2<TD> const& array1, SArray2<TD> const& array2)
{
    SArray2<TD> aux(array1.size());
    for(unsigned i = 0; i < array1.size(); i++)
        aux[i] = array1[i] * array2[i];    
    return aux;
}

/**
* @brief operator*, operador para multiplicar Escalar - Array.
*
* @param esc, escalar para multiplicar
* @param array, array para multiplicar
* @result aux, array de resultado
*/
template <typename TD>
SArray2<TD> operator* (TD const& esc, SArray2<TD> const& array)
{
    SArray2<TD> aux(array.size());
    for(unsigned i = 0; i < array.size(); i++)
        aux[i] = esc * array[i];   
    return aux;  
}

/**
* @brief operator^, operador para hacer potencias Array - Escalar.
*
* @param array1, array
* @param esc, escalar exponente
* @result aux, array de resultado
*/
template <typename TD>
SArray2<TD> operator^ (SArray2<TD> const& array1, TD const& esc)
{
    SArray2<TD> aux(array1.size());
    for(unsigned i = 0; i < array1.size(); i++)
        aux[i] = pow(array1[i], esc);   
    return aux;   
}

#endif