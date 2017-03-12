#include "MiCadenaClasica.h"
#include <string>

//Esta funcion nos devuelve la longitud de una cadena
int longitud_cadena(char *cadena)
{
  int longitud = 0;
  char * copia = cadena;
  //Recorremos el vector mientras no sea el caracter \0
  while(*(copia)){
    longitud++;
    copia++;
  }
  return longitud;
}

//Nos devuelve si la cadena es un palindromo
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

//Nos dice cual de las dos cadenas es mayor
int comparar_cadenas(char * cadena1, char * cadena2){
  int long1 = longitud_cadena(cadena1);
  int long2 = longitud_cadena(cadena2);

  //Por defecto pensamos que son iguales
  int devuelve = 0;

  //Comparamos cual de las dos cadenas es mayor
  if( long1 > long2)
    devuelve = 1;
  else if (long1 < long2)
    devuelve = -1;

  return devuelve;
}

//Copia una cadena en otra, esta funcion sobreescibre el contenido de la cadena
void copiar_cadena(char * destino, const char * origen){
  //Vemos la longitud de la segunda cadena para recorrerla
  int longcad = longitud_cadena((char *)origen);

  //Recorremos la cadena y la vamos copiando
  for(int pos = 0; pos < longcad; pos++ ){
    destino[pos] = *(origen+pos);
  }

}

//encadena una cadena con otra
void encadenar_cadena(char * destino, const char * origen){
  //Vemos la longitud de la segunda cadena para recorrerla
  int longori = longitud_cadena((char *)origen);
  int longdes = longitud_cadena(destino);
  //Recorremos la cadena y la vamos copiando
  for(int pos = 0; pos < longori; pos++ ){
    destino[longdes+pos] = *(origen+pos);
  }

}

//Esta funcion devuelve una subcadena de la cadena original
char* extraer_subcadena(char * cadena, int p, int l){

  //Donde se guardara la subcadena
  const int TAM = 256;
  char sub_cadena[TAM];
  char * prt_sub_cadena = sub_cadena;

  int longcad = longitud_cadena(cadena);
  int fin = p+l;

  //Si es mas grande que la longitud el final es el final
  if(fin>longcad)
    fin=longcad;

  //Vamos guardando los elementos desde p hasta el final
  int pos;
  for(pos = p; pos < fin; pos++){
    *(prt_sub_cadena+pos-p) = *(cadena+pos);
  }

  //Añadimos el \0
  *(prt_sub_cadena+pos-p) = '\0';

  //Devolvemos la cadena extraida
  return prt_sub_cadena;
}

//Esta funcion invierte una cadena
char * invertir_cadena(char * cadena){

  //Donde se guardara la cadena invertida
  const int TAM = 256;
  char cad_inver[TAM];
  char * prt_cad_inver = cad_inver;
  int longcad = longitud_cadena(cadena);

  //Recorremos desde el final hasta el principio
  int pos;
  for(pos = longcad-1; pos >= 0; pos--)
  {
    *(prt_cad_inver+(longcad-1)-pos) = *(cadena+pos);
  }

  //Guardamos el \0 para indicar el final de la cadena clasica
  *(prt_cad_inver+(longcad-1)-pos) = '\0';

  return prt_cad_inver;
}
