#include "funciones.h"

void crearEstructura()
{

    punteroMatriz = new int *[tamaño]; // reservamos memoria para las filas
    for (int i = 0; i < tamaño; i++)
    {
        punteroMatriz[i] = new int[tamaño]; // reservamos memoria para las columnas
    }

    llenarEstructura();
}



void pedirDatos()
{
    bool datoCorrecto = false;

    while (!datoCorrecto)
    {
        cout << "Ingrese el tamano de la estructura M (desde 3x3 hasta 9x9 el numero debe ser impar): ";
        cin >> tamaño;

        // validacion
        if (tamaño % 2 == 1 && tamaño >= 3 && tamaño <= 9)
        {
            datoCorrecto = true;
        }
        else
        {

            cout << "Digite un valor correcto (3, 5, 7, 9)" << endl;
        }
    }
}

void llenarEstructura()
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

//---------------------------------------------------------------//

// MODULO DE VALIDACION //Regla k

void pedirClaveK()
{
    int tamañok;
    int fila;
    int columna;
    int valor;

    cout << "------  Ingrese la clave para generar una cerradura para esa Clave  ------ \n Cual es el tamano que va a tener la cerradura : ";
    cin >> tamañok;

    // generamos el arreglo que va a contener la regla K

    reglaK = new int[tamañok + 1];

    //aprovechamos y generamos el arrayX que va a contener las matrices
    cerraduraX = new int **[tamañok];

    for (int i = 0; i <= tamañok; i++)
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
                    reglaK[0] = fila - 1 ;
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

//Funciones para validar la regla K

//El enfoque que vamos a utilizar es , el usuario va a ingresar la fila y la columna , de acuerdo a eso vamos a hacer una matriz de prueba para validar si podemos usar en la primera matriz la matriz minima (3x3) si el usuario da en el centro de la matriz entonces la primera estructura ya no va a ser de 3x3 sino de 5x5 y asi sucesivamente

void generadorDeEstructuraX(){

   
    int num = 3; 

    bool matrizValida = false;

    while(!matrizValida){


        if(esCentro(reglaK[0], reglaK[1] , num) ==false && esValida(reglaK[0], reglaK[1] , num) == true){
            matrizValida = true;
            //cout<<"entre"<<endl;

        }else{
            num = num + 2;
            cout<<"le sume 2"<<endl;
        }



    }


    cout<<"Matriz valida para la primera estructura "<< num << " x "<< num <<endl;

    //ahora una vez ya sepamos cual matriz podemos usar para la primera estructura de X, procedemos a incorporarla.







}


//validador para generar la primera matriz de la cerradura.

bool esCentro(int fila, int columna, int tamañoMatriz) {
    bool centro = (fila == tamañoMatriz / 2) && (columna == tamañoMatriz / 2);
    return centro;
}

bool esValida(int fila, int columna, int tamañoMatriz) {
    bool valida = (fila >= 0 && fila < tamañoMatriz) && (columna >= 0 && columna < tamañoMatriz);
    return valida;
}
