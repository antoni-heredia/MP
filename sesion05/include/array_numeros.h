#ifndef MATRIZ_NUMEROS
#define MATRIZ_NUMEROS

/*
  La funcion devuelve la posicion del mayor elemento de una region del vector
  -pv primera posicion del vector
  -izda limite inferior de la zona donde se va a buscar el mayor
  -dcha limite superior de la zona donde se va a buscar el mayor
*/

int * PosMayor (int * pv, int izda, int dcha);

/*
  La funcion rellena un vector con valores aleatorios
  -v[] es el vector que se va a Rellenar
  -util son las casillas que tiene el vector
  -min el minino de los numero aleatorios
  -max el maximo de los numeros aleatorios
*/
void RellenaVectorSinOrden (int * v, int util, int min, int max);

/*
  La funcion rellena un vector con valores aleatorios usando la funcion anterior
  y los ordena
  -v[] es el vector que se va a Rellenar
  -util son las casillas que tiene el vector
  -min el minino de los numero aleatorios
  -max el maximo de los numeros aleatorios
*/
void RellenaVector (int * v, int util, int min, int max);

/*
  La ordena un vector de int
  -v[] es el vector que se va a ordenar
  -numero de elementos que contiene el vector
*/
void OrdenaVector(int * v, int elementos);

/*
  Muestra los datos que hay en un vector
  -mensaje -> El mensaje que se muestra antes de los datos
  -v[] -> Vector donde estan los datos a mostrar
  -util -> Cantidad de datos que queremos mostrar
  -n -> Datos por linea a mostrar
*/
void MuestraVector (char *mensaje, int v[], int util, int n);

/*
  Mezcla los vector de forma ordenada y los guarda en mezcla
  -mezcla vector donde se guardan la mezcla de los vectores
  -v1 vector uno de la mezcla
  -util_v1 cantidad de elementos de v1
  -v2 vector dos de la mezcla
  -util_v2 cantidad de elementos de v2
*/
int MezclaVectores (int * mezcla, int * v1, int util_v1, int * v2, int util_v2);
#endif
