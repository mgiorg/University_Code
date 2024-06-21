#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"
#include "correttore_esercizio3.h"
#include "../utils/listi.h"
#include "../utils/vec.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;
    
  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);
    
    int src_vec_size = rand() % 10;
    int* src_vec = vectori_rand(src_vec_size, 11, 0);
    printf("src: ");
    fflush(stdout);
    vectori_print(src_vec, src_vec_size);
    fflush(stdout);
    
    ListNode* gt_list = ground_truth(src_vec, src_vec_size);
    printf("expected: ");
    fflush(stdout);
    List_print(gt_list);
    fflush(stdout);
	
    ListNode* output_list = compute_derivative(src_vec, src_vec_size);
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
    
    List_free(output_list);
    List_free(gt_list);
    vectori_free(src_vec);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
      
  return 0;
}
