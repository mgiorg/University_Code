#include "aux.h"

void bombardamentoNavale(Mat *src, int r, int c) {
	int rows = src -> rows;
  	int cols = src -> cols;
  	if (r > rows || c > cols) return;
  	if (src -> row_ptrs[r][c] == 1) {
    	src -> row_ptrs[r][c] = 0;
      	for (int j = c - 1; j > -1; j--) {
    		if (src -> row_ptrs[r][j] == 1) {             	
            	src -> row_ptrs[r][j] = 0;
            }
          	else break;
        }
        for (int i = r - 1; i > -1; i--) {
			if (src -> row_ptrs[i][c] == 1) {
            	src -> row_ptrs[i][c] = 0;
            }
          	else break;
        }
        for (int j = c + 1; j < cols; j++) {
			if (src -> row_ptrs[r][j] == 1) {
            	src -> row_ptrs[r][j] = 0;
            }
          	else break;
        }
        for (int i = r + 1; i < rows; i++) {
			if (src -> row_ptrs[i][c] == 1) {
            	src -> row_ptrs[i][c] = 0;
            }
          	else break;
        }
	} 
  	else return;
}


