#include <stdio.h>
#include <stdlib.h>

#include "esercizio2.h"
#include "../utils/vec.h"
#include "../utils/list.h"

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;
  int num[10] = { 3, 2, 0, 4, 3, 1, 4, 3, 2 };

  char buffer[1024];
  int i, n;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);
 
    sprintf(buffer, "lists/list%d.txt", i);
    TipoSCL source_list = TipoSCL_load(buffer);
    printf("src ");
    TipoSCL_print(source_list);

    printf("rotate list of %d positions\n", num[i]);

    sprintf(buffer, "vectors/expectedvector%d.txt", i);
    int* expected_vector = vectori_load(&n, buffer);
    printf("expected ");
    vectori_print(expected_vector, n);

    int* output_vector;
    int result = rotateList(&output_vector, source_list, num[i]);
    printf("output ");
    vectori_print(output_vector, result);
    printf("Size of the output vector: %d\n", result);

    int cmp = vectori_compare(expected_vector, output_vector, n);
    if(cmp > 0 && result == n) { 
      printf("SUCCESS\n");
      successes++;
    }
    else { 
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    
    TipoSCL_free(source_list);
    vectori_free(output_vector);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
