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
#include <ctype.h>

using namespace std;
int main (){
    char c = cin.get(); // Lectura adelantada
    while (!cin.eof()) {

        if(!isblank(c) && c != '\n')
            cout.put (c);
        else
            cout << endl;

        c = cin.get(); // Nueva lectura
    }
    return (0);
}
