#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

void ordenar(int *v, int n){
  bool cambio=true;
  for (int i = 0; i < n-1 && cambio; i++) {
      cambio = false;
    for (int j = 0; j < n-i-1; j++) {
      if (v[j]>v[j+1]) {
        cambio = true;
        int aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
  }
}

void sintaxis(){
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {

  if (argc!=3)
    sintaxis();

  int tam=atoi(argv[1]);     // Tamaño del vector
  int vmax=atoi(argv[2]);    // Valor máximo

  if (tam<=0 || vmax<=0)
    sintaxis();

  int v2[tam];
  srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  for (int i=0; i<tam; i++)  // Recorrer vector
    v2[i] = rand() % vmax;    // Generar aleatorio [0,vmax[


/*
  int v1[tam];
  for (int i=0; i<tam; i++)  // Recorrer vector
  v1[i] = i;
  
  
*/

  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();
  // Algoritmo a evaluar
  ordenar(v2,tam);
  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

  return 0;
}
