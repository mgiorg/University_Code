/**
 * MAXSEQ.c
 */
/**
 * 	Scrivere un programma che dato un numero
	N>0 di valori da inserire da tastiera, stampi a
	video il massimo della sequenza inserita e la
	posizione in cui tale valore è stato inserito.
 */
#include <stdio.h>

int main()
{
	int N[5];
	int max;
	int pos;

	for(int i = 0; i < 5; ++i)
	{
		printf("Inserire numero: ");
		scanf("%d", &N[i]);
	}

	for(int i = 0; i < 5; ++i)
	{
		if(i == 0)
		{
			max = N[i];
			pos = i+1;
		}

		if(N[i] > max) 
		{
			max = N[i];
			pos = i+1;
		}
	}

	printf("La sequenza impostata è: ");
	for(int i = 0; i < 5; ++i)
	{
		printf("%d, ", N[i]);
	}
	printf("Il valore massimo è: %d; \nLa sua posizione è la numero: %d.", max, pos);

	return 0;
}