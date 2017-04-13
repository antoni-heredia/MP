#ifndef LISTA
#define LISTA

// Bastará cambiar el tipo asociado al alias TipoBase
// y recompilar para poder gestionar otro tipo de lista.
typedef double TipoBase;

// Cada nodo de la lista es de tipo "Nodo"
struct Nodo {
  TipoBase valor;
  Nodo *sig;
};

typedef Nodo * PNodo; // Para los punteros a nodos
typedef Nodo * Lista; // Para la lista

void LeerLista(Lista &l);

void PintaLista (const Lista l);

void LiberaLista(Lista & l);

bool ListaVacia (const Lista l);

int CuentaElementos (const Lista l);

bool EstaOrdenada (const Lista l);

void OrdenaSeleccionLista (Lista &l);

PNodo ElementoPosicion(const Lista l, int pos);

void InsertaOrdenadamente (Lista &l, TipoBase v);

void MezclaListas (Lista &l, Lista &l1, Lista &l2);

#endif
