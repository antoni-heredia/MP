/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// PRÁCTICA 4
//
/*
  Lee una cadena y la imprime saltandose la primera palabra
*/
/*********************************************************************/

#include <iostream>
#include <cstring>
#include "MiCadenaClasica.h"
using namespace std;

/*********************************************************************/


int main()
{
  const int LONGITUD = 256;
  char cadena[LONGITUD];

  //Pedimos que se introduzca la cadena
  cout << "Introduce una cadena: ";
  cin.getline(cadena,LONGITUD);

  //Guardamos la posicion donde esta el primer espacio
  int longitud = longitud_cadena(cadena);


  cout << "La longitud de la cadena es: " << longitud << endl;

	return (0);
}

/*********************************************************************/
