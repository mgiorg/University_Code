#include "mat_sparsa_lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct elem {
	int i; //indice della riga
	int j; //indice della colonna
	int x; //valore dell'elemento

	struct elem *next;
} elem;

struct matrice_sparsa {
	int m; //numero righe
	int n; //numero colonne

	elem *head;
};

matrice_sparsa* matrice_sparsa_new(int m, int n) {
	// TODO: Implement here
	matrice_sparsa *mat;
	mat -> m = m;
	mat -> n = n;
	
	struct elem e;
	mat->head=&e;

	struct elem temp=*mat->head;

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			e.j = j;
			e.i = i;
			e.x = 0;

			mat-> head = &e.next;
		}
	}
	return NULL;
}

void matrice_sparsa_delete(matrice_sparsa* mat) {
	// TODO: Implement here
}

int get_num_row(matrice_sparsa* mat) {
	// TODO: Implement here
	return 0;
}

int get_num_col(matrice_sparsa* mat) {
	// TODO: Implement here
	return 0;
}

void mat_set(matrice_sparsa* mat, int i, int j, int x) {
	// TODO: Implement here
}

int mat_get(matrice_sparsa* mat, int i, int j) {
	// TODO: Implement here
	return 0;
}

void mat_print(matrice_sparsa* mat) {
	// TODO: Implement here
}
