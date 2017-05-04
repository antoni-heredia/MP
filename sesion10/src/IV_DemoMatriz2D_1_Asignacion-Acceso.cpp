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
#include "Matriz2D_1_Asignacion-Acceso.h"

using namespace std;
int main() {
  cout << "Creando matriz nula...." << endl;
  Matriz2D_1_Asignacion vacia;
  cout << "Creando matriz vacia...." << endl;

  if(vacia.EstaVacia())
    cout << "La matriz esta vacia..." << endl;
  else
    cout << "La matriz no esta vacia..." << endl;

  Matriz2D_1_Asignacion cuadrada(10);
  cout << "Creando matriz cuadrada...." << endl;
  cuadrada = 2;
  cout << "Inicializando a 2" << endl;
  cout << "Mostrando datos: " << endl;
  cuadrada.Mostrar();

  Matriz2D_1_Asignacion rectangular(2,6);
  cout << "Creando matriz rectangular...." << endl;
  rectangular = 2;
  cout << "Inicializando a 2" << endl;
  cout << "Mostrando datos: " << endl;
  rectangular.Mostrar();

  Matriz2D_1_Asignacion copia;
  copia = rectangular;
  cout << "Creando matriz copia de la rectangular" << endl;
  copia.Mostrar();
  cout << "Modificando el elemento [1,1] a el valor 13" << endl;
  copia(1,1) = 13;
  cout << "Mostran matriz copia despues de modificarla" << endl;
  copia.Mostrar();

  cout << "Mostran el elemento [1,1]: " << copia(1,1) << endl;
  return (0);
}
