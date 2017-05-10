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
using namespace std;
int main (){
    char c;
    int cant = 0;
    cin.get(c); // Nueva lectura
    while (!cin.eof()) {
        cant++;
        cin.get(c); // Nueva lectura
    }
    
    cout << endl << "La cantidad de caracteres leidos actualmente es de: " << cant
    << endl;
    return (0);
}