/**
 * @file union_cronologia.cpp
 * @brief Fichero ejemplo de uso para unir dos cronologías.
 * Se podía haber implementado como una función del TDA Cronologia.
 */
#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

// Esta funcion también puede implementarse como método de la clase Cronologia
void Union(const Cronologia & c1, const Cronologia & c2, Cronologia &resultado){
  Cronologia::const_iterator it1;
  resultado = c1;
  for (it1 = resultado.cbegin(); it1 != resultado.cend(); ++it1) {
    EventoHistorico nuevo;
    string key = (*it1).first;
    nuevo.aniadeAnio(key);
    Cronologia::const_iterator it2 = c2.cfind(key);
    if (it2 != c2.cend()) {    // existe la key.S
      EventoHistorico::const_iterator it_ev1 = (*it1).second.cbegin();
      EventoHistorico::const_iterator it_ev2 = (*it2).second.cbegin();
      while (it_ev1 != (*it1).second.cend()){
        while (it_ev2 != (*it2).second.cend()) {
          if (*it_ev1 != *it_ev2){
            nuevo.aniadeEvento((*it_ev1));
            nuevo.aniadeEvento((*it_ev2));
            resultado.insertaEvento(nuevo);
          }
          ++it_ev2;
        }
        ++it_ev1;
      }
    }
  }
}

// Este método también puede implementarse como operator<< asociado a la clase Cronología (A vuestra elección).
void ImprimeCronologia (const Cronologia &c, ostream &os){
   Cronologia::const_iterator it;
   for (it=c.cbegin(); it!=c.cend();++it){
       os<<(*it).first<<"#";          //año esta en el key del map
       EventoHistorico::const_iterator it_ev;
       for (it_ev=(*it).second.cbegin(); it_ev!=(*it).second.cend();++it_ev)
        os<<(*it_ev)<<"#";
   }
}

int main(int argc, char * argv[]){

  if (argc!=3 && argc!=4){
      cout<<"Error: debe dar al menos los nombres de dos ficheros con cronologías. "<<endl;
      cout<<"[Opcional]: un tercer nombre de fichero para guardar la cronología resultante."<<endl;
      return 0;
   }

   ifstream f1 (argv[1]);
   if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   ifstream f2 (argv[2]);
   if (!f2){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
   }

   Cronologia c1, c2, cUnion;
   f1 >> c1;    // Cargamos los datos de los ficheros en las cronologías.
   f2 >> c2;

   Union(c1, c2, cUnion);

   if (argc==3)   //No se dio fichero de salida, imprimimos en cout
      cout << cUnion;
   else{
     ofstream fout(argv[3]);
     if (!fout){
      cout<<"No puedo crear el fichero "<<argv[3]<<endl;
      return 0;
     }
    fout << cUnion;
   }
}
