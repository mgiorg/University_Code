#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "correttore_esercizio3.h"

float ground_truth(SparseMatrix sparse_mat) {
  if(sparse_mat == NULL) { 
    return 0.0;
  }
  else if(sparse_mat->row == sparse_mat->col) {
    return sparse_mat->value + ground_truth(sparse_mat->next);
  }
  else {
    return ground_truth(sparse_mat->next);
  }
}
