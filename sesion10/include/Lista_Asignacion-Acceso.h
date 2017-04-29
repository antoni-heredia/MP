#ifndef LISTA_ASIGNACION
#define LISTA_ASIGNACION
using namespace std;

//Tipo de dato del cual esta formado el vector dinamico
typedef double TipoBase;	// Tipo de los elementos de la lista

//Constante que se usa cuando se quiere usar un valor nulo
const TipoBase NULO = 0;

// Cada nodo de la lista es de tipo "Nodo"

struct Nodo {
   TipoBase valor;
   Nodo *sig;
};

typedef Nodo * PNodo; 	// Para los punteros a nodos
typedef Nodo * Lista;	// Para la lista

const int TAMANIO = 10;
class Lista_Asignacion{

//Datos privados de la clase
private:
  Nodo * lista;
  int tamanio;
//Metodos publicos de la clase
public:
  /*
    Construtor que crea una lista vacia
    No recibe nada
  */
  Lista_Asignacion(void);

  /*
    Constructor que crea una lista con el tamaño indicado pero que el valor de
    cada nodo esta vacio
    Recibe:
      -tamanio un int que indica el tamaño de la lista
  */
  Lista_Asignacion(int tamanio);

  /*
    Constructor que crea una lista con el tamaño indicado pero que el valor de
    cada nodo sera el indicado en el argumento
    Recibe:
      -tamanio un int que indica el tamaño de la lista
      -valor un TipoBase que indica con que valor se inicia cada nodo
  */
  Lista_Asignacion(int tamanio, TipoBase valor);

  /*
    Constructor que crea una lista que sera la copia de otra lista
    Recibe:
      -otro es una Lista_Asignacion de la cual se copiaran los datos
  */
  Lista_Asignacion(Lista_Asignacion & otro);

  /*
    Destructor que libera la memoria que ocupa la lista
    No recibe nada
  */
  ~Lista_Asignacion(void);

  /*
    Metodo que comprueba si una lista esta vacia
    No recibe nada
    Devuelve un bool que indica true si la lista esta vacia y false si no lo
    esta
  */
  bool EstaVacia(void);


  /*
    El metodo devuelve el numero de nodos de la lista
    No recibe nada
    Devuelve un int con el numero de nodos
  */
  int NumeroDeNodos(void);


  /*
    Metodo que inserta un TipoBase en una posicion indicada
    Recibe:
      -valor un TipoBase con el valor que se quiere Insertar
      -pos un int que indica la posicion en la que se queire indicar
    No recibe nada
  */
  void Insertar(TipoBase valor, int pos);

  /*
    Metodo que borra un nodo de una lista
    Recibe:
      -pos un int que indica el nodo que se quiere borrar
    No recibe nada
  */
  void Borrar (int pos);

  /*
    Metodo que añade un valor al final de una lista
    Recibe:
      -valor un TipoBase que indica el valor que se quiere insertar
    No devuelve nada
  */
  void AniadirValor (TipoBase valor);

  /*
    El metodo devuelve el valor que hay en un nodo indicado
    Recibe:
      -pos un int que indica el numero del nodo a consultar
    Devuelve un TipoBase con el valor del nodo
  */
  TipoBase LeerValor (int pos);

  /*
    El metodo modifica el valor de un nodo
    Recibe:
      -pos un int del numero del nodo a modificar
      -val un TipoBase que sera con el que se modifique el nodo
    No devuelve nada
  */
  void ModificarValor (int pos, TipoBase val);

  /*
    Metodo que inicializa los nodos de una lista
    Recibe:
      -val un TipoBase que con el que se inicializa la lista, si no se indica
      por defecto sera nulo
    No devuelve nada
  */
  void Inicializa(TipoBase val = NULO);

  /*
    Metodo que muestra el valor de los nodos de la lista
    No recibe nada
    No devuelve nada
  */
  void Muestra(void);

  // Operador de asignacion usando otro VectorDinamico_Asignacion
  Lista_Asignacion & operator = (const Lista_Asignacion & otro);

  // Operador de asignacion usando un TipoBase
  Lista_Asignacion & operator = (const TipoBase & valor);

  TipoBase & operator [] (const int indice);

//Metodos privados de la clase
private:
  /*
    El metodo reserva memoria para un tamaño de lista predeterminada
    Recibe:
      -cant un int con el numero de nodos que se desea reservar
    No devuelve nada
  */
  void ReservaMemoria(int cant);

  /*
    El metodo copia todos los datos de una lista a otra
    Recibe:
      -otra una Lista_Asignacion de la cual se copiara los datos
  */
  void CopiarDatos(const Lista_Asignacion & otra);

  void LiberarMemoria(void);

};

#endif
