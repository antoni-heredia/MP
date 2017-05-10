/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 11
//
/*
  Fichero donde se encuentra el codigo de los metodos de la clase
  Lista
 */
/*********************************************************************/

#include <iostream>
#include "Lista.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//                                Clase lista                                //
///////////////////////////////////////////////////////////////////////////////

//Metodos publicos

///////////////////////////////////////////////////////////////////////////////

/*
  Construtor que crea una lista vacia
  No recibe nada
*/

Lista::Lista(void):tamanio(0),lista(0){}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Constructor que crea una lista con el tamaño indicado pero que el valor de
  cada nodo esta vacio
  Recibe:
    -tam un int que indica el tamaño de la lista
*/
Lista::Lista(int tam):tamanio(tam){
  ReservaMemoria(tam);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Constructor que crea una lista con el tamaño indicado pero que el valor de
  cada nodo sera el indicado en el argumento
  Recibe:
    -tam un int que indica el tamaño de la lista
    -valor un TipoBase que indica con que valor se inicia cada nodo
*/
Lista::Lista(int tam, TipoBase valor):tamanio(tam)
{
  ReservaMemoria(tam);
  Inicializa(valor);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Constructor que crea una lista que sera la copia de otra lista
  Recibe:
    -otro es una Lista de la cual se copiaran los datos
*/
Lista::Lista(Lista & otro){
  ReservaMemoria(otro.NumeroDeNodos());
  CopiarDatos(otro);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

//Destructor de la clase
Lista::~Lista(void){
  LiberarMemoria();
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que comprueba si una lista esta vacia
  No recibe nada
  Devuelve un bool que indica true si la lista esta vacia y false si no lo
  esta
*/

bool Lista::EstaVacia(void){
  return (lista == 0);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo devuelve el numero de nodos de la lista
  No recibe nada
  Devuelve un int con el numero de nodos
*/

int Lista::NumeroDeNodos(void){
  return tamanio;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que inserta un TipoBase en una posicion indicada
  Recibe:
    -valor un TipoBase con el valor que se quiere Insertar
    -pos un int que indica la posicion en la que se queire indicar
  No recibe nada
*/

void Lista::Insertar(TipoBase valor, int pos){

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

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que borra un nodo de una lista
  Recibe:
    -pos un int que indica el nodo que se quiere borrar
  No recibe nada
*/
void Lista :: Borrar (int pos_borrar){

  Nodo * ant = lista;
	Nodo * pos = lista;

	// Colocar "ant" y "act" 
	for (int i=1; i<pos_borrar; i++) { 
		ant = pos; 
		pos = pos->sig;
	}

	// "pos" apunta al nodo que se va a borrar
	// "ant" apunta al nodo anterior

	if (pos_borrar==1)   // Saltar el lista 
		lista = lista->sig;
	else 
		ant->sig = pos->sig;
		// Enlazar el anterior con el siguiente 

	delete pos; // Borrar nodo
	
	tamanio--;  // Actualizar tamanio
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Borra el primer nodo que contiene el valor "valor"
  void Lista :: EliminarValor (TipoBase valor)
  {
    int pos = Buscar (valor);

    // Si pos > 0 se encontr� el alumno buscado: eliminarlo
    if (pos > 0) Borrar (pos);
  }

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

int Lista :: Buscar (TipoBase valor) const
{
    Nodo * p = lista;

    bool sigo = true;
    bool encontrado = false;

	int pos = 0;
    	
    while ((p!=0) && sigo) {
    	
		pos++; // Actualizar posici�n

        if (p->valor == valor) {
            sigo = false;
            encontrado = true;
        }
        else 
            p = p->sig;
	}
	
	return (encontrado ? (pos) : -1); 
}	

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo reserva memoria para un tamaño de lista predeterminada
  Recibe:
    -cant un int con el numero de nodos que se desea reservar
  No devuelve nada
*/
void Lista::ReservaMemoria(int cant){

  if(cant > 0){
    lista = new Nodo;
    Nodo * aux = lista;
    for(int n = 1; n < cant; n++){
      aux->sig = new Nodo;
      aux = aux->sig;
    }
    aux = 0;
    tamanio = cant;
  }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que añade un valor al final de una lista
  Recibe:
    -valor un TipoBase que indica el valor que se quiere insertar
  No devuelve nada
*/
void Lista::AniadirValor (TipoBase valor){
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

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo devuelve el valor que hay en un nodo indicado
  Recibe:
    -pos un int que indica el numero del nodo a consultar
  Devuelve un TipoBase con el valor del nodo
*/
TipoBase Lista::LeerValor (int pos){
  Nodo * aux = lista;
  if(pos <=  tamanio)
    for(int n = 0; n < pos; n++){
      aux = aux->sig;
    }
  return aux->valor;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo modifica el valor de un nodo
  Recibe:
    -pos un int del numero del nodo a modificar
    -val un TipoBase que sera con el que se modifique el nodo
  No devuelve nada
*/
void Lista::ModificarValor (int pos, TipoBase val){
  Nodo * aux = lista;
  if(pos <=  tamanio)
    for(int n = 0 ; n < pos; n++){
      aux = aux->sig;
    }
  aux->valor = val;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que muestra el valor de los nodos de la lista
  No recibe nada
  No devuelve nada
*/
void Lista::Muestra(void){

  Nodo * aux = lista;
  while(aux != 0){
    cout << aux->valor << endl;
    aux = aux->sig;
  }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que inicializa los nodos de una lista
  Recibe:
    -val un TipoBase que con el que se inicializa la lista, si no se indica
    por defecto sera nulo
  No devuelve nada
*/
void Lista::Inicializa(TipoBase val){
  Nodo * aux = lista;
  while(aux != 0){
    aux->valor = val;
    aux = aux->sig;
  }
}

///////////////////////////////////////////////////////////////////////////////

Lista & Lista :: operator = (const Lista & otro){

  if(this != &otro){

    LiberarMemoria();

    ReservaMemoria(otro.tamanio);

    CopiarDatos(otro);
  }
  return (*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

Lista & Lista :: operator = (const TipoBase & valor){

  Inicializa(valor);

  return(*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

TipoBase & Lista :: operator [] (const int indice){
  Nodo * aux = lista;
  if(indice <=  tamanio)
    for(int n = 0 ; n < indice; n++){
      aux = aux->sig;
    }

  return (aux->valor);

}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador +=
Lista & Lista :: operator += (const TipoBase & otro) {
  AniadirValor(otro);
  return (*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador -=
Lista & Lista :: operator -= (const TipoBase & otro)
{
  EliminarValor(otro);
  return (*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo copia todos los datos de una lista a otra
  Recibe:
    -otra una Lista de la cual se copiara los datos
*/
void Lista::CopiarDatos(const Lista & otra){
  if(tamanio > 0){
    Nodo * aux_otro = otra.lista;
    Nodo * aux_este = lista;

    while(aux_otro != 0){
      aux_este->valor = aux_otro->valor;
      aux_este = aux_este->sig;
      aux_otro = aux_otro->sig;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void Lista::LiberarMemoria(void){
  if (lista !=0) {

		Nodo *p = lista; // Colocar "p" al principio

		while (lista->sig != 0) {

			lista = lista->sig;  // Nuevo "primero"
			delete p;     // Borrar el antiguo primero
			p = lista;  // Actualizar "p"
		}

		delete lista; // Borrar el único que queda

		lista = 0; // MUY IMPORTANTE
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
