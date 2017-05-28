/**
 * @file filtrado_palabra.cpp
 * @brief Fichero ejemplo de uso para buscar por palabra.
 */
#include "Cronologia.h"

using namespace std;

void FiltradoPalabra(const Cronologia &c, string palabra, Cronologia &r){
  string key;
  Cronologia::const_iterator it1;
  EventoHistorico::const_iterator it_ev1, it_ev2;
  EventoHistorico nuevo;
  for (it1 = c.cbegin(); it1 != c.cend(); ++it1) {
    key = (*it1).first;         // fecha a buscar
    nuevo.aniadeAnio(key);
    it_ev1 = (*it1).second.cbegin();
    while (!(*it_ev1).find(palabra)) {
      nuevo.aniadeEvento((*it_ev1));
      r.insertaEvento(nuevo);
      ++it_ev1;
    }
  }
}

int main(int argc, char const *argv[]) {

  string palabra;
  Cronologia crono;

  if (argc < 0) {
    cout << "Error en el número de argumentos" << endl;
    cout << "Uso: %s <cronologia1.txt> <palabra a buscar <fichero_salida.txt>" << endl;
  }

  if (argc == 2) {
    cout << "Palabra a buscar" << endl;
    cin >> palabra;
    cout << "Salida: Pantalla" << endl;
// ofstream f2 (cout); Por alguna razón no coge cout
  }

  if (argc == 3) {
    palabra = argv[2];
    std::cout << "Salida por pantalla:" << endl;
  }

  if (argc == 4) {
    palabra = argv[2];
    std::cout << "Salida al archivo: " << argv[3] << endl;
  }

  ifstream f1 (argv[1]);

  if (!f1){
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  f1 >> crono;
  Cronologia crono_palabra;
  FiltradoPalabra(crono, palabra, crono_palabra);

  if (argc == 3)
    std::cout << crono << '\n';
  else{
    ofstream fout(argv[3]);
    if (!fout){
     cout<<"No puedo crear el fichero "<<argv[3]<<endl;
     return 0;
    }
    fout << crono;
  }
  return 0;
}
