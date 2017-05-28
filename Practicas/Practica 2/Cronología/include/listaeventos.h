/**
  * @file listaeventos.h
  * @author Antonio Miguel Morillo Chica
  * @date 8 Junio de 2016
  * @brief Clase para la estructura de datos de lista de strings.
  * Permite el manejo de cadenas (strings) en una lista enlazada
  */

#ifndef _LISTAEVENTOS_H_
#define _LISTAEVENTOS_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct EventoHistorico{
  EventoHistorico *siguiente;   /**<Puntero al siguiente evento. */
  string evento;                /**< Nombre del evento           */

};

class ListaEventos{
private:
  int columnas=0;             /**< Posición de cada evento en la lista enlazada */
  EventoHistorico *cabecera;  /**<Primera posición de la lista enlazada */
  int fecha;                  /**< Fecha de cada evento historico */

public:
  /**
  * @brief Constructor por defecto.
  * Contructor por defecto. Crea una Lista de eventos vacía.
  */
  ListaEventos();

  /**
  * @brief Constructor por parametros.
  * @param cadena sucesión de eventoshistoricos separados por #
  * Constructor por parametros. Construye una lista de eventos de tamaño
  * indefinido y escribe en la primera fila los eventos historicos que tenga
  * el string cadena.
  */
  ListaEventos(string cadena);

  /**
  * @brief Constructor de copia
  * @param otra lista que queremos copiar
  */
  ListaEventos(const ListaEventos &otra);

  /**
  * @brief Destructor
  * Destructor: destruye automaticamente la basura.
  */
  ~ListaEventos();

  /**
  * @brief Destruye el objeto
  * Destruye el objeto implicito.
  */
  void destruir();

  /**
  * @brief Copia todos los eventos
  * @param otra Lista de eventos por la que queremos sustituirla
  * Copia todos los eventos de una lista al objeto implicito.
  */
  ListaEventos &copiarLista(const ListaEventos &otra);

  /**
  * @brief Sobrecarga del operator=
  * @param otra Lista de eventos por la que queremos sustituirlo
  * Sobrecarga del operator= iguala la primera lista a la segunda. Esta sí
  * se puede igualar inmediatamente a otra.
  */
  ListaEventos &operator=(const ListaEventos &otra);

  /**
  * @brief Sobrecarga del operador+
  * @param nueva_lsita sucesión de eventoshistoricos separados por #
  * Sobrecarga del operador+ suma dos listas en una sola construyendo una sola
  * lista donde la segunda es una concatenación de la siguiente.
  */
  ListaEventos &operator+(const string nueva_lista);

  /**
  * @brief Inserta un nuevo año a la cronología
  * @param evento que se quiere insertar
  * @return Añade al objeto implícito un año nuevo en la posición correspondiente.
  * @pre el año ya ha sido definido.
  */
  void insertar(string evento);

  /**
  * @brief Inserta una lista completa de eventos
  * @param list lista de eventos que se quieren insertar
  * @return Añade al objeto implícito una los eventos correspondientes.
  * @pos el año ha de ser fijado
  */
  void insertarLista(string list);

  /**
  * @brief Muestra el titulo de un evento.
  * @param i celda que contiene el evento
  * @return Devuelve el string que contiene.
  *
  */
  string getEvento(int i);

  /**
  * @brief Consulta los eventos de toda una fecha
  * @return devuelve la lista de eventos en un vector de strings.
  */
  vector<string> getEventos();

  /**
  * @brief Cantidad de años dentro de la cronología
  * @return Devuelve el tamaño de la lista enlazada principal (columnas).
  */
  int getColumnas();

  /**
  * @brief Consulta la fecha de la lista de eventos
  * @return Devuelve la fecha de los eventos de la lista
  */
  const int getFecha();

};

#endif
