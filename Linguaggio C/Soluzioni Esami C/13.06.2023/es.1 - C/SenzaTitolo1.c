#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"
Mat * prima_gli_unici(Mat *m) {
  	int riga, colonna, len, j = 0;
  	bool primo = true, trovato = false;
	int rows = m -> rows;
  	int cols = m -> cols;
  	Mat* nuova = mat_alloc(rows, cols);
	int* numeri = (int*) malloc (rows * cols * sizeof(int));
  	int* num_riga = (int*) malloc (rows * cols * sizeof(int));
	
  	for (riga = 0; riga < rows; riga++) {
    	for (colonna = 0; colonna < cols; colonna++) {
          	trovato = false;
        	if (primo) {
            	nuova -> mat[riga][colonna] = m -> mat[riga][colonna];
               	numeri[j] = m -> mat[riga][colonna];
                num_riga[j] = 1;
              	len = 1;
               	primo = false;
            }
          	if (colonna == 0 && riga == 0) continue;
        	for (int i = 0; i < len; i++) {
            	if (m -> mat[riga][colonna] == numeri[i]) {
                  	trovato = true;
                	if (num_riga[i] % 2 == 0) {
                    	nuova -> mat[riga][colonna] = -1;
                    }
                  	else {
                    	nuova -> mat[riga][colonna] = -2;
                    }
                  	break;
                } 	
            }
          	if (not trovato) {
              	j++;
            	nuova -> mat[riga][colonna] = m -> mat[riga][colonna];
              	numeri[j] = m -> mat[riga][colonna];
              	num_riga[j] = riga + 1;
              	len++;
            }
          	
        }
    }
	return nuova;
}
