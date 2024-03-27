#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Funzioni.c"

int main() {
	double *risultato = soluzioneEquazionePtr(1, 1, 1);
	printf("Risultato x1: %lf\nRisultato x2: %lf\n", *risultato, *(risultato+1)); 
	return 0;
}