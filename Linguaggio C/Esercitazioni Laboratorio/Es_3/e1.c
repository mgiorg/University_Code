#include <stdio.h>
#include <stdlib.h>

int main() {
	int* numero = (int* )malloc(sizeof(int));
	int* prev = (int* )malloc(sizeof(int));
	int* minimo = (int* )malloc(sizeof(int));
	*minimo = 100000;
	*prev = 0;

	printf("Inserire numero intero positivo: ");
	scanf("%d", numero);

	while(*numero != 0) {
		if(*prev != 0) {
			if(*numero < *prev) {
				if(*numero < *minimo) *minimo = *numero;
			}
		}
		*prev = *numero;
		printf("Inserire numero intero positivo: ");
		scanf("%d", numero);
	}
	printf("Il numero minimo è: %d", *minimo);
}