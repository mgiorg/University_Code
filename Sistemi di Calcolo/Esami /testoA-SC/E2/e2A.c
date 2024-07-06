#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// inserisci la soluzione qui...


void destinazioniDisponibili(const char *filename, const char *partenza, int budget, struct destinazione **list) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[256];
    *list = NULL;
    struct destinazione *tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        char start[4], end[4];
        int cost;

        // Parse the line in the format partenza-destinazione-costo
        if (sscanf(line, "%3[^-]-%3[^-]-%d", start, end, &cost) == 3) {
            if (strcmp(start, partenza) == 0 && cost <= budget) {
                struct destinazione *new_dest = (struct destinazione *)malloc(sizeof(struct destinazione));
                if (!new_dest) {
                    perror("Error allocating memory");
                    fclose(file);
                    return;
                }
                strcpy(new_dest->destinazione, end);
                new_dest->costo = cost;
                new_dest->next = NULL;

                // Append to the list
                if (*list == NULL) {
                    *list = new_dest;
                    tail = new_dest;
                } else {
                    tail->next = new_dest;
                    tail = new_dest;
                }
            }
        }
    }

    fclose(file);
}

