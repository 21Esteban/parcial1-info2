




#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


//int **punteroMatriz,tamaño; int *reglaK;
extern int *reglaK;extern int ***cerraduraX;extern int tamañoCerradura;


//prototipos

// void pedirDatos();
int **crearEstructura(int tamaño);
void liberarArreglo(int** arreglo);
void llenarEstructura(int **punteroMatriz,int tamaño);
void mostrarMatriz(int **punteroMatriz,int tamaño);

void mostrarMatrizConLibreria(int **punteroMatriz, int tamaño);


void girarIzquierda(int **punteroMatriz, int veces);

void pedirClaveK();
void encontrar_valores(int num_bucles, int condiciones[],int *configuracion);
void generadorDeEstructuraX();
void llenarCerraduraX(int*configuracion);
// void crearEstructuraGenerica(int tamaño1);

bool esCentro(int fila, int columna, int tamañoMatriz);
bool esValida(int fila, int columna, int tamañoMatriz);
//variables globales




#endif // FUNCIONES_H
