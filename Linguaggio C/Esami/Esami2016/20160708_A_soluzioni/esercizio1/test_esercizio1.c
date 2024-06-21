#include <stdio.h>
#include <stdlib.h>

#include "../utils/matf_struct.h"
#include "correttore_esercizio1.h"
#include "esercizio1.h"

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;

  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);
     
    Mat* src_mat = Mat_rand((rand() % 9) + 1, (rand() % 9) + 1, 5.0f, 0);
    printf("src ");
    Mat_print(src_mat);
    fflush(stdout);

    Mat* gt_dest_mat = Mat_alloc(src_mat->rows, src_mat->cols);
    ground_truth(gt_dest_mat, src_mat);
    printf("expected ");
    Mat_print(gt_dest_mat);
    fflush(stdout);
    Mat_write("/tmp/gt_tdp.txt", gt_dest_mat);
    Mat_free(gt_dest_mat);
    
    Mat* dest_mat = Mat_alloc(src_mat->rows, src_mat->cols);
    matrix_compute_integral(dest_mat, src_mat);
    printf("output ");
    Mat_print(dest_mat);
    fflush(stdout);
    
    gt_dest_mat = Mat_read("/tmp/gt_tdp.txt");    
    int cmp = Mat_compare(gt_dest_mat, dest_mat);
    if(cmp > 0) {
      printf("SUCCESS\n");
      fflush(stdout);
      successes++;
    }
    else {
      printf("FAILURE\n");
      fflush(stdout);
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    fflush(stdout);
    
    Mat_free(src_mat);
    Mat_free(dest_mat);
    Mat_free(gt_dest_mat);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
    
  return 0;
}
