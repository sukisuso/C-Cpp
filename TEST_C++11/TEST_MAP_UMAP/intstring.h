/**
*
*    @file IntString.h
*    @Author Jesus Juan Aguilar y Humberto Huapaya Leon.
*    @date  31/10/2014.
*    @version 1.0
*    @brief: Practica 3 PROA.
*
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#ifndef _INTSTRING_H_
#define _INTSTRING_H_

class IntString
{
    public:
        IntString();
        bool insert(string word);
        int getKey(string word);
        string getWord(int pos);  
             
    private:
        vector <string> vector_s;
        unordered_map<string,unsigned> u_map;
        unsigned size;
};

#endif