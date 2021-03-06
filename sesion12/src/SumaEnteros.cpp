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
#include <string>     // std::string, std::stoi

using namespace std;
int main (){
    char c;
    string numero = "";
    int suma = 0;
    c = cin.get(); // Lectura adelantada
    while (!cin.eof()) {

        if(c != '*' && !isblank(c)){
            numero += c;
        }
        else{
            if(numero != "")
                suma += stoi(numero);
            numero = "0";
        }

        c = cin.get(); // Nueva lectura
    }
    cout << "La suma de todos los numeros es: " << suma << endl;
    return (0);
}
