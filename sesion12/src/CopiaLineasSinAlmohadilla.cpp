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
    const int TAM = 256;
    char  c[TAM];
    cin.getline(c,TAM); // Lectura adelantada
    while (!cin.eof()) {

        if(c[0] != '#')
            cout << c << endl;
        
        cin.getline(c,TAM); // Lectura adelantada
    }
    return (0);
}
