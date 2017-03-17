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
#include "matriz_numeros.h"
using namespace std;

/*********************************************************************/


int main(int argc, char * argv[])
{
  const int TOPE = 100;
  int vector [TOPE];
  int tope_lleno, ext_inf, ext_sup;
  switch (argc) {
    case 1:
      tope_lleno = TOPE;
      ext_inf = 0;
      ext_sup = TOPE - 1;
    break;
    case 2:
      tope_lleno = atoi(argv[1]);
      ext_inf = 0;
      ext_sup = atoi(argv[1]) - 1;
    break;

    case 3:
      tope_lleno = atoi(argv[1]);
      ext_inf = 0;
      ext_sup = atoi(argv[2]);
    break;

    case 4:
      tope_lleno = *(argv[1]);
      ext_inf = atoi(argv[2]);
      ext_sup = atoi(argv[3]);
    break;

    case 5:
      cout << "Numero de argumentos invalidos...." << endl;
      cout << "Saliendo del programa...." << endl;
      return 1;
    break;
  }

  RellenaVectorSinOrden(vector,tope_lleno,0,50);
  char mensaje[TOPE];
  cout << "Introduzca el mensaje a mostrar: ";
  cin.getline(mensaje,TOPE);

  MuestraVector(mensaje,vector,tope_lleno,10);

  cout << "El mayor es: " << *(PosMayor(vector,ext_inf,ext_sup));

  cout << endl << endl;
	return (0);
}

/*********************************************************************/
