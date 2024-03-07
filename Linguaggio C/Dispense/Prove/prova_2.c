/**
 * Aritmetica dei puntatori
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	/*int i = 5;
	printf("Valore di i: %d, indirizzo di i: %p\n", i, &i);*/


	/*int i = 10;
	int* p = &i;
	*p = 100; //modifica la variabile i
	printf("%d", i);
	print("%d", *p); */

	int*p;
	p = 0x122605df0;
	*p = 100; //modifica la variabile
	return 0;
}