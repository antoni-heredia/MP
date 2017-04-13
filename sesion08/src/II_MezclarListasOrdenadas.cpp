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

  Lista l1;
  LeerLista(l1);
  cout << "El contenido de la lista es: "   <<endl;
  PintaLista(l1);

  if(EstaOrdenada(l1))
    cout << "La lista esta ordenada" << endl;
  else
    cout << "La lista esta desordenada" << endl;
  OrdenaSeleccionLista(l1);

  cout << "La lista ordenada es: "   <<endl;
  PintaLista(l1);


  Lista l2;
  LeerLista(l2);

  Lista resultado;
  MezclaListas(resultado, l1, l2);
  PintaLista(resultado);
  cout << "se debe haber pintado" << endl;
  LiberaLista(l1);
  LiberaLista(l2);
  LiberaLista(resultado);

  return (0);
}
