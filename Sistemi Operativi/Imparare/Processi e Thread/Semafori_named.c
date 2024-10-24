/**
 * MECCANISMI DI SINCRONIZZAZIONE: NAMED_SEMAPHORES
 * I semafori named sono simili ai semplici, mapossono essere utilizzati per la sincronizzazione tra processi diversi. 
 * Un named semaphore è identificato da un nome univoco e viene creato con:
 * -> SEM_OPEN = crea o apre un semaforo con un nome specificato;
 * -> SEM_WAIT = riduce il valore del semaforo;
 * -> SEM_POST = incrementa il valore del semaforo;
 * -> SEM_CLOSE = chiude un semaforo aperto;
 * -> SEM_UNLINK = rimuove un semaforo named dal sistema;
 */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

#define CONSUMERS 2
#define PRODUCERS 2

#define EMPTY_NAME "/empty"
#define FULL_NAME "/full"

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t* empty;
sem_t* full;
pthread_mutex_t mutex;

// Funzione per produrre un item
void produce(int item) {
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
}

// Funzione per consumare un item
int consume() {
    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    return item;
}

// Processo produttore
void* producer() {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(empty); // Attendi uno spazio vuoto
        pthread_mutex_lock(&mutex);
        produce(i); // Produci un item
        printf("Prodotto: %d\n", i);
        pthread_mutex_unlock(&mutex);
        sem_post(full); // Incrementa il conteggio degli spazi pieni
        sleep(1); // Simula il tempo di produzione
    }
    return NULL;
}

// Processo consumatore
void* consumer() {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(full); // Attendi uno spazio pieno
        pthread_mutex_lock(&mutex);
        int item = consume(); // Consuma un item
        printf("Consumato: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(empty); // Incrementa il conteggio degli spazi vuoti
        sleep(1); // Simula il tempo di consumo
    }
    return NULL;
}

int main() {
    // Inizializza i semafori named
    empty = sem_open(EMPTY_NAME, O_CREAT, 0644, BUFFER_SIZE); // Semaforo per spazi vuoti
    full = sem_open(FULL_NAME, O_CREAT, 0644, 0); // Semaforo per spazi pieni
    pthread_mutex_init(&mutex, NULL); // Inizializza la mutex per la sezione critica

    pthread_t producer_thread, consumer_thread;

    // Crea i processi per produttore e consumatore
   
    pthread_create(&producer_thread, NULL, producer, NULL);
    
   
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    
    pthread_join(producer_thread, NULL);
    
    
    pthread_join(consumer_thread, NULL);
 

    // Chiudi e rimuovi i semafori named
    sem_close(empty);
    sem_close(full);
    sem_unlink(EMPTY_NAME);
    sem_unlink(FULL_NAME);
    pthread_mutex_destroy(&mutex);

    return 0;
}
