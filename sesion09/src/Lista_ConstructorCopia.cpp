#include <iostream>
#include "Lista_ConstructorCopia.h"
using namespace std;

/*
  Construtor que crea una lista vacia
  No recibe nada
*/
Lista_ConstructorCopia::Lista_ConstructorCopia(void):tamanio(0),lista(0){}

/*
  Constructor que crea una lista con el tamaño indicado pero que el valor de
  cada nodo esta vacio
  Recibe:
    -tam un int que indica el tamaño de la lista
*/
Lista_ConstructorCopia::Lista_ConstructorCopia(int tam):tamanio(tam){
  ReservaMemoria(tam);
}

/*
  Constructor que crea una lista con el tamaño indicado pero que el valor de
  cada nodo sera el indicado en el argumento
  Recibe:
    -tam un int que indica el tamaño de la lista
    -valor un TipoBase que indica con que valor se inicia cada nodo
*/
Lista_ConstructorCopia::Lista_ConstructorCopia(int tam, TipoBase valor):tamanio(tam)
{
  ReservaMemoria(tam);
  Inicializa(valor);
}
/*
  Metodo que comprueba si una lista esta vacia
  No recibe nada
  Devuelve un bool que indica true si la lista esta vacia y false si no lo
  esta
*/
bool Lista_ConstructorCopia::EstaVacia(void){
  return (lista == 0);
}

/*
  El metodo devuelve el numero de nodos de la lista
  No recibe nada
  Devuelve un int con el numero de nodos
*/
int Lista_ConstructorCopia::NumeroDeNodos(void){
  return tamanio;
}


/*
  Metodo que inserta un TipoBase en una posicion indicada
  Recibe:
    -valor un TipoBase con el valor que se quiere Insertar
    -pos un int que indica la posicion en la que se queire indicar
  No recibe nada
*/
void Lista_ConstructorCopia::Insertar(TipoBase valor, int pos){

  if(pos<tamanio){

    Nodo * aux_ant;
    Nodo * aux = lista;

    Nodo * insertar = new Nodo;
    insertar->valor = valor;

      for(int n = 0; n < pos ; n++){
        aux_ant = aux;
        aux = aux->sig;
      }

    insertar->sig = aux;

    if(pos != 0){
      aux_ant->sig = insertar;
    }else{
      lista = insertar;
    }
    tamanio++;
  }
}

/*
  Metodo que borra un nodo de una lista
  Recibe:
    -pos un int que indica el nodo que se quiere borrar
  No recibe nada
*/
void Borrar (int pos){

}

/*
  El metodo reserva memoria para un tamaño de lista predeterminada
  Recibe:
    -cant un int con el numero de nodos que se desea reservar
  No devuelve nada
*/
void Lista_ConstructorCopia::ReservaMemoria(int cant){
  if(cant > 0){
    lista = new Nodo;
    Nodo * aux = lista;
    for(int n = 1; n < cant; n++){
      aux->sig = new Nodo;
      aux = aux->sig;
    }
    aux = 0;
  }
}
/*
  Metodo que añade un valor al final de una lista
  Recibe:
    -valor un TipoBase que indica el valor que se quiere insertar
  No devuelve nada
*/
void Lista_ConstructorCopia::AniadirValor (TipoBase valor){
  Nodo * aux_ant;
  Nodo * aux = lista;

  while(aux != 0){
    aux_ant = aux;
    aux = aux->sig;
  }

  Nodo * insertar;
  insertar = new Nodo;
  insertar->valor = valor;
  insertar->sig = 0;
  aux_ant->sig = insertar;
  tamanio++;
}

/*
  El metodo devuelve el valor que hay en un nodo indicado
  Recibe:
    -pos un int que indica el numero del nodo a consultar
  Devuelve un TipoBase con el valor del nodo
*/
TipoBase Lista_ConstructorCopia::LeerValor (int pos){
  Nodo * aux = lista;
  if(pos <=  tamanio)
    for(int n = 0; n < pos; n++){
      aux = aux->sig;
    }
  return aux->valor;
}

/*
  El metodo modifica el valor de un nodo
  Recibe:
    -pos un int del numero del nodo a modificar
    -val un TipoBase que sera con el que se modifique el nodo
  No devuelve nada
*/
void Lista_ConstructorCopia::ModificarValor (int pos, TipoBase val){
  Nodo * aux = lista;
  if(pos <=  tamanio)
    for(int n = 0 ; n < pos; n++){
      aux = aux->sig;
    }
  aux->valor = val;
}

/*
  Metodo que muestra el valor de los nodos de la lista
  No recibe nada
  No devuelve nada
*/
void Lista_ConstructorCopia::Muestra(void){

  Nodo * aux = lista;
  while(aux != 0){
    cout << aux->valor << endl;
    aux = aux->sig;
  }
}

/*
  Metodo que inicializa los nodos de una lista
  Recibe:
    -val un TipoBase que con el que se inicializa la lista, si no se indica
    por defecto sera nulo
  No devuelve nada
*/
void Lista_ConstructorCopia::Inicializa(TipoBase val){
  Nodo * aux = lista;
  while(aux != 0){
    aux->valor = val;
    aux = aux->sig;
  }
}


Lista_ConstructorCopia::~Lista_ConstructorCopia(void){
}
