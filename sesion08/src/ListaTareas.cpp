#include <iostream>
#include "ListaTareas.h"
using namespace std;

int MuestraMenu(void){
    cout << "---------------Menu---------------" << endl;
    cout << "1.-Llega nueva tarea" << endl;
    cout << "2.-Asignar tarea a recurso" << endl;
    cout << "3.-Recurso solicita tarea" << endl;
    cout << "4.-Recurso entra en pausa" << endl;
    cout << "5.-Activar recurso" << endl;
    cout << "6.-Desactivar recurso" << endl;
    cout << "7.-Finalizar" << endl;

    int opcion;

    cout << "Introduzca una opcion: ";
    cin >> opcion;

    while(opcion < 0 || opcion > 7){
      cout << "Introduzca una opcion: ";
      cin >> opcion;
    }
    return opcion;

}

bool ActivarRecurso(Recurso *recursos, int id, int max_recursos){
  int pos = posRecurso(recursos, id , max_recursos);
  Estado estado = recursos[pos].estado;
  bool esperando = false;
  if(estado == Estado::desactivado){
    recursos[pos]. estado = Estado::esperando;
    esperando = true;
  }
  return esperando;
}

bool DesactivarRecurso(Recurso *recursos, int id, int max_recursos){
  int pos = posRecurso(recursos, id , max_recursos);
  Estado estado = recursos[pos].estado;
  bool desactivado = false;
  if(estado == Estado::esperando || estado == Estado::pausa){
    recursos[pos]. estado = Estado::desactivado;
    desactivado = true;
  }
  return desactivado;
}

void IniciarRecursos(Recurso *recursos, int cant, int max_recursos, int id_recurso){

  //Se inician los cant primeros con estado esperando a una tarea
  for(int r = 0; r < cant; r++){
    recursos[r].id = id_recurso+r;
    recursos[r].estado = Estado::esperando;
  }

  //Se inician desde cant hasta el maximo de permitidos con estado desactivado
  for(int r = cant; r < max_recursos; r++){
    recursos[r].id = id_recurso+r;
    recursos[r].estado = Estado::desactivado;
  }

}

int idRecurso(Recurso *recursos, int pos){
  return recursos[pos].id;
}

int posRecurso(Recurso *recursos, int id, int max_recursos){
  int r = 0;
  int encontrado = false;

  while(r < max_recursos && !encontrado){
    if(id ==  recursos[r].id)
      encontrado = true;
    r++;
  }

  return r-1;
}

Estado EstadoRecurso(Recurso *recursos, int id, int max_recursos){

  int pos = posRecurso(recursos, id, max_recursos);

  return recursos[pos].estado;
}

string NombreEstado( Estado es){

  string es_str;
  switch (es) {
    case Estado::inactivo :
      es_str = "inactivo";
    break;
    case Estado::pausa :
      es_str = "pausa";
    break;
    case Estado::esperando :
      es_str = "esperando";
    break;
    case Estado::ocupado :
      es_str = "ocupado";
    break;
    case Estado::desactivado :
      es_str = "desactivado";
    break;
  }

  return es_str;
}
void MostrarInformacion(Recurso *recursos, int max_recursos){
  cout << "----------Informacion de recursos----------" << endl;
  cout << "ID\t|ESTADO\t|" << endl;
  for(int r = 0; r < max_recursos; r++){
    int id = recursos[r].id;
    Estado es = EstadoRecurso(recursos, id, max_recursos);
    cout << id << "\t|" << NombreEstado(es) << "\t|" << endl;
  }
}

bool PonerPausa(Recurso * recursos, int id, int max_recursos){
  int pos = posRecurso(recursos, id , max_recursos);
  Estado estado = recursos[pos].estado;
  bool pausado = false;
  if(estado == Estado::esperando || estado == Estado::ocupado){
    if(estado == Estado::ocupado)
      AcabarTarea(recursos, id, max_recursos);
    recursos[pos]. estado = Estado::pausa;
    pausado = true;
  }
  return pausado;
}

bool SolicitarTarea(Recurso * recursos, int id, int max_recursos){

}

bool AcabarTarea(Recurso * recursos, int id, int max_recursos){
  
}
