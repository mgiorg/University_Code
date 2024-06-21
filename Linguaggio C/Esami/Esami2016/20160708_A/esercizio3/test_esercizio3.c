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
    
    int tmp_src_list1_size = (rand() % 4) + 1;
    ListNode *tmp_src_list1 = Listi_rand(tmp_src_list1_size, 11, 0);

    int tmp_src_list2_size = (rand() % 4) + 1;
    ListNode *tmp_src_list2 = Listi_rand(tmp_src_list2_size, 11, 0);
    ListNode *src_list2 = NULL;
    int append = rand() % 3;
    if(append) {
      src_list2 = Listi_append(tmp_src_list1, tmp_src_list2);
      Listi_free(tmp_src_list2);
    }
    else {
      src_list2 = tmp_src_list2;
    }

    append = rand() % 2;
    ListNode *src_list1 = NULL;
    if(append) {
      int fill_list_size = (rand() % 2) + 1;
      ListNode *fill_list = Listi_rand(fill_list_size, 11, 0);
      src_list1 = Listi_append(tmp_src_list1, fill_list);
      Listi_free(fill_list);
      Listi_free(tmp_src_list1);
    }
    else {
      src_list1 = tmp_src_list1;
    }

    printf("src list 1: ");
    Listi_print(src_list1);
    fflush(stdout);

    printf("src list 2: ");
    Listi_print(src_list2);
    fflush(stdout);
		       
    int gt_prefix_length = ground_truth(src_list1, src_list2);
    printf("expected: %d\n", gt_prefix_length);
    fflush(stdout);
    FILE* f = fopen("/tmp/gt_tdp.txt", "w");
    if(f == NULL) {
      printf("Error while opening file /tmp/gt_tdp.txt... aborting!\n");
      fflush(stdout);
      exit(-1);
    }
    fprintf(f, "%d", gt_prefix_length);
    fflush(f);
    fclose(f);
    
    int output_prefix_length = compute_prefix_length(src_list1, src_list2);
    printf("output: %d\n", output_prefix_length);
    fflush(stdout);

    f = fopen("/tmp/gt_tdp.txt", "r");
    if(f == NULL) {
      printf("Error while opening file /tmp/gt_tdp.txt... aborting!\n");
      fflush(stdout);
      exit(-1);
    }
    fscanf(f, "%d", &gt_prefix_length);
    fflush(f);
    fclose(f);
    if(gt_prefix_length == output_prefix_length) {
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
    
    Listi_free(src_list2);
    Listi_free(src_list1);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
  
  return 0;
}
