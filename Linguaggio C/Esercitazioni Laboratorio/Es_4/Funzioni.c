#include <stdio.h>
#include <stdlib.h>
void printArray(int v[], int dim) {
	for(int i = 0; i < dim; i++) printf("%d ", v[i]);
	printf("\n");
}

// Funzione array random
void random_array(int v[], int dim, int max_value) {
	for(int i = 0; i < dim; i++) {
		v[i] = rand() % (max_value);
	}
}

//vec_clone
int* vec_clone(const int v[], int dim) {
	int* p = (int*)malloc(dim * sizeof(int));
	for(int i = 0; i < dim; i++) {
		*(p+i) = v[i];
	}
	return p;
}