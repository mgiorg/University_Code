#include "esercizio1.h"
#include<stdlib.h>

void compute_diagonal_integral(float** v , Mat* src) {
  if (src->rows!=src->cols)
    v=0;
  if (!src->rows)
    v=0;
  *v=(float*) malloc(src->rows*sizeof(float));
  for(int k=0; k<src->rows; k++){
    float acc=0;
    for (int r=0; r<=k; r++)
      for (int c=0; c<=k; c++)
	acc+=src->row_ptrs[r][c];
    (*v)[k]=acc;
  }
}
