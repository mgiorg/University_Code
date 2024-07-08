#include "e2A.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// inserisci la soluzione qui...
void reverseTextFile(const char * input_file, const char * output_file) {
    FILE* input = fopen(input_file, "r");
    if(!input) return;
    FILE* output = fopen(output_file, "w");
    if(!output) return;

    int count = 0;
    char buf[256];
    

    while(fgets(buf, sizeof(buf), input) != NULL) {
        count++;
    }
    rewind(input);

    char** mat = (char**)malloc(count * sizeof(char*));
    int i = 0;
    while(fgets(buf, sizeof(buf), input) != NULL) {
        mat[i] = (char*) malloc(256 * sizeof(char));
        strcpy(mat[i], buf);
        ++i;
    }
    i = count -1;
    while(i >= 0) {
        fprintf(output, "%s", mat[i]);
        
        --i;
    }
    

    fclose(input);
    fclose(output);
}
