/**
 * @file Cronologia.cpp
 * @brief Fichero de implementación de métodos del TDA Cronologia.
 */
#include "Cronologia.h"

using namespace std;

istream &operator>> (istream& is, Cronologia &c){
  string anio, evento, evento_completo;

  while (is) {
    EventoHistorico nuevo;
    evento_completo.clear();
    getline(is, evento_completo);
    anio.clear();

    for (int i = 0; i < 4; i++)
      anio.push_back(evento_completo[i]);

    evento.clear();
    for (int i = 5; i < evento_completo.size(); i++) {
      if (evento_completo[i] == '#' || evento_completo[i] == '\n'){
        nuevo.aniadeEvento(evento);
        evento.clear();
      }else
        evento.push_back(evento_completo[i]);
    }
    nuevo.aniadeEvento(evento);
    c.crono[anio].insertaEventoHistorico(nuevo);
  }
  // devuelvo el control.
  return is;
}

ostream &operator<<(ostream &os, Cronologia &c){
  Cronologia::const_iterator it;
  for (it=c.cbegin(); it!=c.cend();++it){
    os<<(*it).first << ": " << endl;          //año esta en el key del map
    EventoHistorico::const_iterator it_ev;
    for (it_ev=(*it).second.cbegin(); it_ev!=(*it).second.cend();++it_ev)
      os<< " --> " << (*it_ev) << endl;
  }
}

EventoHistorico Cronologia::GetEventos (int anio){
  string key = to_string(anio);
  EventoHistorico eventos = crono[key];
  return eventos;
}
