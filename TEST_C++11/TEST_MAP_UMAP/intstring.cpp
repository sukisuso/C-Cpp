/**
*
*    @file IntString.cpp
*    @Author Jesus Juan Aguilar y Humberto Huapaya Leon.
*    @date  31/10/2014.
*    @version 1.0
*    @brief: Practica 3 PROA.
*
*/
#include "intstring.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

/** 
* @brief Constructor de la clase intstring.
*/
IntString::IntString()
{
	size = 0;
}

/** 
* @brief Funcion insertar, si existe la palabra en el diccionario devuelve false
*
* @param word palabra a insertar
*/
bool IntString::insert(string word)
{
    unordered_map<string,unsigned>::const_iterator got = u_map.find (word);
    if ( got == u_map.end() )
    {        
        pair<string,unsigned> par (word,size);
        u_map.insert(par);
        vector_s.push_back(word);
        size ++;
    }
    else
    {
        return false;
    }
    return true;
}

/** 
* @brief Funcion que devuelve la clave de una palabra
*
* @param word palabra de la que se quiere saber la clave
*/
int IntString::getKey(string word)
{
    return u_map[word];
}

/** 
* @brief Funcion que devuelve la palabra dada una clave
*
* @param pos clave de la que se quiere saber la palabra
*/
string IntString::getWord(int pos)
{
    return vector_s.at(pos);
}