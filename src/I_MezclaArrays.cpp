/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 5
//
/*
*/
/*********************************************************************/

#include <iostream>
#include <cstring>
#include "matriz_numeros.h"
using namespace std;

/*********************************************************************/


int main()
{
  const int MAX = 256;
  int array[MAX];

  RellenaVector(array,256,0,100);

  char mensaje[MAX];
  cout << "Introduzca el mensaje a mostrar: ";
  cin.getline(mensaje,MAX);

  MuestraVector(mensaje,array,MAX,10);
  cout << endl << endl;
	return (0);
}

/*********************************************************************/
