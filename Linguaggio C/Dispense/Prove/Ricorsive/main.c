// FILE: 
// ARGS:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cercaMatrice.c"


//----------------------------------------------------------------MAIN

int main() {
	/*int array[] = {0, 1, 2, 3, 4, 5, 6, 7};
	
	stampa_stringa("Ciao mamma sono appena tornato a casa");
	stampa_array(array, sizeof(array)/sizeof(array[0]));*/

	/*int n;
	int c = 0;
	printf("Impostare quanti dischi vuoi spostare: ");
	scanf("%d", &n);

	printf("Movimento di %d dischi tra paletti 1, 2, e 3\n", n);
	muovi(n, 1, 2, 3, &c);

	printf("Il programma ha eseguito %d iterazioni\n", c);*/
	int** m = (int**)malloc(R*sizeof(int*));
	for(int i = 0; i < C; ++i) {
		m[i] = (int*)malloc(C*sizeof(int));
	}
	initPalude(m, prob_terra);
	stampaPalude(m);	

	return 0;
}
