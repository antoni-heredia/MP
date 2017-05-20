/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 13
//
/*
 */
/*********************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */

using namespace std;

void ProcesarStream(istream & i);
bool ProcesarLinea(string linea);

int main (int argc, char *argv[]){

    if(argc > 2){
        cout << "Numero de parametros incorrecto..." << endl;
        exit(1);
    }

    //Si el numero de parametros es  correcto
    if(argc == 1){
        //En caso de que no se le pase ningun argumento se le pasa por defecto
        //cin
        ProcesarStream(cin);
    }else{

        ifstream fi;
        fi.open(argv[1]);

        //Si no se ha podido abrir el fichero se sale
        if(!fi){
            cout << "No se pudo abrir " << argv[1] << endl;
            exit(1);
        }

        ProcesarStream(fi);
        fi.close();
    
    }

   
    return (0);
}

void ProcesarStream(istream & in){
    string linea;

    getline(in,linea);

    //Si se ha procesado algun grupo se pondra el endl, si no la linea no
    //tendria ninguna suma

    if(ProcesarLinea(linea))
        cout << endl;
    //Procesamos todas las demas lineas
    while(!in.eof()){

        getline(in,linea);
        if(ProcesarLinea(linea))
            cout << endl;
    }
}

bool ProcesarLinea(string linea){
    int cont = 0; // Contador de palabras
    istringstream iss; // Objeto istringstream
    iss.str (linea); // Asociar "cad" al flujo "iss"
    /*
        cant_grupos -> la cantidad de grupos que tiene esta linea
        cant_nums -> la cantidad de numeros que tiene un grupo en concreto
        cant_nums_proces -> cantidad de numeros procesados de este grupo
    */
    int cant_grupos, cant_nums, cant_nums_proces;
    
    // grupos_proces -> cantidad total de grupos procesados
    //Por defecto los inicializamos todos a 0
    int grupos_proces = cant_grupos = cant_nums_proces = 0;

    //Un numero en concreto
    double numero;

    //La suma total de un grupo
    double suma = 0;

    //Leemos la cantidad de grupos que tiene esta linea
    iss >> cant_grupos;
    
    //Para saber si emepzamos un grupo nuevo por defecto sera que si
    bool nuevo_grupo = true;

    //Se recorrera la linea mientras queden numeros o que los grupos procesados
    // sean menores o igual que los totales
    while (iss >> numero && grupos_proces <= cant_grupos){
        
        //Si estamos procesando un grupo nuevo
        if(nuevo_grupo){
            //Sumamos uno en la cantidad de grupos procesados totales
            grupos_proces++;

            //Decimos que el siguiente numero no es el inicio de un grupo
            nuevo_grupo = false;

            //Guardamos la cantidad de numeros que tiene este grupo
            cant_nums = numero;
            
            //Y reiniciamos los numeros de este grupo procesados
            cant_nums_proces = 0;

            //Cogemos el primer numero del grupo
            iss >> numero;
        }

        //si se diera la causalidad que algun  grupo tiene 0 numeros
        if(cant_nums != 0){
            suma += numero;
            cant_nums_proces++;
        }
        
        //Una vez que todos  los numeros de un grupo han sido procesados
        if(cant_nums_proces  == cant_nums){

            //Se muetra la suma total
            cout << suma << " ";
            //Se reinicializa la suma
            suma = 0;
            //Decimos que lo siguiente sera el inicio de un nuevo grupo
            nuevo_grupo = true;
        }
        
    } // Extraer una palabra
    return (grupos_proces != 0);
}