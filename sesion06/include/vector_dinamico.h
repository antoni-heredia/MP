#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO

//El mayor primo que como mucho se podra tener
const int MAYOR = 100;

//Tamaño de bloque
const int TAM_BLOQUE = 4;

//Tamaño inicial del vector
const int TAM = 5;

//Cantidad de cadenas iniciales que se pueden guardar
const int CANT_CADENAS = 10;


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


/*
  Funcion que actua para redimensionar el tamaño de un "vector" de cadenas;
  Basicamente redimensiona el tamño de un vector de cadenas clasicas
  alojado en el heap y devuelve la posicion donde se encuentra la
  primera poscion del vector

  p -> vector de cadenas clasicas a dimensionar
  tipo -> tipo de redimension a realizar
  cap -> capacidad actual del vector

*/
char ** RedimensionaVectorCadenas (char * * p, TipoRedimension tipo, int & cap);


/*
  Dada una cadena clasica nos devuelve la longitud total de la cadena
  cadena -> cadena clasica(incluye un '\0')
*/
int LongitudCadena(char * cadena);


#endif
