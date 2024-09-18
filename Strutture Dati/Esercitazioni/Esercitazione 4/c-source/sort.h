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

//------------------------MERGE SORT------------------------------
void merge(int arr[], int left, int mid, int right); 
void mergeSort_aus(int arr[], int left, int right);
void mergeSort(array *);

//---------------------------HEAP SORT------------------------------
void maxHeap(int arr[], int n, int i);
void heapSort(array*);

//---------------------INSERTION SORT-------------------------------
void insertionSortRicorsivo(int arr[], int n);
void insertionSort(array*);

//------------------------SELECTION SORT------------------------------
void selectionSortRecursive(int arr[], int n, int index);
void selectionSort(array*);

//--------------------------QUICK SORT------------------------------
int partition(int arr[], int low, int high);
void quickSortRecursive(int arr[], int low, int high);
void quickSort(array*);

void radixSort(array*);
void bucketSort(array*);
void bubbleSort(array*);
void purposelyWrongBubbleSort(array*);

#endif	/* SORT_H */

