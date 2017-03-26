/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 6
//
/*
*/
/*********************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include "vector_dinamico.h"

using namespace std;

int main(int argc, char * argv[])
{
  //Capacidad inicial del vector
  int cap = CANT_CADENAS;
  //Cantidad de cadenas actualmente
  int cant = 0;

  //vector dinamico donde se guardaran las cadenas
  char * * cadenas =  new char * [cap];
  string cadena;

  while (getline (cin, cadena)) {
    
    if(cant == cap)
      cadenas =
      RedimensionaVectorCadenas(cadenas,TipoRedimension::DeUnoEnUno,cap);
    char * cadena_tmp = new  char  [cadena.length()+1];
    int i;
    for( i = 0; i < cadena.length();i++)
      cadena_tmp[i] = cadena[i];

    cadena_tmp[i] = '\0';
    cadenas[cant] = cadena_tmp;
    cout << cadenas[cant] << endl;
    cant++;

  }
  for(int i = 0; i < cant ;i++)
    cout << cadenas[i] <<endl;

}
