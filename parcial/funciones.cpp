#include "funciones.h"

void girarIzquierda(int **punteroMatriz, int tamaño, int veces)
{
    for (int k = 0; k < veces; ++k)
    {
        int **temp = new int *[tamaño];
        for (int i = 0; i < tamaño; ++i)
        {
            temp[i] = new int[tamaño];
            for (int j = 0; j < tamaño; ++j)
            {
                temp[i][j] = punteroMatriz[j][tamaño - 1 - i];
            }
        }

        // Copiamos la matriz girada de vuelta a la original
        for (int i = 0; i < tamaño; ++i)
        {
            for (int j = 0; j < tamaño; ++j)
            {
                punteroMatriz[i][j] = temp[i][j];
            }
        }

        // Liberamos la memoria usada para las columnas en la matriz temporal
        for (int i = 0; i < tamaño; ++i)
        {
            delete[] temp[i];
        }
        // Liberamos las filas en la matriz temporal
        delete[] temp;
    }
}
