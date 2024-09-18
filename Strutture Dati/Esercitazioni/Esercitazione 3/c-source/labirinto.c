#include "labirinto.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int n;
    int **matrix;
    int **marcata;
} labirinto_struct ;

labirinto * labirinto_new(int n) {
    // TODO: Da completare
    labirinto_struct* l1 = (labirinto_struct* )malloc(sizeof(labirinto_struct));
    labirinto *l = (labirinto* )l1;
    l1-> matrix = (int** )malloc(n*sizeof(int*));
    l1-> marcata = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; ++i) {
        l1->matrix[i] = (int* )malloc(n*sizeof(int));
        l1-> marcata[i] = (int *)malloc(n * sizeof(int));
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            l1->matrix[i][j] = NULL;
            l1->marcata[i][j] = NULL;
        }
    }
    l1-> n = n;
	return l;
}

void labirinto_delete(labirinto * lab) {
    // TODO: Da completare
    
}

void labirinto_setpiena(labirinto * lab, int r, int c) {
    // TODO: Da completare
    labirinto_struct* temp = (labirinto_struct* )lab;
    temp->matrix[r][c] = LABIRINTO_PIENA;
}

int labirinto_uscita(labirinto * lab, int r, int c) {
    // TODO: Da completare
    labirinto_struct* l = (labirinto_struct*) lab;
    if(r == l->n-1 && c == l->n-1) return 1;
    else return 0; 
}

int labirinto_percorribile(labirinto * lab, int r, int c) {
    // TODO: Da completare
    labirinto_struct *l = (labirinto_struct *)lab;
    if(r < 0 || r >= l-> n || c < 0 || c >= l-> n) {
        return 0;
    }
    if(l-> matrix[r][c] == LABIRINTO_PIENA) {
        return 0;
    }
    else return 1;
}

int labirinto_uscitaraggiungibileda(labirinto * lab, int r, int c) {
    // TODO: Da completare
    labirinto_struct *l = (labirinto_struct *)lab;
    if(labirinto_percorribile(lab, r, c) == 0) {
        return 0;
    }
    if(labirinto_uscita(lab, r, c))
    {
        return 1;
    }
    
    if(l-> marcata[r][c] == 0) {
        l-> marcata[r][c] = 1;
        return labirinto_uscitaraggiungibileda(lab, r-1, c) ||
               labirinto_uscitaraggiungibileda(lab, r+1, c) ||
               labirinto_uscitaraggiungibileda(lab, r, c-1) ||
               labirinto_uscitaraggiungibileda(lab, r, c+1); 
    }
    return 0;
}

int labirinto_risolvibile(labirinto * lab) {
    // TODO: Da completare
    if(labirinto_uscitaraggiungibileda(lab, 0, 0)) return 1;
	else return 0;
}

void labirinto_tostring(labirinto * lab, char * buffer, int buffer_size) {
	labirinto_struct * ptr = (labirinto_struct *) lab;
        assert(buffer_size >= (ptr->n + 1) * ptr->n);
    buffer[0] = '\0';
    char *buffer_ptr = buffer;
    int i;
    for (i = 0; i < ptr->n; i++) {
        int j;
        for (j = 0; j < ptr->n; j++) {
            char c;
            if(ptr->matrix[i][j] == LABIRINTO_PIENA)
                c = '#';
            if(ptr->matrix[i][j] == LABIRINTO_VUOTA && ptr->marcata[i][j] == LABIRINTO_FALSE)
                c = '.'; 
            if(ptr->matrix[i][j] == LABIRINTO_VUOTA && ptr->marcata[i][j] == LABIRINTO_TRUE)
                c = '+'; 
            buffer_ptr[0] = c;
            buffer_ptr++;
        }
        buffer_ptr[0] = '\n';
        buffer_ptr++;
    }
    buffer_ptr[0] = '\0';
}