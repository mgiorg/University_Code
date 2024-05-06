#include "aux.h"

TipoLista append (TipoLista l, T e) {
	if (l == NULL) return cons (e, l);
  	return cons (car(l), append(cdr(l), e));
}

int length (TipoLista l) {
	if (l == NULL) return 0;
  	return 1 + length(cdr(l));
}

TipoLista ruota_aux(TipoLista l) {
	if (l == NULL) return listaVuota();
  	else {
    	return cons(car(l), ruota_aux(cdr(l)));
    }
}


TipoLista ruota(TipoLista l) {
	TipoLista nuova = (TipoLista) malloc (length(l) * sizeof(int));
  	nuova = ruota_aux(l);
  	if (nuova == NULL) return listaVuota();
  	else {
    	return append(cdr(nuova), car(l));
    } 
}

TipoLista comb_aux (TipoLista lista) {
	if (lista == NULL) return listaVuota();
  	else {
    	return cons(car(lista), comb_aux(cdr(lista)));
    }
}

TipoLista combinazione(TipoLista lucchetto, int password) {
  	TipoLista lista = (TipoLista) malloc (length(lucchetto) * sizeof(int));
  	lista = lucchetto;
  
	while (car(lucchetto) != password && lucchetto != NULL) {
      	lucchetto = cdr(lucchetto);
    	lista = ruota(lista);
    }
   	return comb_aux(lista);
}
