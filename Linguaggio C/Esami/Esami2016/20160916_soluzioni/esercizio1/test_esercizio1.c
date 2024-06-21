#include <stdio.h>
#include <stdlib.h>

#include "../utils/mati_struct.h"
#include "correttore_esercizio1.h"
#include "esercizio1.h"

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;

  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);

    Mat* src_mat = Mat_rand((rand() % 3) + 1, (rand() % 3) + 1, 3, 0);
    printf("src ");
    fflush(stdout);
    Mat_print(src_mat);
    fflush(stdout);

    Mat* gt_dest_mat = Mat_rand((rand() % 4) + 6, (rand() % 4) + 6, 6, 0);
    Mat* dest_mat = Mat_clone(gt_dest_mat);
    printf("dest ");
    fflush(stdout);
    Mat_print(dest_mat);
    fflush(stdout);

    int start_row = (rand() % 6);
    int start_col = (rand() % 6);
    printf("Sum block in position: (%d, %d)\n", start_row, start_col);
    fflush(stdout);
    
    int gt_result = ground_truth(gt_dest_mat, src_mat, start_row, start_col);
    printf("expected ");
    fflush(stdout);
    Mat_print(gt_dest_mat);
    fflush(stdout);
    printf("number of elements copied: %d\n", gt_result);
    fflush(stdout);
	    
    int result = matrix_block_sum(dest_mat, src_mat, start_row, start_col);
    printf("output ");
    fflush(stdout);
    Mat_print(dest_mat);
    fflush(stdout);
    printf("number of elements copied: %d\n", result);
    fflush(stdout);
    
    int cmp = Mat_compare(gt_dest_mat, dest_mat);
    if(cmp > 0 && result == gt_result) {
      printf("SUCCESS\n");
      fflush(stdout);
      successes++;
    }
    else {
      printf("FAILURE\n");
      fflush(stdout);
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    fflush(stdout);
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
