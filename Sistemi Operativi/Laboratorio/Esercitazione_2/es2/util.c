#include "util.h"      // Include le dichiarazioni delle funzioni e le macro

#include <signal.h>    // Include per la gestione dei segnali
#include <stdlib.h>    // Include per le funzioni di allocazione della memoria
#include <stdio.h>     // Include per printf e perror
#include <string.h>    // Include per memset
#include <unistd.h>    // Include per le funzioni POSIX di I/O

void (*cleanupFunction)();  // Puntatore a funzione per la pulizia

// Gestore per il segnale SIGINT
static void sigint_handler(int sig_no) {
    cleanupFunction();  // Chiama la funzione di pulizia
    exit(0);           // Esce dal programma
}

// Funzione per impostare il gestore di segnale
void setQuitHandler(void(*f)()) {
    cleanupFunction = f;  // Assegna la funzione di pulizia

    struct sigaction action; // Struttura per gestire il segnale
    memset(&action, 0, sizeof(action)); // Inizializza la struttura a zero
    action.sa_handler = &sigint_handler; // Imposta il gestore del segnale
    sigaction(SIGINT, &action, NULL); // Registra il gestore per SIGINT
}
