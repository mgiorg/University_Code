#include<stdlib.h>
#include "esercizio1.h"


void ground_truth(float** v , Mat* src) {
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
