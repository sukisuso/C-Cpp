/**
*
*    @file test_tabla.cpp
*    @Author Jesus Juan Aguilar
*    @date  14/11/2014.
*    @version 1.0
*    @brief: Practica 5 PROA. PARTE 3
*
*/

/* Icludes, namespace y constantes */
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include "tabla_t.h"
#include "alumno.h"
using namespace std;

const unsigned N_CASOS = 200; // Numero de Alumnos.
const unsigned TAM = 400;     // Tamaño adecuado de la Tabla Hash.

/***********************************************
*  MAIN
***********************************************/
/* Compatible con Vector, Lista, Deque*/
int main (int argc, char *argv[])
{
  //Tabla<string, Alumno,vector > tabla_1(TAM);
  //Tabla<string, Alumno,deque > tabla_1(TAM);
    Tabla<string, Alumno,list > tabla_1(TAM);
    string code = "";
    
    //Generamos alumnos y los introducimos en la tabla
    for(unsigned i = 0; i < N_CASOS; i++){
        Alumno alu((i % 10)+1);
        tabla_1.insertar(alu.getDNI(), alu);
        code = alu.getDNI();
    }
    Alumno res(1);
    string code_false = "assjnsdfoas";    

    if(tabla_1.buscar(code, res)) //Buscamos elemento que se encuentra en la tabla
    {
        cout << "Alumno, con DNI: "<< code << " se encuentra en la tabla." <<endl;
    }
    else
    {
        cout << "Alumno, con DNI: "<< code << " no ha sido encontrado." <<endl;
    }
    
    if(tabla_1.buscar(code_false, res))//Buscamos elemento que no se encuentra en la tabla
    {
        cout << "Alumno, con DNI: "<< code_false << " se encuentra en la tabla." <<endl;
    }
    else
    {
        cout << "Alumno, con DNI: "<< code_false << " no ha sido encontrado." <<endl;
    }
    
    return 0;
}
