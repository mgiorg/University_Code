#include "lista/lista.c"

TipoLista init(T* vec, int len);
TipoLista doubledCopy(TipoLista list);
TipoLista multipleSublist(TipoLista list, unsigned int m);
TipoLista subList(TipoLista list, int start, int end);
TipoLista interleave(TipoLista l1, TipoLista l2);
void aggiungi_aux(TipoLista l1, TipoLista l2, int count, TipoLista* lista) ;
void lista_free(TipoLista lista);

int main() {
	T vec[] = {0, 1, 2, 3, 4};
	T vec2[] = {5, 6, 7, 8, 9};
	int n = 5;
	TipoLista lista = init(vec, n);
	TipoLista lista2 = init(vec2, n);
	printlist(lista);
	printlist(lista2);

	TipoLista risultato = interleave(lista, lista2);
	printlist(risultato);

	lista_free(lista);
	lista_free(lista2);
	lista_free(risultato);
	return 0;
}

TipoLista init(T* vec, int len) {
	if(len == 1) {
		return cons(*vec, listaVuota());
	}
	else {
		TipoLista lista = init((vec+1), len-1);
		return cons(*vec, lista);
	}
}

TipoLista doubledCopy(TipoLista list) {
	if(list == listaVuota()) {
		return listaVuota();
	}
	else {
		TipoLista lista = doubledCopy(cdr(list));
		lista = cons(list->info, lista);
		lista = cons(list-> info, lista);
		return lista;
	}
}

TipoLista subList(TipoLista list, int start, int end) {
	if(end == 1) {
		return listaVuota();
	}
	else {
		TipoLista lista =  subList(cdr(list), start - 1, end - 1);

		if(start <= 1)
			lista = cons(list->info, lista);
		return lista;
	}
}

TipoLista interleave(TipoLista l1, TipoLista l2) {
	//Ritorna tutti gli elementi di l1 nelle posizioni pari e quelle
	//di l2 nelle posizioni dispari (hanno la stessa lunghezza)
	TipoLista risultato = listaVuota();
	aggiungi_aux(l1, l2, 1, &risultato);
	return risultato;
}

void aggiungi_aux(TipoLista l1, TipoLista l2, int count, TipoLista* lista) {
	if(l1 == NULL || l2 == NULL) return;
	aggiungi_aux(cdr(l1), cdr(l2), count+1, lista);
	if (count % 2 == 0)
	{
		// Posizione pari
		*lista = cons(l1-> info, *lista);
	}
	else
	{
		// Posizione dispari
		*lista = cons(l2->info, *lista);
	}
}
	


void lista_free(TipoLista lista)
	{
	while (lista != NULL)
	{
		TipoLista nodoDaRimuovere = lista;
		lista = lista->next;
		free(nodoDaRimuovere);
	}
}