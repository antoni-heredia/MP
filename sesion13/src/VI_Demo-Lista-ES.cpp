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
#include "Lista.h"
using namespace std;

int main (int argc, char *argv[]){
    
    if(argc != 3){
        cout << "Numero de parametros incorrectos" << endl;
        exit(1);
    }
    //Leyendo datos del fichero de texto
    Lista lista(argv[1]);
    //No pruebo el leerlista ya que lo uso en el constructor y por lo tanto
    //queda probado ahi

    //Escribiendo datos en otro fichero
    lista.EscribirLista(argv[2]);
    return (0);
}
