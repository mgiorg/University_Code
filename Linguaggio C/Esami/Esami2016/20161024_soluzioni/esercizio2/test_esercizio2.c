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
    
    int list_num_elements = rand() % 10 + 1;
    int vec_num_elements = rand() % 10 + 1;

    int* src_vec = vectori_rand(vec_num_elements, list_num_elements, 0);
    printf("src vector ");
    fflush(stdout);
    vectori_print(src_vec, vec_num_elements);
    fflush(stdout);
    
    ListNode* src_list = List_rand(list_num_elements, vec_num_elements, 1);
    printf("src list ");
    fflush(stdout);
    List_print(src_list);
    fflush(stdout);
    
    ListNode* gt_list = ground_truth(src_list, src_vec, vec_num_elements);
    printf("expected: ");
    fflush(stdout);
    List_print(gt_list);
    fflush(stdout);

    ListNode* output_list = fetch_elements(src_list, src_vec, vec_num_elements);
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
    
    List_free(src_list);
    vectori_free(src_vec);
    List_free(gt_list);
    List_free(output_list);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
	 (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
    
  return 0;
}
