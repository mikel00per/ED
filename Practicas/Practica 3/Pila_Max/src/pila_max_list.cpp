#include "pila_max_list.h"

using namespace std;

template <class T>
Pila_max<T>::Pila_max(const Pila_max<T> &otra){
  if (otra.cabecera!=0) {
    Celda *orig=otra.cabecera;
    Celda *nueva;
    cabecera=nueva= new Celda(orig->elemento,0);
    orig=orig->siguiente;
    while (orig!=0) {
      nueva->siguiente=new Celda(orig->elemento,0);
      nueva=nueva->siguiente;
      orig=orig->siguiente;
    }
  }
  else cabecera=0;
  nelementos=otra.nelementos;
}

template <class T>
Pila_max<T>::~Pila_max(){
  Celda *aux;
  while (cabecera!=0) {
    aux= cabecera;
    cabecera=cabecera->siguiente;
    delete aux;
  }
}

template <class T>
Pila_max<T> &Pila_max<T>::operator=(const Pila_max<T> &otra){
  if (this!=&otra) {
    Celda *aux;
    while (cabecera!=0) {
      aux= cabecera;
      cabecera=cabecera->siguiente;
      delete aux;
    }
    if (otra.cabecera!=0) {
      Celda *orig=otra.cabecera;
      Celda *nueva;
      cabecera=nueva= new Celda(orig->elemento,0);
      orig=orig->siguiente;
      while (orig!=0) {
        nueva->siguiente=new Celda(orig->elemento,0);
        nueva=nueva->siguiente;
        orig=orig->siguiente;
      }
    }
    nelementos=otra.nelementos;
  }
  return *this;
}

template <class T>
void Pila_max<T>::poner(int n){

  elemento nuevo;
  nuevo.n = n;

  if (vacia())
    nuevo.max = n;
  else{
    elemento anterior = tope();
    nuevo.max = (n > anterior.max) ? n : anterior.max;
  }

  insertar(nuevo);
}

template <class T>
void Pila_max<T>::insertar(T &e){
  cabecera = new Celda(e,cabecera);
  nelementos++;
}

template <class T>
void Pila_max<T>::quitar(){
  assert (cabecera != 0);
  Celda *aux = cabecera;
  cabecera = cabecera -> siguiente;
  delete aux;
}
