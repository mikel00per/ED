/**
  * @file pila_max_VD.h
  * @brief Fichero cabecera del TDA pila como vector
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos.
  */

#ifndef __PILA_MAX_H__
#define __PILA_MAX_H__

#include "vector_dinamico.h"

/**
  * @brief T.D.A. Pila
  *
  * La implementación interna se basa en un vector dinámico de donde se insertan
  * y sacan datos a modo de cola LIFO, Last Input First Outout, el primero que
  * entra es el primero que sale. Es la misma idea que el funcionamiento de la
  * pila con las llamadas de las funciones.
  *
  * @author Antonio Miguel Morillo Chica
  * @date 13-11-2016
  */
class Pila_max{
  private:
  /**
    * @brief Rep de pila_max
    *
    * Guardamos los datos en un vector_dinamico de tipo elemento
    * En este caso no hay invariante de la representación ya que
    * todo descansa en la clase vector_dinamico
    *
    */
    Vector_Dinamico<elemento> v; ///<puntero, vector dinámico

  public:
  /**
   * @brief Consulta si la pila está vacía.
   *
   */
  bool vacia();

  /**
   * @brief Introduce un nuevo elemento en la pila.
   * @param n numero a introducir a la pila
   */
  void poner(int n);

  /**
   * @brief Elimina el último elemento de la pila.
   *
   */
  void quitar();

  /**
   * @brief Consulta el máximo elemento de la pila.
   *
   */
  elemento tope();
};

#include <pila_max_VD.cpp>

#endif
