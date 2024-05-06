#include "aux.h"


TipoAlbero figlio_lontano(TipoAlbero a) {
  	int somma_max;
	if (a == NULL) return NULL;
  	if (sinistro(a) == NULL && destro(a) == NULL) {
      	int somma = radice(a);
    	return creaAlbBin(radice(a), NULL, NULL);
    }
    else if (sinistro(a) != NULL && destro(a) == NULL) {
    	int somma = radice(a) + radice(figlio_lontano(sinistro(a)));
      	return creaAlbBin(somma, figlio_lontano(sinistro(a)), NULL);
    } 
  	else if (sinistro(a) == NULL && destro(a) != NULL) {
    	int somma = radice(a) + radice(figlio_lontano(destro(a)));
      	return creaAlbBin(somma, NULL, figlio_lontano(destro(a)));
    }
  	else {
      	if (radice(figlio_lontano(sinistro(a))) >= radice(figlio_lontano(destro(a))) ) {
        	somma_max = radice(figlio_lontano(sinistro(a)));
        }
      	else {
        	somma_max = radice(figlio_lontano(destro(a)));
        }

    	int somma = radice(a) + somma_max;
      	return creaAlbBin(somma, figlio_lontano(sinistro(a)), figlio_lontano(destro(a)));
    }
}

