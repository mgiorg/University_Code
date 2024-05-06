#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"



int findMedia(TipoLista l) {
return sommaLista(l) / length(l);
}


TipoLista mediaMenoMax_aux(TipoLista l, bool cond, int max, int valore) {
int media;
 
  if (l == NULL) return listaVuota();
  else {
    if (cdr(l) == NULL) {
          if (valore > max) {
            max = valore;
            }
          return cons (max, mediaMenoMax_aux(cdr(l), cond, max, valore));
        }
      else if (cond) {
          valore = car(l);
          cond = false;
          media = findMedia(cdr(l));
        return cons (max - media, mediaMenoMax_aux(cdr(l), cond, max, valore));
        }
      else {
        if (valore > max) {
            max = valore;
            }
          valore = car(l);
          media = findMedia(cdr(l));
         
          return cons (max - media, mediaMenoMax_aux(cdr(l), cond, max, valore));
         
        }
    }
}

TipoLista mediaMenoMax(TipoLista l) {
bool cond = true;
  int massimo = 0;
  int valore = 0;
  return mediaMenoMax_aux(l, cond, massimo, valore);
}



void getValue(TipoLista* liste, int n, int* array, int index) {
 
  	TipoNodo* liste_trasf[n];
 
  	if (length(*(liste + 1)) > 0) {

        int max = -200;
        for (int k = 0; k < n; k++) {
            if (car(*(liste + k)) > max) {
                max = car(*(liste + k));
            }

            *(liste_trasf + k) = cdr(*(liste + k));
        }

        *(array + index) = max;

        getValue(liste_trasf, n, array, index + 1);
   
  }
 
}


int* massimiElementi(TipoLista* liste, int n) {
 
  	int* array = (int*) calloc (length(*(liste + 1)), sizeof(int));
                                 
    TipoLista* liste_trasf = (TipoLista*) malloc(n * sizeof(int) * length(*(liste + 1)));
 
  	for (int i = 0; i < n; i++) {
    	*(liste_trasf + i) = mediaMenoMax(*(liste + i));
    }
  
  	getValue(liste_trasf, n, array, 0);
 
  	return array;
}
