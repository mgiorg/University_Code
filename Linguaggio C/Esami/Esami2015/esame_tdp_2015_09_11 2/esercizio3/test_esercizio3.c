#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"
#include "../utils/list.h"

int main(int argc, char** argv) {    
  int total_test_number = 10, successes = 0;
  
  char buffer[1024];
  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
 
    sprintf(buffer, "lists/src1list%d.txt", i);
    TipoSCL source1_list = TipoSCL_load(buffer);
    printf("l1       ");
    TipoSCL_print(source1_list);

    sprintf(buffer, "lists/src2list%d.txt", i);
    TipoSCL source2_list = TipoSCL_load(buffer);
    printf("l2       ");
    TipoSCL_print(source2_list);

    sprintf(buffer, "lists/expectedlist%d.txt", i);
    TipoSCL expected_list = TipoSCL_load(buffer);
    printf("expected ");
    TipoSCL_print(expected_list);

    TipoSCL result_list = minElements(source1_list, source2_list);
    printf("result   ");
    TipoSCL_print(result_list);

    int cmp = TipoSCL_compare(expected_list, result_list);
    if(cmp > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    
    TipoSCL_free(source1_list);
    TipoSCL_free(source2_list);
    TipoSCL_free(result_list);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
