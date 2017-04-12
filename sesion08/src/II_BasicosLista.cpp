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
double Media(const Lista lista);
double Varianza(const Lista lista);
int main() {

  Lista lista;
  LeerLista(lista);
  cout << "El contenido de la lista es: " << endl;
  PintaLista(lista);
  cout << "El numero de nodos es: " << CuentaElementos(lista) << endl;
  cout << "La media de los nodos es: " << Media(lista) << endl;
  cout << "La varianza de los nodos es: " << Varianza(lista) << endl;

  LiberaLista(lista);
  LeerLista(lista);
  return (0);
}

double Media(const Lista lista) {
  int cant = 0;
  TipoBase suma = 0;
  PNodo aux = lista; // Colocar el aux en el primer elemento de la lista
  while (aux != 0) {
    cant++;
    suma += (aux->valor);
    aux = aux->sig;
  }
  return (suma / cant);
}

double Varianza(const Lista lista) {
  double media = Media(lista);
  int cant = 0;
  TipoBase suma = 0;
  PNodo aux = lista; // Colocar el aux en el primer elemento de la lista
  while (aux != 0) {
    cant++;
    suma += ((aux->valor) - media) * ((aux->valor) - media);
    aux = aux->sig;
  }
  return (suma / cant);
}
