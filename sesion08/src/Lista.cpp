#include "Lista.h"
#include <iostream>
using namespace std;

void LeerLista(Lista &l) {

  PNodo fin; // Puntero al último nodo
  l = 0; // Iniciar con la dirección nula
  double n;  // Valor a guardar en cada nodo
  // Primera lectura
  cout << "Introduzca valor (0 para terminar): ";
  cin >> n;
  if (n >= 0) {
    // Pedimos memoria para el primer nodo
    l = new Nodo;
    l->valor = n; // Guardar "n" en el nuevo nodo
    l->sig = 0;   // Este nodo es, por ahora, el último
    // El ultimo tambien es el primero (solo hay uno)
    fin = l;
    // Segunda lectura
    cout << "Introduzca valor (0 para terminar): ";
    cin >> n;
    while (n >= 0) {
      // Pedimos memoria para el siguiente nodo, y enlazamos
      fin->sig = new Nodo;
      fin = fin->sig; // Actualizar posicion del ultimo
      fin->valor = n; // Guardar "n" en el nuevo nodo
      fin->sig = 0;   // Este nodo es, por ahora, el último
      // Siguiente lectura
      cout << "Introduzca valor (0 para terminar): ";
      cin >> n;
    } // while (n != 0)
  }   // if (n != 0)
}

void PintaLista(const Lista l) {

  PNodo aux = l; // Colocar el aux en el primer elemento de la lista
  while (aux != 0) {
    cout << (aux->valor) << endl;
    aux = aux->sig;
  }

}

void LiberaLista(Lista &l) {

  PNodo aux = l;
  if (!ListaVacia(l)) {
    while (l->sig != 0) {
      aux = aux->sig;
      delete l;
      l = aux;
    }
    delete l;
  }
  l = 0;
}

bool ListaVacia(const Lista l) { return (l == 0); }

int CuentaElementos(const Lista l) {
  int cant = 0;
  PNodo aux = l; // Colocar el aux en el primer elemento de la lista
  while (aux != 0) {
    cant++;
    aux = aux->sig;
  }
  return cant;
}

bool EstaOrdenada (const Lista l){

  PNodo aux = l; // Colocar el aux en el primer elemento de la lista
  bool ordenado = true;
  if(!ListaVacia(l)){
    TipoBase anterior = aux->valor;
    aux = aux->sig;
    while (aux != 0 && ordenado) {
      if(aux->valor < anterior)
        ordenado = false;
      else{
        anterior = aux->valor;
        aux = aux->sig;
      }
    }
  }

  return ordenado;
}

PNodo ElementoPosicion(const Lista l, int pos){
  int cant = 0;
  PNodo devolver;
  PNodo aux = l; // Colocar el aux en el primer elemento de la lista
  while (aux != 0 && cant <= pos) {
    cant++;
    devolver = aux;
    aux = aux->sig;
  }
  return devolver;
}

void OrdenaSeleccionLista (Lista &l){

  int total_utilizados = CuentaElementos(l);
  for (int izda = 0 ; izda < total_utilizados ; izda++){
    TipoBase minimo = ElementoPosicion(l,izda)->valor;
    int posicion_minimo = izda;
    for (int i = izda + 1; i < total_utilizados ; i++){
      PNodo aux = ElementoPosicion(l,i);
      if (aux->valor < minimo){
        minimo = aux->valor;
        posicion_minimo = i;
      }
    }
    TipoBase intercambia = ElementoPosicion(l,izda)->valor;
    PNodo nodo_izda = ElementoPosicion(l,izda);
    nodo_izda->valor = ElementoPosicion(l,posicion_minimo)->valor;
    PNodo nodo_min = ElementoPosicion(l,posicion_minimo);
    nodo_min->valor = intercambia;
  }

}

void InsertaOrdenadamente (Lista &l, TipoBase v){

  PNodo aux = l;
  PNodo aux_fin;
  TipoBase aniadir;
  bool introducido = false;
  while (aux!= 0) {

    aniadir=aux->valor;

    if(aniadir >= v && !introducido){
      aux->valor = v;
      introducido = true;

      aux_fin = aux;
      aux= aux->sig;
      TipoBase aniadir_aux = aniadir;
      aniadir = aux->valor;
      aux->valor = aniadir_aux;

      if(aux!= 0){
        aux_fin = aux;
        aux= aux->sig;
      }
    }

    if(aux!= 0 && !introducido){
      aux->valor = aniadir;
      aux_fin = aux;
      aux= aux->sig;
    }

    if(aux!= 0 && introducido){
      TipoBase aniadir_aux = aniadir;
      aniadir = aux->valor;
      aux->valor = aniadir_aux;
      aux_fin = aux;
      aux= aux->sig;
    }

  }
  aux_fin->sig = new Nodo;
  aux_fin = aux_fin->sig;
  aux_fin->valor = aniadir;
  aux_fin->sig = 0;
}
