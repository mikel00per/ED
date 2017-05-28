
using namespace std;

struct elemento {
  int n;
  int max;

  friend ostream& operator<<(ostream &salida, const elemento &e){
    salida << "[ "<< e.n << " | " << e.max << " ] ";
    return salida;
  };
};

#define CUAL_COMPILA 2

#if CUAL_COMPILA==1
#include <pila_max_VD.h>

#elif CUAL_COMPILA==2
#include <pila_max_list.h>

#else
#include <pila_max_cola.h>

#endif
