#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "aux.h"

int* controlla_colonne(Mat *m, double w, double v){
	int rows = m -> rows;
  	int cols = m -> cols;
  	int* vet = (int*) malloc (rows * sizeof(int));
  	for (int j = 0; j < cols; j++) {
      	int somma = 0;
    	for (int i = 0; i < rows; i++) {
        	somma += m -> mat[i][j];
        }
      	double media = somma / rows;
      	(media >= w && media <= v)? *(vet + j) = 1 : *(vet + j) = 0;
        	
        
    }
  	return vet;
}

