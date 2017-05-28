/**
  * @file vector_dinamico.h
  * @brief Fichero cabecera del TDA Vector Dinamico
  *
  * Se crea un vector con capacidad de crecer y decrecer
  */
#ifndef _VECTOR_DINAMICO_H_
#define _VECTOR_DINAMICO_H_

/**
 *  @brief T.D.A. Vector_Dinamico
 *
 * Una instancia @e v del tipo de datos abstracto @c Vector_Dinamico sobre el
 * tipo @c float es un array 1-dimensional de un determinado tamaño @e n, que
 * puede crecer y decrecer a petición del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]}
 *
 * donde  v[i] es el valor almacenado en la posición  i del vector
 *
 * La eficiencia en espacio es @e O(n).
 *
 * Un ejemplo de su uso:
 * @include usopilas_max.cpp
 *
 */
template <class T>
class Vector_Dinamico{
  private:
    /**
     * @page repVector_Dinamico Rep del TDA Vector_Dinamico
     *
     * @section invVector_Dinamico Invariante de la representación
     *
     * Un objeto válido @e v del TDA Vector_Dinamico debe cumplir
     * - @c v.nelementos>= 0
     * - @c v.datos apunta a una zona de memoria con capacidad para albergar
     *   @c nelementos valores de tipo @c int
     *
     * @section faVector_Dinamico  Función de abstracción
     *
     * Un objeto válido @e rep del TDA Vector_Dinamico representa al vector de
     * tamaño @e n
     *
     * {v.datos[0],v.datos[1],...,v.datos[v.nelementos-1]}
     *
     */
    T *v;               ///<vector
    int reservados;     ///<memoria reservada
    int ocupados;       ///<numero de posiciones ocupadas

  public:
    /**
     * @brief Contructor por defecto
     * @param n valor por defecto a 0
     */
    Vector_Dinamico(int n=0);

    /**
     * @brief Constructor de copia
     * @param v Vector que se quiere copiar
     */
    Vector_Dinamico(const Vector_Dinamico & v);

    /**
     * @brief Destructor de la clase
     * Recolector automatico de basura.
     */
    ~Vector_Dinamico();

    /**
     * @brief Sobrecarga del operado asignación.
     * @param v vector que se quiere igualar al objeto implicito
     */
    Vector_Dinamico &operator=(const Vector_Dinamico &v);

    /**
     * Sobrecarga del operador [] para acceder a una posición del vector
     * @param  pos indice al qu se quiere acceder.
     * @return devuelve el objeto elemento correspondiente
     */
    T& operator[] (int pos);

    /**
    * Sobrecarga del operador constante [] para acceder a una posición del vector
    * @param  pos indice al qu se quiere acceder.
    * @return devuelve el objeto elemento correspondiente
     */
    const T& operator[] (int pos) const;

    /**
     * Función que reasigna el tamaño
     * @param n tamaño deseado para el vector.
     */
    void resize(int n);

    /**
     * Consultor del tamaño reservados
     * @return devuelve el tamaño que se ha reservado.
     */
    int size();

    /**
     * Consultor de posiciones ocupadas
     * @return devuelve la actidad de espacios ocupados en el vector
     */
    int getOcupados();

    /**
     * Añade al vector un elemento
     * @param e elemento que se quiere añadir
     */
    void add(T e);

    /**
     * Elimina una posición del vector. 
     */
    void delet();
};

#include <vector_dinamico.cpp>

#endif
