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
// Definición de la clase VectorDinamico (2)
//
// Incluye: 
//		* constructor de copia
//		* destructor
//		* operador de asignación
//		* sobrecarga de [].
//
// Fichero: VectorDinamico_Asignacion-Acceso.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <iomanip>
	#include <cstring>
	#include <string>
	
	#include "VectorDinamico_Asignacion-Acceso.h"
	
	using namespace std; 

    /***********************************************************************/
	// Constructor sin argumentos, o con un argumento
	VectorDinamico :: VectorDinamico (int tam_inicial) 
		: tam (tam_inicial), usados (0), tipo_redimension (EnBloques) 
	{
		PideMemoria (tam);
	}

    /***********************************************************************/
	// Constructor de copia
	VectorDinamico :: VectorDinamico (const VectorDinamico & otro)
		: tam (otro.tam), usados (otro.usados), 
		  tipo_redimension (otro.tipo_redimension)
	{
		PideMemoria (tam);
		CopiarDatos (otro);
	}
	
    /***********************************************************************/
	// Destructor
	VectorDinamico :: ~VectorDinamico (void)
	{
		LiberaMemoria();
	}

	/*******************************************************************/
	// Consulta si el vector esta vacio
	bool VectorDinamico :: EstaVacio (void) const
	{	
		return (usados==0);
	}

    /***********************************************************************/
	// Métodos de consulta de los datos privados

	// Devuelve el número de casillas reservadas 
	int VectorDinamico :: Capacidad (void) const
	{
		return (tam);
	}
	
	// Devuelve el número de casilllas ocuppadas
	int VectorDinamico :: NumDatosGuardados(void) const
	{
		return (usados);
	}
	
    /***********************************************************************/
	// Establece/consulta el tipo de redimensionamiento

	// Establece el tipo de redimensionamiento
	void VectorDinamico :: SetRedimensionamiento (TipoRedimension tipo)
	{
		tipo_redimension = tipo;
	}

	// Devuelve el tipo de redimensionamiento
	TipoRedimension VectorDinamico :: GetRedimensionamiento (void) const
	{
		return (tipo_redimension);
	}

    /***********************************************************************/
	// Añade un elemento al vector. Este método puede provocar el 
	// redimensionamiento del vector si no hay espacio disponible. 

	void VectorDinamico :: Aniade (TipoBase valor)
	{
		// Comprobar si es necesario redimensionar el almacén
		
		if (NumDatosGuardados() == Capacidad()) { 
			
			// Redimensionar 
			RedimensionaAlmacen ();
		}

		datos [usados] = valor;
		usados++;
	}

    /***********************************************************************/
	// Metodo de acceso individual a elementos
	// Metodo de lectura
	// PRE: 0 <= posicion < usados	
	
	TipoBase & VectorDinamico ::  operator [] (const int posicion)
	{
		return (datos [posicion]);
	}
	
	TipoBase & VectorDinamico ::  operator [] (const int posicion) const
	{
		return (datos [posicion]);
	}	
	
    /***********************************************************************/
	// Operador de asignación desde otro dato VectorDinamico
	VectorDinamico & VectorDinamico :: operator = (const VectorDinamico & otro)
	{
		if (this != &otro) { // Evitar autoasignación

			// Libera la memoria ocupada
			LiberaMemoria();	

			// Reserva de memoria para los datos del otro vector
			PideMemoria (otro.usados);

			// Copia los campos privados y los coeficientes
			CopiarDatos(otro);
		}
		return (*this);  // Devuelve el objeto implicito:
						 // parte izquierda de la asignación
	}
	
	/*********************************************************************/
	// Operador de asignación desde un dato TipoBase
	VectorDinamico & VectorDinamico :: operator = (const TipoBase & valor)
	{
		for (int i=0; i < usados; i++) 
			datos[i] = valor;
			  
		return (*this); // devuelve el objeto implicito:
						// parte izquierda de la asignación
	}

    /***********************************************************************/
    /***********************************************************************/
	// METODOS PRIVADOS DE LA CLASE VectorDinamico
    /***********************************************************************/
    /***********************************************************************/
    
    /***********************************************************************/
    // Pide memoria para guardar "num_casillas" datos	
	void VectorDinamico :: PideMemoria (const int num_casillas)
	{
		datos = new TipoBase[num_casillas]; 
	}
	
    /***********************************************************************/
    // Libera memoria
	void VectorDinamico :: LiberaMemoria (void)
	{
		if (datos) { 
			delete [] datos;
			datos = 0;
		}
	}

    /***********************************************************************/
    // Copiar datos desde otro objeto de la clase
    // PRE: Se ha reservado memoria para los datos
	void VectorDinamico :: CopiarDatos (const VectorDinamico & otro)
	{
		// Copia los valores de los campos privados desde "otro" 
		tam = otro.tam;  
		usados = otro.usados;			 

		// Copiar los valores 
		memcpy (datos, otro.datos, usados*sizeof(TipoBase));
	}
		
    /***********************************************************************/
	// Redimensiona el vector dinámico de acuerdo al tipo de redimensión 
	// establecido y registrado.
	// Copia todos los datos en el nuevo almacén.  

	void VectorDinamico :: RedimensionaAlmacen (void)
	{
        switch (tipo_redimension) {

            case (DeUnoEnUno): // 1 casilla más
                tam++;
                break;

            case (EnBloques): // TAM_BLOQUE casillas más
                tam+=TAM_BLOQUE;
                break;

            case (Duplicando): // Duplicar tamaño
                tam*=2;
                break;
        }
	
		cout << endl;
		cout << "REDIMENSIONADO HASTA --> " << tam << " CASILLAS" << endl;
		cout << endl;

		// Pedir memoria para el nuevo almacen 
		int * tmp = new TipoBase[tam]; 

		// Copiar los datos 
		memcpy (tmp, datos, usados*sizeof(TipoBase)); 
		
		// Liberar la memoria del antiguo almacén
		delete [] datos; 

		// Reasignacion del puntero "datos" paara que referencie a la 
		// nueva zona de memoria ampliada y con los datos copiados. 
		datos = tmp; 
	}


    /***********************************************************************/
    /***********************************************************************/
	// Otras funciones no pertenecientes a la clase
    /***********************************************************************/
    /***********************************************************************/
    
    /***********************************************************************/
	// Muestra el contenido de un vector dinámico 
	void PintaVectorDinamico (const VectorDinamico &v, const char * const msg)
	{
		cout << endl; 
		cout << "--------------------------------------------------" << endl;
		cout << msg << endl;
		
		cout << "  Capacidad = " << v.Capacidad()  << " datos" << endl; 
		cout << "  Contiene = " << v.NumDatosGuardados() << " datos" << endl; 
		cout << "  Redimensionamiento = " 
             << ToStringTipoRedimension(v.GetRedimensionamiento()) << endl;
		cout << endl;    
		
		for (int i=0; i < v.NumDatosGuardados(); i++) 
			cout << setw(3) << v[i] << " "; 
		cout << endl;

		cout << "--------------------------------------------------" << endl;  
		cout << endl;
	}
	
    /***********************************************************************/
	// Función que convierte a string el valor enumerado

	string ToStringTipoRedimension (TipoRedimension tipo)
	{
		string str_tipo;
		
		switch (tipo) { 
		
			case (DeUnoEnUno):	
						str_tipo = "de uno en uno";
						break;
			case (EnBloques):	
						str_tipo = "en bloques";
						break;
			case (Duplicando):	
						str_tipo = "duplicando";
						break; 
		}

		return(str_tipo);
	}
	
	/***********************************************************************/
    /***********************************************************************/
