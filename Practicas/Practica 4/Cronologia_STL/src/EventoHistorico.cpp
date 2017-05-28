/**
 * @file EventoHistorico.cpp
 * @brief Fichero de implementación de métodos del TDA EventoHistorico.
 */
#include "EventoHistorico.h"

using namespace std;

ostream &operator<<(ostream &os, EventoHistorico &e){
  os<<e.getFirst()<<": " << endl;          //año esta en el key del map
  EventoHistorico::const_iterator it_ev;
  for (it_ev=e.cbegin(); it_ev!=e.cend();++it_ev)
     os<<" ---> " << (*it_ev) << endl;
}

void EventoHistorico::insertaEventoHistorico(EventoHistorico e){
  eventos.first = e.getFirst();
  EventoHistorico::const_iterator it_ev;
  for (it_ev=e.cbegin(); it_ev!=e.cend();++it_ev)
    eventos.second.insert((*it_ev));
}
