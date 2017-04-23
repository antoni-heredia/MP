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
#include "Lista_ConstructorCopia.h"

using namespace std;
int main() {
  cout << "Creando una lista con 4 nodos inicializados a 1..." << endl;
  Lista_ConstructorCopia lista(4,1);
  cout << "Insertamos el valor 2 en la posicion 0" << endl;
  lista.Insertar(2,0);
  cout << "Insertamos el valor 4 en la posicion 3" << endl;
  lista.Insertar(4,3);
  cout << "Insertamos el valor 9 en la ultima posicion" << endl;
  lista.AniadirValor(9);

  cout << "Modificamos el valor del nodo 3 por el valor 12" << endl;
  lista.ModificarValor(3,12);

  //Mostramos todos los valores
  cout << "Mostramos todos los valores" << endl;
  lista.Muestra();

  cout << "Mostrando posicion 3: " << lista.LeerValor(3) << endl;

  return (0);
}
