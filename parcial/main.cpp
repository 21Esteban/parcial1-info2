#include"funciones.h"

//Variables Globales

int **punteroMatriz,tamaño;


int main()
{

    //pedimos los datos para rellenar la estructura M
    pedirDatos();
    //creamos la estructura M
    crearEstructura();
    //rellenamos la estructura M
    llenarEstructura();
    //mostramos la matriz;
    mostrarMatriz(punteroMatriz,tamaño);





    //liberamos la memoria usada para las columnas
    for(int i = 0; i<tamaño ; i++){
        delete[]  punteroMatriz[i] ;
    }

    //ahora liberamos las filas

    delete[] punteroMatriz;

    return 0;
    

}


void pedirDatos() {
    bool datoCorrecto = false;

    while (!datoCorrecto) {
        cout << "Ingrese el tamano de la estructura M (desde 3x3 hasta 9x9 el numero debe ser impar): ";
        cin >> tamaño;

        //validacion
        if (tamaño % 2 == 1 && tamaño >= 3 && tamaño <= 9) {
            datoCorrecto = true;
        } else {

            cout << "Digite un valor correcto (3, 5, 7, 9)" << endl;
        }
    }


}


void crearEstructura(){

    punteroMatriz = new int*[tamaño]; //reservamos memoria para las filas
    for(int i = 0 ;i < tamaño ; i++){
        punteroMatriz[i] = new int [tamaño];//reservamos memoria para las columnas
    }

}


void llenarEstructura(){

    int variableDeLLenado = 1; int centro;

    centro = tamaño/2;

    for(int i = 0 ; i <tamaño ; i++){
        for(int j = 0; j < tamaño ; j++){

            if( centro  == i  && centro  == j ){
                punteroMatriz[i][j]=0;

            }else{
            punteroMatriz[i][j]=variableDeLLenado;
            variableDeLLenado++;
            }
        }
    }
}

void mostrarMatriz(int **punteroMatriz,int tamaño){

    for(int i = 0 ; i <tamaño ; i++){
        for(int j = 0; j < tamaño ; j++){

           // cout<<punteroMatriz[i][j];
             cout<<" "<<*(*(punteroMatriz+i)+j)<<" "; //cualquiera de las 2 formas nos sirve


        }
        cout<<endl;
}

}

void rotarMatriz(int **punteroMatriz){

}





