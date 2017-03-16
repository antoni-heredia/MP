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
#include "matriz_numeros.h"

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
  La funcion rellena un vector con valores aleatorios
  -v[] es el vector que se va a Rellenar
  -util son las casillas que se van a rellenar del vector
  -min el minino de los numero aleatorios
  -max el maximo de los numeros aleatorios
*/

void RellenaVector (int * v, int util, int min=0, int max=100){
  GeneradorAleatorioEnteros generador (min,max);
  for(int cont = 0; cont < util; cont++)
    *(v+cont) = generador.Siguiente();
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
        *(v+i-1) = intercambia;
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

}
