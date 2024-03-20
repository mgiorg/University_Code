#ifndef SORT_H
#define	SORT_H

typedef struct {
    int *arr;
    int size;
} array;

void swap(int *, int *);
void sortAlgCaller(void (*sort_alg)(array*), array *a);
int nextInt(int max);

/* sorting algs - aggiungerne nuovi se utile*/

void merge(int arr[], int left, int right); 
void mergeSort_aus(int arr[], int left, int right);
void mergeSort(array *);

void maxHeap(int arr[], int n, int i);
void heapSort(array*);
void insertionSort(array*);
void selectionSort(array*);
void quickSort(array*);
void radixSort(array*);
void bucketSort(array*);
void bubbleSort(array*);
void purposelyWrongBubbleSort(array*);

#endif	/* SORT_H */

