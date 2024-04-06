#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


//int **punteroMatriz,tamaño; int *reglaK;
extern int **punteroMatriz; extern int tamaño; extern int *reglaK;


//prototipos

void pedirDatos();
void crearEstructura();
void llenarEstructura();
void mostrarMatriz(int **punteroMatriz,int tamaño);
void girarIzquierda(int **punteroMatriz, int tamaño, int veces);
void pedirClaveK();

//variables globales




#endif // FUNCIONES_H
