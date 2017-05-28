/**
  * @file cronologia.h
  * @author Antonio Miguel Morillo Chica
  * @date 10 Octubre de 2016
  * @brief Clase para la estructura de datos de un vector dinámico de listas enlazadas.
  * Permite el manejo de listas enlazadas dentro de un vector dinámico.
  */

#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include "listaeventos.h"
#include <istream>
#include <fstream>

using namespace std;

class Cronologia{

private:
  ListaEventos *lista_eventos;   /**< "Vector" de listas enlazadas */
  int filas=0;                   /**< Posición de la siguiente lista */

public:
  /**
  * @brief Constructor sin parámetros.
  * Constructor sin parámetros. Crea una creonología vacía.
  */
  Cronologia();

  /**
  * @brief Constructor con parámetros.
  * @param filas cantidas de años distintos
  * Constructor con parámetros. Crea una Cronologia con el tamaño de las filas
  */
  Cronologia(const int filas);

  /**
  * @brief Destructor de la clase.
  * Destructor de la clase. Elimina los objetos de tipo cronología.
  */
  ~Cronologia();

  /**
  * @brief Crea una creonología de un tamño determinado.
  * @param filas numero de años distintos
  * Crea una creonología de un tamño determinado. Para ser usado dentro de la
  * clase.
  */
  void crear(int filas);

  /**
  * @brief Destruye una cronología
  * Destruye una cronología. Se usa dentro de la clase no sobre un objeto implicito.
  */
  void destruir();

  /**
  * @brief Consulta una lista de eventos de un año determinado
  * @param n año que se quiere consultar.
  * @return Devuelve un vector con cada uno de los eventos de ese año.
  */
  vector<string> GetEventos(int n);

  /**
  * @brief Consultor de filas.
  * @return Devuelve la cantidad de años distintos dentro de una cronología
  * determinada.
  */
  int getFilas();

  friend istream &operator >>(istream &entrada, Cronologia &crono);

};

#endif
