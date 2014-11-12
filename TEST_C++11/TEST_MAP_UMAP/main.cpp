/**
*
*    @file previo.cpp
*    @Author Jesus Juan Aguilar
*    @date  31/10/2014.
*    @version 1.0
*    @brief: Practica 3 PROA.
*
*/

/**< Icludes, namespace y constantes */
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream> 
#include <fstream>
#include <map>
#include <unordered_map>
#include "intstring.h"
using namespace std;

const int tam_buf = 1024;

/**< Definicion de funciones */
void readfile(vector <string> & vec);
void loadMap(const vector <string> & vec, map<string,int> &map);
void load_unordered_Map(const vector <string> & vec, unordered_map<string,int> &map);
void readfile_dic(vector <unsigned> & vec, IntString & diccionario);
void loadMap_dic_map(const vector <unsigned> & vec, map<unsigned,unsigned> &map);
void loadMap_dic_umap(const vector <unsigned> & vec, unordered_map<unsigned,unsigned> &map);

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
    vector<string> vec_1; 
    vector<unsigned> res_1,res_2 ,vec_2; 
    struct timespec t_1, t_2;
    double t_total =0 ;
    IntString in_str;

    readfile(vec_1);
    readfile_dic(vec_2, in_str);

    //MAP
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(int i = 0; i < 1000; i++) 
    {
        map<string,int> map;
        loadMap(vec_1, map);
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << "Tiempo en cargar Map: " << t_total<<endl;

    //UNORDERED MAP
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(int i = 0; i < 1000; i++)
    {
        unordered_map<string,int> u_map;
        load_unordered_Map(vec_1, u_map);
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << "Tiempo en cargar Unordered_Map: " << t_total<<endl;

     /*DICCIONARIO CON MAP*/
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(int i = 0; i < 1000; i++)
    {
        map<unsigned,unsigned> un_map;
        loadMap_dic_map(vec_2, un_map );
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << "Tiempo en cargar Texto usando Diccionario y Vector Con MAP: " << t_total<<endl;
    
        /*DICCIONARIO CUN UNORDERED_MAP*/
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(int i = 0; i < 1000; i++)
    {
        unordered_map<unsigned,unsigned> otro_map;
        loadMap_dic_umap(vec_2, otro_map );
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << "Tiempo en cargar Texto usando Diccionario y Vector con Unordered_Map: " << t_total<<endl;


    return 0;
}

/** [PREVIO]
* @brief readfile, es una funcion para leer todas las palabras de un fichero y almacenarlas en un vector de la stl
*
* @param vec, el vector que almacenara las palabras del fichero.
*/
void readfile(vector <string> & vec)
{
    char *pch;
    FILE * pFile;
    char mystring [tam_buf];
    pFile = fopen ("texto2.txt" , "r");
    if (pFile == NULL)
    {
        exit(1);
    }
    else
    {
        while (fgets(mystring , tam_buf , pFile) != NULL) 
        {
            pch = strtok (mystring, u8" ,.-!¡?¿()[]:;\n");  
            while (pch != NULL)
            {
                vec.push_back(pch);
                pch = strtok (NULL, u8" ,.-!¡?¿()[]:;\n");
            }      
        }
        fclose (pFile);
     }
}


/**
* @brief Funcion que carga la clase map <string,int> del STL para guardar el numero de repeticiones.
*
* @param vec Vector que contiene todas las palabras del fichero en foramto string
* @param map Resultado de contar todas las palabras
* 
*/
void loadMap(const vector <string> & vec, map<string,int> &map)
{
    for(auto str : vec)
    {
        map[str]++;
    }
}

/**
* @brief Funcion que carga la clase unordered_map <string,int> del STL para guardar el numero de repeticiones.
*
* @param vec Vector que contiene todas las palabras del fichero en foramto string
* @param map Resultado de contar todas las palabras
* 
*/
void load_unordered_Map(const vector <string> & vec, unordered_map<string,int> &map)
{
    for(auto str : vec)
    {
        map[str]++;
    }
}

/**
* @brief Funcion que carga la clase map <unsigned,unsigned> del STL para guardar el numero de repeticiones.
*
* @param vec Vector que contiene todas las palabras del fichero en foramto unsigned
* @param map Resultado de contar todas las palabras
* 
*/
void loadMap_dic_map(const vector <unsigned> & vec, map<unsigned,unsigned> &map)
{
    for(auto interger : vec)
    {   
       map[interger]++;
    }
}

/**
* @brief Funcion que carga la clase unordered_map <unsigned,unsigned> del STL para guardar el numero de repeticiones.
*
* @param vec Vector que contiene todas las palabras del fichero en foramto unsigned
* @param map Resultado de contar todas las palabras
* 
*/
void loadMap_dic_umap(const vector <unsigned> & vec, unordered_map<unsigned,unsigned> &map)
{
    for(auto interger : vec)
    {   
       map[interger]++;
    }
}

/** 
* @brief readfile, es una funcion para leer todas las palabras de un fichero y almacenarlas en un vector de la stl de unsigneds
* 	 haciendo uso de la clase IntString
*
* @param vec, el vector que almacenara las palabras del fichero.
* @param diccionario, Diccionario para mantener los pares string - unsigned del fichero.
*/
void readfile_dic(vector <unsigned> & vec, IntString & diccionario)
{
    char *pch;
    FILE * pFile;
    char mystring [tam_buf];
    pFile = fopen ("texto2.txt" , "r");
    if (pFile == NULL)
    {
        exit(1);
    }
    else
    {
        while (fgets(mystring , tam_buf , pFile) != NULL) 
        {
            pch = strtok (mystring, u8" ,.-!¡?¿()[]:;\n"); 
            while (pch != NULL)
            {   
		diccionario.insert(pch);
		vec.push_back(diccionario.getKey(pch));
                pch = strtok (NULL, u8" ,.-!¡?¿()[]:;\n");  
            }       
        }
        fclose (pFile);
     }
}
