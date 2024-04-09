#include"funciones.h"

//Variables Globales

int *reglaK; int ***cerraduraX;int tamanoCerradura;int *configuracion;

//cerradura K

int main()
{


    pedirClaveK();
    generadorDeEstructuraX();

    //liberamos la memoria de reglaK

    delete[] reglaK;

    //la memoria de int ***cerraduraX y int *configuracion la liberamos en la funcion generadorDeEstructuraX

    return 0;
    

}



//hay que eliminar la memoria de regla K al final

/*int arreglo[3][3][3] = {
    {
        // Matriz 1
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    },
    {
        // Matriz 2
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    },
    {
        // Matriz 3
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    }
};*/

