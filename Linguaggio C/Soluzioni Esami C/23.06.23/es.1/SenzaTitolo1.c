#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"


float somma_diag(Mat *mat, int row, int col) {
	int rows = mat -> rows;
  	int cols = mat -> cols;
  	float somma = mat -> mat[row][col];
  	for (int i = 1; i < rows; i++) {
    	if (row + i < rows && col + i < cols) {
        	somma += mat -> mat[row + i][col + i];
        }
      	else break;
    }
  	for (int i = 1; i < rows; i++) {
    	if (row - i >= 0 && col - i >= 0) {
        	somma += mat -> mat[row - i][col - i];
        }
      	else break;
    }
  	return somma;
}

