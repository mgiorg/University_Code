#include "e2B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inserisci la soluzione qui...
int compare(const void *a, const void *b) {
    struct connessione *connA = (struct connessione *)a;
    struct connessione *connB = (struct connessione *)b;
    return (connA->costo - connB->costo);
}

void destinazioniAcquistabili(struct connessione * list, const char * partenza, int budget, const char * filename) {
    struct connessione* temp = list;
    struct connessione* filtered = NULL;
    int count = 0;

    while(temp != NULL) {
        if(strcmp(temp-> partenza, partenza)== 0 && temp-> costo <= budget) count++;
        temp = temp-> next;
    }

    //alloco l'array per le connessioni valide
    filtered = (struct connessione*) malloc(count * sizeof(struct connessione));
    if(filtered == NULL) {perror("ERORRE ALLOCAZIONE"); return;}

    temp = list;
    int i = 0;
    while(temp != NULL) {
        if(strcmp(temp-> partenza, partenza)== 0 && temp-> costo <= budget) {
            filtered[i] = *temp;
            i++;
        }
        temp = temp-> next;
    }

    // Ordina l'array per costo crescente
    qsort(filtered, count, sizeof(struct connessione), compare);

    FILE* f = fopen(filename, "w");
    if(f == NULL) {perror("ERRORE APERTURA FILE"); free(filtered); return;}

    for(int j = 0; j < count; ++j) {
        fprintf(f, "%s-%s-%d\n", filtered[j].partenza, filtered[j].destinazione, filtered[j].costo);
    }

    fclose(f);
    free(filtered);
}