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
#include "Matriz2D_1.h"

using namespace std;

int main()
{
  Matriz2D matriz = CreaMatriz2DValoresAleatorios(5,5);

  cout << "Mostrando datos introducidos" << endl;

  MuestraMatriz2D(matriz);

  cout << "Copiando la matriz a otra matriz" << endl;

  Matriz2D matriz_copia = CopiaProfunda(matriz);

  cout << "Liberando espacio matriz" << endl;
  LiberaMatriz (matriz);

  cout << "Mostrando datos matriz original: " << endl;

  MuestraMatriz2D(matriz);

  cout << "Mostrando datos matriz copia: " << endl;

  MuestraMatriz2D(matriz_copia);

  Matriz2D matriz_extraida = ExtraerMatriz(matriz_copia,2,2,4,4);


  cout << "Mostrando datos matriz extraida: " << endl;

  MuestraMatriz2D(matriz_extraida);


  Matriz2D matriz_sin_fila = EliminaFila(matriz_copia,2);

  cout << "El resultado de eliminar fila 2 de la matriz: " << endl;
  MuestraMatriz2D(matriz_sin_fila);



  Matriz2D matriz_sin_columna = EliminaColumna(matriz_copia,2);

  cout << "El resultado de eliminar columna 2 de la matriz: " << endl;
  MuestraMatriz2D(matriz_sin_columna);


  Matriz2D traspuesta = TrasponerMatriz(matriz_copia);

  cout << "El resultado de la matriz traspuesta es: " << endl;
  MuestraMatriz2D(traspuesta);

  Matriz2D invertida = InvierteFilas(matriz_copia);

  cout << "El resultado de la matriz invertida es: " << endl;
  MuestraMatriz2D(invertida);
  return(0);
}
