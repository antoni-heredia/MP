#include <iostream>
#include "Matriz2D_1.h"
#include "GeneradorAleatorioEnteros.h"

using namespace std;

/*
  Devuelve una Matriz2D vacia pero con tantas filas y columnas como se haya
  indicado.
  fils -> Nº de filas
  cols -> Nº de columnas
*/
Matriz2D  CreaMatriz2D (int fils, int cols){
  //Declamos la mariz a devolver
  Matriz2D  matriz;

  //Creamos la matriz con el numero de filas dado
  matriz.datos = new int * [fils];

  //Gardamos los datos del numero de filas y columnas
  matriz.fils=fils;
  matriz.cols=cols;

  //Recorremos todas las filas de la matriz para inicializar la columna
  for(int f = 0; f < fils; f++)
    matriz.datos[f] = new int [cols];

  //Devolvemos la matriz
  return matriz;
}

/*
  Libera todas las posiciones de memoria de los datos de un Matriz2D

  matriz-> matriz que se quiere liberar la memoria
*/
void  LiberaMatriz (Matriz2D  &matriz){

  //Guardamos el numero de filas ya que tenemos que recorrerlas para eliminarlas
  int fils=matriz.fils;

  //Reseteamos el valor de las filas y las columnas
  matriz.fils = 0;
  matriz.cols = 0;

  //Recorremos todas las filas de la matriz para liberar las  columnas
  for(int f = 0; f < fils; f++)
    delete [] matriz.datos[f];

  //Liberamos todas las filas
  delete matriz.datos;

}

/*
  Devuelve una Matriz2D con tantas filas y columnas como se haya
  indicado y ademas va pidiendo los valores para llenarla
  fils -> Nº de filas
  cols -> Nº de columnas
*/
Matriz2D  CreaMatriz2DValores (int fils, int cols){

  //Declamos la mariz a devolver creandola con un metodo ya creado anteriormente
  Matriz2D  matriz = CreaMatriz2D(fils,cols);
  cout << "Introduzca los datos de la matriz: " << endl;
  for(int f = 0; f < fils; f++)
    for(int c = 0; c < cols; c++){
      cout << "["<<f << "," << c << "]: ";
      cin >> matriz.datos[f][c];
    }

  return matriz;
}


/*
  Devuelve una Matriz2D con tantas filas y columnas como se haya
  indicado y ademas la rellena con valores aleatorios
  fils -> Nº de filas
  cols -> Nº de columnas
*/
Matriz2D  CreaMatriz2DValoresAleatorios(int fils, int cols){


  GeneradorAleatorioEnteros generador(0,100);

  //Declamos la mariz a devolver creandola con un metodo ya creado anteriormente
  Matriz2D  matriz = CreaMatriz2D(fils,cols);

  for(int f = 0; f < fils; f++)
    for(int c = 0; c < cols; c++){
      matriz.datos[f][c] = generador.Siguiente();
    }

  return matriz;
}
/*
  Muestra todos los datos de la matriz

  matriz -> matriz de la que se quiere mostrar los datos
*/

void MuestraMatriz2D(Matriz2D matriz){
  for(int f = 0; f < matriz.fils; f++){
    for(int c = 0; c < matriz.cols; c++)
      cout << matriz.datos[f][c] << " ";
    cout << endl;
  }
  if(matriz.fils == 0)
    cout << "La matriz no tiene ningun dato almacenado" << endl;
}



/*
  Devuelve una copia de la matriz del argumento
  matriz -> matriz que vamos a copiar a otra matriz
*/
Matriz2D CopiaProfunda(Matriz2D matriz){
  Matriz2D matriz_copia = CreaMatriz2D(matriz.fils, matriz.cols);

  for(int f = 0; f < matriz.fils; f++){
    for(int c = 0; c < matriz.cols; c++)
      matriz_copia.datos[f][c] = matriz.datos[f][c];
  }

  return matriz_copia;
}


/*
  Devuelve una matriz que es la extracion de una matriz dada
  matriz -> matriz desde donde vamos a extraer los datos
  f_origen -> fila desde donde se empieza a copiar
  c_origen -> columna desde donde se empieza a copiar
  f_fin -> fila donde se acaba de copiar
  c_fin -> columna donde se acaba de copiar
*/
Matriz2D ExtraerMatriz(Matriz2D matriz,
                      int f_origen,int c_origen,int f_fin,int c_fin){
  //Creamos la matriz donde vamos a copiar los datos
  Matriz2D matriz_extraida = CreaMatriz2D(f_fin-f_origen+1, c_fin-c_origen+1);

  //Comprobamos que los parametros que hemos pasado son correctos
  if(f_origen >= 0 && f_origen < f_fin && f_fin < matriz.fils &&
     c_origen >= 0 && c_origen < c_fin && c_fin < matriz.cols){

    //Variable para apuntar a la primera fila de la nueva matriz
    int f_ext = 0;

    //Recorremos las filas desde donde indica el argumento f_origen hasta donde
    //indica el argumento de f_fin
    for(int f = f_origen; f <= f_fin; f++){

      //Variable para apuntar a la primera columna de la nueva fila que estamos
      //recorriendo
      int c_ext = 0;

      //Recorremos las columnas desde donde indica el argumento c_origen hasta donde
      //indica el argumento de c_fin
      for(int c = c_origen; c <= c_fin; c++){

        //Copiamos los datos de una matriz a otra
        matriz_extraida.datos[f_ext][c_ext] = matriz.datos[f][c];

        c_ext++;
      }

      f_ext ++;
    }
  }
  else{
    //Si los argumentos son invalidos nos salimos del programa
    cout << "Los argumentos para extraer la matriz son invalidos...." << endl;
    cout << "Saliendo...." << endl;
    exit(1);
  }

  //Devolvemos la nueva matriz extraida de la matriz original
  return matriz_extraida;
}


