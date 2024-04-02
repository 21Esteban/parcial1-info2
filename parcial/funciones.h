#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//prototipos

void pedirDatos();
void crearEstructura();
void llenarEstructura();
void mostrarMatriz(int **punteroMatriz,int tamaño);
void girarIzquierda(int **punteroMatriz, int tamaño, int veces);
#endif // FUNCIONES_H
