#include <stdio.h>
#include <stdlib.h>

#include "esercizio2.h"
#include "../utils/sparse_vector_utils.h"

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;
  int set_elem_result;
  float get_elem_result;

  SparseVector* vec_a = SparseVector_alloc(6);
  vec_a->values = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  vec_a->values->pos = 0;
  vec_a->values->value = 2.5f;
  vec_a->values->next = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  vec_a->values->next->pos = 1;
  vec_a->values->next->value = -1.3f;
  vec_a->values->next->next = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  vec_a->values->next->next->pos = 5;
  vec_a->values->next->next->value = 4.0f;
  vec_a->values->next->next->next = NULL;
  printf("Vector a_");
  SparseVector_print(vec_a); 

  SparseVector* vec_b = SparseVector_alloc(6);
  printf("Vector b_");
  SparseVector_print(vec_b); 

  printf("\nCalling SparseVector_getElem(a_vec, 3)\n");
  printf("Expected: %f\n", 0.0f);
  get_elem_result = SparseVector_getElem(vec_a, 3);
  printf("Result:   %f\n", get_elem_result);
  if(get_elem_result == 0.0f) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  printf("Calling SparseVector_getElem(a_vec, 5)\n");
  printf("Expected: %f\n", vec_a->values->next->next->value);
  get_elem_result = SparseVector_getElem(vec_a, 5);
  printf("Result:   %f\n", get_elem_result);
  if(get_elem_result == vec_a->values->next->next->value) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  printf("Calling SparseVector_getElem(a_vec, 4)\n");
  printf("Expected: %f\n", 0.0f);
  get_elem_result = SparseVector_getElem(vec_a, 4);
  printf("Result:   %f\n", get_elem_result);
  if(get_elem_result == 0) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  printf("Calling SparseVector_getElem(a_vec, 1)\n");
  printf("Expected: %f\n", -1.3f);
  get_elem_result = SparseVector_getElem(vec_a, 1);
  printf("Result:   %f\n", get_elem_result);
  if(get_elem_result == -1.3f) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  SparseVector* set_expected_vec = SparseVector_alloc(6);
  printf("Calling SparseVector_setElem(b_vec, 9, 3.6f)\n");
  printf("Expected return value: %d\n", 0);
  printf("Expected ");
  SparseVector_print(set_expected_vec);   
  set_elem_result = SparseVector_setElem(vec_b, 9, 3.6f);
  printf("Result return value:   %d\n", set_elem_result);
  printf("Result ");
  SparseVector_print(vec_b);   
  if(set_elem_result == 0 && SparseVector_compare(vec_b, set_expected_vec)) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  set_expected_vec->values = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  set_expected_vec->values->pos = 2;
  set_expected_vec->values->value = 3.6f;
  set_expected_vec->values->next = NULL;
  printf("Calling SparseVector_setElem(b_vec, 2, 3.6f)\n");
  printf("Expected return value: %d\n", 1);
  printf("Expected ");
  SparseVector_print(set_expected_vec);   
  set_elem_result = SparseVector_setElem(vec_b, 2, 3.6f);
  printf("Result return value:   %d\n", set_elem_result);
  printf("Result ");
  SparseVector_print(vec_b);   
  if(set_elem_result == 1 && SparseVector_compare(vec_b, set_expected_vec)) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  set_expected_vec->values->next = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  set_expected_vec->values->next->pos = 0;
  set_expected_vec->values->next->value = -1.0f;
  set_expected_vec->values->next->next = NULL;
  printf("Calling SparseVector_setElem(b_vec, 0, -1.0f)\n");
  printf("Expected return value: %d\n", 1);
  printf("Expected ");
  SparseVector_print(set_expected_vec);   
  set_elem_result = SparseVector_setElem(vec_b, 0, -1.0f);
  printf("Result return value:   %d\n", set_elem_result);
  printf("Result ");
  SparseVector_print(vec_b);   
  if(set_elem_result == 1 && SparseVector_compare(vec_b, set_expected_vec)) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  SparseVector_free(set_expected_vec);
  set_expected_vec = SparseVector_alloc(6);
  set_expected_vec->values = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  set_expected_vec->values->pos = 0;
  set_expected_vec->values->value = 2.5f;
  set_expected_vec->values->next = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  set_expected_vec->values->next->pos = 1;
  set_expected_vec->values->next->value = -1.3f;
  set_expected_vec->values->next->next = NULL;
  printf("Calling SparseVector_setElem(a_vec, 5, 0.0f)\n");
  printf("Expected return value: %d\n", 1);
  printf("Expected ");
  SparseVector_print(set_expected_vec);   
  set_elem_result = SparseVector_setElem(vec_a, 5, 0.0f);
  printf("Result return value:   %d\n", set_elem_result);
  printf("Result ");
  SparseVector_print(vec_a);   
  if(set_elem_result == 1 && SparseVector_compare(vec_a, set_expected_vec)) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  printf("Calling SparseVector_getElem(a_vec, 0)\n");
  printf("Expected: %f\n", vec_a->values->value);
  get_elem_result = SparseVector_getElem(vec_a, 0);
  printf("Result:   %f\n", get_elem_result);
  if(get_elem_result == vec_a->values->value) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");

  set_expected_vec->values = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  set_expected_vec->values->pos = 2;
  set_expected_vec->values->value = 3.6f;
  set_expected_vec->values->next = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  set_expected_vec->values->next->pos = 0;
  set_expected_vec->values->next->value = -1.0f;
  set_expected_vec->values->next->next = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  set_expected_vec->values->next->next->pos = 1;
  set_expected_vec->values->next->next->value = 3.0f;
  set_expected_vec->values->next->next->next = NULL;
  printf("Calling SparseVector_setElem(b_vec, 1, 3.0f)\n");
  printf("Expected return value: %d\n", 1);
  printf("Expected ");
  SparseVector_print(set_expected_vec);   
  set_elem_result = SparseVector_setElem(vec_b, 1, 3.0f);
  printf("Result return value:   %d\n", set_elem_result);
  printf("Result ");
  SparseVector_print(vec_b);   
  if(set_elem_result == 1 && SparseVector_compare(vec_b, set_expected_vec)) {
    printf("SUCCESS\n");
    successes++;
  }
  else { 
    printf("FAILURE\n"); 
  }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");


  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
