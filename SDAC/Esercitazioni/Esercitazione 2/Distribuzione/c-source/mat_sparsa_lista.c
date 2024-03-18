#include "mat_sparsa_lista.h"
#include <stdlib.h>
#include <stdio.h>

struct elem {
	int i; //indice della riga
	int j; //indice della colonna
	int x; //valore dell'elemento

	struct elem *next;
};

typedef struct matrice_sparsa {
	int m; //numero righe
	int n; //numero colonne

	struct elem *head;
}matrice_sparsa;

matrice_sparsa* matrice_sparsa_new(int m, int n) {
	// TODO: Implement here
	matrice_sparsa *mat;
	mat -> m = m;
	mat -> n = n;
	
	mat-> head = (struct elem*)malloc(sizeof(struct elem));
	struct elem* temp = mat-> head;
	int contatore = 0;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			contatore++;
			temp-> i = i;
			temp-> j = j;
			temp-> x = i+j;
			temp-> next = (struct elem*)malloc(sizeof(struct elem));
			temp = temp-> next;
		}
	}
	return mat;
}

void matrice_sparsa_delete(matrice_sparsa* mat) {
	// TODO: Implement here
	struct elem* temp = mat-> head;
	for(int i = 0; i < mat-> m; ++i) {
		for(int j = 0; j < mat-> n; ++j) {
			struct elem* p = temp;
			temp = temp-> next;
			free(p);
		}

	}
}

int get_num_row(matrice_sparsa* mat) {
	// TODO: Implement here
	return mat-> m;
}

int get_num_col(matrice_sparsa* mat) {
	// TODO: Implement here
	return mat->n;
}

void mat_set(matrice_sparsa* mat, int i, int j, int x) {
	// TODO: Implement here
	struct elem* temp = mat-> head;
	for(int riga = 0; riga < mat->m; riga++) {
		for(int colonna = 0; colonna < mat-> n; colonna++) {
			if(temp-> i == i && temp-> j == j) {
				temp-> x = x;
				return;
			}
			else {
				temp = temp-> next;
			}
		}
	}
}

int mat_get(matrice_sparsa* mat, int i, int j) {
	// TODO: Implement here
	struct elem *temp = mat->head;
	for (int riga = 0; riga <= mat->m; ++riga)
	{
		for (int colonna = 0; colonna <= mat->n; ++colonna)
		{
			if (temp->i == i && temp->j == j)
				return temp-> x;
			else{
				temp = temp->next;
			}
		}
	}
	//ERRORE
	return -1;
}

void mat_print(matrice_sparsa* mat) {
	// TODO: Implement here
	struct elem* temp = mat-> head;
	for(int i = 0; i < mat->m; ++i) {
		for(int j = 0; j < mat->n; ++j) {
			printf("%d ", temp-> x);
			temp = temp-> next;
		}
		printf("\n");
	}
	printf("\n");
}
