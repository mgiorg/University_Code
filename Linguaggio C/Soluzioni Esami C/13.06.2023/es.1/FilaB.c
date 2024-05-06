#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

int max (int somma1, int somma2, int somma3, int somma4) {
	if (somma1 >= somma2 && somma1 >= somma3 && somma1 >= somma4) return somma1;
  	else if (somma2 >= somma1 && somma2 >= somma3 && somma2 >= somma4) return somma2;
  	else if (somma3 >= somma1 && somma3 >= somma2 && somma3 >= somma4) return somma3;
  	else return somma4;
}



void mat (Mat *m, Mat* nuova, int rows, int cols) {
  	int j, k;
    for (int c = 0; c < cols; c++) {
         if (c % 2 == 0) {
            for (int i = 0; i < rows; i++) {
                nuova -> mat[i][c] = m -> mat[i][c];
            }
         }
         else {
            for (int i = 0; i < rows; i++) {
               	nuova -> mat[i][c] = m -> mat[rows - 1 - i][c];
            }
        }
   	}
}
	
    


int massimo_flip_colonna(Mat *m) {
	int rows = m -> rows;
  	int cols = m -> cols;
  	int somma1 = 0, somma2 = 0, somma3 = 0, somma4 = 0;
  	Mat* nuova = mat_alloc(rows, cols);
	mat(m, nuova, rows, cols);
  	for (int i = 0; i < rows; i++) {
    	for (int j = 0; j < cols; j++) {
        	if (i < rows / 2 && j < rows / 2) {
            	somma1 += nuova -> mat[i][j];
            }
          	else if (i < rows / 2 && j >= rows / 2) {
            	somma2 += nuova -> mat[i][j];
            }
          	else if (i >= rows / 2 && j < rows / 2) {
            	somma3 += nuova -> mat[i][j];
            }
          	else somma4 += nuova -> mat[i][j];
        }
    }
  	return max(somma1, somma2, somma3, somma4);
}

