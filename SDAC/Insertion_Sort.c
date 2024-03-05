/**
 * Insertion_sort.c 
 * Ricorsivo
*/

#include <stdio.h>

static void infila(int i, int ultimo);
int ordina(int primo, int n);
static void printArray(int primo, int ultimo);

/* static int A[] = {8, 5, 3, 2, 9, 0, 7, 1, 4, 6}; */
static int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

static void infila(int i, int ultimo) {
    //infila A[i] nella parte ordinata, che comincia da A[i+1] e termina in A[ultimo] 
    int h = i+1;
    int k = A[i];
    while((A[h] < k) && (h <= ultimo)) {
        A[h-1] = A[h];
        h++;
    }
    A[h-1] = k;
    return;
}
/* esercizio assegnato: realizzare infila ricorsivamente */


int ordina(int primo, int ultimo) {
    //infila elemento A[primo] nella parte ordinata che va da A[primo+1] a A[ultimo]
    if(ultimo > primo) {
        infila(primo, ordina(primo+1, ultimo)); //Studia ricorsione qui
    }
    return ultimo;
}

static void printArray(int primo, int ultimo) {
    for(int i = primo; i <= ultimo; i++)
        printf("A[%d] = %d\t", i, A[i]);
        printf("\n");
    return;
}

int main() {
    int n = sizeof(A)/sizeof(A[0]);
    printArray(0, n-1);
    ordina(0, n-1);
    printArray(0, n-1);
    return 0; /* standard in C */
} 