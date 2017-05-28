#include <cassert>

using namespace std;

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int n){
  assert(n >= 0);
  if(n>0){
    v = new T[n];
    ocupados = 0;
    reservados = n;
  }
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico<T> &otro){
  if(otro.getOcupados() > 0){
    v = new T [otro.size()];
    reservados = otro.size();
    for(int i = 0; i < otro.getOcupados(); i++){
      v[i] = otro.v[i];
      ocupados++;
    }
  }
  else
    v = 0;
}

template <class T>
Vector_Dinamico<T>::~Vector_Dinamico(){
  if (ocupados > 0){
    delete [] v;
    reservados = 0;
    ocupados = 0;
  }
}

template <class T>
Vector_Dinamico<T> &Vector_Dinamico<T>::operator=(const Vector_Dinamico<T>&otro){
  if (this != otro) {
    if (ocupados > 0)
      delete [] v;
    v = new T [otro.size()];
    reservados = otro.size();
    for (int i = 0; i < otro.getOcupados(); i++) {
      v[i] = otro.v[i];
      ocupados++;
    }
  }
  return *this;
}

template <class T>
T& Vector_Dinamico<T>::operator[] (int pos){
  assert(pos > 0 && this->ocupados != 0);
  return this->v[pos];
}

template <class T>
const T& Vector_Dinamico<T>::operator[] (int pos) const{
  assert(pos > 0 && this->ocupados != 0);
  return this->v[pos];
}

template <class T>
int Vector_Dinamico<T>::getOcupados(){
  return this->ocupados;
}

template <class T>
int Vector_Dinamico<T>::size(){
  return this->reservados;
}

template <class T>
void Vector_Dinamico<T>::add(T e){
  if(this->reservados == this->ocupados){
    resize(reservados*2 + 1);
  }
  v[ocupados] = e;
  ocupados++;
}

template <class T>
void Vector_Dinamico<T>::delet(){
  ocupados--;
  if(reservados < ocupados / 4)
    resize(ocupados / 2);
}

template <class T>
void Vector_Dinamico<T>::resize(int n){
int minimo = 0;
  assert (n>=0);
  if (n != reservados){
    if (n != 0){
      T *aux = new T[n];
      if (reservados > 0) {
        minimo = reservados < n ? reservados:n;
        for (int i = 0; i < minimo; i++)
          aux[i] = v[i];
        delete [] v;
      }
      reservados = n;
      v = aux;
    }
    else{
      if (reservados > 0)
        delete [] v;
      this->v= 0;
      this->reservados = 0;
      this->ocupados = 0;
    }
  }
}
