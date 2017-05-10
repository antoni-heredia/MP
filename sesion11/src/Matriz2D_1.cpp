/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 11
//
/*
  Fichero donde se encuentra el codigo de los metodos de la clase
  Matriz2D_1
 */
/*********************************************************************/

#include <iostream>
#include "Matriz2D_1.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//                               Clase matriz                                //
///////////////////////////////////////////////////////////////////////////////

//Metodos publicos

///////////////////////////////////////////////////////////////////////////////

/*
 El contructor vacio se encargara de crear una matriz vacia. Es decir
 sin tamaño ni  elementos
 No recibe nada.
*/
Matriz2D_1::Matriz2D_1(void):matriz(0),fils(0),
  cols(0){}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
 Este constructor crea una matriz cuadrada
 Recibe un int que indica el numero de filas y columnas
*/
Matriz2D_1::Matriz2D_1(int num):fils(num),
  cols(num){
  ReservaMemoria(num, num);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
 Este constructor crea una matriz rectangular
 Recibe un int con el numero de filas (fils) y otro int con el numero de
 columnas(cols)
*/
Matriz2D_1::Matriz2D_1(int filas, int colms):
  fils(filas),cols(colms){
  ReservaMemoria(filas, colms);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
 Este constructor crea una matriz rectangular y ademas la inicializa con
 un dato pasado por el argumento
 Recibe un int con el numero de filas (fils), otro int con el numero de
 columnas(cols) y un TipoBase que indica el dato con el que se inicializara
*/
Matriz2D_1::Matriz2D_1(int filas, int colms,
  TipoBase dato):fils(filas),cols(colms){
  ReservaMemoria(fils, cols);
  InicializarDato(dato);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
 Este constructor crea una copia profunda de otra Matriz2D_1
 Recibe una Matriz2D_1 que seara de la cual se copien los
 datos
*/
Matriz2D_1::Matriz2D_1(const Matriz2D_1 & otra){
    ReservaMemoria(otra.fils, otra.cols);
    CopiarDatos(otra);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El destructor se encargara de liberar la memoria ocupada por la matriz
  No recibe nada
*/
Matriz2D_1::~Matriz2D_1(void){
  LiberarMemoria();
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo devolvera si la matriz esta vacia
  No recibe nada
  Devuelve un bool con el resultado de la comprobacion
*/
bool Matriz2D_1::EstaVacia(void){
  return (matriz == 0);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
int Matriz2D_1 :: Filas(void) const {
  return fils;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

int Matriz2D_1 :: Columnas(void) const {
  return cols;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador de asignacion
Matriz2D_1 & Matriz2D_1 :: operator = (const Matriz2D_1 & otro){

  if(this != &otro){
    LiberarMemoria();

    ReservaMemoria(otro.fils, otro.cols);

    CopiarDatos(otro);
  }
  return (*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador de asignacion
Matriz2D_1 & Matriz2D_1 :: operator = (const TipoBase & valor){
  InicializarDato(valor);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

//Operador de acceso ()
TipoBase & Matriz2D_1 :: operator () (const int fila, const int colu)
{
  return (matriz[fila][colu]);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador unario +
Matriz2D_1 Matriz2D_1:: operator + (void)
{
  //Se devuelve la matriz tal y como es
  return (*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

//Operador unario -
Matriz2D_1 Matriz2D_1:: operator - (void)
{

  //Se crea una matriz temporal en la que se guardaran los datos modificados
  Matriz2D_1 tmp (fils, cols);
  
  //Se compian todos los datos pero con el signo cambiado
  for(int f = 0; f < fils; f++)
    for(int c = 0; c < cols; c++)
      tmp.matriz[f][c] = -matriz[f][c];

  return (tmp);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo muestra el contenido de la matriz
  No recibe nada
  No devuelve nada
*/
void Matriz2D_1::Mostrar(void){
    for(int f = 0; f < fils; f++){
      for(int c = 0; c < cols; c++)
        cout << matriz[f][c] << " ";
      cout << endl;
    }


}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador binario + (1)
Matriz2D_1 operator + (const Matriz2D_1 & p1, const Matriz2D_1 & p2) {
  Matriz2D_1 tmp;

  if(p1.fils == p2.fils && p1.cols == p2.cols){
    tmp.ReservaMemoria(p1.fils, p2.cols);
    for(int f = 0; f < p1.fils; f++)
      for(int c = 0; c < p1.cols; c++){
        tmp.matriz[f][c] = p1.matriz[f][c] + p2.matriz[f][c];
      }
  }
  
  return (tmp);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador binario + (2)
Matriz2D_1 operator + (const TipoBase c, const Matriz2D_1 & p){
  // Crear Matriz2D_1 constante
  Matriz2D_1 matriz_cte = MatrizConstante (c, p.fils, p.cols);
  Matriz2D_1 tmp (p.fils, p.cols);
  tmp = matriz_cte + p; // Producto de dos Matriz2D_1s
  // Llama a la versión (1)
  return (tmp);
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador binario + (3)
Matriz2D_1 operator + (const Matriz2D_1 & p, const TipoBase c){
  return (c + p); // Llama a la versión (2)
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador binario - (1)
Matriz2D_1 operator - (const Matriz2D_1 & p1, const Matriz2D_1 & p2) {
  Matriz2D_1 tmp;

  if(p1.fils == p2.fils && p1.cols == p2.cols){
    tmp.ReservaMemoria(p1.fils, p2.cols);
    for(int f = 0; f < p1.fils; f++)
      for(int c = 0; c < p1.cols; c++){
        tmp.matriz[f][c] = p1.matriz[f][c] - p2.matriz[f][c];
      }
  }
  
  return (tmp);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador binario - (2)
Matriz2D_1 operator - (const TipoBase c, const Matriz2D_1 & p){
  // Crear Matriz2D_1 constante
  Matriz2D_1 matriz_cte = MatrizConstante (c, p.fils, p.cols);
  Matriz2D_1 tmp (p.fils, p.cols);
  tmp = matriz_cte - p; // Producto de dos Matriz2D_1s
  // Llama a la versión (1)
  return (tmp);
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador binario - (3)
Matriz2D_1 operator - (const Matriz2D_1 & p, const TipoBase c){
  return (c - p); // Llama a la versión (2)
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador +=
Matriz2D_1 & Matriz2D_1 :: operator += (const TipoBase & otro) {
  (*this) = (*this) + otro; // operador binario +
  return (*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador -=
Matriz2D_1 & Matriz2D_1 :: operator -= (const TipoBase & otro)
{
  (*this) = (*this) - otro; // Operador binario -
  return (*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Operador ==
bool Matriz2D_1 :: operator == (const Matriz2D_1 & otro){
 
  bool iguales = (fils  == otro.fils && cols == otro.cols);
  
  if (iguales) {
    for(int f = 0; f < fils && iguales ; f++)
      for(int c = 0; c < cols && iguales; c++)
        if(matriz[f][c] != otro.matriz[f][c])
          iguales = false;  
  }

  return (iguales);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador !=
bool Matriz2D_1 :: operator != (const Matriz2D_1 & otro){
 
  return (!(*this == otro));

}

///////////////////////////////////////////////////////////////////////////////

//Metodos privados

///////////////////////////////////////////////////////////////////////////////

/*
 El metodo reservara memoria para un numero de filas y columnas indicados
 en los argumentos
 Recibe int fils que sera el numero de filas y int cols que es el numero
 de columnas
 No devuelve nada
*/
void Matriz2D_1::ReservaMemoria(int filas, int colms){
  matriz = new TipoBase * [filas];
  fils = filas;
  cols = colms;
  for(int f = 0; f < filas; f++)
    matriz[f] = new TipoBase[colms];
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo copia todos los datos de una matriz a otra
  Recibe:
    -otra una Matriz2D_1 de la cual se copiara los datos
*/
void Matriz2D_1::CopiarDatos(const Matriz2D_1 & otra){

  fils = otra.fils;
  cols = otra.cols;

  for(int f = 0; f < fils; f++){
    for(int c = 0; c < cols; c++)
      matriz[f][c] = otra.matriz[f][c];
  }

}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
 El metodo inicializara la matriz, tenga el tamaño que tenga con un dato
 Recibe un TipoBase que sera el dato con el que se inicializara
 No devuelve nada
*/
void Matriz2D_1::InicializarDato(TipoBase dato){
  for(int f = 0; f < fils; f++)
    for(int c = 0; c < cols; c++)
      matriz[f][c] = dato;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void Matriz2D_1::LiberarMemoria(void){
  if(matriz){
      for(int f = 0; f < fils; f++)
      delete [] matriz[f];
    delete [] matriz;
    matriz = 0;
  }
  
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                            Otras funciones                                //
///////////////////////////////////////////////////////////////////////////////

// Muestra el contenido de una matriz, precedido del mensaje "msg"
void PintaMatriz (const Matriz2D_1 m, const char * const msg)
{
	cout << endl; 
	cout << "--------------------------------------------------" << endl;
	cout << msg << endl;
	
	for (int f=0; f<m.Filas(); f++) {
		
		for (int c=0; c<m.Columnas(); c++){
      TipoBase i = (f,c);
			cout << i << " ";	
      
    }
		cout << endl;
	}
	cout << "--------------------------------------------------" << endl;  
	cout << endl;
}

// Devuelve un poliniomio constante
Matriz2D_1 MatrizConstante (const TipoBase valor, int fils, int cols)
{
  Matriz2D_1 maz_cte (fils, cols, valor); // constructor

  return (maz_cte); // Devuelve una copia del objeto local
}