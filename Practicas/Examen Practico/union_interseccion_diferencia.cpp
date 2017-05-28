/******************************************************************************/
/*
/*
/*
/*
/******************************************************************************/

#include <iostream>
#include <set>

using namespace std;

void leerConjunto(set<int> &conj, int cantidad) {
  int elemento;
  for (int i = 0; i < cantidad; ++i) {
    cout << "Escribe un elemento: ";
    cin >> elemento;
    conj.insert(elemento);
  }
}

void imprimirConjunto(const set<int> &conj) {
  set<int>::iterator it;
  for (it = conj.begin(); it != conj.end(); it++)
    cout << " " << (*it);
  cout << endl;
}


set<int> opUnion(const set<int> &a, const set<int> &b) {
  set<int> unionSet;
  set<int>::iterator it;

  for (it = a.begin(); it != a.end(); it++)
    unionSet.insert(*it);

  for (it = b.begin(); it != b.end(); it++)
  if (unionSet.count(*it) == 0)
  unionSet.insert(*it);

  return unionSet;
}

set<int> opInterseccion(set<int> &a, set<int> &b) {
  set<int> interseccion;
  set<int> mayor, menor;
  set<int>::iterator it;

  if (a.size() > b.size()) {
    mayor = a;
    menor = b;
  } else {
    mayor = b;
    menor = a;
  }

  for (it = menor.begin(); it != menor.end(); it++)
    if (mayor.count(*it) > 0)
      interseccion.insert(*it);

  return interseccion;
}

set<int> opDiferencia(set<int> &a, set<int> &b) {
  set<int> diferencia;
  set<int>::iterator it;

  for (it = a.begin(); it != a.end(); it++)
    if (b.count(*it) == 0)
      diferencia.insert(*it);

  return diferencia;
}

int main(){
  set<int> a, b;
  int aux;

  cout << "Cuantos elementos son en el conjunto A: ";
  cin >> aux;
  leerConjunto(a, aux);

  cout << endl << "Cuantos elementos son en el conjunto B: ";
  cin >> aux;
  leerConjunto(b, aux);

  cout << endl << "Conjunto A:";
  imprimirConjunto(a);
  cout << "Conjunto B:";
  imprimirConjunto(b);
  cout << "A union B:";
  //imprimirConjunto(&opUnion(a, b));
  imprimirConjunto(opUnion(a, b));
  cout << "A interseccion B:";
  imprimirConjunto(opInterseccion(a, b));
  cout << "A - B:";
  imprimirConjunto(opDiferencia(a, b));
  cout << "B - A:";
  imprimirConjunto(opDiferencia(b, a));

  return 0;
}
