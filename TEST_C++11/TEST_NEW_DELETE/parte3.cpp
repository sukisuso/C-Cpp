/**
*
*    @file parte3.cpp
*    @Author Jesus Juan Aguilar
*    @date  10/11/2014.
*    @version 1.0
*    @brief: Practica 4 PROA.
*
*/
/**< Includes, namespace y constantes*/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

const int TAM = 10000;
const int REP = 100;

/**< struct PRUEBA*/
struct Prueba
{
    float f1, f2;
    int i1, i2, i3; 
  
    static unsigned pos;
    static unsigned char pool[];
    static bool alloc_map[];
  
    void* operator new (size_t) throw(bad_alloc);
    void operator delete (void* m);
};

unsigned Prueba::pos = 0;
unsigned char Prueba::pool[TAM*sizeof(Prueba)];
bool Prueba::alloc_map[TAM] = {false};

/**< Sobrecarga del operador NEW*/
void* Prueba::operator new (size_t) throw(bad_alloc) 
{
    for(unsigned i = pos; i < TAM; i++)
        if(!alloc_map[i])
        {
	        alloc_map[i] = true;
	        pos = i;
	        return pool + (i * sizeof(Prueba));	
        }
  throw bad_alloc();
}

/**< Sobrecarga del operador DELETE*/
void Prueba::operator delete (void* m)
{
    if(!m) 
        return;
    unsigned long block = (unsigned long)m -(unsigned long)pool;
    block /= sizeof(Prueba);
    alloc_map[block] = false;

    if(block < pos) // Si se realiza un delete de una posicion menos a la que apunta pos.
        pos = block;
}

/**< Definicion de funciones */
int costeMem1();
int costeMem2();

/***********************************************
*  MAIN
***********************************************/
int main (int argc, char *argv[])
{
   struct timespec t_1, t_2;
    double t_total =0 ;

    /*COSTEMEM1*/
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(int i = 0; i < REP; i++) {
        costeMem1();
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << "CosteMem1: " << t_total<<endl;


     /*COSTEMEM2*/
    clock_gettime(CLOCK_REALTIME, &t_1);
    for(int i = 0; i < REP; i++) {
        costeMem2();
    }
    clock_gettime(CLOCK_REALTIME, &t_2);
    t_total = (t_2.tv_sec - t_1.tv_sec) + (t_2.tv_nsec * 1.0e-9 - t_1.tv_nsec *1.0e-9);
    cout << "CosteMem2: " << t_total<<endl;
    
    
    cout << endl <<costeMem1()<< endl;
    cout << costeMem2()<< endl;
    return 0;
}

/** 
* @brief Reserva usando memoria estatica un vector de 10000 elementos Prueba. 
* 
* @return suma, resultado de sumar todos los elementos i1 del vector
*/
int costeMem1()
{
    Prueba vec_stat [TAM];
    volatile int suma = 0;

    for( unsigned i = 0; i < TAM; ++i)
    {
        vec_stat[i].i1 = i;
    }

    for( unsigned i = 0; i < TAM; ++i)
    {
        suma += vec_stat[i].i1;
    }

    return suma;
}

/** 
* @brief  Reserva usando memoria dinamica un vector de 10000 elementos Prueba. 
* 
* @return suma, resultado de sumar todos los elementos i1 del vector
*/
int costeMem2()
{
    Prueba * vec_dina [TAM];
    volatile int suma = 0;

    for( unsigned i = 0; i < TAM; ++i)
    {
        vec_dina[i] = new Prueba();
        (*vec_dina[i]).i1 = i;
    }

    for( unsigned i = 0; i < TAM ; ++i)
    {
        suma += vec_dina[i]->i1;
        delete vec_dina[i];
    }

    return suma;
}