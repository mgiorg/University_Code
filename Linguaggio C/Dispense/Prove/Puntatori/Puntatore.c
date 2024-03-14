/**
 * Aritmetica dei puntatori
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM 5


//Funzione che cerca un elemento in un array di interi usando un puntatore
int cercaArray(int* p, int n, int e); 
void stampaArray(int* p, int n);
void rovesciaArray(int* p, int n);

//Scambia due interi esterni alla funzione
void scambia(int* a, int* b);

int* ritornaArray(int n);


int main() {
	/**
	 * ARRAY DI PUNTATORI
	*/
	int** p = malloc(NUM*sizeof(int*));
	for(int i = 0; i < NUM; ++i){
		p[i] = malloc(NUM*sizeof(int));
		for(int j = 0; j < NUM; ++j){
			p[i][j] = i;
		}
	}

	for(int i = 0; i < NUM; ++i){
		for(int j = 0; j < NUM; ++j){
			printf("%d", *p[i]);
			p[i]++;
		}
		printf("\n");
	}
	free(p);
	
	return 0;
}



/**
 * Corpo delle funzioni
*/
int cercaArray(int* p, int n, int e){
	for(int i = 0; i < n; ++i){
		if(*p == e) return 1;
		p++;
	}
	return 0;
}

void stampaArray(int* p, int n){
	for(int i = 0; i < n; ++i){
		printf("%d ", *p);
		p++;
	}
	printf("\n");
}

void rovesciaArray(int* p, int n){
	for(int i = 0; i < n/2; ++i){
		scambia(&p[i], &p[n-i-1]);
	}
}

void scambia(int* a, int* b){
	int temp = *a;

	*a = *b;
	*b = temp;
}

int* ritornaArray(int n){
	int* array = (int*)malloc(n * sizeof(int));

	for(int i = 0; i < n; ++i){
		*array = 0;
		array++;
	}
	return array;
}