#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int SommaSuff(TipoLista l) {
	if (l == NULL) return 0;
  	return car(l) + SommaSuff(cdr(l));
}

TipoLista ListaSuffisso(TipoLista l) {
  	if(cdr(l) == NULL) return cons(car(l), listaVuota());
    	
	if (car(l) < car(cdr(l))) return cons(car(l), listaVuota()); 
  	
   	return cons(car(l), ListaSuffisso(cdr(l)));   
}

TipoLista append(int e, TipoLista l) {
	if (l == NULL) return cons(e, l);
    return cons(car(l), append(e, cdr(l)));
}

TipoLista ListaInversa(TipoLista l) {
	if (cdr(l) == NULL) return append(car(l), listaVuota());
  	return append(car(l), ListaInversa(cdr(l))); 
}

TipoLista precedentiMenoSuffisso_aux(TipoLista l, int somma_suff, int somma_prec) {
	if (cdr(l) == NULL) return cons(somma_prec - somma_suff, listaVuota());
  	return cons(somma_prec - somma_suff, precedentiMenoSuffisso_aux(cdr(l), somma_suff, somma_prec + car(l)));
}


TipoLista precedentiMenoSuffisso(TipoLista l) {
  	
  	if (l == NULL) return listaVuota();
  	TipoLista lista_suff = (TipoLista) malloc (length(l) * sizeof(int));
  	lista_suff = ListaSuffisso(ListaInversa(l));
  	int somma_suff = SommaSuff(lista_suff);
  	return precedentiMenoSuffisso_aux(l, somma_suff, 0); 
}


double* mediaPrecedentiMenoSuffisso(TipoLista* liste, int n){
  	double* ris = (double*) malloc (n * sizeof(double));
	for (int i = 0; i < n; i++) {
    	int len = length(liste[i]);
      	TipoLista nuova = (TipoLista) malloc (len * sizeof(int));
      	if(liste[i] == NULL) {
        	ris[i] = 0.0;
        }
      	else {
            nuova = precedentiMenoSuffisso(liste[i]);
            ris[i] = (double) sommaLista(nuova) / (double) length(nuova);
        }
    } 	
  	return ris;
}


