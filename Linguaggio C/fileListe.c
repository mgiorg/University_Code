#include <stdio.h>
#include "funzioni.c"

void cercaMaxRipetizione(TipoLista l, int info, int* maxInfo, int rep, int* maxRep) {
	if(estVuota(l)) return;
	if(car(l) == info) {
		rep++;
		if(rep >= *maxRep) {
			*maxRep = rep;
			if(info > *maxInfo) {
				*maxInfo = info;
			}
		}
		if(!estVuota(cdr(l))) cercaMaxRipetizione(cdr(l), info, maxInfo, rep, maxRep);
	} else {

		if(!estVuota(cdr(l))) cercaMaxRipetizione(cdr(l), car(cdr(l)), maxInfo, 0, maxRep);
	}
}
TipoLista aux(int info, int i) {
	if(i == 0) return NULL;
	return cons((char)info, aux(info, i-1));
}

TipoLista ritornaUguali(TipoLista l) {
	if(estVuota(l)) return NULL;
	int maxRep = 0;
	int maxInfo = 0;
	cercaMaxRipetizione(l, car(l), &maxInfo, 0, &maxRep);
	return aux(maxInfo, maxRep);
}
TipoLista finale(TipoLista* liste, int n) {
	int maxLength = 0;
	int maxInfo = 0;
	for(int i = 0; i < n; ++i) {
		TipoLista l = ritornaUguali(liste[i]);
		printlistcar(l);
		if(length(l) >= maxLength && length(l) > 0) {
			maxLength = length(l);
			if(length(l) == maxLength && car(l) > maxInfo) maxInfo = car(l);
		}
	}
	return aux(maxInfo, maxLength);
}

int main() {
	int n = 4;
	TipoLista* liste = (TipoLista*)malloc(n*sizeof(TipoLista));

	liste[0] = cons((int)'a', cons((int)'b', cons((int)'c', cons((int)'c', cons((int)'x', cons((int)'d', cons((int)'c', NULL)))))));
	liste[1] = NULL;
	liste[2] = cons((int)'f', cons((int)'f', cons((int)'s', cons((int)'s', cons((int)'s', cons((int)'r', cons((int)'s', NULL)))))));
	liste[3] = cons((int)'g', cons((int)'a', cons((int)'c', cons((int)'l', cons((int)'k', cons((int)'l', cons((int)'r', NULL)))))));
	
	printlistcar(finale(liste, n));

	for(int i = 0; i < n; ++i) {
		freelist(liste[i]);
	}

	return 0;
}