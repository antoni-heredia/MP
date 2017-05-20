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

    int num_fila, num_palabra;
    while(fi2 >> num_fila){

        fi2 >> num_palabra;
        string frase;
        int linea = 1;
        getline(fi1,frase);

        while(!fi1.eof()){
            if(linea == num_fila){
                int num_palabra_proce = 1;
                string palabra;

                istringstream iss; // Objeto istringstream
                iss.str (frase); // Asociar "cad" al flujo "iss""
                
                while(iss >> palabra){
                    if(num_palabra == num_palabra_proce){
                        cout << palabra << " ";
                    }
                    num_palabra_proce++;
                }

            }
            getline(fi1,frase);
            linea++;
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
