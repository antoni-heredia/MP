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
#include "Lista_Asignacion-Acceso.h"

using namespace std;
int main() {

  cout << "Creando una lista con 4 nodos inicializados a 1..." << endl;
  Lista_Asignacion lista(4,1);
  cout << "Insertamos el valor 2 en la posicion 0" << endl;
  lista.Insertar(2,0);
  cout << "Insertamos el valor 4 en la posicion 3" << endl;
  lista.Insertar(4,3);
  cout << "Insertamos el valor 9 en la ultima posicion" << endl;
  lista.AniadirValor(9);

  cout << "Mostrando el valor del nodo 3: " << lista[3] << endl;

  cout << "Modificamos el valor del nodo 3 por el valor 12" << endl;
  lista[3] = 12;

  //Mostramos todos los valores
  cout << "Mostramos todos los valores" << endl;
  lista.Muestra();

  cout << "Mostrando lista copia: " << endl;
  Lista_Asignacion copia = lista;
  copia.Muestra();

  cout << "Reiniciando lista copia a 0: " << endl;
  copia = 0;
  copia.Muestra();
  return (0);
}
