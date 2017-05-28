
using namespace std;

////////////////////////////////////////////////////////////////////////////////

bool Pila_max::vacia(){
  return (v.getOcupados() == 0);
}

void Pila_max::poner(int n){
  elemento nuevo;
  nuevo.n = n;

  if (vacia()){
    nuevo.max = n;}
  else{
    elemento anterior = tope();
    nuevo.max = (n > anterior.max) ? n : anterior.max;
  }
  v.add(nuevo);
}

void Pila_max::quitar(){
  v.delet();
}

elemento Pila_max::tope() {
  return v[v.getOcupados()];
}

////////////////////////////////////////////////////////////////////////////////
