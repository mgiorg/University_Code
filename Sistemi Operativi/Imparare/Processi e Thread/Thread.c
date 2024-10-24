/**
 * CREAZIONE DI THREAD
 * I thread sono entità più leggere rispetto ai processi.
 * Un thread è un flusso di esecuzione indipendente all'interno di un processo,
 * condivisione delle risorse dello spazio di memoria del processo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Sono il thread %ld, il valore passato è %d\n", pthread_self(), *(int*)arg);
    return NULL;
}

int main() {
    pthread_t thread_id;
    int* parametro = (int*) malloc(sizeof(int));
    *parametro = 100;

    pthread_create(&thread_id, NULL, thread_function, (void*) parametro);
    pthread_join(thread_id, NULL); //Aspetta che il thread finisca

    return 0;
}