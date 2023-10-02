#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_indice(int a[], int n)
{
	int mx = a[0];
	int s;

	for(int i = 1; i < n; ++i)
	{
		if(a[i] > mx)
		{
			mx = a[i];
			s = i;
		}
	}
	return s;
}

int* max_pointer(int a[], int n)
{
	int* mx = a;

	for(int i = 1; i < n; ++i)
	{
		if(a[i] > *mx)
		{
			mx = &a[i];
		}
	}
	return mx;
}
int main()
{
	int a[10] = {9, 2, 3, 4, 5, 6, 7, 8, 0, 0};

	int indice = max_indice(a, 10);
	int* puntatore = max_pointer(a, 10);

	printf("L'indice dell'elemento massimo è %d\n\n", indice);
	printf("Il puntatore all'elemento massimo ha indirizzo %p e valore %d\n", puntatore, *puntatore);
	printf("%p", &a[8] - 32);
	
	return 0;
}
