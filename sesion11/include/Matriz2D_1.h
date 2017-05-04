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
  Fichero donde se encuentra la declaracion de la clase Matriz2D_1,junto
  a todos los datos necesarios para usar la misma
 */
/*********************************************************************/
#ifndef MATRIZ2D_1
#define MATRIZ2D_1

using namespace std;

//Tipo de dato del cual esta formado el vector dinamico
typedef double TipoBase;

const TipoBase NULO = 0;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class Matriz2D_1{

private:
  TipoBase * * matriz;
  int fils;
  int cols;
public:

///////////////////////////////////////////////////////////////////////////////

  /*
    El contructor vacio se encargara de crear una matriz vacia. Es decir
    sin tamaño ni  elementos
    No recibe nada.
  */
  Matriz2D_1(void);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Este constructor crea una matriz cuadrada
    Recibe:
      -num un int que indica el numero de filas y columnas
  */
  Matriz2D_1(int num);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Este constructor crea una matriz rectangular
    Recibe:
      -fils un int con el numero de filas
      -cols un int con el numero de columnas
  */
  Matriz2D_1(int fils, int cols);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Este constructor crea una matriz rectangular y ademas la inicializa con
    un dato pasado por el argumento
    Recibe:
      -fils un int con el numero de filas
      -cols un int con el numero de columnas
      -dato un TipoBase que indica el dato con el que se inicializara
  */
  Matriz2D_1(int fils, int cols, TipoBase dato);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    Este constructor crea una copia profunda de otra Matriz2D_1
    Recibe:
      - otra una Matriz2D_1 que seara de la cual se copien los
        datos
  */
  Matriz2D_1(Matriz2D_1 & otra);
  
///////////////////////////////////////////////////////////////////////////////
  
///////////////////////////////////////////////////////////////////////////////

  /*
    El destructor se encargara de liberar la memoria ocupada por la matriz
    No recibe nada
  */
  ~Matriz2D_1(void);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo devolvera si la matriz esta vacia
    No recibe nada
    Devuelve un bool con el resultado de la comprobacion
  */
  bool EstaVacia(void);
  
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  // Operador de asignacion usando otro VectorDinamico_Asignacion
  Matriz2D_1 & operator = (const Matriz2D_1 & otro);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  // Operador de asignacion usando un TipoBase
  Matriz2D_1 & operator = (const TipoBase & valor);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
  // Operador de acceso a un elemento
  TipoBase & operator () (const int fils, const int cols);

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo muestra el contenido de la matriz
    No recibe nada
    No devuelve nada
  */
  void Mostrar(void);
  
///////////////////////////////////////////////////////////////////////////////
  
//Metodos privados de la clase
private:
  
///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo reservara memoria para un numero de filas y columnas indicados
    en los argumentos
    Recibe:
      -fils un int  que sera el numero de filas
      -cols un int  que es el numero de columnas
    No devuelve nada
  */
  void ReservaMemoria(int fils, int cols);
  
///////////////////////////////////////////////////////////////////////////////
  
///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo copia todos los datos de una matriz a otra
    Recibe:
      -otra una Matriz2D_1 de la cual se copiara los datos
  */
  void CopiarDatos(const Matriz2D_1 & otra);
  
///////////////////////////////////////////////////////////////////////////////
    
///////////////////////////////////////////////////////////////////////////////

  /*
    El metodo inicializara la matriz, tenga el tamaño que tenga con un dato
    Recibe:
      - dato TipoBase que sera el dato con el que se inicializara, con valor por
        defecto null
    No devuelve nada
  */
  void InicializarDato(TipoBase dato = NULO);
  
///////////////////////////////////////////////////////////////////////////////
  
///////////////////////////////////////////////////////////////////////////////

  void LiberarMemoria(void);

///////////////////////////////////////////////////////////////////////////////

};

#endif
