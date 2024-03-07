/**
 * Aritmetica dei puntatori
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM 5

int main() {

	int f[NUM] = {0};
	int* g = f;
	for(int i = 0; i < NUM; i++){
		*(g+i) = i;
		printf("%d\n", *(g+i));
		
	}

	return 0;
}