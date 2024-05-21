#include "funzioni.c"

int conta_numeri_pari(TipoLista l, T c)
{
	if (car(cdr(cdr(l))) == c)
		return 1 + conta_numeri_pari(cdr(cdr(l)), c);
	return 0;
	
}
int conta_numeri_dispari(TipoLista l, T c)
{
	if (car(cdr(cdr(l))) == c)
		return 1 + conta_numeri_pari(cdr(cdr(l)), c);
	return 0;
}
int posizioni_alternanza(TipoLista l)
{
	// TODO: Implementazione funzione RICORSIVA
	// l: ['a', 'b', 'a', 'c', 'd']
	// return 3
	T car1 = car(l);
	T car2 = car(cdr(l));

	int pari = conta_numeri_pari(l, car1);
	int dispari = conta_numeri_dispari(cdr(l), car2);

	return pari + dispari;
}

int main() {
	TipoLista l = listaVuota();
	l = cons('f', l);
	l = cons('a', l);
	l = cons('a', l);
	l = cons('b', l);
	l = cons('a', l);

	printlist(l);
	printf("Risultato = %d\n", posizioni_alternanza(l));

	freelist(l);

	return 0;
}