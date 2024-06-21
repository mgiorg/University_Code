#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"
#include "correttore_esercizio3.h"
#include "../utils/listi.h"

int main(int argc, char** argv) {
    int total_test_number = 10, successes = 0;
    
    int i;
    for(i = 0; i < total_test_number; ++i) {
        printf("Test number %d out of %d\n", i + 1, total_test_number);

        ListNode* src_list = List_rand(rand() % 11, 10, 0);
        printf("src: ");
        List_print(src_list);

	int multiplier = (rand() % 4) + 1;
	printf("Search for multipliers of %d\n", multiplier);
	
	ListNode* gt_list = ground_truth(src_list, multiplier);
	printf("expected: ");
	List_print(gt_list);
		
        ListNode* output_list = list_multipliers(src_list, multiplier);
        printf("output: ");
	List_print(output_list);
	
	int cmp = List_compare(gt_list, output_list);
	if(cmp > 0) {
	  printf("SUCCESS\n");
	  successes++;
        }
        else {
            printf("FAILURE\n");
        }
        printf("Current success rate: %0.02f%%\n", 
	       (float)(successes) * 100.0f/ (float)(total_test_number));
        printf("\n*************************************************\n\n");

        List_free(output_list);
	List_free(gt_list);
	List_free(src_list);
    }

    printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

    return 0;
}
