#include <stdio.h>
#include <stdlib.h>

#include "../utils/mat_struct.h"
#include "correttore_esercizio1.h"
#include "esercizio1.h"

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;
  int rows[10] = { 2, 1, 5, 0, 2, 0, 0, 4, 3, 1 };
  int cols[10] = { 2, 1, 4, 4, 0, 0, 0, 1, 2, 1 };

  char buffer[1024];
  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
 
    sprintf(buffer, "data/source_submat_%d.txt", i);
    Mat* source_mat = Mat_load(buffer);
    printf("src ");
    Mat_print(source_mat);

    sprintf(buffer, "data/source_mat_%d.txt", i);
    Mat* dest_mat = Mat_load(buffer);
    printf("dest ");
    Mat_print(dest_mat);

    printf("Sum block in position: (%d, %d)\n", rows[i], cols[i]);

    sprintf(buffer, "data/source_mat_%d.txt", i);
    Mat* gt_dest_mat = Mat_load(buffer);
    int gt_result = ground_truth(gt_dest_mat, source_mat, rows[i], cols[i]);
    printf("expected ");
    Mat_print(gt_dest_mat);

    int result = matrix_block_sum(dest_mat, source_mat, rows[i], cols[i]);
    printf("output ");
    Mat_print(dest_mat);
    printf("number of elements copied: %d\n", result);

    int cmp = Mat_compare(gt_dest_mat, dest_mat);
    if(cmp > 0 && result == gt_result) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    
    Mat_free(source_mat);
    Mat_free(dest_mat);
    Mat_free(gt_dest_mat);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
