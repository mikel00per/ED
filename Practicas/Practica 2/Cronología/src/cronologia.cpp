#include"cronologia.h"

using namespace std; 

/******************************************************************************/

Cronologia::Cronologia(){
  this->filas = 0;
  lista_eventos = 0;
}

/******************************************************************************/

Cronologia::Cronologia(const int filas){
  this->filas = filas;
  crear(filas);
}

/******************************************************************************/

Cronologia::~Cronologia(){
  destruir();
}

/******************************************************************************/

void Cronologia::crear(int filas){
  destruir();
  this->filas = filas;
  this->lista_eventos = new ListaEventos[filas];
}

/******************************************************************************/

void Cronologia::destruir(){
  delete [] this->lista_eventos;
}

/******************************************************************************/

int Cronologia::getFilas(){
  return this->filas;
}

/******************************************************************************/
/*
ListaEventos Cronologia::getAnio(int n){
  for (size_t i = 0; i < filas(); i++) {
    if (lista_eventos[i].getFecha() == n) {
      ListaEventos aux = ListaEventos(lista_eventos[i]);
      break;
    }
  }

  return aux;
}
*/
/******************************************************************************/

vector<string> Cronologia::GetEventos(int n){
  std::vector<string> v;
  ListaEventos anioLista;

  for (int i = 0; i < this->filas; i++) {
    if (this->lista_eventos[i].getFecha() == n) {
      v = this->lista_eventos[i].getEventos();
    }
  }
  return v;
}

/******************************************************************************/

istream &operator >>(istream &entrada, Cronologia &crono){
  string lista_eventos;

  char c;
  int n_anios = 0;

  while (entrada.get(c))
    if (c=='\n')
      n_anios++;

  crono.crear(n_anios);

  entrada.clear();
  entrada.seekg(0,entrada.beg);

  for(int i = 0; i<crono.getFilas() ; i++){
    getline(entrada, lista_eventos);
    if (lista_eventos != ""){
      crono.lista_eventos[i].insertarLista(lista_eventos);}
  }

  return entrada;
}

/******************************************************************************/
