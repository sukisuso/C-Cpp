/**
 * Clase para representar alumnos
 * Curso 2014/2015
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef _ALUMNO_H_
#define _ALUMNO_H_

class Alumno
{
    string dni;
    string nombre;
    string apellidos;
    unsigned curso;
    unsigned telefono;
    
    static const unsigned NUM_NOMBRE = 15;
    static string list_nombre[];
    static string list_apellido[];


public:
    Alumno() {};
    Alumno(unsigned );
    string getDNI() const 
        {return dni; };
        
    friend ostream & operator<<(ostream &, const Alumno &);
             
};

#endif
