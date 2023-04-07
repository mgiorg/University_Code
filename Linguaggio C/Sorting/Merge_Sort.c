/**
 * Merge_Sort.c
 *
 *  -> Fase di Partizione dell'array
 *  -> Fase di Sorting delle partizioni
 *  -> Merge delle partizioni ordinate
 */
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int size);

int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("L'array assegnato è: \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nL'array ordinato è il seguente: \n"); 
	printArray(arr, arr_size);

	return 0;
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;

	int n1 = m-l+1; //Quanti elementi nell'array-SINISTRA
	int n2 = r-m; //Quanti in quello DESTRA

	int L[n1], R[n2]; //creazione array temporanei

	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}

	//Indici dei subarray
	i = 0; 
	j = 0; 
	k = l; 

	/**
	 * Scrittura della funzione di confronto e inserimento di valori nell'array
	 */
	while(i < n1 && j < n2)
	{
		if(L[i] < R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		++k;
	}

	/**
	 * Copia dei rimanenti valori dell'array 
	 */
	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		arr[k] = R[j];
		j++;
		k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) 
	{
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}