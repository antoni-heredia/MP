/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 8
//
/*
 */
/*********************************************************************/

#include "Lista.h"
#include <iostream>

using namespace std;
int main() {

  Lista lista;
  LeerLista(lista);
  cout << "El contenido de la lista es: "   <<endl;
  PintaLista(lista);

  if(EstaOrdenada(lista))
    cout << "La lista esta ordenada" << endl;
  else
    cout << "La lista esta desordenada" << endl;
  OrdenaSeleccionLista(lista);

  cout << "La lista ordenada es: "   <<endl;
  PintaLista(lista);

  InsertaOrdenadamente (lista, 10);
  cout << "La lista añadiendo elemento es: "   <<endl;
  PintaLista(lista);

  LiberaLista(lista);
  return (0);
}
