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
    bool nueva_linea = true;
    int cant_lineas = 0;
    cin.get(c); // Nueva lectura
    while (!cin.eof()) {

        if(c == '\n' && !nueva_linea){
            cout.put('\n');
            nueva_linea = true;
        }else if(c != '\n' && nueva_linea){
            cant_lineas++;
            nueva_linea = false;
        }
        if(!nueva_linea)
            cout.put(c);
        cin.get(c); // Nueva lectura
    }
    
    cout << endl << "La cantidad de lineas no vacias leidas es de: "
    << cant_lineas << endl;
    return (0);
}