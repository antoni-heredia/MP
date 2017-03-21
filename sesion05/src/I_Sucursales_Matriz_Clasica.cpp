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
#include "sucursales.h"

using namespace std;


int main()
{


  int  ventas[NUM_SUC][NUM_PRODUC];
  int ventas_producto[NUM_PRODUC];

  string cadena;
  char producto;
  int sucursal = 0;
  int cantidad;

  for(int f = 0; f < NUM_SUC; f++){
    for(int c = 0; c < NUM_PRODUC; c++)
      ventas[f][c] = 0;
  }
  for(int c = 0; c < NUM_PRODUC; c++)
    ventas_producto[c] = 0;
  int operaciones = 0;
  while (getline (cin, cadena) && sucursal != -1) {
    int pos = 0;
    //Recogemos los datos de la cadenas
    char * ptr_cadena = &cadena[0];
    sucursal = atoi(ptr_cadena+pos);

    if(sucursal != -1){
      operaciones++;
      pos += 1 + numDigitos(sucursal);
      producto = *(ptr_cadena+pos);
      pos += 2;
      cantidad = atoi(ptr_cadena+pos);
      ventas[sucursal-1][producto-'a'] += cantidad;
      ventas_producto[producto-'a'] += cantidad;
    }
  }

  cout << "El numero total de operaciones de venta es: " << operaciones << endl;

  int suc_mas = masVentas(ventas);
  int mas_ventas = ventasSucursal(ventas, suc_mas);
  cout << "La sucursal que mas ha vendido ("<< mas_ventas <<" ventas) ha sido: "
       << suc_mas << endl;
  muestraVentasSucursales(ventas);

  cout << "El numero con sucursales con ventas es: "
       << sucursalesConVentas(ventas) << endl;

  cout << "El total de unidades vendidas es de: "
       << totalUnidadesVendidas(ventas) << endl;

  cout << "El producto mas vendido ha sido: "
       << productoMasVendido( ventas_producto) << endl;

  muestraVentasProducto(ventas_producto);

  cout << "Se han vendido " << tiposDiferentesDeProductos(ventas_producto) <<
          " productos diferentes" << endl;

  cout << "El total de unidades vendidas(calculadas por producto) es de: "
       << totalUnidadesVendidasProducto(ventas_producto) << endl;

  cout << endl << endl;

}

/*********************************************************************/
