#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#define N 1000 // number of threads
#define M 10000 // number of iterations per thread
#define V 1 // value added to the balance by each thread at each iteration

unsigned long int* local_sums;
int n = N, m = M, v = V;

void* thread_work(void *arg) {
	int thread_id = *(int*)arg; // Ogni thread conosce il proprio ID
	local_sums[thread_id] = 0; // Inizializza la somma locale per il thread corrente

	// Incrementa la somma locale
	for (int i = 0; i < m; i++)
		local_sums[thread_id] += v;

	return NULL;
}

int main(int argc, char **argv)
{
	if (argc > 1) n = atoi(argv[1]);
	if (argc > 2) m = atoi(argv[2]);
	if (argc > 3) v = atoi(argv[3]);
	
	local_sums = (unsigned long int*)calloc(n, sizeof(unsigned long int));
	if(local_sums == NULL) {
		printf("Errore allocazione di memoria per le somme locali!\n");
		exit(EXIT_FAILURE);
	}

	printf("Going to start %d threads, each adding %d times %d to its local sum...", n, m, v); fflush(stdout);
	pthread_t* threads = (pthread_t*)malloc(n * sizeof(pthread_t));
	int* thread_ids = (int*)malloc(n * sizeof(int)); // Array di ID per i thread
	if (threads == NULL || thread_ids == NULL) {
		fprintf(stderr, "Errore nell'allocazione della memoria per i thread.\n");
		exit(EXIT_FAILURE);
	}
	int i;
	for (i = 0; i < n; i++) {
		thread_ids[i] = i;
		if (pthread_create(&threads[i], NULL, thread_work, &thread_ids[i]) != 0) {
			fprintf(stderr, "Can't create a new thread, error %d\n", errno);
			exit(EXIT_FAILURE);
		}
	}
	printf("ok\n");

	printf("Waiting for the termination of all the %d threads...", n); fflush(stdout);
	for (i = 0; i < n; i++)
		pthread_join(threads[i], NULL);
	printf("ok\n");

	unsigned long int shared_variable = 0;
	for(i = 0; i < n; i++) {
		shared_variable += local_sums[i];
	}

	unsigned long int expected_value = (unsigned long int)n*m*v;
	printf("The value of the shared variable is %lu. It should have been %lu\n", shared_variable, expected_value);
	if (expected_value > shared_variable) {
		unsigned long int lost_adds = (expected_value - shared_variable) / v;
		printf("Number of lost adds: %lu\n", lost_adds);
	}

    free(threads);
	free(thread_ids);
	free(local_sums);

	return EXIT_SUCCESS;
}

