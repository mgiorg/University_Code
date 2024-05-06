#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"


TipoAlbero alberoPiuDistanzaNodo_aux(TipoAlbero a, int livello) {
  	TipoAlbero nuovo = creaAlbBin(radice(a), sinistro(a), destro(a));
  	
	if (a == NULL) return albBinVuoto();
  
  	nuovo -> info = a -> info + livello;
  
  	if (sinistro(a) == NULL && destro(a) == NULL) {
    	return nuovo;
    }
  	else {
    	if (sinistro(a) != NULL && destro(a) == NULL) {
        	nuovo -> sinistro = alberoPiuDistanzaNodo_aux(sinistro(a), livello + 1);
          	return nuovo;
        }
      	else if (sinistro(a) == NULL && destro(a) != NULL) {
        	nuovo -> destro = alberoPiuDistanzaNodo_aux(destro(a), livello + 1);
          	return nuovo;
        }
      	else {  	         	
          	nuovo -> destro = alberoPiuDistanzaNodo_aux(destro(a), livello + 1);          	
          	nuovo -> sinistro = alberoPiuDistanzaNodo_aux(sinistro(a), livello + 1);        	
          	return nuovo;
        }
    }
  	
}


TipoAlbero alberoPiuDistanzaNodo(TipoAlbero a) {
	
	return alberoPiuDistanzaNodo_aux(a, 0);
}


