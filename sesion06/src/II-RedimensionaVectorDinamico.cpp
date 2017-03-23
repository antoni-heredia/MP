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
using namespace std;
//Tamaño de bloque
const int TAM_BLOQUE = 4;

//Tamaño inicial del vector
const int TAM = 5;

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

  if(argc>2){
    //En caso de que el numero de parametros sea 2 contando con el nombre del
    //programa
    cout << "Numero de argumentos invalidos...." << endl;
    cout << "Saliendo del programa...." << endl;
    exit(1);
  }

  int cap = TAM;
  int * ptr = new int [cap];
  int argumento;
  //Vemos la cantidad de elementos y segun cual sea realizamos una acciones u
  //otras
  TipoRedimension tipo = TipoRedimension::DeUnoEnUno;
  if(argc==2){
    argumento = atoi(argv[1]);
    //En caso de que tenga un argumento dependiendo de su valor cambiara
    //el tipo de redimension
    if(argumento == 2)
      tipo = TipoRedimension::EnBloques;
    else if(argumento == 3)
      tipo = TipoRedimension::Duplicando;
    else{
      //Como el argumento no tiene el valor correcto se sale del programa
      cout << "El argumento es invalido...." << endl;
      cout << "Saliendo del programa...." << endl;
      exit(1);
    }
  }

  //Variables que usaremos en la lectura de datos
  int numero;
  string frase;

  //La cantidad de elementos del vector
  int cant_vect = 0;

  //Pedimos que introduzca los datos
  cout << "Introduzca un entero: " ;
  cin >> frase;

  //Si lo introducido no es "FIN" entra en el while
  while(frase != "FIN"){
    //Como ya sabemos que no es "FIN" convertimos el dato a int
    numero = stoi(frase);

    //Si no queda espacio redimensionamos el vector
    if(cant_vect>=cap)
      ptr = Redimensiona(ptr,tipo, cap);

    //Añadimos el nuevo elemento al vector
    *(ptr+cant_vect) = numero;

    //Aumentamos la cantidad de elementos
    cant_vect++;

    //Volvemos a pedir que nos introduzca los datos
    cout << "Introduzca un entero: " ;
    cin >> frase;
  }

  //Un simple bucle for para mostrar los datos leidos
  cout << "Los datos leidos son: " << endl;
  for(int x = 0; x < cant_vect; x++)
    cout << *(ptr+x) <<endl;

  //Liberamos la memoria reservada en el heap
  delete [] ptr;

  cout << endl << endl;
	return (0);
}

/*********************************************************************/
