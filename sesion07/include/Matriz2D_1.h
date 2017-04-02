#ifndef MATRIZ2D_1
#define MATRIZ2D_1

/*
  Struct que nos define un tipo nuevo llamado Matriz2D

  datos -> Matriz dinamica (alojada en el heap).
  fils -> Nº de filas que contiene la Matriz
  cols -> Nº de columnas que contiene la matriz
*/
typedef struct {
  int ** datos; // Puntero a vector de punteros a los datos
  int fils; // Num. de filas
  int cols; // Num. de columnas
} Matriz2D;

/*
  Devuelve una Matriz2D vacia pero con tantas filas y columnas como se haya
  indicado.
  fils -> Nº de filas
  cols -> Nº de columnas
*/

Matriz2D  CreaMatriz2D (int fils, int cols);

/*
  Libera todas las posiciones de memoria de los datos de un Matriz2D

  matriz-> matriz que se quiere liberar la memoria
*/
void  LiberaMatriz (Matriz2D  &matriz);


/*
  Devuelve una Matriz2D con tantas filas y columnas como se haya
  indicado y ademas va pidiendo los valores para llenarla
  fils -> Nº de filas
  cols -> Nº de columnas
*/

Matriz2D  CreaMatriz2DValores (int fils, int cols);



/*
  Devuelve una Matriz2D con tantas filas y columnas como se haya
  indicado y ademas la rellena con valores aleatorios
  fils -> Nº de filas
  cols -> Nº de columnas
*/
Matriz2D  CreaMatriz2DValoresAleatorios (int fils, int cols);


/*
  Muestra todos los datos de la matriz

  matriz -> matriz de la que se quiere mostrar los datos
*/

void MuestraMatriz2D(Matriz2D matriz);

/*
  Devuelve una copia de la matriz del argumento
  matriz -> matriz que vamos a copiar a otra matriz
*/
Matriz2D CopiaProfunda(Matriz2D matriz);


/*
  Devuelve una matriz que es la extracion de una matriz dada
  matriz -> matriz desde donde vamos a extraer los datos
  f_origen -> fila desde donde se empieza a copiar
  c_origen -> columna desde donde se empieza a copiar
  f_fin -> fila donde se acaba de copiar
  c_fin -> columna donde se acaba de copiar
*/
Matriz2D ExtraerMatriz(Matriz2D matriz,
                      int f_origen,int c_origen,int f_fin,int c_fin);
/*
  Elimina las filas de una matriz
  matriz -> matriz a la que se le va a eliminar la fila
  fila -> la fila que se va a eliminarlas
*/

Matriz2D EliminaFila(Matriz2D matriz, int fila);

/*
  Elimina la columna de una matriz
  matriz -> matriz a la que se le va a eliminar la fila
  columna -> la columna que se va a eliminar
*/

Matriz2D EliminaColumna(Matriz2D matriz, int columna);

/*
  Se devuelve la matriz traspuesta de la matriz pasada

  matriz-> La matriz que queremos trasponer

*/
Matriz2D TrasponerMatriz(Matriz2D matriz);


/*
  Intercambia la posicion de todas las filas. Es decir, la ultima pasa a ser la
  primera y la primera la ultima

  matriz -> matriz a la que se le va  intercmabiar las filas
*/
Matriz2D InvierteFilas(Matriz2D matriz);

/*
  Intercambia la posicion de todas las filas. Es decir, la ultima pasa a ser la
  primera y la primera la ultima

  matriz -> matriz a la que se le va  intercmabiar las filas
*/
Matriz2D InvierteFilas(Matriz2D matriz);
#endif
