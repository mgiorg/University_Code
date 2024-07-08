#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// inserisci la soluzione qui...
struct destinazione* creaNodo(const char* dest, int costo) {
    struct destinazione* newNode = (struct destinazione*)malloc(sizeof(struct destinazione));
    if(newNode != NULL) {
        strncpy(newNode-> destinazione, dest, sizeof(struct destinazione)-1);
        newNode-> destinazione[sizeof(struct destinazione)-1] = '\0';
        newNode->costo = costo;
        newNode-> next = NULL;
    }
    return newNode;
}

void aggiungiNodo(struct destinazione** list, const char* dest, int costo) {
    struct destinazione* newNode = creaNodo(dest, costo);
    if(*list == NULL) {
        *list = newNode;
    } else {
        struct destinazione* temp = *list;
        while(temp-> next != NULL) {
            temp = temp-> next;
        }
        temp-> next = newNode;
    }
}

void destinazioniDisponibili(const char *filename, const char *partenza, int budget, struct destinazione **list) {
    //Inizializzo la lista come lista vuota
    *list = NULL;

    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    char line[256];
    while(fgets(line, sizeof(line), file) != NULL) {
        char part[4], dest[4];
        int costo;

        if(sscanf(line, "%3s-%3s-%d", part, dest, &costo)) {
            if(strcmp(part, partenza) == 0 && costo <= budget) aggiungiNodo(list, dest, costo);
        }
    }
    fclose(file);
}

