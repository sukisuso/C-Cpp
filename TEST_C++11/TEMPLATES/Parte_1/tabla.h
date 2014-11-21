/**
 * Clase para Tabla
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

class Tabla
{
public:
    typedef string TipoClave;
    typedef Alumno TipoDato;
    struct Celda {
        TipoClave clave;
        TipoDato dato;
    };
        
    Tabla(unsigned); 
    bool buscar(TipoClave, TipoDato&) ; 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(ostream & sal) const;

private:
    typedef vector<Celda> ListaDatos; 
    vector<ListaDatos> t;
};

#endif
