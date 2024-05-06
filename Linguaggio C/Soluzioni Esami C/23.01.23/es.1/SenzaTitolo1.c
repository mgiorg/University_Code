#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"


Mat* massima_sottomatrice(Mat *m) {
  	
  	int i, j;
  	int indiceR = 0, indiceC = 0, massimo = 0;
  	int rows = m -> rows;
  	int cols = m -> cols;
  	Mat* ris = mat_alloc(rows / 2, cols / 2);
  	int limite = ((rows / 2) + 1) * ((rows / 2) + 1);
 	for (int conta = 0; conta < limite; conta++) {
      	int somma = 0;
		for (i = indiceR; i < rows / 2 + indiceR; i++) {
        	for (j = indiceC; j < cols / 2 + indiceC; j++) {
              	somma += m -> mat[i][j];
            }          	
        }  
      	if (somma > massimo) {
        	massimo = somma;         	
          	int riga = -1;
          	int colonna = 0;
          	for (i = indiceR; i < rows / 2 + indiceR; i++) {
              	riga++;
        		for (j = indiceC; j < cols / 2 + indiceC; j++) {
                  	ris -> mat[riga][colonna] = m -> mat[i][j];
                  	colonna++;          		
            	}             	
              	colonna = 0;           	
        	}  
        }     
      	++indiceC;
      	if (indiceC == cols - ((rows / 2) - 1)) {
        	indiceC = 0;
          	indiceR++;
        }
      	if (indiceR == rows - ((rows / 2) - 1)) {
        	break;
        }      	
    }
  	return ris;
}
