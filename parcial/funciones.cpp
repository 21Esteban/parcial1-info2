#include "funciones.h"

int **crearEstructura(int tamaño)
{
    // creamos la matriz
    int **punteroMatriz = new int *[tamaño]; // reservamos memoria para las filas
    for (int i = 0; i < tamaño; i++)
    {
        punteroMatriz[i] = new int[tamaño]; // reservamos memoria para las columnas
    }

    // ahora vamos a llenar la matriz para incorporarla en la cerraduraX

    llenarEstructura(punteroMatriz, tamaño);

    return punteroMatriz;
}

void liberarArreglo(int** arreglo,int filas) {


    for (int i = 0; i < filas; ++i) {
        delete[] arreglo[i]; // Liberar cada fila del arreglo
    }
    delete[] arreglo; // Liberar el arreglo en sí
}



// void pedirDatos()
// {
//     bool datoCorrecto = false;

//     while (!datoCorrecto)
//     {
//         cout << "Ingrese el tamano de la estructura M (desde 3x3 hasta 9x9 el numero debe ser impar): ";
//         cin >> tamaño;

//         // validacion
//         if (tamaño % 2 == 1 && tamaño >= 3 && tamaño <= 9)
//         {
//             datoCorrecto = true;
//         }
//         else
//         {

//             cout << "Digite un valor correcto (3, 5, 7, 9)" << endl;
//         }
//     }
// }

void llenarEstructura(int **punteroMatriz, int tamaño)
{

    int variableDeLLenado = 1;
    int centro;

    centro = tamaño / 2;

    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < tamaño; j++)
        {
            if (centro == i && centro == j)
            {
                punteroMatriz[i][j] = 0;
            }
            else
            {
                punteroMatriz[i][j] = variableDeLLenado++;
                // cout<<punteroMatriz[i][j];
            }
        }
    }
}

void mostrarMatriz(int **punteroMatriz, int tamaño)
{
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < tamaño; j++)
        {
            if (punteroMatriz[i][j] == 0)
            {
                cout << "   "; // Imprime tres espacios en lugar de 0 para mantener la misma cantidad de caracteres
            }
            else
            {
                cout << punteroMatriz[i][j] << "  "; // Imprime el valor de la matriz seguido de dos espacios adicionales
            }
        }
        cout << endl;
    }
}

void mostrarMatrizConLibreria(int **punteroMatriz, int tamaño)
{
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < tamaño; j++)
        {
            if (punteroMatriz[i][j] == 0)
            {
                cout <<  setw(4)<<" "; // Imprime tres espacios en lugar de 0 para mantener la misma cantidad de caracteres
            }
            else
            {
                cout << setw(4) <<punteroMatriz[i][j]; // Ajusta el ancho de cada elemento para una mejor alineación
            }
        }
        cout << endl;
    }
}

void girarIzquierda(int **punteroMatriz,  int veces,int tamaño)
{

    //calculamos el tamaño de la matriz entrante



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

        //-----------------//
        mostrarMatrizConLibreria(punteroMatriz,tamaño);

    }
}

//---------------------------------------------------------------//

// MODULO DE VALIDACION //Regla k

void pedirClaveK()
{

    int fila; //variable para ubicar la celda
    int columna; //variable para ubicar la celda
    int valor;

    cout << "------  Ingrese la clave para generar una cerradura para esa Clave  ------ \n Cual es el tamano que va a tener la cerradura : ";
    cin >> tamañoCerradura;

    // generamos el arreglo que va a contener la regla K
    //la regla K tiene una posicion mas por eso usamos la variable tamañoCerradura y le sumamos 1
    reglaK = new int[tamañoCerradura + 1];

    // aprovechamos y generamos el arrayX que va a contener las matrices
    cerraduraX = new int **[tamañoCerradura];//OJO todavia no hemos reservado la memoria para lo de adentro de las matrices , eso lo hacemos en la funcion que genera las estructuras

    //hacemos un bucle que se va a repetir el tamaño de la cerradura + 1 para pedir los valores para el arreglo de K al ser <=tamañoCerradura y i = 0 es lo mismo que tamañoCerradura + 1
    for (int i = 0; i <= tamañoCerradura; i++)
    {
        if (i == 0)
        {
            bool filaValida = false;
            int PrimeraVez = true;

            while (!filaValida)
            {
                cout << (PrimeraVez ? "Ingrese la fila : " : "La fila debe ser un numero positivo \n Ingrese nuevamente la fila :  ") << endl;
                cin >> fila;
                if (fila > 0)
                {
                    reglaK[0] = fila - 1;
                    filaValida = true;
                }
                else
                {
                    PrimeraVez = false;
                }
            }
        }

        else if (i == 1)
        {
            bool columnaValida = false;
            int PrimeraVez = true;

            while (!columnaValida)
            {
                cout << (PrimeraVez ? "Ingrese la columna : " : "La columna debe ser un numero positivo \n Ingrese nuevamente la columna : ") << endl;
                cin >> columna;
                if (columna > 0)
                {
                    reglaK[1] = columna - 1;
                    columnaValida = true;
                }
                else
                {
                    PrimeraVez = false;
                }
            }
        }

        else
        {
            bool valorValido = false;
            int PrimeraVez = true;

            while (!valorValido)
            {
                cout << (PrimeraVez ? "Ingrese el valor o condicion de la celda de la matriz " + to_string(i - 1) + " con respecto a la siguiente estructura " + to_string(i) + " (Matriz)  : " : "la condicion debe estar en el rango -1 , 0 , 1 . \n Ingrese nuevamente el valor : ") << endl;
                cin >> valor;
                if (valor == 0 || valor == 1 || valor == -1)
                {
                    reglaK[i] = valor;
                    valorValido = true;
                }
                else
                {
                    PrimeraVez = false;
                }
            }
        }
    }
}




