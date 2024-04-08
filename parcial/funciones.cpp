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
                cout <<  setw(4)<< 0; // Imprime tres espacios en lugar de 0 para mantener la misma cantidad de caracteres
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

// Funciones para validar la regla K

// El enfoque que vamos a utilizar es , el usuario va a ingresar la fila y la columna , de acuerdo a eso vamos a hacer una matriz de prueba para validar si podemos usar en la primera matriz la matriz minima (3x3) si el usuario da en el centro de la matriz entonces la primera estructura ya no va a ser de 3x3 sino de 5x5 y asi sucesivamente

void generadorDeEstructuraX()
{

    int tamaño = 3;
    int posiblesTamaños[] = {3,5,7,9,11,13,15};
    
    bool matrizValida = false;

    while (!matrizValida)
    {

        if (esCentro(reglaK[0], reglaK[1], tamaño) == false && esValida(reglaK[0], reglaK[1], tamaño) == true)
        {
            matrizValida = true;
            // cout<<"entre"<<endl;
        }
        else
        {
            tamaño = tamaño + 2;
            cout << "le sume 2" << endl;
        }
    }

    cout << "Matriz valida para la primera estructura " << tamaño << " x " << tamaño << endl;

    cout<<endl;

    // ahora una vez ya sepamos cual matriz podemos usar para la primera estructura de X, procedemos a incorporarla.

    //asignamos memoria para la primera estructura de X
    cerraduraX[0] = new int*[tamaño] ;//en la posicion 0 vamos a guardar tamaño espacio de memoria
    for (int l = 0; l < tamaño; ++l) {
            cerraduraX[0][l] = new int[tamaño]; //ahora entramos a la primera matriz y asignamos o guardamos t espacio para las columnas
        }


    int** estructura = crearEstructura(tamaño); // esta funcion tambien tiene la implementación para llenar esa matriz , ahora tenemos que llenar el arreglo o cerraduraX con esa matriz generada.

    //ahora copiamos la informacion de estructura en cerradura[0]
    for(int q = 0 ; q<tamaño ; q++){
        for(int w = 0 ; w < tamaño;w++){
            cerraduraX[0][q][w] = estructura[q][w];
        }
    }
    //liberamos la memoria de estructura

    //liberarArreglo(estructura);
    
    // imprimimos la matriz para ver que esta pasando

    // recorremos la cerradura
    for (int i = 0; i < 1; i++)
    {
        // recorremos las filas
        for (int j = 0; j < tamaño; j++)
        {
            // recorremos las columnas
            for (int k = 0; k < tamaño; k++)
            {
                cout << cerraduraX[i][j][k];
            }
            cout << endl;
        }
    }

    llenarCerraduraX(tamaño);

}

// Funcion encargada de completar la estructura X
void llenarCerraduraX(int tamañoPrimeraEstructura)
{
    int tamañoPosibleMatriz = 0;
    cout<<"Celda  : "<<reglaK[0] << " ," <<reglaK[1]<<endl;


    // La cerradura se va a ir llenando de acuerdo a la condicion dada en la claveK

   // int primeraCondicion = reglaK[2];
     tamañoPosibleMatriz  = tamañoPrimeraEstructura+2;


    // generamos una posible matriz para cumplir con la condicion de la claveK
    int **posibleMatriz = crearEstructura(tamañoPosibleMatriz); // en el documento dice que no se pueden repetir las matrices consecutivamente por lo que hacemos que la posible matriz sea de tamaño diferente.

    mostrarMatrizConLibreria(posibleMatriz,tamañoPosibleMatriz);

    int variableQueEntraCerradura = 0;

    for (int i = 2; i < tamañoCerradura; i++)
    {

        bool matrizValida = false;

        int rotacion = 1;
        while(!matrizValida){
            cout<<"Valores que vamos a comparar : "<<cerraduraX[variableQueEntraCerradura][reglaK[0]][reglaK[1]] <<"; y " << posibleMatriz[reglaK[0]][reglaK[1]];

            //si rotamos la matriz y ninguna nos sirve entonces eliminamos esa matriz
            if(rotacion >3){
                //limpiamos la memoria de posible matriz y creamos una nueva
             liberarArreglo(posibleMatriz,tamañoPosibleMatriz);
             tamañoPosibleMatriz +=2;
             posibleMatriz = crearEstructura(tamañoPosibleMatriz);
             rotacion = 1;
            }   

            if (reglaK[i] == 1)
        {
            if (cerraduraX[variableQueEntraCerradura][reglaK[0]][reglaK[1]] > posibleMatriz[reglaK[0]][reglaK[1]])
            {


                //cerraduraX[variableQueEntraCerradura + 1] = posibleMatriz;
                matrizValida = true;
                variableQueEntraCerradura++;
                //llenamos esos espacios reservados de la cerraduraX[1] con la PosibleMatriz
                //ahora, vamos a asignar la memoria que necesita la cerradura para la estructura de acuerdo a la matriz creada

                cerraduraX[variableQueEntraCerradura] = new int*[tamañoPosibleMatriz] ;//en la posicion i-1 (1) vamos a guardar tamaño espacio de memoria
                for (int g = 0; g < tamañoPosibleMatriz; ++g) {
                    cerraduraX[variableQueEntraCerradura][g] = new int[tamañoPosibleMatriz]; //ahora entramos a la primera matriz y asignamos o guardamos t espacio para las columnas
                }

                for(int x = 0; x <tamañoPosibleMatriz;x++){
                    for(int y = 0; y<tamañoPosibleMatriz;y++  ){
                        // cout<<*(*(*(cerraduraX+1)+0)+0);

                        cerraduraX[variableQueEntraCerradura][x][y] = posibleMatriz[x][y];
                        cout<<cerraduraX[variableQueEntraCerradura][x][y];
                    }
                    cout<<endl;
                }

            }else{
                cout<<endl;
                girarIzquierda(posibleMatriz,rotacion,tamañoPosibleMatriz);
                rotacion++;
                cout<<endl;
            }


        }else if(reglaK[i] == -1){
            if (cerraduraX[variableQueEntraCerradura][reglaK[0]][reglaK[1]] < posibleMatriz[reglaK[0]][reglaK[1]])
            {
                cerraduraX[variableQueEntraCerradura + 1] = posibleMatriz;
            }


        }else if(reglaK[i] == 0){
            if (cerraduraX[variableQueEntraCerradura][reglaK[0]][reglaK[1]] == posibleMatriz[reglaK[0]][reglaK[1]])
            {
                cerraduraX[variableQueEntraCerradura + 1] = posibleMatriz;
            }
        }
        }
        // Si la condicion es 1 debemos de hacer que el punto de la matriz 2 en esa celda sea menor que la 1
        

    }
}

    // validador para generar la primera matriz de la cerradura.

    bool esCentro(int fila, int columna, int tamañoMatriz)
    {
        bool centro = (fila == tamañoMatriz / 2) && (columna == tamañoMatriz / 2);
        return centro;
    }

    bool esValida(int fila, int columna, int tamañoMatriz)
    {
        bool valida = (fila >= 0 && fila < tamañoMatriz) && (columna >= 0 && columna < tamañoMatriz);
        return valida;
    }
