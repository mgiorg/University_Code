#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int length(TipoLista l) {
if (l == NULL) return 0;
  return 1 + length(cdr(l));
}

int posizioni_alternanza_aux(TipoLista l) {
 
if (l == NULL) return 0;  
    if (length(l) == 1) return 1;
  	if (length(l) == 2) return 2;
    if (car(l) == car(cdr(cdr(l)))) {
    	return 1 + posizioni_alternanza_aux(cdr(l));        
    }
    else {
    	return 2;  
    }           
}


int posizioni_alternanza(TipoLista l) {
    bool inizio = true;
    if (l == NULL) return 0;
    if (length(l) == 1) return 1;
    if (length(l) == 2) return 2;
	return posizioni_alternanza_aux(l);
}




void aggiungi_elem(TipoLista l, int start, int i, char* ris) {
  	if (estVuota(l)) return;
  	if (i >= start) {
    	ris[i - start] = car(l);
  	}
	aggiungi_elem(cdr(l), start, i + 1, ris);
}


char* prefisso_alternante(TipoLista *liste, int n) {
  	int max = 0, num;
  	TipoLista lista_max;
  	for (int i = 0; i < n; i++) {
    	num = posizioni_alternanza(liste[i]);
      	if (num > max) {
        	max = num;
          	lista_max = liste[i];        
        }
    }    
  	char* ris = (char*) calloc ((length(lista_max) - max), sizeof(char)); 
    aggiungi_elem(lista_max, max, 0, ris);
  	return ris;
}
