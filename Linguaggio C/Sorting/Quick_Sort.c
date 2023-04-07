/**
 * Quick_Sort.c
 */
#include <stdio.h>

void swap(int* a, int*b);
int part(int arr[], int low, int high); //funzione di partizione del vettore
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);

int main()
{
	int array[] = {5, 4, 8, 5, 89, 4, 2, 7, 48, 1};
	int size = sizeof(array)/sizeof(array[0]);
	printf("L'array assegnato è:\n");
	printArray(array, size);

	quickSort(array, 0, size-1);

	printf("\nL'array ordinato è:\n");
	printArray(array, size);

	return 0;
}

void swap(int* a, int* b)
{
	//inversione di valori
	int temp = *a;
	*a = *b; 
	*b = temp;
}

int part(int arr[], int low, int high)
{
	//uso l'ultimo elemento dell'array come PIVOT
	int PIVOT = arr[high];
	int i = low-1;

	for(int j = low; j < high; ++j)
	{
		if(arr[j] < PIVOT)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

void quickSort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pi = part(arr, low, high); //partizione dell'array

		quickSort(arr, low, pi - 1); //partizioni di 'sinistra'
		quickSort(arr, pi + 1, high); //partizioni di 'destra'
	}
}

void printArray(int arr[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}