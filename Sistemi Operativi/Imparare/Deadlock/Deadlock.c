/**
 * DEADLOCK: NEL: CODICE:
 * Il deadlock si verifica quando sono presenti contemporaneamente queste condizioni:
 * ? MUTUA ESCLUSIONE (almeno una risorsa è disponibile solo per un processo alla volta)
 * ? PROCESSO E ATTESA (un processo mantiene una risorsa mentre aspetta un'altra)
 * ? NON-PREEMPTION (le risorse non possono essere forzatamente prelevate da un processo)
 * ? ATTESA CIRCOLARE (Esiste una catena circolare di processi, in cui ciascun processo attende una risorsa trattenuta dal prossimo)
 * 
 * ESEMPIO DI UN CODICE CON DEADLOCK
 * !Stiamo usando le mutex, ma il deadlock si può formare anche con i semafori
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t R1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t R2 = PTHREAD_MUTEX_INITIALIZER;

void* process1(void* arg) {
    pthread_mutex_lock(&R1);
    printf("Processo 1 ha bloccato R1\n");
	fflush(stdout);
    
    //sleep(1); //Ritardo per assicurare la condizione di attesa

    pthread_mutex_lock(&R2);
    printf("Processo 1 ha bloccato R2\n");
	fflush(stdout);
    
    pthread_mutex_unlock(&R2);
    pthread_mutex_unlock(&R1);
    return NULL;
}

void* process2(void* arg) {
    pthread_mutex_lock(&R2);
    printf("Processo 2 ha bloccato R2\n");
    fflush(stdout);
    
    //sleep(1); //Ritardo per assicurare la condizione di attesa

    pthread_mutex_lock(&R1);
    printf("Processo 2 ha bloccato R1\n");
	fflush(stdout);
    
    pthread_mutex_unlock(&R1);
    pthread_mutex_unlock(&R2);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, process1, NULL);
    pthread_create(&t2, NULL, process2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

/**
 * * t1 blocca R1, t2 blocca R2
 * * Il deadlock si verifica quando t1 cerca di bloccare R2, che è già bloccata da t2, e viceversa
 * * Devono passare altre operazioni prima che sblocchino le risorse, il che porta al deadlock
 */

