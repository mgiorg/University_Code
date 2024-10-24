/**
 * MECCAMISMI DI SINCRONIZZAZIONE: MUTEX
 * Un mutex è un meccanismo per garantire che solo un thread alla volta
 * possa accedere ad una risorsa condivisa
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    int value = *(int*) arg;
    printf("Il valore dell'arg vale: %d\n", value);
    for(int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&lock);
        printf("Sto sommando alla variabile counter il valore: %d\n", value);
        counter+= value;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int args[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < NUM_THREADS; i++) {
        args[i] = i;
        pthread_create(&threads[i], NULL, increment, &args[i]);
    }

    for(int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("VALORE DEL COUNTER: %d\n", counter);
    pthread_mutex_destroy(&lock);

    return 0;
}