#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"
#include "../utils/sparse_vector_element_utils.h"

int main(int argc, char** argv) {    
  int total_test_number, successes = 0;
  
  int size_a, size_b;
  char filename_a[] = "./vectors/vectors_a.txt";
  SparseVectorElement** lists_vectors_a = SparseVectorElementListArray_load(&size_a, filename_a); 
  char filename_b[] = "./vectors/vectors_b.txt";
  SparseVectorElement** lists_vectors_b = SparseVectorElementListArray_load(&size_b, filename_b); 
  char filename_expected[] = "./vectors/vectors_expected.txt";
  SparseVectorElement** lists_vectors_expected = SparseVectorElementListArray_load(&size_b, filename_expected); 
  total_test_number = size_a;
 
  int i;
  for(i = 0; i < size_a; ++i) {
    printf("Test number %d out of %d\n", i+1, total_test_number);
    
    printf("Input      a_");
    SparseVectorElementList_print(lists_vectors_a[i]); 
    printf("Input      b_");
    SparseVectorElementList_print(lists_vectors_b[i]); 
    printf("Expected exp_");
    SparseVectorElementList_print(lists_vectors_expected[i]);

    SparseVectorElement* result_list = recursiveSum(lists_vectors_a[i], lists_vectors_b[i]);
    printf("Result   sum_");
    SparseVectorElementList_print(result_list); 
  
    int result = SparseVectorElementList_compare(result_list, lists_vectors_expected[i]);

    if(result > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
