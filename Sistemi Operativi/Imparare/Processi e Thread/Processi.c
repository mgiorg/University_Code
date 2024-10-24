/**
 * CREAZIONE DI PROCESSI CON FORK
 * Il processo è un programma in esecuzione.
 * Esso contiene un contatore di programma, variabili e risorse allocate. 
 * I processi sono entità isolate e indipendenti
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    pid_t pid = fork(); //Creato un processo figlio
    pid = fork();

    if(pid == 0) {
        //Codice eseguito dal processo figlio
        printf("Sono il processo figlio, il codice del processo è %d\n", pid);
    }
    else {
        //Codice eseguito dal processo padre
        printf("Sono il processo padre, il codice del processo è %d\n", pid);
    }

    return 0;
}