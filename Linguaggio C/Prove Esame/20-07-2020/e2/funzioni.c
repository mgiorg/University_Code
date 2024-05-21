#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char T;
struct NodoSCL
{
	T info;
	struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;

TipoLista listaVuota() { return NULL; }

bool estVuota(TipoLista l) { return (l == NULL); }

TipoLista cons(T e, TipoLista l)
{
	TipoLista nuovo = (TipoLista)malloc(sizeof(TipoNodo));
	nuovo->info = e;
	nuovo->next = l;
	return nuovo;
}

T car(TipoLista l)
{
	if (l == NULL)
	{
		printf(" ERRORE : lista vuota \n ");
		exit(1);
	}
	return l->info;
}

TipoLista cdr(TipoLista l)
{
	if (l == NULL)
	{
		printf(" ERRORE : lista vuota \n ");
		exit(1);
	}
	return l->next;
}

void printlist_aux(TipoLista l)
{
	if (estVuota(l))
		return;
	printf("%c, ", car(l));
	printlist_aux(cdr(l));
}

void printlist(TipoLista l)
{
	if (estVuota(l))
		printf("()");
	else
		printlist_aux(l);
	printf("\n");
}

void freelist(TipoLista l)
{
	if (l == NULL)
		return;
	freelist(l->next);
	free(l);
}
