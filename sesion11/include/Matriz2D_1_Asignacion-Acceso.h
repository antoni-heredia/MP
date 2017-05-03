/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 2
//
// Declaración de la clase clase Matriz2D_1 (2)
// Incluye: 
//		* constructor de copia
//		* destructor
// 		* operador de asignación
//		* sobrecarga de ()
//
// Fichero: Matriz2D_1_Asignacion-Acceso.h
//
/***************************************************************************/

	#ifndef MATRIZ_2D_1_ASIGNACION_ACCESO
	#define MATRIZ_2D_1_ASIGNACION_ACCESO
	
	/***********************************************************************/
	// Definiciones de tipos

	typedef int TipoBase;	// Tipo de los elementos de la matriz
	
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	class Matriz2D_1 
	{
	private:
		// Los datos se almacenan en filas independientes. Cada fila es 
		// accesible desde un vector de punteros (datos[0], datos[1], ...)
		// "datos" contiene la dirección de memoria del primer elemento 
		// del vector de punteros. Ese vector contiene "filas" casillas, 
		// y cada fila contiene "columnas" datos "TipoBase".
		 
		TipoBase ** datos = 0;	// Datos. 
		int filas = 0;			// Número de filas
		int columnas = 0;		// Número de columnas

		// PRE: 0 <= filas
		// PRE: 0 <= columnas
		
	public:
		/*******************************************************************/
		// Constructor sin argumentos: crea una matriz vacia 
		Matriz2D_1(void);

		/*******************************************************************/
		// Constructor de matrices cuadradas
		Matriz2D_1 (int orden);

		/*******************************************************************/
		// Constructor de matrices rectangulares 
		Matriz2D_1 (int fils, int cols);

		/*******************************************************************/
		// Constructor de copia
		Matriz2D_1 (const Matriz2D_1 & otro);

		/*******************************************************************/
		// Destructor
		~Matriz2D_1 (void);

		/*******************************************************************/
		// Consulta si la matriz esta vacia
		bool EstaVacia (void) const;

		/*******************************************************************/
		// Rellena todas las casillas de la matriz con el valor "valor"
		void Inicializar (const TipoBase valor=0);

		/*******************************************************************/
		// Consulta el número de filas y columnas
		int Filas (void) const;
		int Columnas (void) const;

		/*******************************************************************/
		// Metodo de acceso individual a elementos: Operator ()
		// Metodo de escritura / lectura
		// PRE: 0 <= fila < filas
		// PRE: 0 <= columna < columnas
		TipoBase & operator () (const int fila, const int columna);
		TipoBase & operator () (const int fila, const int columna) const;

		/*******************************************************************/
		// Operador de asignación 
		Matriz2D_1 & operator = (const Matriz2D_1 & otro);
		Matriz2D_1 & operator = (const TipoBase & valor);

	private:
		/*******************************************************************/
		// Petición / liberación de memoria
		void ReservarMemoria (int filas, int columnas);
		void LiberarMemoria (void); 

		/*******************************************************************/
        // Copiar datos desde otro objeto de la clase
		void CopiarDatos (const Matriz2D_1 & otro);
	};
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/***********************************************************************/
	/***********************************************************************/
	// Otras funciones no pertenecientes a la clase
	
	// Muestra el contenido de una matriz 
	void PintaMatriz (const Matriz2D_1 m, const char * const msg);
	
	/***********************************************************************/
	/***********************************************************************/
	
	#endif
