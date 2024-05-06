#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

Mat* inverti_e_max_quad(Mat* m) {
  	
	int rows = m -> rows;
  	int cols = m -> cols;
  	Mat* nuova = mat_alloc(rows, cols);
  	int i, j, somma1 = 0, somma2 = 0, somma3 = 0, somma4 = 0;
  	float media1, media2, media3, media4;
  
  
  	for (i = 0; i < rows; i++) { // modifica la matrice 
    	for (j = 0; j < cols; j++) {  
          	if (j > i && m -> mat[i][j] % 2 == 0) {
            	nuova -> mat[i][j] = -m-> mat[i][j];
            }
          	else if (i >= j && m -> mat[i][j] % 2 == 1) {
            	nuova -> mat[i][j] = -m-> mat[i][j];
            } 
          	else {
            	nuova -> mat[i][j] = m-> mat[i][j];
            }
        }
    }
  
  	Mat* Quad1 = mat_alloc(rows/2, cols/2);
  	Mat* Quad2 = mat_alloc(rows/2, cols/2);
  	Mat* Quad3 = mat_alloc(rows/2, cols/2);
  	Mat* Quad4 = mat_alloc(rows/2, cols/2);
  
  	for (i = 0; i < rows/2; i++) {  // QUADRANTE 1
    	for (j = 0; j < cols/2; j++) {
        	Quad1 -> mat[i][j] = nuova -> mat[i][j];
        }
    }
  	for (i = 0; i < rows/2; i++) {  // QUADRANTE 2
    	for (j = 0; j < cols/2; j++) {
        	Quad2 -> mat[i][j] = nuova -> mat[i][j + cols/2];
        }
    }
  	for (i = 0; i < rows/2; i++) {  // QUADRANTE 3
    	for (j = 0; j < cols/2; j++) {
        	Quad3 -> mat[i][j] = nuova -> mat[i + rows/2][j];
        }
    }
  	for (i = 0; i < rows/2; i++) {  // QUADRANTE 4
    	for (j = 0; j < cols/2; j++) {
        	Quad4 -> mat[i][j] = nuova -> mat[i + rows/2][j + cols/2];
        }
    }
  	
  	for (i = 0; i < rows; i++) {
    	for (j = 0; j < cols; j++) {
        	if (i < rows/2 && j < cols/2) somma1 += nuova -> mat[i][j];
            else if (i < rows/2 && j >= cols/2) somma2 += nuova -> mat[i][j];  // calcolo somme quadranti
        	else if (i >= rows/2 && j < cols/2) somma3 += nuova -> mat[i][j];
        	else if (i >= rows/2 && j >= cols/2) somma4 += nuova -> mat[i][j];
        }
    }
  	

    if (somma1 >= somma2 && somma1 >= somma3 && somma1 >= somma4) {
    	return Quad1;
    }	
    else if (somma2 > somma1 && somma2 >= somma3 && somma2 >= somma4) {
    	return Quad2;
    }
  	else if (somma3 > somma1 && somma3 > somma2 && somma3 >= somma4) {
    	return Quad3;
    }
  	else return Quad4;
}               

