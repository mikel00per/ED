/**
 * @file Cronologia.h
 * @brief Fichero cabecera del TDA Cronologia.
 */
#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "EventoHistorico.h"

using namespace std;

/**
 *  @brief TDA Cronología.
 *  Una instancia @e c del tipo de datos abstracto @c Cronologia es un
 *  objeto contenedor de EventosHistoricos representados como un
 *  map de la STL con: [[Key][Value]].
 *
 *  Los ejemplos de su uso los encontramos en:
 *  pruebaronologia.cpp:
 *  @include pruebacronologia.cpp
 *  union_cronologia.cpp:
 *  @include union_cronologia.cpp
 *  filtrado_palabra.cpp:
 *  @include filtrado_palabra.cpp
 *  filtrado_intervalo:
 *  @include filtrado_intervalo.cpp
 *
 *  @author Antonio Miguel Morillo Chica
 *  @date 10 diciembre 2016
 */
class Cronologia{
  private:
    /**
     * @page repCronologia Representación del TDA Cronologia.
     *
     * @section invCronologia Invariante de la representación
     * El invariante es \e Cronologia.crono no repite key. Así mismo
     * la key perteneciende Cronologia.crono ha de conincidir con la key
     * perteneciente a EventoHistorico.eventos.
     *
     * @section faCronologia Función de abstracción.
     * Un objeto válido @e rep del TDA Cronologia representa un contenedor map
     * de pair de un set de forma que el segundo elemento de Cronologia tiene
     * la misma clave que el map: [ [Key] [[SubKey] [[evento1] [evento2] ...]] ].
     */
    map <string, EventoHistorico> crono; /**< map de la stl */
  public:
    /**
     *  @brief Clase iteradora constante sobre el map.
     *  Se mueve de forma constante por el map.
     */
    class const_iterator{
      private:
        map <string, EventoHistorico>::const_iterator it;
      public:
        /**
         *  @brief Sobrecarga del operador ++.
         */
        const_iterator &operator++(){ ++it; return *this;}
        /**
         *  @brief Sobrecarga del operador --.
         */
        const_iterator &operator--(){ --it; return *this;}
        /**
         *  @brief Sobrecarga del operador *.
         *  @return Devuelve un pair.
         */
        const pair<const string, EventoHistorico> &operator*(){ return *it; }
        /**
         *  @brief Sobrecarga del operador ==.
         */
        bool operator==(const const_iterator &i){ return i.it==it; }
        /**
         *  @brief Sobrecarga del operador !=.
         */
        bool operator!=(const const_iterator &i){ return i.it!=it; }
        friend class Cronologia;
    };
    /**
     *  @brief Clase iteradora sobre el map.
     *  Se mueve de forma NO constante por el map.
     */
    class iterator{
      private:
        map <string, EventoHistorico>::iterator it;
      public:
        /**
         *  @brief Sobrecarga del operador ++.
         */
        iterator &operator++(){ ++it; return *this; }
        /**
         *  @brief Sobrecarga del operador --.
         */
        iterator &operator--(){ --it; return *this; }
        /**
         *  @brief Sobrecarga del operador *.
         *  @return Devuelve un pair.
         */
        pair <const string, EventoHistorico> &operator*(){return *it; }
        /**
         *  @brief Sobrecarga del operador ==.
         */
        bool operator==(const iterator &i){ return i.it==it; }
        /**
         *  @brief Sobrecarga del operador !=.
         */
        bool operator!=(const iterator &i){ return i.it!=it; }
        friend class Cronologia;
    };
    /**
     * @brief  Inicializa el iterador con parámetros.
     * Inicializa el iterador con la posición perteneciente a una key
     * específica, forma constante.
     * @param  key año a buscar
     * @return     devuelve un iterador desde la posición del año.
     */
    const_iterator cfind(string key) const{ const_iterator i; i.it=crono.find(key);  return i; }
    /**
     * @brief Inicializa el iterador, sin parámetros.
     * Iterador constante.
     * @return devuelve la posición de inicio.
     */
    const_iterator cbegin() const{ const_iterator i; i.it=crono.cbegin(); return i;}
    /**
     * @brief Inicializa el iterador, sin parámetros.
     * Iterador constante.
     * @return devuelve la posición de final.
     */
    const_iterator cend() const{ const_iterator i; i.it=crono.cend(); return i;}
    /**
     * @brief  Inicializa el iterador con parámetros.
     * Inicializa el iterador con la posición perteneciente a una key
     * específica, forma constante.
     * @param  key año a buscar
     * @return     devuelve un iterador desde la posición del año.
     */
    iterator find(string key){ iterator i; i.it=crono.find(key); return i; }
    /**
     * @brief Inicializa el iterador, sin parámetros.
     * Iterador NO constante.
     * @return devuelve la posición de inicial.
     */
    iterator begin(){ iterator i; i.it=crono.begin(); return i; }
    /**
     * @brief Inicializa el iterador, sin parámetros.
     * Iterador NO constante.
     * @return devuelve la posición final.
     */
    iterator end(){ iterator i; i.it=crono.end(); return i; }
    /**
     * @brief Consulta los EventosHistoricos de un año.
     * @param  anio fecha a consultar.
     * @return devuelve un objeto de tipo EventoHistorico.
     */
    EventoHistorico GetEventos (int anio);
    /**
     * @brief Inserta un evento en el map.
     * En la key del objeto que entra por parámetro será la misma que la
     * del map.
     * @param e EventoHistorico que queremos añadir.
     */
    void insertaEvento(EventoHistorico e){ crono[e.getFirst()] = e; }
    /**
     * @brief Sobrecarga del operador <<.
     * Operador que se usa para mostrar un objeto de tipo Cronologia.
     */
    friend ostream &operator<<(ostream &os, Cronologia &crono);
    /**
     * @brief Sobrecarga del operador >>.
     * Operador que se usa para leer de un fichero.
     */
    friend istream &operator>>(istream &is, Cronologia &crono);
};

#endif
