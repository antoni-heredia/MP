#ifndef SUCURSALES
#define SUCURSALES
const int MAX = 256;
const int NUM_SUC = 100;
const int NUM_PRODUC = 'j' - 'a';
//Devuelve la cantidad de digitos que tiene un numero dado
int numDigitos(int numero);

//Devuelve la cantidad de ventas dada una sucursal
int ventasSucursal( int  ventas[][NUM_PRODUC], int sucursal);

//Devuelve la sucursal con mas ventas
int masVentas( int  ventas[][NUM_PRODUC]);

//Muestra las ventas de cada sucursal
void muestraVentasSucursales(int ventas[][NUM_PRODUC]);

//Nos dice la cantidad de sucursales con ventas
int sucursalesConVentas(int ventas[][NUM_PRODUC]);

//Nos devuelve el total de unidades vendidas
int totalUnidadesVendidas(int ventas[][NUM_PRODUC]);

//Nos dice el producto mas vendido
char productoMasVendido(int ventas_producto[NUM_PRODUC]);

//Devuelve las ventas de cada producto
void muestraVentasProducto(int ventas_producto[NUM_PRODUC]);

//Devuelve la cantidad de  difrentes prodcutos vendidos
int tiposDiferentesDeProductos(int ventas_producto[NUM_PRODUC]);

//Devuelve el total de unidades vendidas pero calculadas con el producto
int totalUnidadesVendidasProducto(int ventas_producto[NUM_PRODUC]);
#endif
