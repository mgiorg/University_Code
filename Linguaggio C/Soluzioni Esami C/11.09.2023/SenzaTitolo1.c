#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


TipoLista append(TipoLista l, T e) {
	if (estVuota(l)) 
    	return cons(e, l);
  	return cons(car(l), append(cdr(l), e));
}


TipoLista sommeDueADue_aux(TipoLista l) {
	int somma = 0;
  	somma = car(l) + car(cdr(l));  

  	if (cdr(cdr(l)) == NULL) {
    	return cons(somma, listaVuota());
    }
  	else {
		return cons(somma, sommeDueADue_aux (cdr(cdr(l))));
    }	
}


TipoLista sommeDueADue(TipoLista l) {
  	TipoLista l1 = (TipoLista) malloc ((length(l) + 1) * sizeof(int));
	if (l == NULL) return listaVuota();
  	if (length(l) == 1) {
    	return cons(2 * car(l), listaVuota());
    }
  	if (length(l) % 2 != 0) {
    	l1 = append (l, car(l));
    }
  	else {
    	l1 = l;
    }
  	return sommeDueADue_aux(l1);
}



double* mediaSommeDueADue(TipoLista* liste, int n) {
	double* arr = (double*) malloc (n * sizeof(double));
  	double media;
  	for (int i = 0; i < n; i++) {
    	TipoLista l_tmp = sommeDueADue (*(liste + i));
  		media = (double) sommaLista(l_tmp) / (double) length(l_tmp);
      	*(arr + i) = media;
    } 
  	return arr;
}
