#include "MiCadenaClasica.h"
#include <string>

int longitud_cadena(char *cadena)
{
  int longitud = 0;
  char caracter = *(cadena);
  //Recorremos el vector mientras no sea el caracter \0
  while(caracter != '\0' ){
    longitud++;
    caracter = *(cadena+longitud);
  }
  return longitud;
}

bool Palindromo(char * cadena){

  //Guardamos la longitud de la cadena
  int final = longitud_cadena(cadena)-1;
  int total_utilizados = final;
  bool palindromo = true;

  for(int inicio = 0; inicio <= (total_utilizados-1)/2 && palindromo; inicio++)
  {

    /*
			comparamos si las posiciones son iguales
	    	de no ser iguales diremos que no es un palindromo
	    	pasamos los dos a minuscula ya que no es algo que
			nos importe en este caso
		*/

		if( tolower(*(cadena+final))  != tolower(*(cadena+inicio)))
			palindromo = false;

		//El elemento a comparar es uno menos
		final--;
  }

  return palindromo;

}

int comparar_cadenas(char * cadena1, char * cadena2){
  int long1 = longitud_cadena(cadena1);
  int long2 = longitud_cadena(cadena2);

  //Por defecto pensamos que son iguales
  int devuelve = 0;

  if( long1 > long2)
    devuelve = 1;
  else if (long1 < long2)
    devuelve = -1;

  return devuelve;
}

void copiar_cadena(char * destino, char * origen){
  int longcad = longitud_cadena(origen);
  for(int pos = 0; pos < longcad; pos++ ){
    destino[pos] = *(origen+pos);
  }
}
