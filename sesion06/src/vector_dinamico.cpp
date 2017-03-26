#include <iostream>
#include "vector_dinamico.h"
using namespace std;

/*
  Funcion que actua para redimensionar el tamaño de un "vector";
  Basicamente redimensiona el tamño de un vector alojado en el heap
  y devuelve la posicion donde se encuentra la primera poscion del vector

  p -> vector a dimensionar
  tipo -> tipo de redimension a realizar
  cap -> capacidad actual del vector

*/

int * Redimensiona (int * p, TipoRedimension tipo, int & cap){

  //Hacemos una copia de la capacidad actual ya que se va a modificar y la vamos
  //a necesitar a la hora de copiar el vector antiguo en el nuevo
  int casillas_actuales = cap;

  //Vemos la capacidad que va a tener la redimension usando el enum
  if(tipo == TipoRedimension::DeUnoEnUno)
    cap++;
  else if (tipo == TipoRedimension::EnBloques)
    cap+=TAM_BLOQUE;
  else
    cap*=2;

  //Creamos el nuevo vector redimensionado
  int * ptr_new = new int [cap];

  //Copiamos el vector antiguo en el nuevo
  for(int i = 0; i<=casillas_actuales;i++){
    *(ptr_new+i) = *(p+i);
  }

  //Borramos la memoria reservada en el heap antes de sobreescribir el puntero
  //ya que despues no podremos
  delete [] p;
  return ptr_new;

}

int LongitudCadena(char * cadena){
  int tam = 0;
  while(*(cadena)){
    tam++;
    cadena++;
  }
  return tam;
}

char ** RedimensionaVectorCadenas (char ** p, TipoRedimension tipo, int & cap){
  //Hacemos una copia de la capacidad actual ya que se va a modificar y la vamos
  //a necesitar a la hora de copiar el vector antiguo en el nuevo
  int casillas_actuales = cap;
  //Vemos la capacidad que va a tener la redimension usando el enum
  if(tipo == TipoRedimension::DeUnoEnUno)
    cap++;
  else if (tipo == TipoRedimension::EnBloques)
    cap+=TAM_BLOQUE;
  else
    cap*=2;


  //Creamos el nuevo vector redimensionado
  char * * ptr_new = new char * [cap];
  //Copiamos el vector antiguo en el nuevo
  for(int i = 0; i<casillas_actuales;i++){
    char * cadena_tmp = new  char  [LongitudCadena(p[i])+1];

    int x = 0;
    for( x = 0; x < LongitudCadena(p[i]);x++)
      cadena_tmp[x] = p[i][x];
    cadena_tmp[x] = '\0';

    ptr_new[i] = cadena_tmp;
  }
  //Borramos la memoria reservada en el heap antes de sobreescribir el puntero
  //ya que despues no podremos
  for(int i = 0; i<casillas_actuales;i++){
    delete []  p[i];
  }
  delete [] p;
  cout << "pasa"<< endl;

  return ptr_new;

}
/*********************************************************************/
