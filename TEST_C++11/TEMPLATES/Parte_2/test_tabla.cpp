/**
*
*    @file test_tabla.cpp
*    @Author Jesus Juan Aguilar
*    @date  20/11/2014.
*    @version 1.0
*    @brief: Practica 5 PROA. PARTE 2
*
*/

/* Icludes, namespace y constantes */
#include <iostream>
#include <vector>
#include <string>
#include "tabla_t.h"
#include "alumno.h"
using namespace std;

const unsigned N_CASOS = 200; // Numero de Alumnos.
const unsigned TAM = 400;     // Tamaño adecuado de la Tabla Hash.

/* Definicion de funciones */
void check_alumno(string code, Tabla<string, Alumno> & tabla_1, Alumno &alu);

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
    Tabla<string, Alumno> tabla_1(TAM);
    string code = "";
   
    //Generamos alumnos y los introducimos en la tabla
    for(unsigned i = 0; i < N_CASOS; i++){
        Alumno alu((i % 10)+1);
        tabla_1.insertar(alu.getDNI(), alu);
        code = alu.getDNI();
    }
    Alumno res(1);

    check_alumno(code, tabla_1, res);         //Comprobamos elemento que existe
    check_alumno("asdasdd", tabla_1, res);    //Comprobamos elemento que no existe

    return 0;
}

/**
* @brief check_alumno, es una funcion para comprobar si un alumno se encuentra o no en la tabla.
*
* @param code, es el DNI del alumno.
* @param tabla_1, es la tabla en la que se encuentran todos los alumnos.
* @param alu, es el alumno que se devolvera como resultado en caso de que se encuentre en la tabla.
*/
void check_alumno(string code, Tabla<string, Alumno> & tabla_1, Alumno &alu)
{
    if(tabla_1.buscar(code, alu))
    {
        cout << "Alumno, con DNI: "<< code << " se encuentra en la tabla." <<endl;
        cout << alu;
    }
    else
    {
        cout << "Alumno, con DNI: "<< code << " no ha sido encontrado." <<endl;
    }
	
}