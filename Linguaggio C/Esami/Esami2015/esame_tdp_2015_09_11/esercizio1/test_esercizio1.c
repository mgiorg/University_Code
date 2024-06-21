#include <stdio.h>
#include <stdlib.h>

#include "../utils/mat.h"
#include "esercizio1.h"


int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;
  int rows[10] = { 2, 1, 5, 0, 2, 0, 0, 4, 3, 1 };
  int cols[10] = { 2, 1, 4, 4, 0, 0, 0, 1, 2, 1 };
  int expected_result[10] = { 9, 4, 0, 0, 16, 1, 9, 0, 4, 16};

  char buffer[1024];
  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
 
    sprintf(buffer, "matrices/submat%d.txt", i);
    Mat* source_mat = Mat_load(buffer);
    printf("src ");
    Mat_print(source_mat);

    sprintf(buffer, "matrices/mat%d.txt", i);
    Mat* dest_mat = Mat_load(buffer);
    printf("dest ");
    Mat_print(dest_mat);

    printf("Copy block in position: (%d, %d)\n", rows[i], cols[i]);

    sprintf(buffer, "matrices/expectedmat%d.txt", i);
    Mat* expected_mat = Mat_load(buffer);
    printf("expected ");
    Mat_print(expected_mat);
        
    int result = matrixBlockCopy(dest_mat, source_mat, rows[i], cols[i]);
    printf("output ");
    Mat_print(dest_mat);
    printf("number of elements copied: %d\n", result);

    int cmp = Mat_compare(expected_mat, dest_mat);
    if(cmp > 0 && result == expected_result[i]) {
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
    Mat_free(expected_mat);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
