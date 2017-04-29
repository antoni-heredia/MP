#include <iostream>
#include "Matriz2D_1_Asignacion-Acceso.h"
using namespace std;
/*
 El contructor vacio se encargara de crear una matriz vacia. Es decir
 sin tamaño ni  elementos
 No recibe nada.
*/
Matriz2D_1_Asignacion::Matriz2D_1_Asignacion(void):matriz(0),fils(0),
  cols(0){}

/*
 Este constructor crea una matriz cuadrada
 Recibe un int que indica el numero de filas y columnas
*/
Matriz2D_1_Asignacion::Matriz2D_1_Asignacion(int num):fils(num),
  cols(num){
  ReservaMemoria(num, num);
}

/*
 Este constructor crea una matriz rectangular
 Recibe un int con el numero de filas (fils) y otro int con el numero de
 columnas(cols)
*/
Matriz2D_1_Asignacion::Matriz2D_1_Asignacion(int filas, int colms):
  fils(filas),cols(colms){
  ReservaMemoria(filas, colms);
}

/*
 Este constructor crea una matriz rectangular y ademas la inicializa con
 un dato pasado por el argumento
 Recibe un int con el numero de filas (fils), otro int con el numero de
 columnas(cols) y un TipoBase que indica el dato con el que se inicializara
*/
Matriz2D_1_Asignacion::Matriz2D_1_Asignacion(int filas, int colms,
  TipoBase dato):fils(filas),cols(colms){
  ReservaMemoria(fils, cols);
  InicializarDato(dato);
}

/*
 Este constructor crea una copia profunda de otra Matriz2D_1_Asignacion
 Recibe una Matriz2D_1_Asignacion que seara de la cual se copien los
 datos
*/
Matriz2D_1_Asignacion::Matriz2D_1_Asignacion(
  Matriz2D_1_Asignacion & otra){
    ReservaMemoria(otra.fils, otra.cols);
    CopiarDatos(otra);
}


/*
  El destructor se encargara de liberar la memoria ocupada por la matriz
  No recibe nada
*/
Matriz2D_1_Asignacion::~Matriz2D_1_Asignacion(void){
  LiberarMemoria();
}
// Operador de asignacion
Matriz2D_1_Asignacion & Matriz2D_1_Asignacion :: operator =
(const Matriz2D_1_Asignacion & otro){

  if(this != &otro){

    LiberarMemoria();

    ReservaMemoria(otro.fils, otro.cols);

    CopiarDatos(otro);
  }
  return (*this);
}

// Operador de asignacion
Matriz2D_1_Asignacion & Matriz2D_1_Asignacion :: operator =
(const TipoBase & valor){
  InicializarDato(valor);
}

TipoBase & Matriz2D_1_Asignacion :: operator () (const int fila, const int colu)
{
  return (matriz[fila][colu]);
}

/*
  El metodo devolvera si la matriz esta vacia
  No recibe nada
  Devuelve un bool con el resultado de la comprobacion
*/
bool Matriz2D_1_Asignacion::EstaVacia(void){
  return (matriz == 0);
}

/*
  Modifica el valor de un elemento en concreto de la matriz
  Recibe:
    -fila un int con el numero de la fila donde se encuentra la casilla
    -col un int con el numero de la columna donde se encuentra la columna
    -val un TipoBase con el valor que se quiere poner en la casilla indicada
*/
void Matriz2D_1_Asignacion::ModificarValor (int fila, int col, TipoBase val){
  matriz[fila][col] = val;
}

/*
  El metodo devuelve el valor de la casilla que queremos
  Recibe:
    -fila un int que indica el numero de la fila en la que se encuentra
    -col un int que indica el numero de la columna en la que se encuentra
*/
TipoBase Matriz2D_1_Asignacion::LeerValor (int fila, int col){
  return matriz[fila][col];
}


/*
 El metodo inicializara la matriz, tenga el tamaño que tenga con un dato
 Recibe un TipoBase que sera el dato con el que se inicializara
 No devuelve nada
*/
void Matriz2D_1_Asignacion::InicializarDato(TipoBase dato){
  for(int f = 0; f < fils; f++)
    for(int c = 0; c < cols; c++)
      matriz[f][c] = dato;
}

/*
  El metodo muestra el contenido de la matriz
  No recibe nada
  No devuelve nada
*/
void Matriz2D_1_Asignacion::Mostrar(void){
  if(matriz != 0)
    for(int f = 0; f < fils; f++){
      for(int c = 0; c < cols; c++)
        cout << matriz[f][c] << " ";
      cout << endl;
    }


}
/*
 El metodo reservara memoria para un numero de filas y columnas indicados
 en los argumentos
 Recibe int fils que sera el numero de filas y int cols que es el numero
 de columnas
 No devuelve nada
*/
void Matriz2D_1_Asignacion::ReservaMemoria(int filas, int colms){
  matriz = new TipoBase * [filas];
  for(int f = 0; f < filas; f++)
    matriz[f] = new TipoBase[colms];
}

/*
  El metodo copia todos los datos de una matriz a otra
  Recibe:
    -otra una Matriz2D_1_Asignacion de la cual se copiara los datos
*/
void Matriz2D_1_Asignacion::CopiarDatos(const Matriz2D_1_Asignacion & otra){

  fils = otra.fils;
  cols = otra.cols;
  for(int f = 0; f < fils; f++){
    for(int c = 0; c < cols; c++)
      matriz[f][c] = otra.matriz[f][c];
  }

}
void Matriz2D_1_Asignacion::LiberarMemoria(void){
  for(int f = 0; f < fils; f++)
    delete [] matriz[f];
  delete [] matriz;
}
