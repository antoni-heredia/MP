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
