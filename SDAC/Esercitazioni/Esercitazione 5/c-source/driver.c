/**
 * driver.c
 * Traduzione da Java a C
*/
#include <stdio.h>
#include <stdlib.h>
#include "algoritmi.c"

void stampaArray_float(float a[], int length)
{
	printf("[");
	for (int i = 0; i < length - 1; i++)
	{
		printf("%.2f, ", a[i]);
	}
	printf("%.2f]\n", a[length - 1]);
}

void stampaArray_char(char a[], int length)
{
	printf("[");
	for (int i = 0; i < length - 1; i++)
	{
		printf("%c, ", a[i]);
	}
	printf("%c]\n", a[length - 1]);
}

void stampaMatrice(int m[][4], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	float a1[] = {1, -2, 3, -1, -4, -3};
	float a2[] = {0, -2, 3, 1, -4, -3};
	char b1[] = {'r', 'v', 'r', 'v', 'b', 'v', 'r'};
	int m[][4] = {{1, 2, 3, 4}, {2, 1, 4, 3}, {4, 3, 2, 1}, {3, 4, 1, 2}};
	float a3[] = {0, 2, 3, 1, -4, -3, -125};

	printf("TEST 1: il vettore di input è:\n");
	stampaArray_float(a1, 6);
	permuta_negativi_positivi(a1, 6);
	printf("TEST 1: il vettore di output generato dalla tua soluzione è:\n");
	stampaArray_float(a1, 6);

	printf("TEST 2: il vettore di input è:\n");
	stampaArray_float(a2, 6);
	permuta_negativi_positivi(a2, 6);
	printf("TEST 2: il vettore di output generato dalla tua soluzione è:\n");
	stampaArray_float(a2, 6);

	printf("\n");

	printf("TEST 3: il vettore di input è:\n");
	stampaArray_char(b1, 7);
	bandiera(b1, 7);
	printf("TEST 3: il vettore di output generato dalla tua soluzione è:\n");
	stampaArray_char(b1, 7);

	printf("\n");

	printf("TEST 4: la matrice di input è:\n");
	stampaMatrice(m, 4, 4);
	int res = isQuadratoLatino(m, 4, 4);
	printf("TEST 4: l'output generato dalla tua soluzione è: %d\n", res);

	printf("\n");

	printf("TEST 5: il vettore di input è:\n");
	stampaArray_float(a3, 7);
	primiKMin(a3, 7, 6);
	printf("TEST 5: la soluzione del Docente è: ");

	return 0;
}
