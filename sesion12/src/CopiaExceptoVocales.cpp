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
    c = cin.get(); // Lectura adelantada
    while (!cin.eof()) {

        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
            cout.put (c);
        
        c = cin.get(); // Nueva lectura
    }
    return (0);
}