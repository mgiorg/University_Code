#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef float TipoInfoSCL;

struct ElemSCL {
	TipoInfoSCL info;
	struct ElemSCL* next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL* TipoSCL;

int scl_len(TipoSCL scl) {
	//Calcola la lunghezza della SCL
	TipoSCL temp = scl;
	int c = 0;
	while(temp-> next != NULL) {
		temp = temp-> next;
		c++;
	}
	return c;
}

float scl_sum(TipoSCL scl) {
	//Somma delle info della SCL
	TipoSCL temp = scl;
	float somma = 0;
	while (temp->next != NULL)
	{
		somma+= temp-> info;
		temp = temp->next;
		
	}
	return somma;
}

float scl_media(TipoSCL scl) {
	//Media delle info della SCL
	TipoSCL temp = scl;
	int c = 0;
	float somma = 0;
	while (temp->next != NULL)
	{
		somma += temp->info;
		temp = temp->next;
		c++;
	}
	return (float)somma/c;
}

void scl_duplicate(TipoSCL scl, int pos) {
	//Duplica l'elemento nella posizione "pos" aggiungendo
	//un nuovo nodo dopo l'elemento in questione

	TipoSCL temp = scl;
	for(int i = 0; i < pos-1; ++i) {
		temp = temp-> next;
	}
	TipoNodoSCL* nodo_temporaneo = (TipoNodoSCL*)malloc(sizeof(TipoNodoSCL));
	nodo_temporaneo-> next = temp-> next;
	temp-> next = nodo_temporaneo;
	nodo_temporaneo-> info = temp-> info;
}

void scl_append(TipoSCL scl, TipoSCL nodo) {
	if(scl == NULL) {
		scl = nodo;
		scl-> next = NULL;
	}
	else {
		TipoSCL temp = scl;
		while(temp-> next != NULL) {
			temp = temp-> next;
		}
		temp-> next = nodo;
		temp = temp-> next;
		temp->next = NULL;
	}
}

// void scl_positives(TipoSCL scl, TipoSCL ris) {
// 	TipoSCL temp = scl;
// 	while(temp-> next != NULL) {
// 		if(temp-> info > 0) {
// 			scl_append(ris, temp);
// 		}
// 	}
// }






//-----------------FREE SCL-------------------

void scl_free(TipoSCL scl) {
	if(scl-> next == NULL) {
		return;
	}
	else {
		printf("Chiamata ricorsiva\n");
		scl_free(scl->next);
		printf("Libero elemento precedente\n");
		free(scl);
	}
	
}

void scl_print(TipoSCL scl)
{
	// Print
	TipoSCL temp = scl;
	printf("[ ");
	while (temp->next != NULL)
	{
		printf("%.2f ", temp-> info);
		temp = temp->next;
	}
	printf("]\n\n");
}