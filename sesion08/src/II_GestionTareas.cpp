/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 8
//
/*
 */
/*********************************************************************/

#include <iostream>
#include "ListaTareas.h"

using namespace std;


int main(int argc, char * argv[]) {
  int max_recursos;
  int recursos_activos;
  int id_recurso;
  Recurso *recursos;

  if(argc != 4){
    cout << "Numero de parametros incorrecto...." << endl;
    cout << "Saliendo del programa...." << endl;
    exit(1);
  }
  max_recursos = atoi(argv[1]);
  recursos_activos = atoi(argv[2]);
  if(recursos_activos>max_recursos){
    cout << "Los parametros son incorrectos...." << endl;
    cout << "Saliendo del progroma....." << endl;
    exit(1);
  }

  id_recurso = atoi(argv[3]);

  recursos = new Recurso[max_recursos];

  IniciarRecursos(recursos, recursos_activos,max_recursos, id_recurso);
  MostrarInformacion(recursos, max_recursos);

  int opcion = MuestraMenu();
  while( opcion != 7 ){
    MostrarInformacion(recursos, max_recursos);
    int id;
    switch (opcion) {

      case 1:
      break;

      case 2:
      break;
      case 3:
      break;

      case 4:
        cout << "Introduzca el id del recurso a pausar: ";
        cin >> id;
        if(PonerPausa(recursos, id, max_recursos))
          cout << "Recurso pausado" << endl;
        else
          cout << "No se ha podido pausar el recurso" << endl;
          MostrarInformacion(recursos, max_recursos);
      break;

      case 5:
        cout << "Introduzca el id del recurso a activar: ";
        cin >> id;
        if(ActivarRecurso(recursos, id, max_recursos))
          cout << "Recurso activado" << endl;
        else
          cout << "No se ha podido activado el recurso" << endl;
          MostrarInformacion(recursos, max_recursos);
      break;

      case 6:
        cout << "Introduzca el id del recurso a desactivar: ";
        cin >> id;
        if(DesactivarRecurso(recursos, id, max_recursos))
          cout << "Recurso desactivado" << endl;
        else
          cout << "No se ha podido desactivar el recurso" << endl;
          MostrarInformacion(recursos, max_recursos);
      break;
    }
    opcion = MuestraMenu();
  }

  cout << "Saliendo del sistema de gestion....." << endl;
  return (0);
}
