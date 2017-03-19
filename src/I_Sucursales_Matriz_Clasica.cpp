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
#include <cstdlib>
#include <cctype>

using namespace std;

/*********************************************************************/
int numDigitos(int numero)
{
    int digitos = 0;
    if (numero < 0) digitos = 1; // remove this line if '-' counts as a digit
    while (numero) {
        numero /= 10;
        digitos++;
    }
    return digitos;
}

int main()
{
  const int MAX = 256;
  const int NUM_SUC = 100;
  const int NUM_PRODUC = 'j' - 'a';

  int ventas[NUM_SUC][NUM_PRODUC];
  int ventas_sucursal[NUM_SUC];
  int ventas_producto[NUM_PRODUC];

  string cadena;
  char producto;
  int sucursal = 0;
  int cantidad;

  for(int f = 0; f < NUM_SUC; f++){
    ventas_sucursal[f] = 0;
    for(int c = 0; c < NUM_PRODUC; c++)
      ventas[f][c] = 0;
  }
  for(int c = 0; c < NUM_PRODUC; c++)
    ventas_producto[c] = 0;

  while (getline (cin, cadena) && sucursal != -1) {
    int pos = 0;
    //Recogemos los datos de la cadenas
    char * ptr_cadena = &cadena[0];
    sucursal = atoi(ptr_cadena+pos);

    if(sucursal != -1){
      pos += 1 + numDigitos(sucursal);
      producto = *(ptr_cadena+pos);
      pos += 2;
      cantidad = atoi(ptr_cadena+pos);
      ventas[sucursal][producto-'a'] += cantidad;
      ventas_sucursal[sucursal] += cantidad;
      ventas_producto[producto-'a'] += cantidad;
    }
  }
  for(int f = 0; f < NUM_SUC; f++){
    if(ventas_sucursal[f] != 0){
      for(int c = 0; c < NUM_PRODUC; c++){
        if(ventas_producto[c] != 0)
          cout << ventas[f][c] << " ";
      }
    cout << endl;
    }
  }

  cout << endl << endl;

}

/*********************************************************************/
