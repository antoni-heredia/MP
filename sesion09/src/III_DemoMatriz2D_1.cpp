/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 9
//
/*
 */
/*********************************************************************/

#include <iostream>
#include "Matriz2D_1_ConstructorCopia.h"

using namespace std;
int main() {
  cout << "Creando matriz nula...." << endl;
  Matriz2D_1_ConstructorCopia vacia;
  cout << "Creando matriz vacia...." << endl;

  if(vacia.EstaVacia())
    cout << "La matriz esta vacia..." << endl;
  else
    cout << "La matriz no esta vacia..." << endl;

  Matriz2D_1_ConstructorCopia cuadrada(10);
  cout << "Creando matriz cuadrada...." << endl;
  cuadrada.InicializarDato(2);
  cout << "Inicializando a 2" << endl;
  cout << "Mostrando datos: " << endl;
  cuadrada.Mostrar();

  Matriz2D_1_ConstructorCopia rectangular(2,6);
  cout << "Creando matriz rectangular...." << endl;
  rectangular.InicializarDato(2);
  cout << "Inicializando a 2" << endl;
  cout << "Mostrando datos: " << endl;
  rectangular.Mostrar();

  Matriz2D_1_ConstructorCopia copia(rectangular);
  cout << "Creando matriz copia de la rectangular" << endl;
  copia.Mostrar();
  cout << "Modificando el elemento [1,1] a el valor 13" << endl;
  copia.ModificarValor(1,1,13);
  cout << "Mostran matriz copia despues de modificarla" << endl;
  copia.Mostrar();

  return (0);
}
