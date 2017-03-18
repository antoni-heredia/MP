/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 5
//
/*
*/
/*********************************************************************/

#include <iostream>
#include "array_numeros.h"
using namespace std;

/*********************************************************************/


int main(int argc, char * argv[])
{
  //Tamaño maximo de los vectores
  const int TOPE = 100;
  int v1[TOPE];
  int v2[TOPE];

  //Para ver el maximo y minimo de los aleatorios a generar
  int min, max;

  //Vemos la cantidad de elementos y segun cual sea realizamos una acciones u
  //otras
  switch (argc) {
    case 1:
      min = 0;
      max = 100;
    break;
    case 2:
      min = 0;
      max = atoi(argv[1]);
    break;

    case 3:
      min = atoi(argv[1]);
      max = atoi(argv[2]);
    break;

    //En caso de que el numero de parametros sea 4 contando con el nombre del
    //programa
    case 4:
      cout << "Numero de argumentos invalidos...." << endl;
      cout << "Saliendo del programa...." << endl;
      return 1;
    break;
  }

  //Se rellena el primer vector
  RellenaVector(v1,TOPE,min,max);

  //Se pide el mensaje para mostrar los datos
  char mensaje[TOPE];
  cout << "Introduzca el mensaje a mostrar: ";
  cin.getline(mensaje,TOPE);

  //Se muestra el primer vector
  MuestraVector(mensaje,v1,TOPE,10);

  //Se rellena el segundo vector y se muestra
  RellenaVector(v2,TOPE,min,max);
  MuestraVector(mensaje,v2,TOPE,10);

  //Se inicia el tercer vector que es donde se mezclan los vectores anteriores
  // y los mestra
  int v3[TOPE*2];
  MezclaVectores(v3,v1,TOPE,v2,TOPE);
  MuestraVector(mensaje,v3,TOPE*2,10);

  cout << endl << endl;
	return (0);
}

/*********************************************************************/
