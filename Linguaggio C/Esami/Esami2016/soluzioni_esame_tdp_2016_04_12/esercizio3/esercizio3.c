#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "esercizio3.h"

float sparse_matrix_diagonal_sum(SparseMatrix sparse_mat) {
  if(sparse_mat == NULL) { 
    return 0.0;
  }
  else if(sparse_mat->row == sparse_mat->col) {
    return sparse_mat->value + sparse_matrix_diagonal_sum(sparse_mat->next);
  }
  else {
    return 0.0 + sparse_matrix_diagonal_sum(sparse_mat->next);
  }
}
