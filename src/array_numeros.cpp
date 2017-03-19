/***************************************************************************/
// CLASE GeneradorAleatorioEnteros
//
//  Ejemplo de uso:
/*
	int menor, mayor;
	......

	// Objeto generador de n�meros aleatorios
	GeneradorAleatorioEnteros generador_aleat (menor, mayor);

	int valor_generado = generador_aleat.Siguiente();
*/

/***************************************************************************/
#include<cstdlib>
#include<cctype>
#include <iostream>
#include <random>
#include <chrono>
#include "array_numeros.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{
private:

   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   /************************************************************************/
   long long Nanosec(){
      return (chrono::high_resolution_clock::now().
              time_since_epoch().count());
   }
   /************************************************************************/

public:

   /************************************************************************/
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }

   /************************************************************************/
   GeneradorAleatorioEnteros(int min, int max) {
      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006

      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }

   /************************************************************************/
   int Siguiente(){
      return (distribucion_uniforme(generador_mersenne));
   }
   /************************************************************************/
};

/////////////////////////////////////////////////////////////////////////////


/*
  La funcion devuelve la posicion del mayor elemento de una region del vector
  -pv primera posicion del vector
  -izda limite inferior de la zona donde se va a buscar el mayor
  -dcha limite superior de la zona donde se va a buscar el mayor
*/

int * PosMayor (int * pv, int izda, int dcha){

  int * mayor = pv+izda;
  for(int pos  = izda+1; pos < dcha; pos++){
    if( *(pv+pos) > *(mayor) ){
      mayor = pv+pos;
    }
  }
  return mayor;
}

/*
  La funcion rellena un vector con valores aleatorios
  -v[] es el vector que se va a Rellenar
  -util son las casillas que se van a rellenar del vector
  -min el minino de los numero aleatorios
  -max el maximo de los numeros aleatorios
*/
void RellenaVectorSinOrden (int * v, int util, int min=0, int max=100){
  GeneradorAleatorioEnteros generador (min,max);
  for(int cont = 0; cont < util; cont++)
    *(v+cont) = generador.Siguiente();

}




void RellenaVector (int * v, int util, int min=0, int max=100){
  RellenaVectorSinOrden (v, util, min, max);
  OrdenaVector(v, util);
}


/*
  La ordena un vector de int
  -v[] es el vector que se va a ordenar
*/
void OrdenaVector(int * v, int elementos){
  bool cambio = true;
  int intercambia;

  for (int izda = 0; izda < elementos && cambio; izda++){
    cambio = false;
    for (int i = elementos-1 ; i > izda ; i--){
      if (*(v+i) < *(v+i-1)){
        cambio = true;
        intercambia = *(v+i);
        *(v+i) = *(v+i-1);
        *(v+i-1) = 0intercambia;
      }
    }
  }
}

/*
  Muestra los datos que hay en un vector
  -mensaje -> El mensaje que se muestra antes de los datos
  -v[] -> Vector donde estan los datos a mostrar
  -util -> Cantidad de datos que queremos mostrar
  -n -> Datos por linea a mostrar
*/

void MuestraVector (char * mensaje, int * v, int util, int n){

  cout << mensaje << endl;

  for(int x = 0; x<util; x++){
    if( x % n == 0)
      cout << endl;
    cout << *(v+x) << " ";
  }
  cout << endl << endl;
}

/*
  Mezcla los vector de forma ordenada y los guarda en mezcla
  -mezcla vector donde se guardan la mezcla de los vectores
  -v1 vector uno de la mezcla
  -util_v1 cantidad de elementos de v1
  -v2 vector dos de la mezcla
  -util_v2 cantidad de elementos de v2
*/
int MezclaVectores (int * mezcla, int * v1, int util_v1, int * v2, int util_v2){

  int fin;

  if(util_v1>util_v2)
    fin = util_v1;
  else
    fin = util_v2;
  int elemento = 0;
  for(int pos = 0;pos<fin;pos++){
    if(pos<util_v1){
      *(mezcla+elemento) = *(v1+pos);
      elemento++;
    }

    if(pos<util_v2){
      *(mezcla+elemento) = *(v2+pos);
      elemento++;
    }
  }
  return elemento;
}
