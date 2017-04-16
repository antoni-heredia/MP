using namespace std;
#ifndef LISTA_TAREAS
#define LISTA_TAREAS

enum TipoTarea {critica,normal,baja_prioridad};
enum Estado{inactivo, pausa, esperando, ocupado, desactivado};

struct Tarea{
  int id;
  TipoTarea tipo;
  Tarea *sig;
};

struct Recurso{
  int id;
  Tarea tarea_asignada;
  Estado estado;
};


int MuestraMenu(void);
bool ActivarRecurso(Recurso *recursos, int id, int max_recursos);
bool DesactivarRecurso(Recurso *recursos, int id, int max_recursos);
void IniciarRecursos(Recurso *recursos, int cant, int max_recursos, int id_recurso);
void MostrarInformacion(Recurso *recursos, int max_recursos);
int idRecurso(Recurso *recursos, int pos);
int posRecurso(Recurso *recursos, int id, int max_recursos);
string NombreEstado(Estado es);
Estado EstadoRecurso(Recurso *recursos, int id, int max_recursos);
bool PonerPausa(Recurso * recursos, int id, int max_recursos);
bool AcabarTarea(Recurso * recursos, int id, int max_recursos);
bool SolicitarTarea(Recurso * recursos, int id, int max_recursos);
#endif
