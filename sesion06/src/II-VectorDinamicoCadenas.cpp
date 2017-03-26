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

  //Leemos hasta el final del fichero
  while (getline (cin, cadena)) {

    //Mientras que haya capacidad no hay por que redimensionar
    if(cant == cap)
      cadenas =
      RedimensionaVectorCadenas(cadenas,TipoRedimension::DeUnoEnUno,cap);
    //Creamos una cadena donde guardar la linea
    char * cadena_tmp = new  char  [cadena.length()+1];
    int i;
    //Guardamos los caracteres de la linea en la cadena
    for( i = 0; i < cadena.length();i++)
      cadena_tmp[i] = cadena[i];
    //Añadimos el finalizador de cadena
    cadena_tmp[i] = '\0';
    //Guardamos la cadena
    cadenas[cant] = cadena_tmp;
    cant++;

  }

  int lineas_totales = cant;
  int lineas_no_vacias = 0;
  int parrafos = 0;
  bool fin_parrafo = true;
  for(int linea = 0; linea< lineas_totales; linea++){
    int longi = LongitudCadena(cadenas[linea]);

    if(longi != 0){
      lineas_no_vacias++;
      if(fin_parrafo){
        parrafos++;
        fin_parrafo = false;
      }
    }else
      fin_parrafo = true;

  }

  cout << "Las lineas totales han sido: " << lineas_totales << endl;
  cout << "Las lineas no vacias han sido: " << lineas_no_vacias << endl;
  cout << "El numero de parrafos ha sido: " << parrafos << endl;

}
