/**
 * ? COME EVITARE O RISOLVERE IL DEADLOCK?
 * 
 * Il sistema operativo può effettuare diverse cose, come
 * * IGNORARE IL PROBLEMA (strategia "algoritmo dello STRUZZO");
 * * PREVENIRE IL DEADLOCK (evitando una o più delle condizioni necessarie);
 * * RILEVARE E RECUPERARE (tramite algoritmi di rilevamento e metodi di recupero, come il rilascio forzato delle risorse);
 * * EVITARE IL DEADLOCK (utilizzando tecniche di allocazione sicura, come l'ALGORITMO DEL BANCHIERE di Dijkstra)
 */

/**
 * Questo algoritmo verifica lo stato di sicurezza prima di concedere risorse ai processi.
 * Se il sistema rimane in uno stato "sicuro" (senza rischio di deadlock), le risorse vengono allocate.
 */

#include <stdio.h>
#include <stdbool.h>

#define PROCESSI 3
#define RISORSE 3

/// Matrice massima di risorse richieste da ciascun processo
int max[PROCESSI][RISORSE] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2}
};

// Matrice attuale delle risorse allocate a ciascun processo
int alloc[PROCESSI][RISORSE] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2}
};

// Matrice di bisogno calcolata come `Need[i][j] = Max[i][j] - Allocation[i][j]`
int need[PROCESSI][RISORSE];

// Risorse disponibili nel sistema
int available[RISORSE] = {3, 3, 2};

//Funzione per calcolare la matrice 'Need'
void calcolaNeed() {
	for(int i = 0; i < PROCESSI; ++i) 
		for(int j = 0; j < RISORSE; ++j) 
			need[i][j] = max[i][j] - alloc[i][j];
}

//Funzione per verificare se il sistema è in uno stato sicuro
bool statoSicuro() {
	bool finish[PROCESSI] = {false, false, false};
	int work[RISORSE];

	for(int i = 0; i < RISORSE; ++i) 
		work[i] = available[i];

	int count = 0;

	while(count < PROCESSI) {
		bool found = false;
		for(int p = 0; p < PROCESSI; ++p) {
			if(!finish[p]) {
				int j;
				for(j = 0; j < RISORSE; ++j) {
					if(need[p][j] > work[j]) break;
				}

				if(j == RISORSE) {
					for(int k = 0; k < RISORSE; ++k) {
						work[k] += alloc[p][k];
					}
					finish[p] = true;
					found = true;
					count++;
				}
			}
		}
		if(!found) return false;
	}
	return true;
}

//Funzione per richiedere risorse per un processo 'p'
bool richiestaRisorse(int p, int richiesta[]) {
	for(int i = 0; i < RISORSE; ++i) {
		if(richiesta[i] > need[p][i]) {
			printf("Errore: richiesta eccede il bisogno.\n");
			return false;
		}
		if(richiesta[i] > available[i]) {
			printf("Errore: risorse non disponibili.\n");
            return false;
		}
	}

	for(int i = 0; i < RISORSE; ++i) {
		available[i] -= richiesta[i];
		alloc[p][i] += richiesta[i];
		need[p][i] -= richiesta[i];
	}

	if(statoSicuro()) {
		printf("Richiesta approvata per il processo %d\n", p);
		return true;
	} else {
		for(int i = 0; i < RISORSE; ++i) {
		available[i] += richiesta[i];
		alloc[p][i] -= richiesta[i];
		need[p][i] += richiesta[i];
		}
		printf("Richiesta negata: causerebbe deadlock.\n");
		return false;
	}
}

int main() {
	calcolaNeed();

	int richiesta1[RISORSE] = {0, 0, 0};
	int richiesta2[RISORSE] = {0, 0, 0};

	richiestaRisorse(1, richiesta1);
	richiestaRisorse(2, richiesta2);

	return 0;
}


