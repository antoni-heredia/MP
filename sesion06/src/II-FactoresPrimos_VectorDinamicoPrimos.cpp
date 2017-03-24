/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 6
//
/*
*/
/*********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;
//Tamaño de bloque
const int TAM_BLOQUE = 4;
//TAmaño del vector dinamico
const int TAM = 2;
//El mayor primo que como mucho se podra tener
const int MAYOR = 100;

// parejas primo-potencia
struct Pareja {
  int primo;
  int potencia;
};

//enum para guardar los tipos de redimension que hacemos
enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};

/*
  Funcion que actua para redimensionar el tamaño de un "vector";
  Basicamente redimensiona el tamño de un vector alojado en el heap
  y devuelve la posicion donde se encuentra la primera poscion del vector

  p -> vector a dimensionar
  tipo -> tipo de redimension a realizar
  cap -> capacidad actual del vector

*/

int * Redimensiona (int * p, TipoRedimension tipo, int & cap){

  //Hacemos una copia de la capacidad actual ya que se va a modificar y la vamos
  //a necesitar a la hora de copiar el vector antiguo en el nuevo
  int casillas_actuales = cap;

  //Vemos la capacidad que va a tener la redimension usando el enum
  if(tipo == TipoRedimension::DeUnoEnUno)
    cap++;
  else if (tipo == TipoRedimension::EnBloques)
    cap+=TAM_BLOQUE;
  else
    cap*=2;

  //Creamos el nuevo vector redimensionado
  int * ptr_new = new int [cap];

  //Copiamos el vector antiguo en el nuevo
  for(int i = 0; i<=casillas_actuales;i++){
    *(ptr_new+i) = *(p+i);
  }

  //Borramos la memoria reservada en el heap antes de sobreescribir el puntero
  //ya que despues no podremos
  delete [] p;
  return ptr_new;

}
/*********************************************************************/


int main(int argc, char * argv[])
{

  if(argc>3 || argc == 1){
    //En caso de que el numero de parametros sea 2 contando con el nombre del
    //programa
    cout << "Numero de argumentos invalidos...." << endl;
    cout << "Saliendo del programa...." << endl;
    exit(1);
  }



  //El mayor primo que se calculara que por defecto se usa la constante MAX
  int p = MAYOR;

  //El numero que se quiere factorizar
  int n;

  //Como minimo le vamos a tener que pasar un argumento este sera el numero a
  //factorizar
  n = atoi(argv[1]);


  //En el caso de que hayamos pasado 2 elementos pues el segundo elemento sera
  //el mayor primo que como mucho tendremos
  if(argc==3) p = atoi(argv[2]);

  //El vector donde se guardan los datos como no sabemos cuantos primos va a
  //haber, ponemos un numero pequeño ya que luego
  //podemos ir aumentando ese tamaño
  int * primos = new int [TAM];

  //Capacidad inicial del vector y cantidad de elementos actualmente del vector
  int cap = TAM;
  int cant_vect = 0;

  //Vector para marcar cuales son primos y cuales no
  bool es_primo[p];


  //por defecto diremos que todos son primos y luego iremos quitando
  for (int i=0; i<=p; i++)
		es_primo[i] = true;


	// Criba, copiado del ejercicio 10 de las soluciones de FP
	for (int num=2; num*num <= p; num++) { // empezar por num=2 y
										           // terminar si num^2>limite
		if (es_primo[num]) {
			for (int k=2; k*num <= p; k++) { // marcar los m�ltiplos de
				es_primo[k*num] = false;		  // num como no-primos
			}
		} // if (es_primo[num])

	} // for num



	// Ya est�n "tachados" los n�meros no-primos en "es_primo".
	// Ahora recorremos "es_primo" completamente y copiamos a
	// "primos" �nicamente los que permacenen a "true".
  TipoRedimension tipo = TipoRedimension::DeUnoEnUno;

	for (int i=1; i<=p; i++) {

		if (es_primo[i]) {
      //Si no hay espacio le añadimos na posicion al vector dinamico
      if(cant_vect==cap) primos = Redimensiona(primos,tipo, cap);

      //Añadimos el primo al vector dinamico
      *(primos+cant_vect) = i;

      //Aumentamos la cantidad de primos introducidos
      cant_vect++;
		}

	}

  /***********************************************************************/
	// Calcualr descomposici�on en factores primos
	/***********************************************************************/




	const int CASILLAS_DESCOMPOSICION = 50;

	Pareja descomposicion[CASILLAS_DESCOMPOSICION] = {{0,0}};
	int utilizados_descomposicion = 0;


	//  C�lculo

	int pos_primos = 1;

	int dividendo = n;
	int divisor = primos[pos_primos]; // Empezar por el 2 - casilla 1
									  // (la casilla 0 guarda el 1)

	while (dividendo != 1) {

		if  (dividendo%divisor==0)	{ // Se encontr� un factor primo

			descomposicion[utilizados_descomposicion].primo = divisor;
			descomposicion[utilizados_descomposicion].potencia = 1;

			// Se sigue probando con el mismo factor

			dividendo = dividendo / divisor;

			while (dividendo%divisor==0) {
				descomposicion[utilizados_descomposicion].potencia++;
				dividendo = dividendo / divisor;
			}

			utilizados_descomposicion++;
		}

		// Probar con el siguiente primo
		pos_primos++;
		divisor = primos[pos_primos];
	}

	cout << n << " = ";

	for (int i=0; i<utilizados_descomposicion-1; i++) {
		cout << setw(2) << descomposicion[i].primo << "^"
		     << descomposicion[i].potencia << " x ";
	}
	cout << setw(3) << descomposicion[utilizados_descomposicion-1].primo
	     << "^" << descomposicion[utilizados_descomposicion-1].potencia;


  //Liberamos la memoria reservada en el heap
  delete [] primos;

  cout << endl << endl;
	return (0);
}

/*********************************************************************/
