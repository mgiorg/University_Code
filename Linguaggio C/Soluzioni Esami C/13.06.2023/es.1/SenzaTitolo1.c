#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"
void flip_riga(Mat *m, Mat *flip, int rows, int cols) {
  	int i, j;
	for (i = 0; i < rows; i++) {
    	if (i % 2 == 0) {
        	for (j = 0; j < cols; j++) {
            	flip -> mat[i][cols - 1 - j] = m -> mat[i][j];
            }
        }
        else {
        	for (j = 0; j < cols; j++) {
            	flip -> mat[i][j] = m -> mat[i][j];
            } 
        }  
    }
}

int massimo_flip_riga(Mat *m){
  	int somma1 = 0, somma2 = 0, somma3 = 0, somma4 = 0;
  	int rows = m -> rows;
  	int cols = m -> cols;
	Mat *flip = mat_alloc(rows, cols);
    flip_riga(m, flip, rows, cols);
  	for (int i = 0; i < rows; i++) {
    	for (int j = 0; j < cols; j++) {
        	if (i < rows/2 && j < cols/2) {
            	somma1 += flip -> mat[i][j];
            }
          	else if (i < rows/2 && j >= cols/2) {
            	somma2 += flip -> mat[i][j];
            }
          	else if (i >= rows/2 && j < cols/2) {
            	somma3 += flip -> mat[i][j];
            }
          	else if (i >= rows/2 && j >= cols/2) {
            	somma4 += flip -> mat[i][j];
            }
        }
    }
  	if (somma1 > somma2 && somma1 > somma3 && somma1 > somma4) return somma1;
  	else if (somma2 > somma1 && somma2 > somma3 && somma2 > somma4) return somma2;
  	else if (somma3 > somma1 && somma3 > somma2 && somma3 > somma4) return somma3;
  	else return somma4;
	
}
