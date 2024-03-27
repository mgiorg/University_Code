#include <stdio.h>
#include "Funzioni.c"

int main() {
	int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int* p = vec_clone(v, 10);
	printArray(p, 10);
	return 0;
}