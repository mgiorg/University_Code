#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"
                       
  

TipoLista minimiLocali(TipoLista l) {
	if (l == NULL) return listaVuota();
  	if (cdr(cdr(l)) == NULL) {
    	return listaVuota();
    }
  	else {
    	if (car(l) >= car(cdr(l)) && car(cdr(l)) <= car(cdr(cdr(l)))) {
        	return cons(car(cdr(l)), minimiLocali(cdr(l)));
        }
      	else {
        	return minimiLocali(cdr(l));  
        }            
    }  	
}


int calcolaSomma(TipoLista l) {
	if (l == NULL) return 0;
  	else {
    	return car(l) + calcolaSomma(cdr(l));
    }
}

int massimaSommaMinimi(TipoLista* liste, int n){
  	int massimo = 0;
  	TipoLista minLoc = (TipoLista) malloc (sizeof(int));
	for (int i = 0; i < n; i++) {
    	minLoc = minimiLocali(liste[i]);
       	int somma = calcolaSomma(minLoc);
        if (somma > massimo) {
        	massimo = somma;
        }
    }
  	return massimo;
}

