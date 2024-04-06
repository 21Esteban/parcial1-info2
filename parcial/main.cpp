#include"funciones.h"

//Variables Globales

int **punteroMatriz,tamaño; int *reglaK;

//cerradura K

int main()
{

    //pedimos los datos para rellenar la estructura M
    pedirDatos();
    //creamos la estructura M
    crearEstructura();
    //rellenamos la estructura M
    llenarEstructura();
    //mostramos la matriz;
    mostrarMatriz(punteroMatriz,tamaño); //podemos comentar la matriz orginal M
    pedirClaveK();




    //liberamos la memoria usada para las columnas
    for(int i = 0; i<tamaño ; i++){
        delete[]  punteroMatriz[i] ;
    }

    //ahora liberamos las filas

    delete[] punteroMatriz;

    return 0;
    

}













//Funciones para validar la regla K

//El enfoque que vamos a utilizar es , el usuario va a ingresar la fila y la columna , de acuerdo a eso vamos a hacer una matriz de prueba para validar si podemos usar en la primera matriz la matriz minima (3x3) si el usuario da en el centro de la matriz entonces la primera estructura ya no va a ser de 3x3 sino de 5x5 y asi sucesivamente

void validarReglaK(){

   //definimos estas variables y las pasamos por referencia en la funcion pedir clave porque las necesitamos en esta funcion.





    //Funcion que valida la regla dada pra la primera estructura





}


/*void pedirClaveK(){
    int tamañok ;
    int fila;
    int columna;
    int valor;

    cout<<"----Ingrese la clave para generar una cerradura para esa Clave---- \n que tamaño va a tener la cerradura : ";
    cin>>tamañok;

    //generamos el arreglo que va a contener la regla K

    reglaK = new int[tamañok+1];


    for (int i = 0 ; i <= tamañok ; i ++){

        if(i == 0){
            bool filaValida = false;
            int PrimeraVez = true;

            while(!filaValida){
                cout<<(PrimeraVez ? "Ingrese la fila : " : "La fila debe ser un numero positivo")<<endl;
                cin>>fila;
                if(fila > 0){
                    reglaK[0] = fila;
                    filaValida = true;
                }
                else {
                    PrimeraVez = false;
                }


            }
        }


        else if(i == 1){
            bool columnaValida = false;
            int PrimeraVez = true;

            while(!columnaValida){
                cout<<(PrimeraVez ? "Ingrese la columna : " : "La columna debe ser un numero positivo")<<endl;
                cin>>columna;
                if(columna > 0){
                    reglaK[1] = columna;
                    columnaValida = true;
                }
                else {
                    PrimeraVez = false;
                }



            }

        }

        else{
            bool valorValido = false;
            int PrimeraVez = true;

            while(!valorValido){
                cout<<(PrimeraVez ? "Ingrese el valor o condicion con respecto a la siguiente estructura : " : "la condicion debe estar en el rango -1 , 0 , 1")<<endl;
                cin>>valor;
                if(valor > 0){
                    reglaK[i] = valor;
                    valorValido = true;
                }
                else {
                    PrimeraVez = false;
                }


            }

        }



    }

}
*/






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

