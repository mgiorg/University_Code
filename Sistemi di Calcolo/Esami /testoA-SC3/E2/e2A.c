#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
// inserisci la soluzione qui...
void checkError(int res, char* msg) {
    if(res != -1) return;
    perror(msg);
    exit(EXIT_FAILURE);
}
int vowelcount(const char** s, int n){
    if(n == 0 || s == NULL) return -1;
    int somma = 0;
    for(int i = 0; i < n; ++i) {
        pid_t pid = fork();
        checkError(pid, "Error in fork");
        if(pid == 0) {
            const char* str = s[i];
            int vowels = 0;
            int len = strlen(str);
            for(int j = 0; j < len; ++j) {
                char c = tolower(str[j]);
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowels++;
            }
            exit(vowels);
        }
    }

    for(int i = 0; i < n; ++i) {
        int status;
        while(wait(&status) > 0) {
            if(WIFEXITED(status)) 
                somma += WEXITSTATUS(status);
        }
    }
    printf("Somma = %d\n", somma);
    return somma;
}