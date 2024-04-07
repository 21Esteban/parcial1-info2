#include"funciones.h"

//Variables Globales

int *reglaK; int ***cerraduraX;int tamañoK;

//cerradura K

int main()
{

    //pedimos los datos para rellenar la estructura M
    // pedirDatos();
    //creamos la estructura M
    // crearEstructura();
    //rellenamos la estructura M
    // llenarEstructura();
    //mostramos la matriz;
    // mostrarMatriz(punteroMatriz,tamaño); //podemos comentar la matriz orginal M
    pedirClaveK();
    generadorDeEstructuraX();



    //liberamos la memoria usada para las columnas
    // for(int i = 0; i<tamaño ; i++){
    //     delete[]  punteroMatriz[i] ;
    // }

    //ahora liberamos las filas

    // delete[] punteroMatriz;

    return 0;


}



//Funciones para validar la regla K

//El enfoque que vamos a utilizar es , el usuario va a ingresar la fila y la columna , de acuerdo a eso vamos a hacer una matriz de prueba para validar si podemos usar en la primera matriz la matriz minima (3x3) si el usuario da en el centro de la matriz entonces la primera estructura ya no va a ser de 3x3 sino de 5x5 y asi sucesivamente


// void generadorDeEstructuraX(){

//     //Generamos una matriz estandar para evaluar si nos sirve para la cerradura X
//     int num = 3; //Esta variable es el minimo de la matriz y si no se puede por la 3x3 sumamos 2 para probar con la 5x5

//     bool matrizValida = false;

//     while(!matrizValida){


//         if(esCentro(reglaK[0], reglaK[1] , num) && esValida(reglaK[0], reglaK[1] , num)){
//             matrizValida = true;
//             cout<<"entre"<<endl;

//         }else{
//             num = num + 2;
//             cout<<"le sume 2"<<endl;
//         }



//     }


//     cout<<"Matriz valida la "<< num << " x "<< num <<endl;



// }







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

