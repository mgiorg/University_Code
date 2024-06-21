#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "esercizio3.h"
#include "correttore_esercizio3.h"
#include "../utils/listi.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;
    
  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);
    
    ListNode* src_list = List_rand(rand() % 10 + 1, rand() % 10, 0);
    printf("src list ");
    fflush(stdout);
    List_print(src_list);
    fflush(stdout);
    
    float gt_value = ground_truth(src_list);
    printf("expected: %f\n", gt_value);
    fflush(stdout);

    float output_value = recursive_norm(src_list);
    printf("output: %f\n", output_value);
    fflush(stdout);
	
    if(fabs(gt_value - output_value) < 1e-3) {
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
    
    List_free(src_list);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
      
  return 0;
}
