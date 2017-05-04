/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 11
//
/*
  Fichero donde se encuentra la declaracion de la clase VectorDinamico, junto
  a todos los datos necesarios para usar la misma
 */
/*********************************************************************/

#ifndef VECTORDINAMICO_ASIGNACION_ACCESO
#define VECTORDINAMICO_ASIGNACION_ACCESO

using namespace std;

//Tipo de dato del cual esta formado el vector dinamico
typedef double TipoBase;

//enum para guardar los tipos de redimension que hacemos
enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};

//Tamaño del bloque de redimension
const int TAM_BLOQUE = 5;

const TipoBase NULO = 0;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Clase Vector dinamico
class VectorDinamico{

//Datos privados de la clase
private:

  //Puntero que apunta al primer elemento del VectorDinamico
  TipoBase * vector;

  //Tamaño actual del vector dinamico
  int num_casillas;

  //Casillas ocupadas actualmente
  int num_ocupadas;

  //Redimension que se realiza cuando hay que aumentar el numero de casillas del
  //vector
  TipoRedimension redimension;

  //Tamaño inicial del vector dinamico
  static const int TAM_INICIAL = 10;

  //Cantidad de elemenos por columna
  static const int COLS = 10;

//Metodos publicos de la clase
public:

///////////////////////////////////////////////////////////////////////////////

  /*
    Contructor indicando el numero de casillas.
    En caso de usar el constructor sin ningun argmumento se iniciara un vector
    con tamaño inicial = TAM_INICIAL
    Se crea un vector dinamico con un tamaño inicial indicado por el argumento,
  */

  VectorDinamico(const int casillas = TAM_INICIAL);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Contructor de copia
    Se crea un vector dinamico con un tamaño inicial indicado por el tamaño del
    VectorDinamico pasado en el argumentos
    Tambien se inicializa el vector con un valor inicial igual a los valores
    del VectorDinamico pasado por el argumento
  */
  VectorDinamico(const VectorDinamico & otro);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Destructor
    Se encargara de liberar la memoria ocupada por el
    VectorDinamico en el heap
  */
  ~VectorDinamico(void);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Metodo que nos devuelve si el VectorDinamico esta vacio.
    Devuelve un bool que sera TRUE si el VectorDinamico
    esta vacio o FALSE en caso contrario
    No recibe nada.
  */
  bool EstaVacio(void) const;

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Metodo que devuelve el numero de casillas que tiene el
    VectorDinamico
    Devuelve un int que indica el numero de casillas que tiene ocupadas.
    No recibe nada.
  */
  int NumeroDeCasillas(void) const;

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Metodo que devuelve el numero de casillas ocupadas que tiene el
    VectorDinamico
    Devuelve un int que indica el numero de casillas que tiene ocupadas.
    No recibe nada.
  */
  int NumeroDeCasillasOcupadas(void) const;

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Metodo que añade un valor al VectorDinamico en la ultima
    posicion
    No devuelve nada.
    Recibe un TipoBase que sera el que se añada al final del
    VçectorDinamico_ConstructorCopia.
  */
  void AniadirValor(const TipoBase valor);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Metodo que devuelve el tipo de redimenion que se hace cuando se aumenta el
    tamanio del VectorDinamico
    Devuelve un TipoRedimension que indica el tipo de redimension actual
    No recibe nada
  */
  TipoRedimension Redimension(void) const;

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Metodo que establece un nuevo tipo de redimensionar para el
    ºVectorDinamico
    No devuelve nada
    Recibe el TipoRedimension nuevo que se va a establecer
  */
  void Redimension(TipoRedimension nueva_redimension);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo muestra por pantalla el contenido de un vector dinamico
    El metodo no recibe nada
    El metodo no devuelve nada
  */
  void ImprimeVector(string mensaje) const;

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  // Operador de asignacion usando otro VectorDinamico
  VectorDinamico & operator = (const VectorDinamico & otro);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  // Operador de asignacion usando un TipoBase
  VectorDinamico & operator = (const TipoBase & valor);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  TipoBase & operator [] (const int indice);
  
///////////////////////////////////////////////////////////////////////////////

// Operadores relacionales
bool operator == (const VectorDinamico & otro);

bool operator != (const VectorDinamico & otro);

bool operator > (const VectorDinamico & otro);

bool operator <= (const VectorDinamico & otro);

bool operator < (const VectorDinamico & otro);

bool operator >= (const VectorDinamico & otro);

//Metodos privados de la clase
private:

///////////////////////////////////////////////////////////////////////////////

  /*
    Metodo  que reserva un numero de casillas predeterminado
    No devuelve nada
    Recibe un int con el numero de casillas a reservar
  */
  void ReservaCasillas(int casillas);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Metodo que libera la memoria de un vector dinamico
    No recibe nada
    No devuelve nada
  */
  void LiberarMemoria(void);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo copia todos los valores de un vector dinamico a nuestro vector
    dinamico
    No devuelve nada
    Recibe un puntero a un VectorDinamico
  */
  void CopiarDatos(const VectorDinamico & otro);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo redimension el tamaño del vector dinamico para que tenga mas
    capacidad
    No devuelve nada
    No recibe nada
  */
  void Redimensiona(void);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo inicializara el vector, tenga el tamaño que tenga con un dato
    Recibe:
      - dato TipoBase que sera el dato con el que se inicializara, con valor por
        defecto null
    No devuelve nada
  */
  void InicializarDato(TipoBase dato = NULO);

///////////////////////////////////////////////////////////////////////////////

};
#endif
