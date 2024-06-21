#include <stdio.h>
#include <stdlib.h>

#include "esercizio2.h"
#include "correttore_esercizio2.h"
#include "../utils/mati_struct.h"
#include "../utils/listi.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;

  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);

    Mat* src_mat = Mat_rand((rand() % 5) + 1, (rand() % 5) + 1, 11, 1);
    printf("src ");
    fflush(stdout);
    Mat_print(src_mat);
    fflush(stdout);

    int threshold = rand() % 11;
    printf("Create a list containing matrix values lower than %d\n", threshold);
    fflush(stdout);

    ListNode* gt_list = ground_truth(src_mat, threshold);
    printf("expected: ");
    fflush(stdout);
    List_print(gt_list);
    fflush(stdout);

    ListNode* output_list = lowerValues(src_mat, threshold);
    printf("output: ");
    fflush(stdout);
    List_print(output_list);
    fflush(stdout);
    
    int cmp = List_compare_ordered(gt_list, output_list);
    if(cmp > 0) {
      printf("SUCCESS\n");
      fflush(stdout);
      successes++;
    }
    else {
      printf("FAILURE\n");
      fflush(stdout);
    }
    printf("Current success rate: %0.02f%%\n",
	   (float)(successes) * 100.0f/ (float)(total_test_number));
    fflush(stdout);
    printf("\n*************************************************\n\n");
    fflush(stdout);
    
    Mat_free(src_mat);
    List_free(gt_list);
    List_free(output_list);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
	 (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
    
  return 0;
}
