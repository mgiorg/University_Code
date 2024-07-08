#include "e2B.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// inserisci la soluzione qui...
int getBalanceMovements(const char* fname, int min, int max, int * bal) {
    FILE* f = fopen(fname, "r");
    *bal = 0;

    if(f == NULL) {
        perror("ERRORE APERTURA FILE");
        return -1;
    }

    char buf[256];
    int count = 0;
    while(fgets(buf, sizeof(buf), f) != NULL) {
        char segno;
        int giorno, costo;

        if(sscanf(buf, "%d|%c|%d", &giorno, &segno, &costo)) {
            if(giorno>= min && giorno <= max) {
                if(segno == '+') {
                    *bal += costo;
                } else {
                    *bal -= costo;
                }
                count++;
            }
        }
    }

    fclose(f);
    return count;
}
