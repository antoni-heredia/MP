/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 1
//
// Declaraci�n  de la clase VectorDinamico (2)
//
// Incluye: 
//		* constructor de copia
//		* destructor
//		* operador de asignaci�n
//		* sobrecarga de [].
//
// Fichero: VectorDinamico_Asignacion-Acceso.h
//
/***************************************************************************/

	#ifndef VECTOR_DINAMICO_ASIGNACION_ACCESO
	#define VECTOR_DINAMICO_ASIGNACION_ACCESO

	#include <string>
	using namespace std;
	
	/***********************************************************************/
	// Definiciones de tipos

	typedef int TipoBase;	// Tipo de los elementos del vector


	// Tipo enumerado para representar los tipos de redimensionamiento.

	enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

class VectorDinamico 
{
	private: 
	
	    // Los datos se almacenan en un vector din�mico de datos 
		// "TipoBase". 
		// Se accede a ellos a trav�s del puntero "datos". 
		// El n�mero de casillas se establece cuando el constructor crea 
		// el objeto (por defecto, "TAM_DEF") y se guarda en "tam". 
		// PUEDE MODIFICARSE, mediante el m�todo apropiado. 
		// El n�mero de casillas ocupadas se guarda en "usados".
			
		TipoBase * datos = 0;  // Datos.
		int   tam = 0;         // N�mero de casillas reservadas.
		int   usados = 0;      // N�mero de casillas usadas.
		
		// PRE: 0 <= usados < tam
		
		// Tipo de redimensionamiento activo. uede modificarse el tipo 
		// de redimensionamiento en tiempo de ejecuci�n.
		TipoRedimension tipo_redimension;
		
		// Capacidad inicial, por defecto 
		static const int TAM_DEF = 10; 

		// Tamanio del bloque para redimensionamiento "EnBloques"
		static const int TAM_BLOQUE = 5;

	public: 

		/*******************************************************************/
		// Constructor sin argumentos, o con un argumento
		VectorDinamico (const int tam_inicial=TAM_DEF);
	
		// Constructor de copia
		VectorDinamico (const VectorDinamico & otro);
		
		/*******************************************************************/
		// Destructor
		~VectorDinamico (void);

		/*******************************************************************/
		// Consulta si el vector esta vacio
		bool EstaVacio (void) const;

		/*******************************************************************/
		// M�todos de consulta de los datos privados
		int Capacidad (void) const;
		int NumDatosGuardados(void) const;
		
		/*******************************************************************/
		// Establece/consulta el tipo de redimensionamiento
		void SetRedimensionamiento (TipoRedimension tipo);
		TipoRedimension GetRedimensionamiento (void) const;

		/*******************************************************************/
		// A�ade un elemento al vector
		void Aniade (TipoBase valor);

		/*******************************************************************/
		// Metodo de acceso individual a elementos: operator []
		// Metodo de escritura / lectura
		// PRE: 0 <= posicion <usados 		
		TipoBase & operator [] (const int posicion);  	
		TipoBase & operator [] (const int posicion) const;  
				
		/*******************************************************************/
		// Operador de asignaci�n
		VectorDinamico & operator = (const VectorDinamico & otro);
		VectorDinamico & operator = (const TipoBase & valor);

	private:
		/*******************************************************************/
		// Petici�n / liberaci�n de memoria
		void PideMemoria (const int num_casillas);
		void LiberaMemoria (void);

		// Copiar datos desde otro objeto de la clase
		void CopiarDatos (const VectorDinamico & otro);

    	/*******************************************************************/
		// Redimensiona el vector din�mico de acuerdo al tipo de redimensi�n 
		// establecido y registrado. Copia todos los datos en el nuevo almac�n.  
		void RedimensionaAlmacen (void);
	};
	
	
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	
	// Muestra el contenido de un vector din�mico 
	void PintaVectorDinamico (const VectorDinamico &v, const char * const msg);

	// Funci�n que convierte a string el valor enumerado
	string ToStringTipoRedimension (TipoRedimension tipo);
	
	#endif
