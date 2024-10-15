#include "common.h"

#include <fcntl.h>  // O_CREAT and O_EXCL flags
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

sem_t *sem_filled, *sem_empty, *sem_cs;

void initSemaphores() {
    // delete stale semaphores from a previous crash (if any)
    sem_unlink(SEMNAME_FILLED);
    sem_unlink(SEMNAME_EMPTY);
    sem_unlink(SEMNAME_CS);

    /* We create three named semaphores:
    * - sem_filled to check that our buffer is not empty
    *   (we need to initialize it to 0)
    * - sem_empty to check that our buffer is not full
    *   (we need to initialize it to the buffer's capacity BUFFER_SIZE)
    * - sem_cs to enforce mutual exclusion when accessing the file
    */

    /* TODO: create the semaphores as described above */

    sem_filled = sem_open(SEMNAME_FILLED, O_CREAT | O_EXCL, 0600, 0);
    if (sem_filled == SEM_FAILED) handle_error("sem_open filled");

    sem_empty = sem_open(SEMNAME_EMPTY, O_CREAT | O_EXCL, 0600, BUFFER_SIZE);
    if (sem_empty == SEM_FAILED) handle_error("sem_open empty");

    sem_cs = sem_open(SEMNAME_CS, O_CREAT | O_EXCL, 0600, 1);
    if (sem_cs == SEM_FAILED) handle_error("sem_open cs");
}

void closeSemaphores() {
    /* When the program that controls the producer(s) terminates, we
     * need to close all the the semaphores we previously opened */
    sem_close(sem_filled);
    sem_close(sem_empty);
    sem_close(sem_cs);

    /* TODO: implement the operations described above, and handle
     * possible errors using the predefined handle_error() macro */
    if(sem_filled == SEM_FAILED) 
        handle_error("sem_close filled");
    if(sem_empty == SEM_FAILED) 
        handle_error("sem_close empty");
    if(sem_cs == SEM_FAILED) 
        handle_error("sem_close cs");
}

static inline int performRandomTransaction() {
    struct timespec pause = {0};
    pause.tv_nsec = 10*1000000; // 10 ms (10*10^6 ns)
    nanosleep(&pause, NULL);

    int amount = rand() % (2 * MAX_TRANSACTION);
    return (amount >= MAX_TRANSACTION) ? (MAX_TRANSACTION-amount-1) : (amount+1);
}

void produce(int id, int numOps) {
    int localSum = 0;
    while (numOps > 0) {

        if (sem_wait(sem_empty) == -1) { // Attendere fino a quando ci sono spazi vuoti
            handle_error("sem_wait empty");
        }

        // Entrare nella sezione critica
        if (sem_wait(sem_cs) == -1) { // Acquisire il lock per la sezione critica
            handle_error("sem_wait cs");
        }

        // CRITICAL SECTION
        int value = performRandomTransaction();
        writeToBufferFile(value, BUFFER_SIZE, BUFFER_FILENAME);
        localSum += value;

        // Uscire dalla sezione critica
        if (sem_post(sem_cs) == -1) { // Rilasciare il lock della sezione critica
            handle_error("sem_post cs");
        }

        // Segnalare che un nuovo elemento è disponibile
        if (sem_post(sem_filled) == -1) { // Segnala che c'è un nuovo elemento
            handle_error("sem_post filled");
        }

        numOps--;
    }
    printf("Producer %d ended. Local sum is %d\n", id, localSum);
}

int main(int argc, char** argv) {
    srand(PRNG_SEED);
    initFile(BUFFER_SIZE, BUFFER_FILENAME);
    initSemaphores();

    int i, ret;
    for (i=0; i<NUM_PRODUCERS; ++i) {
        pid_t pid = fork();
        if (pid == -1) {
            handle_error("fork");
        } else if (pid == 0) {
            produce(i, OPS_PER_PRODUCER);
            _exit(EXIT_SUCCESS);
        }
    }

    for (i=0; i<NUM_PRODUCERS; ++i) {
        int status;
        ret = wait(&status);
        printf("Status: %d\n", status);
        if (ret == -1) handle_error("wait");
        if (WEXITSTATUS(status)) handle_error_en(WEXITSTATUS(status), "child crashed");
    }

    printf("Producers have terminated. Exiting...\n");
    closeSemaphores();

    exit(EXIT_SUCCESS);
}
