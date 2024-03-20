#include <stdio.h>

#include "sort.h"

//------------------------MERGE SORT------------------------------
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;        int n1 = mid-left+1;    int n2 = right-mid;

    int L[n1], R[n2];       //Creazione di array temporanei
    for(i = 0; i < n1; ++i) //Assegnazione dei valori da sinistra
        L[i] = arr[left+i];
    for(j = 0; j < n2; ++j) //Assegnazione dei valori dal centro a destra
        R[j] = arr[mid+1+j];

    i = 0; j = 0; 
    k = left;
    while(i < n1 && j < n2) { //inserisco tutti i 
         if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia gli elementi rimanenti di L[], se ce ne sono
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia gli elementi rimanenti di R[], se ce ne sono
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_aus(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort_aus(arr, left, mid);
        mergeSort_aus(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(array* a) {
    mergeSort_aus(a-> arr, 0, (a-> size)-1);
    return;
}

//---------------------------HEAP SORT------------------------------
void maxHeap(int arr[], int n, int i) {
    int largest = i;    int left = 2*i +1;      int right = 2*i + 2;

    // Se il figlio sinistro è più grande della radice
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Se il figlio destro è più grande della radice più grande finora
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // Se il più grande non è la radice
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Ricorsivamente esegue il maxHeap sul sottoalbero interessato
        maxHeap(arr, n, largest);
    }
}

void heapSort(array *a) {
    int n = a-> size;
    int* arr = a-> arr;
    
    // Costruisci un heap max
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);

    // Estrai elementi uno per uno dall'heap
    for (int i = n - 1; i > 0; i--) {
        // Sposta la radice (l'elemento più grande) alla fine
        swap(&arr[0], &arr[i]);
        // Chiamata ricorsiva maxHeapify sul ridotto heap
        maxHeap(arr, i, 0);
    }
    return;
}

//---------------------INSERTION SORT-------------------------------

void insertionSort(array *a) {
    fprintf(stdout, "insertionSort currently not implemented.\n");
    return;
}

void selectionSort(array *a) {
    fprintf(stdout, "selectionSort currently not implemented.\n");
    return;
}

void quickSort(array *a) {
    fprintf(stdout, "quickSort currently not implemented.\n");
    return;
}

void radixSort(array *a) {
    fprintf(stdout, "radixSort currently not implemented.\n");
    return;
}

void bucketSort(array *a) {
    fprintf(stdout, "bucketSort currently not implemented.\n");
    return;
}

