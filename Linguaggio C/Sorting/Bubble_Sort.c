/**
 * Bubble_Sort.c
 *
 * Implementazione sorting -> o(n^2)
 */
#include <stdio.h>
 
void swap(int* x1, int* x2);
void bubbleSort(int array[], int size);
void printArray(int array[], int size);

int main()
{
    int arr[] = {7, 4, 68, 3, 25, 78};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Il tuo array ha %d valori!!\n", size);
    bubbleSort(arr, size);

    printf("Il tuo array ordinato:");
    printArray(arr, size);

    return 0;
}

void swap(int* x1, int* x2)
{
    int temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

void bubbleSort(int array[], int size)
{
    for(int i = 0; i < size-1; ++i)
    {
        for(int j = 0; j < size-i-1; ++j)
        {
            //inverto il primo e il secondo elemento se il primo è maggiore del secondo
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void printArray(int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("\n%d", array[i]);
    }
}

