/**
 * @file EventoHistorico.h
 * @brief Fichero cabecera del TDA EventoHistorico
 */
#ifndef _EVENTOHISTORICO_H_
#define _EVENTOHISTORICO_H_

#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <set>

using namespace std;
/**
 *  @brief TDA EventoHistorico.
 *  Una instancia @e c del tipo de datos abstracto @c EventoHistorico
 *  es un objeto pair con un contenedor set que almacenan una fecha
 *  y una sucesión de eventos alojados en un set.
 *
 *  Los ejemplos de su uso los encontramos en los mismos archivos que
 *  hemos visto para Cronología.
 *
 *  @author Antonio Miguel Morillo Chica
 *  @date 10 diciembre 2016
 */
class EventoHistorico{
  private:
    /**
     * @page repEventoHistorico Rep del TDA EventoHistorico.
     *
     * @section invEventoHistorico Invariante de la representación.
     * El invariante es \e eventos no repite key ni elementos.
     *
     * @section faEvento Función de abstracción.
     * Un objeto válido @e rep del TDA EventoHistorico representa el
     * una asociación entre una fecha y un contenedor de efentos
     * de la siguiente forma: [ [Key] [ [Evento1][Evento2] ] ].
     */
    pair<string, set<string>> eventos; /**< pair de la STL */
  public:
    /**
     *  @brief Clase iteradora constante sobre el pair.
     *  Se mueve de forma constante por el pair.
     */
    class const_iterator{
      private:
        set<string>::const_iterator it;
      public:
        /**
         *  @brief Sobrecarga del operador ++.
         */
        const_iterator &operator++(){++it;return *this;}
        /**
         *  @brief Sobrecarga del operador --.
         */
        const_iterator &operator--(){--it; return *this;}
        /**
         *  @brief Sobrecarga del operador *.
         *  @return Devuelve un pair.
         */
        const string operator*(){return *it;}
        /**
         *  @brief Sobrecarga del operador ==.
         */
        bool operator==(const const_iterator &i){return (i.it==it);}
        /**
         *  @brief Sobrecarga del operador !=.
         */
        bool operator!=(const const_iterator &i){return (i.it!=it);}
        friend class EventoHistorico;
    };
    /**
     *  @brief Clase iteradora constante sobre el pair.
     *  Se mueve de forma NO constante por el pair.
     */
    class iterator{
      private:
        set<string>::iterator it; ///<
      public:
        /**
         *  @brief Sobrecarga del operador ++.
         */
        iterator &operator++(){++it; return *this;}
        /**
         *  @brief Sobrecarga del operador --.
         */
        iterator &operator--(){--it; return *this;}
        /**
         *  @brief Sobrecarga del operador *.
         *  @return Devuelve un pair.
         */
        string operator*(){return *it;}
        /**
         *  @brief Sobrecarga del operador ==.
         */
        bool operator==(const iterator &i){return i.it==it;}
        /**
         *  @brief Sobrecarga del operador !=.
         */
        bool operator!=(const iterator &i){return i.it!=it;}
        friend class EventoHistorico;
    };
    /**
     * @brief Inicializa el iterador, sin parámetros.
     * Iterador constante.
     * @return devuelve la posición de inicio.
     */
    const_iterator cbegin() const { const_iterator i; i.it=eventos.second.cbegin(); return i; }
    /**
     * @brief Inicializa el iterador, sin parámetros.
     * Iterador constante.
     * @return devuelve la posición de final.
     */
    const_iterator cend() const { const_iterator i; i.it=eventos.second.cend(); return i; }
    /**
     * @brief Inicializa el iterador, sin parámetros.
     * Iterador NO constante.
     * @return devuelve la posición de inicial.
     */
    iterator begin() {iterator i; i.it=eventos.second.begin(); return i;}
    /**
     * @brief Inicializa el iterador, sin parámetros.
     * Iterador NO constante.
     * @return devuelve la posición final.
     */
    iterator end() {iterator i; i.it=eventos.second.end(); return i;}
    /**
     * @brief Consultor de la key.
     * @return devuelve la key.
     */
    string getFirst(){ return eventos.first; }
    /**
     * @brief Modificador de la clave.
     * @param a clave que queremos asignar a nuestro contenedor.
     */
    void aniadeAnio(string a){ eventos.first = a; }
    /**
     * @brief Modificador del contendor.
     * @param e evento que se quiere insertar en el set del pair.
     */
    void aniadeEvento(string e){eventos.second.insert(e); }
    /**
     * @brief Inserta un EventoHistorico completo.
     * @param e evento historico a añadir.
     */
    void insertaEventoHistorico(EventoHistorico e);
    /**
     * @brief Sobrecarga dle operador <<.
     * El operador << se usa para mostrar un evento. Simplemente itera
     * por el y lo va mostrando.
     */
    friend ostream &operator<<(ostream &os, EventoHistorico &e);
};

#endif
