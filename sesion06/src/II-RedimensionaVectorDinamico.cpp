/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 6
//
/*
*/
/*********************************************************************/

#include <iostream>
#include "vector_dinamico.h"
using namespace std;



int main(int argc, char * argv[])
{

  if(argc>2){
    //En caso de que el numero de parametros sea 2 contando con el nombre del
    //programa
    cout << "Numero de argumentos invalidos...." << endl;
    cout << "Saliendo del programa...." << endl;
    exit(1);
  }

  int cap = TAM;
  int * ptr = new int [cap];
  int argumento;
  //Vemos la cantidad de elementos y segun cual sea realizamos una acciones u
  //otras
  TipoRedimension tipo = TipoRedimension::DeUnoEnUno;
  if(argc==2){
    argumento = atoi(argv[1]);
    //En caso de que tenga un argumento dependiendo de su valor cambiara
    //el tipo de redimension
    if(argumento == 2)
      tipo = TipoRedimension::EnBloques;
    else if(argumento == 3)
      tipo = TipoRedimension::Duplicando;
    else{
      //Como el argumento no tiene el valor correcto se sale del programa
      cout << "El argumento es invalido...." << endl;
      cout << "Saliendo del programa...." << endl;
      exit(1);
    }
  }

  //Variables que usaremos en la lectura de datos
  int numero;
  string frase;

  //La cantidad de elementos del vector
  int cant_vect = 0;

  //Pedimos que introduzca los datos
  cout << "Introduzca un entero: " ;
  cin >> frase;

  //Si lo introducido no es "FIN" entra en el while
  while(frase != "FIN"){
    //Como ya sabemos que no es "FIN" convertimos el dato a int
    numero = stoi(frase);

    //Si no queda espacio redimensionamos el vector
    if(cant_vect>=cap)
      ptr = Redimensiona(ptr,tipo, cap);

    //Añadimos el nuevo elemento al vector
    *(ptr+cant_vect) = numero;

    //Aumentamos la cantidad de elementos
    cant_vect++;

    //Volvemos a pedir que nos introduzca los datos
    cout << "Introduzca un entero: " ;
    cin >> frase;
  }

  //Un simple bucle for para mostrar los datos leidos
  cout << "Los datos leidos son: " << endl;
  for(int x = 0; x < cant_vect; x++)
    cout << *(ptr+x) <<endl;

  //Liberamos la memoria reservada en el heap
  delete [] ptr;

  cout << endl << endl;
	return (0);
}

/*********************************************************************/
