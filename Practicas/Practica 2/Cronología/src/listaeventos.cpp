#include "listaeventos.h"

using namespace std;

/******************************************************************************/

ListaEventos::ListaEventos(){
    cabecera = 0;
}

/******************************************************************************/

ListaEventos::ListaEventos(string cadena){
    insertar(cadena);
}

/******************************************************************************/

ListaEventos::ListaEventos(const ListaEventos &otra){
    copiarLista(otra);
}

/******************************************************************************/

ListaEventos::~ListaEventos(){
  destruir();
}

/******************************************************************************/

void ListaEventos::destruir(){
  EventoHistorico *ptr = cabecera;
  columnas = 0;
  fecha = 0;
  while (cabecera != 0) {
    ptr=cabecera;
    cabecera=cabecera->siguiente;
    delete ptr;
  }
  delete cabecera;
}

/******************************************************************************/

ListaEventos &ListaEventos::copiarLista(const ListaEventos &otra){
  if(otra.cabecera != 0){
    destruir();
    EventoHistorico *aux = otra.cabecera;

    this->fecha = otra.fecha;
    this->columnas = otra.columnas;

    while(aux->siguiente != 0){
      insertar(aux->evento);
      aux = aux -> siguiente;
    }

    delete aux;
  }

  return *this;
}

/******************************************************************************/

ListaEventos &ListaEventos::operator=(const ListaEventos &otra){
  if(otra.cabecera != 0){
    destruir();
    copiarLista(otra);
  }

  return *this;
}

/******************************************************************************/

void ListaEventos::insertar(string event){

  EventoHistorico *evento = new EventoHistorico();

  evento -> evento = event;
  evento -> siguiente = 0;

  if(cabecera== 0)
    cabecera = evento;
  else{
    EventoHistorico *ptr;
    ptr = cabecera;
    while (ptr->siguiente != 0) ptr = ptr->siguiente;
    ptr->siguiente = evento;
  }

  this->columnas++;
}

/******************************************************************************/

void ListaEventos::insertarLista(string list){

  string evento;
  evento.resize(list.size());
  int anio = stoi(list.substr(0,4));
  this->fecha = anio;

  int cnt = 0;
  for (int i = 5; i < (int)list.size(); i++) {
    if(list[i] != '#'){
      evento.push_back(list[i]);
      cnt++;
    }else{
      insertar(evento);
      evento.clear();
      cnt = 0;
    }
  }

  // En caso de no insertar el último lo inserto
  insertar(evento);
}

/******************************************************************************/

string ListaEventos::getEvento(int i){
  string cadena = "";
  EventoHistorico *ptr = cabecera;
  int cnt = 0;
  if(ptr != 0){
    while (cnt != i) {
      ptr = ptr -> siguiente;
      cnt++;
    }
    cadena = ptr-> evento;
  }
  return cadena;
}

/******************************************************************************/

vector<string> ListaEventos::getEventos(){
  std::vector<string> v;
  string evento;
  for (int i = 0; i < this->columnas; i++) {
    evento = getEvento(i);
    v.push_back(evento);
  }
  return v;
}

/******************************************************************************/

int ListaEventos::getColumnas(){
  return this->columnas;
}

/******************************************************************************/

const int ListaEventos::getFecha(){
  return this->fecha;
}

/******************************************************************************/
