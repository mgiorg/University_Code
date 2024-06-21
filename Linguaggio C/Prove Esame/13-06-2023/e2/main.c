#include "funzioni.c"

T sommaKelementi(TipoLista l, int k) {
	if(estVuota(l) || k == 0) return 0;
  	return car(l) + sommaKelementi(cdr(l), k-1);
}

TipoLista avanzarediKelementi(TipoLista l, int k) {
	if(	estVuota(l) || k == 0 ) return l;
  	return avanzarediKelementi(cdr(l), k-1);
}

TipoLista convoluzione_aux(TipoLista l, int k, int n) {
	if(n == 0) return listaVuota();
  	T somma = sommaKelementi(l, k);
  	return cons(somma, convoluzione_aux(avanzarediKelementi(l, k), k, n-1));
}

TipoLista convoluzione(TipoLista l, int k) {
  
  if(estVuota(l)) return listaVuota();
  
  int len = length(l);
  int n = (len + k - 1) / k;
  
  return convoluzione_aux(l, k, n);
	
}

int massimo(TipoLista l) {
    if (estVuota(l)) return 0;
    int max_rest = massimo(cdr(l));
    int current = car(l);
    return (current > max_rest) ? current : max_rest;
}

int* maxPooling(TipoLista* liste, int* v, int n){
  int* output = (int*) malloc(n*sizeof(int));
  if(output == NULL) {
  	printf("Errore nella creazione dell'array\n");
    exit(1);
  }
  for(int i = 0; i < n; ++i) {
  	TipoLista nuovaLista = convoluzione(liste[i], v[i]);
    output[i] = massimo(nuovaLista);
    freelist(nuovaLista);
  }
  return output;
  
}
int main() {


	return 0;
}