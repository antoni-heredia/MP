/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 4
//
// Declaración de la clase clase Lista (2).
//
// Incluye: 
//		* constructor de copia
//		* destructor
//		* operador de asignación 
//		* sobrecarga de [].
//
// Fichero: Lista_Asignacion-Acceso.h
//
/***************************************************************************/

	#ifndef LISTA_ASIGNACION_ACCESO 
	#define LISTA_ASIGNACION_ACCESO 
	
	/***********************************************************************/
	// Definiciones de tipos

	typedef int TipoBase;	// Tipo del valor guardado en cada nodo

	struct TipoNodo 		// Tipo de cada nodo
	{
		TipoBase   info;  // Valor guardado en el nodo
		TipoNodo * sig;	  // Puntero al siguiente
	};

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	
	class Lista 
	{

	private:
		
		TipoNodo * primero = 0; // Puntero al primer nodo 
		int tamanio = 0;		// Número de nodos

		// PRE: tamanio >= 0
		
	public:
		
		/*******************************************************************/
		// Constructor sin argumentos: crea una lista vacia.
		Lista (void);

		/*******************************************************************/
		// Constructor con argumentos: crea una lista con "tam" nodos
		// PRE: tam > 0
		Lista (int tam);

		/*******************************************************************/
		// Constructor de copia
		Lista (const Lista & otro);
		
		/*******************************************************************/
        // Destructor
        ~Lista (void);

		/*******************************************************************/
        // Consulta si la lista esta vacia
		bool EstaVacia (void) const;

		/*******************************************************************/
		// Inicializa la lista al valor dado
		void Inicializar (int valor=0);

		/*******************************************************************/
		// Devuelve el numero de elementos
		int  Tamanio (void) const;

		/*******************************************************************/
        // Métodos de acceso para escribir/leer en una posición dada: 
        // NO MODIFICAN EL NÚMERO DE NODOS

		/*******************************************************************/
		// Busca un alumno con el valor especificado. Devuelve la posición  
		// del primer nodo coincidente, o -1 si no se encuentra.
		/*******************************************************************/
		int Busca (TipoBase valor) const;
	
		/*******************************************************************/
		// Metodo de acceso individual a elementos: operator [] y operator()
		// Metodo de escritura / lectura
		// PRE: 0 <= posicion <usados 		
		TipoBase & operator [] (const int posicion);  	
		TipoBase & operator [] (const int posicion) const;  
		
		TipoBase & operator () (const int posicion);
		TipoBase & operator () (const int posicion) const;  
					
		/*******************************************************************/
		// Operador de asignación
		Lista & operator = (const Lista & otro);
		Lista & operator = (const TipoBase valor);

		/*******************************************************************/
        // Métodos que modifican el tamaño de la lista 
      	// MODIFICAN EL NÚMERO DE NODOS
  			
		/*******************************************************************/
		// Aniade (al final) un nuevo elemento
		void Aniade (const TipoBase valor);

        // Borra el primer nodo que contiene el valor "valor"
    	void Elimina (const TipoBase valor);
    
        // Borra el primer nodo que contiene el valor "valor"
    	void Elimina (const TipoBase valor) const;

		/*******************************************************************/
		// Inserta un nuevo elemento en la posición "pos_insertar"
		// PRE: 1 <= pos_insertar <= tamanio+1
		// El criterio seguido para especificar una posicion será : 
		// 1 -> primero, 2 -> segundo,...
		// Nota: Si pos_insertar == tamanio+1, el resultado es idéntico a la 
		// 		 ejecución del método Aniade()
		void Inserta (const TipoBase valor, int pos_insertar);

		/*******************************************************************/
		// Borra el elemento de la posición "pos_borrar" 
		// PRE: 1 <= pos_borrar <= tamanio
		// El criterio seguido para especificar una posicion será : 
		// 1 -> primero, 2 -> segundo,...
		void Borra (int pos_borrar);

	private:
		
		/*******************************************************************/
		// Petición / liberación de memoria
		void ReservarMemoria (int num_elementos);
		void LiberarMemoria (void); 

        // Copiar datos desde otro objeto de la clase
		void CopiarDatos (const Lista & otro);
		
    };

 	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
   
	/***********************************************************************/
	/***********************************************************************/
	// Otras funciones no pertenecientes a la clase
	
	// Muestra el contenido de una lista 
	void PintaLista (const Lista l, const char * const msg);

	/***********************************************************************/
	/***********************************************************************/
	
	#endif
