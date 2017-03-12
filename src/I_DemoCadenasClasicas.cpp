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


  //Mostramos la longitud de la cadena
  cout << "La longitud de la cadena es: " << longitud << endl;

  //Mostramos si es un palindrdomo
  if(Palindromo(cadena))
    cout << "La cadena es un palindromo" << endl;
  else
    cout << "La cadena no es un palindromo" << endl;


  char cadena2[LONGITUD];
  cout << "Introduce otra cadena: ";
  cin.getline(cadena2,LONGITUD);

  //Se compara el tamaño de las cadenas
  if(comparar_cadenas(cadena,cadena2)>0)
    cout << "La primera cadena introducida es mayor" << endl;
  else if(comparar_cadenas(cadena,cadena2)<0)
    cout << "La primera cadena introducida es menor" << endl;
  else
    cout << "Las dos cadenas son iguales" << endl;

  //SE copia una cadena en otra
  copiar_cadena(cadena,cadena2);
  cout << "El resultado de copiar la segunda cadena en la primera es: "
  << cadena << endl;

  char cadena3[LONGITUD];
  cout << "Introduce otra cadena: ";
  cin.getline(cadena3,LONGITUD);

  //Se concatena las cadenas
  encadenar_cadena(cadena,cadena3);
  cout << "El resultado de encadenar la primera cadena con esta es: "
  << cadena << endl;


  int inicio,longcad;
  cout << "Inicio de la extración de la cadena: ";
  cin >> inicio;
  cout << "Longitud de la cadena a extraer: ";

  //Se crea una subcadena con los datos dados
  cin >> longcad;
  char * cadena_extr = extraer_subcadena(cadena,inicio, longcad);

  cout << "La cadena reultado es: " << cadena_extr << endl;

  //Se invierte la cadena
  char * cad_inver = invertir_cadena(cadena);
  cout << "La cadena invertida es: " << cad_inver << endl;
  return (0);
}

/*********************************************************************/
