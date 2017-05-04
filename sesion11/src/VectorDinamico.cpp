#include <iostream>
#include "VectorDinamico.h"

using namespace std;

/******************************************************************************/


///////////////////////////////////////////////////////////////////////////////
//                               Clase vector                                //
///////////////////////////////////////////////////////////////////////////////

//Metodos publicos

///////////////////////////////////////////////////////////////////////////////
/*
  Contructor indicando el numero de casillas.
  En caso de usar el constructor sin ningun argmumento se iniciara un vector
  con tamaño inicial = TAM_INICIAL
  Se crea un vector dinamico con un tamaño inicial indicado por el argumento,
*/
VectorDinamico::VectorDinamico(const int
  casillas):num_casillas(casillas),num_ocupadas(0),
  redimension(TipoRedimension::EnBloques){

  ReservaCasillas(casillas);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/*
  Contructor de copia
  Se crea un vector dinamico con un tamaño inicial indicado por el tamaño del
  VectorDinamico pasado en el argumentos
  Tambien se inicializa el vector con un valor inicial igual a los valores
  del VectorDinamico pasado por el argumento
*/
VectorDinamico::VectorDinamico(const
  VectorDinamico & otro){

  ReservaCasillas(otro.NumeroDeCasillas());
  CopiarDatos(otro);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Destructor
  Se encargara de liberar la memoria ocupada por el
  VectorDinamico en el heap
*/
VectorDinamico::~VectorDinamico(void){
  LiberarMemoria();
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que nos devuelve si el VectorDinamico esta vacio.
  Devuelve un bool que sera TRUE si el VectorDinamico esta
  vacio o FALSE en caso contrario
  No recibe nada.
*/
bool VectorDinamico::EstaVacio(void) const{
  return (num_casillas == 0);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que devuelve el numero de casillas que tiene el
  VectorDinamico
  Devuelve un int que indica el numero de casillas que tiene ocupadas.
  No recibe nada.
*/
int VectorDinamico::NumeroDeCasillas(void) const{
  return num_casillas;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que devuelve el numero de casillas ocupadas que tiene el
  VectorDinamico
  Devuelve un int que indica el numero de casillas que tiene ocupadas.
  No recibe nada.
*/
int VectorDinamico::NumeroDeCasillasOcupadas(void) const{
  return num_ocupadas;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que añade un valor al VectorDinamico en la ultima
  posicion
  No devuelve nada.
  Recibe un TipoBase que sera el que se añada al final del
  VectorDinamico.
*/
void VectorDinamico::AniadirValor(const TipoBase valor){

  //Se comprueba si hay espacio  para mas valores y si no hay se redimensiona
  if(num_ocupadas == num_casillas)
    Redimensiona();

  //Se añade el valor
  vector[num_ocupadas] = valor;

  //Se aumenta el numero de casillas ocupadas
  num_ocupadas++;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que devuelve el tipo de redimenion que se hace cuando se aumenta el
  tamanio del VectorDinamico
  Devuelve un TipoRedimension que indica el tipo de redimension actual
  No recibe nada
*/
TipoRedimension VectorDinamico::Redimension(void) const{
  return redimension;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo que establece un nuevo tipo de redimensionar para el
  VectorDinamico
  No devuelve nada
  Recibe el TipoRedimension nuevo que se va a establecer
*/
void VectorDinamico::Redimension(TipoRedimension
  nueva_redimension){
  redimension = nueva_redimension;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo muestra por pantalla el contenido de un vector dinamico
  El metodo no recibe nada
  El metodo no devuelve nada
*/
void VectorDinamico::ImprimeVector(string mensaje) const{

  cout << mensaje << endl;
  cout << "(" << vector[0];

  for(int c = 1; c < num_ocupadas; c++){
      if(c%5 == 0)
        cout << endl << " ";
    cout << "," << vector[c];
  }

  cout << ")" << endl;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador de asignacion
VectorDinamico & VectorDinamico :: operator =
(const VectorDinamico & otro){

  if(this != &otro){

    LiberarMemoria();

    ReservaCasillas(otro.NumeroDeCasillas());

    CopiarDatos(otro);
  }
  return (*this);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador de asignacion
VectorDinamico & VectorDinamico :: operator =
(const TipoBase & valor){
  InicializarDato(valor);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

TipoBase & VectorDinamico :: operator [] (const int indice){
  return (vector[indice]);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Operador ==
bool VectorDinamico :: operator == (const VectorDinamico & otro){
 
  bool iguales = (num_ocupadas == otro.num_ocupadas);
  if (iguales) {
    
    int n=0;
    while (iguales)
      if (vector[n] == otro.vector[n]) // Seguir
        n++;
      else {
        iguales = false; // terminar
      }
  }
  return (iguales);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Operador !=
bool VectorDinamico :: operator != (const VectorDinamico & otro){
 
  return (!(*this == otro));

}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador >
bool VectorDinamico :: operator > (const VectorDinamico & otro){

  int n=0;
  bool iguales = true;

  while (iguales)
    if (vector[n] == otro.vector[n]) // Seguir
      n++;
    else 
      iguales = false; // terminar
    
  

  //Comparamos que el primer elemento distinto sea mayor
  return (vector[n] > otro.vector[n]);
  }

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador <=
bool VectorDinamico :: operator <= (const VectorDinamico & otro){

  return (!(*this > otro));

}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador <
bool VectorDinamico :: operator < (const VectorDinamico & otro){

  return (!(*this > otro) && !(*this == otro));
  
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

// Operador >=
bool VectorDinamico :: operator >= (const VectorDinamico & otro){

  return ((*this > otro) || (*this == otro));
  
}

///////////////////////////////////////////////////////////////////////////////

//Metodos privados

///////////////////////////////////////////////////////////////////////////////

/*
  Metodo  que reserva un numero de casillas predeterminado
  No devuelve nada
  Recibe un int con el numero de casillas a reservar
  PREC: casillas > 0
*/
void VectorDinamico::ReservaCasillas(int casillas){
  vector = 0;
  if(casillas > 0)
    vector = new TipoBase [casillas];
}

/*
  Metodo que libera la memoria de un vector dinamico
  No recibe nada
  No devuelve nada
*/
void VectorDinamico::LiberarMemoria(void){
  if(vector)
    delete [] vector;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo copia todos los valores de un vector dinamico a nuestro vector
  dinamico
  No devuelve nada
  Recibe un puntero a un VectorDinamico
*/
void VectorDinamico::CopiarDatos(const
  VectorDinamico & otro){

  num_casillas = otro.num_casillas;
  num_ocupadas = otro.num_ocupadas;
  redimension = otro.redimension;
  for(int c = 0; c < num_ocupadas; c++)
    vector[c] = otro.vector[c];

}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

/*
  El metodo redimension el tamaño del vector dinamico para que tenga mas
  capacidad
  No devuelve nada
  No recibe nada
*/
void VectorDinamico::Redimensiona(void){
 switch (redimension) {
    case DeUnoEnUno:
      num_casillas++;
    break;
    case EnBloques:
      num_casillas += TAM_BLOQUE;
    break;
    case Duplicando:
      num_casillas *= 2;
    break;
  }
  TipoBase * tmp = vector;

  ReservaCasillas(num_casillas);

  for(int c = 0; c < num_ocupadas; c++)
    vector[c] = tmp[c];

  delete [] tmp;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void VectorDinamico::InicializarDato(TipoBase dato){
  num_ocupadas = num_casillas;
  for (int i = 0; i < num_casillas; i++) {
    vector[i] = dato;
  }
}

///////////////////////////////////////////////////////////////////////////////