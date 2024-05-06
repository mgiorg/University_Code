#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

TipoLista convoluzione_aux(TipoLista l, int k, int conta, int somma) {
  	if (l == NULL) return listaVuota();
  	somma += car(l);
  	if (cdr(l) == NULL) {
      	return cons(somma, listaVuota());
    }
	if (conta == k) {    	      	
    	return cons(somma, convoluzione_aux(cdr(l), k, 1, 0));
      	
    }
  	else {
      	return convoluzione_aux(cdr(l), k, conta + 1, somma);    
    }
}

TipoLista convoluzione(TipoLista l, int k) {
	if (l == NULL) return listaVuota();  	
  	return convoluzione_aux(l, k, 1, 0);
}



int calcolaMassimo(TipoLista l, int massimo) {
	if (l == NULL) return massimo;
  	if (car(l) > massimo) {
    	massimo = car(l);
    }
  	return calcolaMassimo(cdr(l), massimo);
}

int* maxPooling(TipoLista* liste, int* v, int n){
  	int massimo;
	int* ris = (int*) malloc (n * sizeof(int));
  	TipoLista appo;
  	for (int i = 0; i < n; i++) {
    	appo = convoluzione(liste[i], v[i]);
      	massimo = calcolaMassimo(appo, 0);
      	ris[i] = massimo;
    }
  	return ris;
}
