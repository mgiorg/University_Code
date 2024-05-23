#include "funzioni.c"
#include <string.h>

int conta_numeri(TipoLista l, T c)
{
	if(estVuota(cdr(l)) || estVuota(cdr(cdr(l)))) {
		if(car(l) == c) return 1;
		else return 0;
	}
	
	else {
		if(car(l) == c) return 1 + conta_numeri(cdr(cdr(l)), c);
		else return 0;
	}
}

int posizioni_alternanza(TipoLista l)
{
	// TODO: Implementazione funzione RICORSIVA
	// l: ['a', 'b', 'a', 'c', 'd']
	// return 3
	if(estVuota(l)) return 0;
	if(estVuota(cdr(l))) return 1;

	T car1 = car(l);
  	printf("Carattere 1: %c\n", car1);
	T car2 = car(cdr(l));
  	printf("Carattere 2: %c\n", car2);

	
	int pari = conta_numeri(l, car1);
	int dispari = conta_numeri(cdr(l), car2);
	
	return pari + dispari;
}

int main() {
	//TipoLista l = listaVuota();
	// l = cons('a', l);
	// l = cons('g', l);
	// l = cons('a', l);
	// l = cons('a', l);
	// l = cons('a', l);

	//printlist(l);
	//printf("Risultato = %d\n", posizioni_alternanza(l));
	char* stringa = "";
	
	printf("%s\n", stringa);


	return 0;
}