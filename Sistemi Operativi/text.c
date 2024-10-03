#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void process_one(int* p) {
    printf("Processo 1: PID = %d, PPID = %d\n", getpid(), getppid());
	*p = 2;
    // Simulazione di lavoro
    sleep(2);
    printf("Processo 1 ha terminato.\n");
	exit(*p);
}

void process_two(int* p) {
    printf("Processo 2: PID = %d, PPID = %d\n", getpid(), getppid());
	*p = 3;
    // Simulazione di lavoro
    sleep(3);
    printf("Processo 2 ha terminato.\n");
	exit(*p);
}

int main() {
	int a = 1;
	printf("Primo valore nel padre: %d\n", a);
    pid_t pid1, pid2;

    // Crea il primo processo figlio
    pid1 = fork();
    
    if (pid1 < 0) {
        perror("Errore nella creazione del primo processo figlio");
        exit(1);
    }
    
    if (pid1 == 0) {
        // Codice eseguito dal primo processo figlio
        process_one(&a);
    }


    // Crea il secondo processo figlio
    pid2 = fork();
    
    if (pid2 < 0) {
        perror("Errore nella creazione del secondo processo figlio");
        exit(1);
    }
    
    if (pid2 == 0) {
        // Codice eseguito dal secondo processo figlio
        process_two(&a);
    }

    // Il processo padre aspetta che i figli terminino
    waitpid(pid1, &a, 0); // Attende il primo figlio
	if(WIFEXITED(a)) {
		a = WEXITSTATUS(a);
		printf("Valore di a modificato dal figlio 1: %d\n", a);
	}
    waitpid(pid2, &a, 0); // Attende il secondo figlio
	printf("Valore di a modificato dal figlio 2: %d\n", a);

    printf("Processo padre ha terminato.\n");
	
    return 0;
}