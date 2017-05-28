/**
  * @file pila_max_list.h
  * @brief Fichero cabecera del TDA pila como vector
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos.
  */

#ifndef __PILA_MAX_H__
#define __PILA_MAX_H__

#include <cassert>

/**
  * @brief T.D.A. List
  *
  * La implementación interna se basa en un vector dinámico de donde se insertan
  * y sacan datos a modo de cola LIFO, Last Input First Outout, el primero que
  * entra es el primero que sale. Es la misma idea que el funcionamiento de la
  * pila con las llamadas de las funciones.
  *
  * @author Antonio Miguel Morillo Chica
  * @date 13-11-2016
  */

template <class T>
class Pila_max{
  private:
    struct Celda{
      T elemento;
      Celda *siguiente;
      Celda() : siguiente(0) {};
      Celda(const T & elem, Celda * sig) : elemento(elem), siguiente(sig) {};
    };

    Celda *cabecera; ///<puntero, vector dinámico
    int nelementos;

  public:
  /**
   * @brief Constructor sin parámetros
   *
   */
  Pila_max():cabecera(0), nelementos(0){};

  /**
   * @brief Constructor de copia
   * @param otra referencia a la lista que se quiere copiar.
   * La lista se copiará sobre el objeto implicito.
   */
  Pila_max(const Pila_max<T> &otra);

  /**
   * @brief Destructor de la clase
   * Invoca a destruir.
   */
  ~Pila_max();

  /**
   * @brief Sobrecarga del operador asignación
   * @param otra refiere a la nueva pila que se quiere asignar al objeto implicito
   */
  Pila_max<T> &operator=(const Pila_max<T> &otra);

  /**
   * @brief Consulta si la pila está vacía.
   *
   */
  bool vacia(){return cabecera==0;};

  /**
   * @brief Introduce un nuevo numero en la pila.
   * @param n numero a introducir a la pila
   */
  void poner(int n);

  /**
   * @brief Introduce un nuevo elemento a la pila
   * @param e elemento a introducir
   */
  void insertar(T & e);

  /**
   * @brief Elimina el último elemento de la pila.
   *
   */
  void quitar();

  /**
   * @brief Consulta el máximo elemento de la pila.
   *
   */
   T& tope() {assert(cabecera!=0); return cabecera->elemento;};

};

#include <pila_max_list.cpp>

#endif
