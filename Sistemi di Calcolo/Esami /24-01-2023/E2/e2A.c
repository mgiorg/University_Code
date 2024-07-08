#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// inserisci la soluzione qui...
void decodeTextFile(const char * encoded_file, const char * key, char ** decoded_text) {
    FILE* f = fopen(key, "r");
    if(!f) perror("FILE CON LA CHIAVE NON ESISTENTE");

    char* keymap = (char*) malloc(58*sizeof(char));

    for(int i = 0; i < 58; i++) {
        keymap[i] = getc(f);
        if(feof(f)) perror("CHIAVE NON VALIDA");
    }
    fclose(f);

    f = fopen(encoded_file, "r");
    if(!f) perror("FILE DI TESTO NON ESISTENTE");

    //Per calcolare la dimensione del file
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    *decoded_text = (char*) malloc((file_size+1) * sizeof(char));
    int i = 0;
    do {
        int c = fgetc(f);
        if(feof(f)) {
            (*decoded_text)[file_size+1] = '\0';
            break;
        }
        int num = (int) c;
        if(num >= 65 && num <= 122) {
            num = num-65;
            (*decoded_text)[i] = keymap[num];
        } else (*decoded_text)[i] = c;
        ++i;
    } while(1);
    
    fclose(f);
    return;
}

