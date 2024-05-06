#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista convoluzione_aux(TipoLista l, int k, int indice) {
  	if (l == NULL) return listaVuota(); 
	if (cdr(l) == NULL) {
    	return cons(car(l), listaVuota());
    }
	else {
      	if (indice % k == 0) {
          	return cons(car(l), convoluzione_aux(cdr(l), k, indice + 1));
        }
      	else {
          	
          	TipoLista listaRitornata = convoluzione_aux(cdr(l), k, indice + 1);
          	return cons(car(listaRitornata) + car(l), cdr(listaRitornata));
        }
    }
}

TipoLista convoluzione(TipoLista l, int k) {
	return convoluzione_aux(l, k, 1);
}

int max(TipoLista l, int massimo) {
  	if (l == NULL) return massimo;

    if (car(l) > massimo) return max(cdr(l), car(l));
  
  	else return max(cdr(l), massimo);
}

int* maxPooling(TipoLista* liste, int* v, int n){
	int* output = (int*) malloc (n * sizeof(int));
	for (int i = 0; i < n; i++) {
      	TipoLista conv = convoluzione(liste[i], v[i]);
      	output[i] = max(conv, -1);
    }
  	return output;
}

