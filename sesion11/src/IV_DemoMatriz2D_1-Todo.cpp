/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 9
//
/*
 */
/*********************************************************************/

#include <iostream>
#include "Matriz2D_1.h"

using namespace std;
int main() {
  cout << "Creando matriz nula...." << endl;
  Matriz2D_1 vacia;
  cout << "Creando matriz vacia...." << endl;

  if(vacia.EstaVacia())
    cout << "La matriz esta vacia..." << endl;
  else
    cout << "La matriz no esta vacia..." << endl;
  
  cout << endl
       << "---------------------------------------------------------------"
       << endl;

  Matriz2D_1 cuadrada(10);
  cout << "Creando matriz cuadrada...." << endl;
  cuadrada = 2;
  cout << "Inicializando a 2" << endl;
  cout << "Mostrando datos: " << endl;
  cuadrada.Mostrar();

  Matriz2D_1 negativa = -cuadrada;
  cout << "Copiando la matriz negativa...." << endl;
  cout << "Mostrando datos: " << endl;
  negativa.Mostrar();

  cout << endl
       << "---------------------------------------------------------------"
       << endl;
  Matriz2D_1 cero = negativa + cuadrada;  
  cout << "Sumando la matriz original y la negativa...." << endl;
  
  cout << "Mostrando datos: " << endl;
  cero.Mostrar();

  cout << endl 
       << "---------------------------------------------------------------"
       << endl;
  
  Matriz2D_1 rectangular(2,6);
  cout << "Creando matriz rectangular...." << endl;
  rectangular = 2;
  cout << "Inicializando a 2" << endl;
  cout << "Mostrando datos: " << endl;
  rectangular.Mostrar();

  cout << "Sumando 3 en todos los elementos" << endl;
  rectangular += 3;
  cout << "Mostrando datos: " << endl;
  rectangular.Mostrar();

  cout << endl 
       << "---------------------------------------------------------------"
       << endl;  
  
  Matriz2D_1 copia;
  copia = rectangular;
  cout << "Creando matriz copia de la rectangular" << endl;
  copia.Mostrar();
  cout << "Comparando la matriz copia y la rectangular" << endl;
  if(copia == rectangular)
    cout << "Son iguales" << endl;
  else
    cout << "Son diferentes" << endl;
  
  cout << endl 
       << "---------------------------------------------------------------"
       << endl;

  cout << "Modificando el elemento [1,1] a el valor 13" << endl;
  copia(1,1) = 13;
  cout << "Mostran matriz copia despues de modificarla" << endl;
  copia.Mostrar();

  cout << "Mostran el elemento [1,1]: " << copia(1,1) << endl;
  
  cout << "Comparando la matriz copia y la rectangular despues de modificarla" 
       << endl;
  if(copia == rectangular)
    cout << "Son iguales" << endl;
  else
    cout << "Son diferentes" << endl;
 
  cout << endl 
       << "---------------------------------------------------------------"
       << endl;
  
  
  return (0);
}