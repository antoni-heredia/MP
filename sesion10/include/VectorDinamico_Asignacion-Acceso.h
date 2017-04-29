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

//Clase Vector dinamico
class VectorDinamico_Asignacion{

//Datos privados de la clase
private:

  //Puntero que apunta al primer elemento del VectorDinamico_Asignacion
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


  /*
    Contructor indicando el numero de casillas.
    En caso de usar el constructor sin ningun argmumento se iniciara un vector
    con tamaño inicial = TAM_INICIAL
    Se crea un vector dinamico con un tamaño inicial indicado por el argumento,
  */

  VectorDinamico_Asignacion(const int casillas = TAM_INICIAL);

  /*
    Contructor de copia
    Se crea un vector dinamico con un tamaño inicial indicado por el tamaño del
    VectorDinamico_Asignacion pasado en el argumentos
    Tambien se inicializa el vector con un valor inicial igual a los valores
    del VectorDinamico_Asignacion pasado por el argumento
  */
  VectorDinamico_Asignacion(const VectorDinamico_Asignacion & otro);

  /*
    Destructor
    Se encargara de liberar la memoria ocupada por el
    VectorDinamico_Asignacion en el heap
  */
  ~VectorDinamico_Asignacion(void);

  // Operador de asignacion usando otro VectorDinamico_Asignacion
  VectorDinamico_Asignacion & operator = (const VectorDinamico_Asignacion & otro);

  // Operador de asignacion usando un TipoBase
  VectorDinamico_Asignacion & operator = (const TipoBase & valor);

  TipoBase & operator [] (const int indice);
  /*
    Metodo que nos devuelve si el VectorDinamico_Asignacion esta vacio.
    Devuelve un bool que sera TRUE si el VectorDinamico_Asignacion
    esta vacio o FALSE en caso contrario
    No recibe nada.
  */
  bool EstaVacio(void) const;

  /*
    Metodo que devuelve el numero de casillas que tiene el
    VectorDinamico_Asignacion
    Devuelve un int que indica el numero de casillas que tiene ocupadas.
    No recibe nada.
  */
  int NumeroDeCasillas(void) const;

  /*
    Metodo que devuelve el numero de casillas ocupadas que tiene el
    VectorDinamico_Asignacion
    Devuelve un int que indica el numero de casillas que tiene ocupadas.
    No recibe nada.
  */
  int NumeroDeCasillasOcupadas(void) const;

  /*
    Metodo que añade un valor al VectorDinamico_Asignacion en la ultima
    posicion
    No devuelve nada.
    Recibe un TipoBase que sera el que se añada al final del
    VçectorDinamico_ConstructorCopia.
  */
  void AniadirValor(const TipoBase valor);

  /*
    Metodo que devuelve el valor que se encuentra en la casilla indicada
    Devuelve un TipoBase que es el que se encuentra en la posicion indicada
    Recibe un int que sera el que indique el numero de la casillas
    PREC:
      pos < tamanio
  */
  TipoBase Valor(int pos) const;

  /*
    Metodo que devuelve el tipo de redimenion que se hace cuando se aumenta el
    tamanio del VectorDinamico_Asignacion
    Devuelve un TipoRedimension que indica el tipo de redimension actual
    No recibe nada
  */
  TipoRedimension Redimension(void) const;

  /*
    Metodo que establece un nuevo tipo de redimensionar para el
    ºVectorDinamico_Asignacion
    No devuelve nada
    Recibe el TipoRedimension nuevo que se va a establecer
  */
  void Redimension(TipoRedimension nueva_redimension);

  /*
    El metodo muestra por pantalla el contenido de un vector dinamico
    El metodo no recibe nada
    El metodo no devuelve nada
  */
  void ImprimeVector(string mensaje) const;

  /*
    El metodo inicializara el vector, tenga el tamaño que tenga con un dato
    Recibe:
      - dato TipoBase que sera el dato con el que se inicializara, con valor por
        defecto null
    No devuelve nada
  */
  void InicializarDato(TipoBase dato = NULO);

//Metodos privados de la clase
private:

  /*
    Metodo  que reserva un numero de casillas predeterminado
    No devuelve nada
    Recibe un int con el numero de casillas a reservar
  */
  void ReservaCasillas(int casillas);


  /*
    Metodo que libera la memoria de un vector dinamico
    No recibe nada
    No devuelve nada
  */
  void LiberarMemoria(void);

  /*
    El metodo copia todos los valores de un vector dinamico a nuestro vector
    dinamico
    No devuelve nada
    Recibe un puntero a un VectorDinamico_Asignacion
  */
  void CopiarDatos(const VectorDinamico_Asignacion & otro);

  /*
    El metodo redimension el tamaño del vector dinamico para que tenga mas
    capacidad
    No devuelve nada
    No recibe nada
  */
  void Redimensiona(void);

};
#endif
