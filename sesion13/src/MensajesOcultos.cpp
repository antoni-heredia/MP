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
        cerr << "Numero de parametros incorrecto..." << endl;
        exit(1);
    }

    ifstream fi1,fi2; // Declaracion del flujo de entrada "fi"

    fi1.open (argv[1]);
    if (fi1.fail()) {
        cerr << "Error: no pudo abrirse " << argv[1] << endl;
        exit (1);
    }

   
    fi2.open (argv[2]);
    if (fi2.fail()) {
        cerr << "Error: no pudo abrirse " << argv[2] << endl;
        exit (2);
    }

    int num_palabra;

    while(fi2 >> num_palabra){
        string palabra;
        int pos = 1;
        while(fi1 >> palabra){
            if(pos == num_palabra)
                cout << palabra << " ";
            pos++;
        }
        fi1.close();
        fi1.open (argv[1]);
    }
    cout << endl;
    //Cerramos los ficheros
    fi1.close();
    fi2.close();
    return (0);
}
