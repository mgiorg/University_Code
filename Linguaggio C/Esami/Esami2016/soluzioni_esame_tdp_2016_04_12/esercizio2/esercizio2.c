#include <stdlib.h>

#include "esercizio2.h"

SparseMatrix dense_to_sparse_matrix(float** mat, int rows, int cols) {  
  SparseMatrix sparse_mat_node_gen = (SparseMatrix)malloc(sizeof(SparseMatrixElement));
  sparse_mat_node_gen->next = NULL;
  SparseMatrix it = sparse_mat_node_gen;
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      if(mat[r][c] != 0.0) {
	it->next = (SparseMatrix)malloc(sizeof(SparseMatrixElement));
	it = it->next;
	it->row = r;
	it->col = c;
	it->value = mat[r][c];
	it->next = NULL;
      }
    }
  }

  SparseMatrix head = sparse_mat_node_gen->next; 
  free(sparse_mat_node_gen);
  return head;
}
