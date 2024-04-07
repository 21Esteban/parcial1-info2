#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;


//int **punteroMatriz,tamaño; int *reglaK;
extern int **punteroMatriz; extern int tamaño; extern int *reglaK;extern int ***cerraduraX;


//prototipos

void pedirDatos();
void crearEstructura();
void llenarEstructura();
void mostrarMatriz(int **punteroMatriz,int tamaño);
void girarIzquierda(int **punteroMatriz, int tamaño, int veces);

void pedirClaveK();
void generadorDeEstructuraX();
// void crearEstructuraGenerica(int tamaño1);

bool esCentro(int fila, int columna, int tamañoMatriz);
bool esValida(int fila, int columna, int tamañoMatriz);
//variables globales




#endif // FUNCIONES_H
