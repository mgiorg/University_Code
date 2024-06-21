#include <stdio.h>
#include <stdlib.h>

#include "esercizio2.h"
#include "correttore_esercizio2.h"
#include "../utils/listi.h"
#include "../utils/vec.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;

  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);
    
    int src_vec_size = (rand() % 9) + 1;
    int* src_vec = vectori_rand(src_vec_size, 2, 1);
    printf("src: ");
    vectori_print(src_vec, src_vec_size);
    fflush(stdout);
    
    ListNode* gt_list = ground_truth(src_vec, src_vec_size);
    printf("expected: ");
    Listi_print(gt_list);
    fflush(stdout);
    Listi_write("/tmp/gt_tdp.txt", gt_list);
    Listi_free(gt_list);
    
    ListNode* output_list = find_transitions(src_vec, src_vec_size);
    printf("output: ");
    Listi_print(output_list);
    fflush(stdout);
    
    gt_list = Listi_read("/tmp/gt_tdp.txt");
    int cmp = Listi_compare_ordered(gt_list, output_list);
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
    printf("\n*************************************************\n\n");
    fflush(stdout);
    
    Listi_free(output_list);
    Listi_free(gt_list);
    vectori_free(src_vec);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
    
  return 0;
}
