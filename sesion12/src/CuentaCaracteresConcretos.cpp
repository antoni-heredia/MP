/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 12
//
/*
 */
/*********************************************************************/

#include <iostream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */

using namespace std;
int main (int argc, char *argv[]){

    if(argc != 2){
        cout << "El numero de argumentos es incorrecto." << endl;
        exit(1);
    }


    char caracter = argv[1][0];
    char c;
    int cant = 0;

    c = cin.get(); // Nueva lectura
    while (!cin.eof()) {

        if(c == caracter)
            cant++;
        
        c = cin.get(); // Nueva lectura
    }
    
    cout << endl << "La cantidad de caracteres leidos actualmente es de: " << cant
    << endl;
    return (0);
}