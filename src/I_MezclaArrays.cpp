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
#include "matriz_numeros.h"
using namespace std;

/*********************************************************************/


int main()
{
  const int MAX = 256;
  int v1[MAX];

  RellenaVector(v1,MAX,0,100);

  char mensaje[MAX];
  cout << "Introduzca el mensaje a mostrar: ";
  cin.getline(mensaje,MAX);

  MuestraVector(mensaje,v1,MAX,10);

  int v2[MAX];
  RellenaVector(v2,MAX,0,100);
  MuestraVector(mensaje,v2,MAX,10);

  int v3[MAX*2];
  MezclaVectores(v3,v1,MAX,v2,MAX);
  MuestraVector(mensaje,v3,MAX*2,10);

  cout << endl << endl;
	return (0);
}

/*********************************************************************/
