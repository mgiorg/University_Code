#include <stdio.h>
#include <stdlib.h>

#include "esercizio2.h"
#include "correttore_esercizio2.h"
#include "../utils/mat.h"
#include "../utils/sparse_matrix.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;

  char buffer[1024];
  int i, rows, cols;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    sprintf(buffer, "data/source_mat_%d.txt", i);
    float** source_mat = matrixf_load(&rows, &cols, buffer);
    printf("source dense ");
    matrixf_print(source_mat, rows, cols);

    SparseMatrix gt_sparse_mat = ground_truth(source_mat, rows, cols);
    printf("expected sparse matrix ");
    SparseMatrix_print(gt_sparse_mat);
    
    SparseMatrix output_sparse_mat = dense_to_sparse_matrix(source_mat, rows, cols);
    printf("output sparse mat      ");
    SparseMatrix_print(output_sparse_mat);

    int cmp = SparseMatrix_compare(gt_sparse_mat, output_sparse_mat);
    if(cmp > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n",
    	   (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");

    SparseMatrix_free(output_sparse_mat);
    SparseMatrix_free(gt_sparse_mat);
    matrixf_free(source_mat, rows);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
  	 (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
