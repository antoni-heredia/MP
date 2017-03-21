/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2016-2017
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero base para practicar modularización
//
/***************************************************************************/

#include <iostream>

#include "adicion.h"
#include "producto.h"
using namespace std;


/***************************************************************************/

int main (void)
{
   int num1, num2; 

   cout << "Introduce un numero: "; 
   cin >> num1; 
   cout << "Introduce otro numero: "; 
   cin >> num2; 

   cout << "La suma es = " << suma (num1, num2) << "\n"; 
   cout << "La resta es = " << resta (num1, num2) << "\n"; 
   cout << "La multiplicación es = " << multiplica (num1, num2) << "\n"; 
   cout << "La división es = " << divide (num1, num2) << "\n"; 

   return (0);
}

/***************************************************************************/

 
