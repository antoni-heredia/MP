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
#include "VectorDinamico_ConstructorCopia.h"

using namespace std;
int main() {
  const int TAM_INICIAL = 6;
  cout << "Se crea un vector con tamaño inicial " << TAM_INICIAL << "." << endl;
  VectorDinamico_ConstructorCopia inicial(TAM_INICIAL);

  cout << "Se procede a leer datos: " << endl;
  cout << "Acaba cuando se introduzca -1" << endl;

  TipoBase dato;
  cout << "Introduzca un dato: ";
  cin >> dato;
  while(dato != -1){
    inicial.AniadirValor(dato);
    cout << "Introduzca un dato: ";
    cin >> dato;
  }
  inicial.ImprimeVector("El contenido del vector es: ");

  cout << "Copiando el vector anterior en otro mediante el constructor de copia"
  << endl;

  VectorDinamico_ConstructorCopia copia(inicial);
  cout << "Introduccion de datos para el vector copia" << endl;
  cout << "Introduzca un dato: ";
  cin >> dato;
  while(dato != -1){
    copia.AniadirValor(dato);
    cout << "Introduzca un dato: ";
    cin >> dato;
  }
  inicial.ImprimeVector("El contenido del vector inicial es: ");
  copia.ImprimeVector("El contenido del vector copia es: ");
  return (0);
}
