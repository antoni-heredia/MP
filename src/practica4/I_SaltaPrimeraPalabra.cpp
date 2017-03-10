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

  //Guardamos la posicion donde esta el primer espacio
  int posicion = PosicionPrimerEspacio(cadena, strlen(cadena));

  //La sobrecarga del operador << nos permite imprimir la cadena a partir de la
  //posicion despues del espacio hasta el final de la cadena clasica
  cout << "La frase a partir del primer espacio es: " << &cadena[posicion+1]
   << endl;

	return (0);
}

/*********************************************************************/
