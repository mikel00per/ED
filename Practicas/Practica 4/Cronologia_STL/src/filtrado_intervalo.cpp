/**
 * @file filtado_intervalo.cpp
 * @brief Fichero ejemplo de uso para buscar por rango.
 */
#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;


void FiltradoIntervalo(Cronologia &c, char* a1, char* a2, Cronologia &r) {
  string  key1 = a1, key2 = a2;
  Cronologia::const_iterator it1;
  EventoHistorico::const_iterator it_ev1, it_ev2;
  EventoHistorico nuevo;
  for (it1 = c.find(key1); it1 != c.find(key2); ++it1) {
    nuevo.aniadeAnio(key);
    it_ev1 = (*it1).cbegin();
    while ( it_ev1 != (*it1).cend() ){
      nuevo.aniadeEvento(*it_ev1);
      r.insertaEvento(nuevo);
      ++it_ev1;
    }
  }
}

int main(int argc, char const *argv[]) {

  return 0;
}
