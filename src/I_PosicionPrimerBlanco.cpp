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
  Lee una cadena y localiza la posición del primer carácter espacio
*/
/*********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/*********************************************************************/
//Nos devuelve la posicion del primer caracter espacio
int PosicionPrimerEspacio(char *cadena, int utilizados){
  int pos = 0;
  char caracter = *(cadena);
  //Recorremos mientras queden elementos y el caracter sea distinto de
  //espacio
  while(pos<utilizados && caracter != ' ' ){
    pos++;
    caracter = *(cadena+pos);
  }
  return pos;
}
/*********************************************************************/


int main()
{
  const int LONGITUD = 256;
  char cadena[LONGITUD];

  //Pedimos que se introduzca la cadena
  cout << "Introduce una cadena: ";
  cin.getline(cadena,LONGITUD);

  //Mostramos la posicion donde se encuentra el espacio en la cadena.
  cout << "La posicion del primer espacio en la cadena es: " <<
  PosicionPrimerEspacio(cadena, strlen(cadena)) << endl;

	return (0);
}

/*********************************************************************/
