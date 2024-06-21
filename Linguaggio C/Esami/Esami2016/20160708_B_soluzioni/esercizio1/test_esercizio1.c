#include <stdio.h>
#include <stdlib.h>

#include "../utils/matf_struct.h"
#include "../utils/vec.h"
#include "correttore_esercizio1.h"
#include "esercizio1.h"

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;

  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);
    
    int sz = (rand() % 9) + 1;
    Mat* src_mat = Mat_rand(sz, sz, 5.0f, 0);
    printf("src ");
    Mat_print(src_mat);
    fflush(stdout);
    
    float* gt_dest_vec;
    ground_truth(&gt_dest_vec, src_mat);
    printf("expected ");
    vectorf_print(gt_dest_vec, src_mat->rows);
    fflush(stdout);   
    vectorf_write("/tmp/gt_tdp.txt", gt_dest_vec, src_mat->rows);
    vectorf_free(gt_dest_vec);

    float *v;
    compute_diagonal_integral(&v, src_mat);
    printf("output ");
    vectorf_print(v, src_mat->rows);
    fflush(stdout);
    
    int gt_dest_vec_dim = 0;
    gt_dest_vec = vectorf_read(&gt_dest_vec_dim, "/tmp/gt_tdp.txt");
    int cmp = vectorf_compare(gt_dest_vec, v, src_mat->rows);
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
    vectorf_free(v);
    vectorf_free(gt_dest_vec);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
    
  return 0;
}
