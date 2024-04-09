#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


//int **punteroMatriz,tamano; int *reglaK;
extern int *reglaK;extern int ***cerraduraX;extern int tamanoCerradura;


//prototipos

// void pedirDatos();
int **crearEstructura(int tamano);
void liberarArreglo(int** arreglo);
void llenarEstructura(int **punteroMatriz,int tamano);
//void mostrarMatriz(int **punteroMatriz,int tamano);

void mostrarMatrizConLibreria(int **punteroMatriz, int tamano);


void girarIzquierda(int **punteroMatriz, int veces);

void pedirClaveK();
void encontrar_valores(int num_bucles, int condiciones[],int *configuracion);
void generadorDeEstructuraX();
void llenarCerraduraX(int*configuracion);
// void crearEstructuraGenerica(int tamano1);






#endif // FUNCIONES_H
