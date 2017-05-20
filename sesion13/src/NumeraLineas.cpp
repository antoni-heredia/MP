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
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <fstream>

using namespace std;
int main (int argc, char *argv[]){

    if(argc != 3){
        cout << "Numero de parametros incorrecto..." << endl;
        exit(1);
    }

    ifstream fi; // Declaracion del flujo de entrada "fi"
    ofstream fo; // Declaracion del flujo de salida

    // Asociar el flujo de entrada "fi"
    fi.open (argv[1]);
    if (fi.fail()) {
        cerr << "Error: no pudo abrirse " << argv[1] << endl;
        exit (1);
    }

    fo.open (argv[2]); // Apertura
    if (!fo) { // Comprobar si se ha podido crear argv[3]
        cerr << "Error: no pudo crearse " << argv[2] << endl;
        exit (1);
    }

    int lineas = 1;
    string linea;
    getline(fi,linea);
    fo << lineas << linea << endl;
    while(!fi.eof()){
        lineas++;
        getline(fi,linea);
        fo << lineas << " " << linea << endl;
    }

    //Cerramos los ficheros
    fi.close();
    fo.close();
    return (0);
}
