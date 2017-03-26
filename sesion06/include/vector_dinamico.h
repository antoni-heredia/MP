#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO

//El mayor primo que como mucho se podra tener
const int MAYOR = 100;

//Tamaño de bloque
const int TAM_BLOQUE = 4;

//Tamaño inicial del vector
const int TAM = 5;

//Cantidad de cadenas iniciales que se pueden guardar
const int CANT_CADENAS = 2;


//enum para guardar los tipos de redimension que hacemos
enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};

// parejas primo-potencia
struct Pareja {
  int primo;
  int potencia;
};

/*
  Funcion que actua para redimensionar el tamaño de un "vector";
  Basicamente redimensiona el tamño de un vector alojado en el heap
  y devuelve la posicion donde se encuentra la primera poscion del vector

  p -> vector a dimensionar
  tipo -> tipo de redimension a realizar
  cap -> capacidad actual del vector

*/

int * Redimensiona (int * p, TipoRedimension tipo, int & cap);

char ** RedimensionaVectorCadenas (char * * p, TipoRedimension tipo, int & cap);

int LongitudCadena(char * cadena);


#endif