void generadorDeEstructuraX()
{

    //sacamos la longitud del arregloK

    int tamaño = tamañoCerradura - 1;
    int *condiciones = new int[tamaño];
    int *configuracion = new int[tamaño];
    //metemos en condiciones los valores de reglak desde el 2 hasta tamañoCerradura+1
    for(int i = 0; i <= tamaño ; i++){
        condiciones[i] = reglaK[i+2];
    }

    encontrar_valores(tamañoCerradura,condiciones,configuracion);

    //aqui ya podemos eliminar la memoria de condiciones
    delete [] condiciones;

    //ahora que ya sabemos una posible configuracion para la cerradura X simplemente reservamos la memoria necesaria para cada matriz

    for(int j = 0 ; j<tamañoCerradura; j++){
        cerraduraX[j] = new int*[configuracion[j]];

        for(int k = 0 ; k <configuracion[j] ; k++){
            cerraduraX[j][k] = new int[configuracion[j]];

        }
    }

    //ahora llenamos cada matriz de la cerradura

    llenarCerraduraX(configuracion);


    //liberamos la memoria del arreglo configuracion

    delete[] configuracion;

}

// Funcion encargada de completar la estructura X
void llenarCerraduraX(int*configuracion)
{
    for(int i = 0;i<tamañoCerradura;i++){
        llenarEstructura(cerraduraX[i],configuracion[i]);
        mostrarMatrizConLibreria(cerraduraX[i],configuracion[i]);
        //mostrarMatriz(cerraduraX[i],configuracion[i]);
        cout<<endl;
    }

}




//Modulo encargado de generar las posibles combinaciones para la cerradura


// Función para encontrar los valores que cumplen con las condiciones dadas
void encontrar_valores(int num_bucles, int condiciones[],int *configuracion) {
    int* valores = new int[num_bucles]; // Arreglo dinámico para almacenar los valores
    for (int i = 0; i < num_bucles; ++i) {
        valores[i] = 3; // Inicializa todos los valores en 3 que es la minima que podemos hacer
    }

    while (true) {
        // Verifica si las condiciones se cumplen
        bool condiciones_cumplidas = true;
        for (int i = 0; i < num_bucles - 1; ++i) {
            int condicion = condiciones[i];
            if (condicion == 1 && !(valores[i] > valores[i + 1])) {
                condiciones_cumplidas = false;
                break;
            } else if (condicion == -1 && !(valores[i] < valores[i + 1])) {
                condiciones_cumplidas = false;
                break;
            } else if (condicion == 0 && !(valores[i] == valores[i + 1])) {
                condiciones_cumplidas = false;
                break;
            }
        }

        if (condiciones_cumplidas) {
            // Imprime los valores que cumplen las condiciones
            cout << "Valores que cumplen las condiciones: ";
            for (int i = 0; i < num_bucles; ++i) {
                configuracion[i] = valores[i];
                cout << valores[i];
                if (i != num_bucles - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
            delete[] valores; // Libera la memoria del arreglo dinámico
            return; // Finaliza la ejecución después de encontrar una solución
        }

        // Incrementa los valores en el arreglo
        for (int i = 0; i < num_bucles; ++i) {
            valores[i] += 2;
            if (valores[i] >= 10) {
                valores[i] = 3;
            } else {
                break;
            }
        }
    }
}





