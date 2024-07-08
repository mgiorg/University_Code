#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// inserisci la soluzione qui...
int loadStringsFromFile (const char * filename, char *** list) {
    FILE* f = fopen(filename, "r");
    if(!f) return -1;

    char buf[256];
    int count = 0;

    while(fgets(buf, sizeof(buf), f) != NULL) {if(isalpha(buf[0])) count++;}
    rewind(f);

    char* str = fgets(buf, sizeof(buf), f);
    *list = (char**) malloc(count * sizeof(char*));

    for(int i = 0; i < sizeof(*list); ++i) {
        str = fgets(buf, sizeof(buf), f);
        if(isalpha(buf[0])){
			(*list)[i] = (char*)malloc((strlen(buf) - 1) * sizeof(char));
        	strcpy((*list)[i], buf);
		}
    }


    fclose(f);
	return count;
}
