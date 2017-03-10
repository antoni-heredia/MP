#include "MiCadenaClasica.h"
int longitud_cadena(char *cadena){
  int longitud = 0;
  char caracter = *(cadena);
  //Recorremos el vector mientras no sea el caracter \0
  while(caracter != '\0' ){
    longitud++;
    caracter = *(cadena+longitud);
  }
  return longitud;
}
