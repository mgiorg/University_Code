#include "aux.h"


int length(TipoSCL lis) {
	if (lis == NULL) return 0;
  	return 1 + length(lis -> next);
}


int sommaElementi_aux(TipoSCL lis, int i, int indice) {
	if (i == indice) return lis -> info;
  	else {
    	sommaElementi_aux(lis -> next, i, indice + 1);
    }
}

int sommaElementi(TipoSCL lis, int i, int j) {
  	if (lis == NULL) return -1;
  	if (i > length(lis) || j > length(lis)) return -1;
	return sommaElementi_aux(lis, i, 0) + sommaElementi_aux(lis, j, 0);
}



void sommatoriaDispari_aux(TipoSCL lis, TipoSCL ris, int somma, int indice) {
	if (lis == NULL) return;
  	
  	else {
    	if (indice % 2 == 1) {
          	somma += lis -> info;
  			ris -> info = somma;
          	sommatoriaDispari_aux(lis -> next, ris -> next, somma, indice + 1);
  		}
      	else {
        	ris -> info = lis -> info;
          	sommatoriaDispari_aux(lis -> next, ris -> next, somma, indice + 1);
        }
    }
  	
}


void sommatoriaDispari(TipoSCL lis, TipoSCL ris) {
	sommatoriaDispari_aux(lis, ris, 0, 0);
}
