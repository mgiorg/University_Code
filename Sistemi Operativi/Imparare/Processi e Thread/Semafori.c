/**
 * MECCANISMI DI SINCRONIZZAZIONE: SEMAFORI
 * Un semafoto semplice è una variabile intera che viene utilizzata per contare il numero di risorse disponibili.
 * Può essere inizializzato ad un valore positivo che rappresenta il numero di risorse disponibili.
 * Le operazioni fondamentali sono WAIT e SIGNAL
 * -> WAIT: Decrementa il valore del semaforto. se il valore è già 0, il thread che chiama questa funzione
 *			viene messo in pausa fino a che il valore non diventa maggiore di zero.
 * -> SIGNAL: Incrementa il valore del semaforo.
 *			  Se ci sono thread in attesa, uno di essi viene sbloccato(FIFO)
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 5

sem_t sem;
int contatore = 0;
int count[NUM_THREADS] = {0};

void* thread_function(void* arg) {
	int thread_id = *(int*) arg;

	printf("Thread %d in attesa di accesso alla risorsa...\n", thread_id);
	sem_wait(&sem);

	printf("Thread %d ha ottenuto accesso alla risorsa.\n", thread_id);
	contatore++;

	printf("Thread %d sta rilasciando la risorsa. \n", thread_id);
	sem_post(&sem);

	return NULL;
}

void* thread_function_no_sem(void* arg) {
	int thread_id = *(int*) arg;
	count[thread_id]++;
    return NULL;
}

int main() {
	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];
	sem_init(&sem, 0, 1);

	for(int i = 0; i < NUM_THREADS; ++i) {
		thread_ids[i] = i;
		pthread_create(&threads[i], NULL, thread_function_no_sem, &thread_ids[i]);
	}

	for(int i = 0; i < NUM_THREADS; ++i) {
		pthread_join(threads[i], NULL);
		contatore += count[i];
	}

	sem_destroy(&sem);
	printf("Il contatore alla fine di tutto vale %d\n", contatore);
	return 0;
}