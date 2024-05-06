#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"
Mat * ultimi_gli_unici(Mat *m){
	int rows = m -> rows;
  	int cols = m-> cols;
  	int indice = 0, i, j;
  	Mat* nuova = mat_alloc(rows, cols);
  	bool trovato;
  	int* vet = (int*) malloc (rows * cols * sizeof(int));
   	int* riga = (int*) malloc (rows * cols * sizeof(int));
  	
  	vet[indice] = m -> mat[rows - 1][cols - 1];
  	riga[indice] = rows;
  
  	for (i = rows - 1; i > -1; i--) {
    	for (j = cols - 1; j > -1; j--) {
        	// sta sull'elemento [i][j]
          	if (i == rows - 1 && j == cols - 1) {
            	nuova -> mat[i][j] = m -> mat[i][j];
            }
          	else {
              	trovato = false;
            	for (int k = 0; k < indice + 1; k++) {
                	if (m -> mat[i][j] == vet[k] ) {
                    	if (riga[k] % 2 == 0) {
                        	nuova -> mat[i][j] = -2;
                        }
                      	else {
                        	nuova -> mat[i][j] = -1;
                        }
                      	trovato = true;
                    }                  
                }
              	if (not trovato) {
                  	++indice;
                	vet[indice] = m -> mat[i][j];
                  	riga[indice] = i + 1;
                  	
                  	nuova -> mat[i][j] = m -> mat[i][j];
                }
            }
       	}
          	
    }
    
  	return nuova;
}

