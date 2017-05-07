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
#include "VectorDinamico.h"

using namespace std;
int main() {
  const int INICIAL = 6;
  cout << "Se crea un vector con tamaño inicial " << INICIAL << "." << endl;
  VectorDinamico inicial(INICIAL);

  cout << "Se procede a leer datos: " << endl;
  cout << "Acaba cuando se introduzca -1" << endl;

  TipoBase dato;
  cout << "Introduzca un dato: ";
  cin >> dato;
  while(dato != -1){
    inicial.AniadirValor (dato);
    cout << "Introduzca un dato: ";
    cin >> dato;
  }
  inicial.ImprimeVector("El contenido del vector es: ");

  cout << "Copiando el vector anterior en otro mediante el constructor de copia"
  << endl << endl;

  VectorDinamico copia = inicial;

  if(inicial == copia)
    cout << "El vector inicial y el de copia son iguales." << endl;
  else
    cout << "El vector inicial y el de copia son diferentes." << endl;
  cout << "--------------------------------------------------------------------"
       << endl << endl;
  
  cout << "Introduccion de datos para el vector copia" << endl;
  cout << "Introduzca un dato: ";
  cin >> dato;
  
  while(dato != -1){
    copia.AniadirValor(dato);
    cout << "Introduzca un dato: ";
    cin >> dato;
  }

  if(inicial > copia)
    cout << "El vector inicial es mas grande que el de copia." << endl;
  else
    cout << "El vector inicial es mas pequeño que el de copia." << endl;
  cout << "--------------------------------------------------------------------"
      << endl << endl;
  
  cout << "Se le añade el valor 13 al vector inicial" << endl;
  inicial.AniadirValor(13);

  if(inicial > copia)
    cout << "El vector inicial es mas grande que el de copia." << endl;
  else
    cout << "El vector inicial es mas pequeño que el de copia." << endl;
  cout << "--------------------------------------------------------------------"
      << endl << endl;

  inicial.ImprimeVector("El contenido del vector inicial es: ");
  copia.ImprimeVector("El contenido del vector copia es: ");

  return (0);
}
