#include  <iostream>
#include "sucursales.h"
using namespace std;
//Devuelve la cantidad de digitos que tiene un numero dado
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

int ventasSucursal( int  ventas[][NUM_PRODUC], int sucursal){
  int ventas_sucursal = 0;
  for(int c = 0; c < NUM_PRODUC; c++){
    ventas_sucursal += ventas[sucursal-1][c];
  }
  return ventas_sucursal;
}

int masVentas( int  ventas[][NUM_PRODUC]){
  int suc_mas = 1;
  int mas_ventas = ventasSucursal(ventas, 1);
  int ventas_sucursal ;
  for(int f = 2; f <= NUM_SUC; f++){
    ventas_sucursal = ventasSucursal(ventas, f);
    if(mas_ventas < ventas_sucursal){
      mas_ventas = ventas_sucursal;
      suc_mas = f;
    }
  }
  return suc_mas;
}

void muestraVentasSucursales(int  ventas[][NUM_PRODUC]){
  int ventas_sucursal;
  for(int f = 1; f <= NUM_SUC; f++){
    ventas_sucursal = ventasSucursal(ventas, f);
    if(ventas_sucursal != 0){
      cout << "Ventas sucural " << f << ": " << ventas_sucursal << endl;
    }
  }
}


int sucursalesConVentas(int ventas[][NUM_PRODUC]){

  int ventas_sucursal;
  int cant = 0;
  for(int f = 1; f <= NUM_SUC; f++){
    ventas_sucursal = ventasSucursal(ventas, f);
    if(ventas_sucursal != 0){
      cant++;
    }
  }
  return cant;
}

int totalUnidadesVendidas(int ventas[][NUM_PRODUC]){
  int ventas_sucursal;
  int cant = 0;

  for(int f = 1; f <= NUM_SUC; f++) cant += ventasSucursal(ventas, f);

  return cant;

}


char productoMasVendido(int ventas_producto[NUM_PRODUC]){
  char pro_mas = 'a';
  int mas_ventas = ventas_producto['a'-'a'];
  int ventas;
  for(int f = 'b'; f <= 'j'; f++){
    ventas = ventas_producto[f-'a'];
    if(ventas>mas_ventas){
      mas_ventas = ventas;
      pro_mas = f;
    }
  }
  return pro_mas;
}
void muestraVentasProducto(int ventas_producto[NUM_PRODUC]){
  for(char c = 'a'; c <= 'j'; c++)
    if(ventas_producto[c-'a'] != 0)
      cout << "Del producto " << c << " se han vendido: "
           << ventas_producto[c-'a'] << endl;
}

int tiposDiferentesDeProductos(int ventas_producto[NUM_PRODUC]){
  int tipos = 0;

  for(char c = 'a'; c <= 'j'; c++)
   if(ventas_producto[c-'a'] != 0){
     tipos++;

   }

  return tipos;
}

int totalUnidadesVendidasProducto(int ventas_producto[NUM_PRODUC]){
  int cant = 0;
  for(char c = 'a'; c <= 'j'; c++) cant += ventas_producto[c-'a'];
  return cant;

}