/*
  Elimina las filas de una matriz
  matriz -> matriz a la que se le va a eliminar la fila
  fila -> la fila que se va a eliminarlas
*/

Matriz2D EliminaFila(Matriz2D matriz, int fila){
  Matriz2D nueva_matriz = CreaMatriz2D(matriz.fils-1,matriz.cols);

  int fila_ins = 0;
  if( fila >= 0 && fila<matriz.fils ){

    /*
      Hago dos bucles for para evitar tener if dentro del for y que se ejecute
      siempre. Recorro hasta antes de llegar a la fila que se quiere eliminar y
      luego recorro a partir de la posicion siguiente a esa fila. Asi evito
      introducirla a la nueva matriz
    */

    for(int f = 0; f < fila; f++){
      for(int c = 0; c < matriz.cols; c++)
        nueva_matriz.datos[fila_ins][c] = matriz.datos[f][c];
      fila_ins++;
    }

    for(int f = fila+1; f < matriz.fils; f++){
      for(int c = 0; c < matriz.cols; c++)
        nueva_matriz.datos[fila_ins][c] = matriz.datos[f][c];
      fila_ins++;
    }

  }else{
    //Si los argumentos son invalidos nos salimos del programa
    cout << "El numero de fila es invalido...." << endl;
    cout << "Saliendo...." << endl;
    exit(1);
  }

  return nueva_matriz;
}


/*
  Elimina la columna de una matriz
  matriz -> matriz a la que se le va a eliminar la fila
  columna -> la columna que se va a eliminar
*/

Matriz2D EliminaColumna(Matriz2D matriz, int columna){
  Matriz2D nueva_matriz = CreaMatriz2D(matriz.fils,matriz.cols-1);

  if( columna >= 0 && columna<matriz.cols ){

    /*
      Hago dos bucles for para evitar tener if dentro del for y que se ejecute
      siempre. Recorro hasta antes de llegar a la columna que se quiere eliminar y
      luego recorro a partir de la posicion siguiente a esa columna. Asi evito
      introducirla a la nueva matriz
    */

    for(int f = 0; f < matriz.fils; f++){
      int cols_ins = 0;

      for(int c = 0; c < columna; c++){
        nueva_matriz.datos[f][cols_ins] = matriz.datos[f][c];
        cols_ins++;
      }

      for(int c = cols_ins+1; c < matriz.cols; c++){
        nueva_matriz.datos[f][cols_ins] = matriz.datos[f][c];
        cols_ins++;
      }
    }

  }else{
    //Si los argumentos son invalidos nos salimos del programa
    cout << "El numero de columna es invalido...." << endl;
    cout << "Saliendo...." << endl;
    exit(1);
  }

  return nueva_matriz;
}

/*
  Se devuelve la matriz traspuesta de la matriz pasada

  matriz-> La matriz que queremos trasponer

*/
Matriz2D TrasponerMatriz(Matriz2D matriz){

  Matriz2D traspuesta = CreaMatriz2D(matriz.cols, matriz.fils);

  //Recorremos todas las filas y las columnas, pero cambiamos la posicion
  //de los columnas por el de las filas y viceversa.
  for(int f = 0; f < matriz.fils; f++){
    for(int c = 0; c < matriz.cols; c++)
      traspuesta.datos[c][f] = matriz.datos[f][c];
  }
  return traspuesta;
}
/*
  Intercambia la posicion de todas las filas. Es decir, la ultima pasa a ser la
  primera y la primera la ultima

  matriz -> matriz a la que se le va  intercmabiar las filas
*/
Matriz2D InvierteFilas(Matriz2D matriz){
  Matriz2D invertida = CreaMatriz2D(matriz.fils, matriz.cols);
  int fin = matriz.fils-1;

  //Recorremos todas las filas y las columnas y empezamos a guardar del final al
  //principio
  for(int f = 0; f < matriz.fils; f++){
    for(int c = 0; c < matriz.cols; c++)
      invertida.datos[fin][c] = matriz.datos[f][c];
    fin--;
  }

  return invertida;
}
