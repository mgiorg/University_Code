#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esercizio2.h"

int successes = 0, total_test_number = 10, added = -1;  
int i, expected_return[10] = { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 };
char* words[10] = { "qui\0", "pluto\0", "pippo\0", "topolino\0", "olaf\0", "olaf\0", "a\0", "pi\0", "quo\0", "qua\0" };
TipoSCL input_array[5] = { NULL, NULL, NULL, NULL, NULL };
TipoSCL expected_array[5] = { NULL, NULL, NULL, NULL, NULL };

int is_equal_scl(TipoSCL scl1, TipoSCL scl2) {
  if(scl1 == NULL && scl2 == NULL) { return 1; }
  if(scl1 == NULL && scl2 != NULL) { return 0; }
  if(scl1 != NULL && scl2 == NULL) { return 0; }

  while(scl1 != NULL && scl2 != NULL) {
    if(strcmp(scl1->info, scl2->info) != 0) { return 0; }
    scl1 = scl1->next;
    scl2 = scl2->next;
  }

  if(scl1 != NULL || scl2 != NULL) { return 0; }

  return 1;
}

int is_equal_scl_array(TipoSCL* array1, TipoSCL* array2, int dim) {
  int i;
  for(i = 0; i < dim; ++i) {
    if(is_equal_scl(array1[i], array2[i]) == 0) { return 0; }
  }
  
  return 1;
}

void print(TipoSCL* array, int dim) {
  int i;
  for(i = 0; i < dim; ++i) {
    printf("words of length %d: ", i+1);
    TipoSCL scl = array[i];
    if(scl == NULL) { 
      printf("[ ]\n"); 
      continue;
    }
    
    printf("[ ");
    while(scl->next != NULL) {
      printf("%s -> ", scl->info);
      scl = scl->next;
    }
    printf("%s ]\n", scl->info);
  }
}

void check_result() {  
  printf("Expected:\n");
  print(expected_array, 5);
  printf("Result:\n");
  print(input_array, 5);
  int result = is_equal_scl_array(input_array, expected_array, 5);
  if(result > 0 && added == expected_return[i]) {
    printf("SUCCESS\n");
    successes++;
  }
  else { printf("FAILURE\n"); }
  printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
  printf("\n*************************************************\n\n");
  i++;
}

int main(int argc, char** argv) {  
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[0]);
  check_result();

  input_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> info = words[0];
  input_array[2] -> next = NULL;
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  expected_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> info = words[1];
  expected_array[4] -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[1]);
  check_result();

  input_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> info = words[0];
  input_array[2] -> next = NULL;
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  input_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> info = words[1];
  input_array[4] -> next = NULL;
  expected_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> info = words[1];
  expected_array[4] -> next = NULL;
  expected_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> next -> info = words[2];
  expected_array[4] -> next -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[2]);
  check_result();

  input_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> next -> info = words[2];
  input_array[4] -> next -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[3]);
  check_result();

  input_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> info = words[0];
  input_array[2] -> next = NULL;
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  input_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> info = words[1];
  input_array[4] -> next = NULL;
  expected_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> info = words[1];
  expected_array[4] -> next = NULL;
  input_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> next -> info = words[2];
  input_array[4] -> next -> next = NULL;
  expected_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> next -> info = words[2];
  expected_array[4] -> next -> next = NULL;
  expected_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> info = words[4];
  expected_array[3] -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[4]);
  check_result();

  input_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> info = words[0];
  input_array[2] -> next = NULL;
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  input_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> info = words[1];
  input_array[4] -> next = NULL;
  expected_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> info = words[1];
  expected_array[4] -> next = NULL;
  input_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> next -> info = words[2];
  input_array[4] -> next -> next = NULL;
  expected_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> next -> info = words[2];
  expected_array[4] -> next -> next = NULL;
  input_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> info = words[4];
  input_array[3] -> next = NULL;
  expected_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> info = words[4];
  expected_array[3] -> next = NULL;
  expected_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> next -> info = words[5];
  expected_array[3] -> next -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[5]);
  check_result();

  input_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> info = words[0];
  input_array[2] -> next = NULL;
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  input_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> info = words[1];
  input_array[4] -> next = NULL;
  expected_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> info = words[1];
  expected_array[4] -> next = NULL;
  input_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> next -> info = words[2];
  input_array[4] -> next -> next = NULL;
  expected_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> next -> info = words[2];
  expected_array[4] -> next -> next = NULL;
  input_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> info = words[4];
  input_array[3] -> next = NULL;
  expected_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> info = words[4];
  expected_array[3] -> next = NULL;
  input_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> next -> info = words[5];
  input_array[3] -> next -> next = NULL;
  expected_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> next -> info = words[5];
  expected_array[3] -> next -> next = NULL;
  expected_array[0] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[0] -> info = words[6];
  expected_array[0] -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[6]);
  check_result();

  input_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> info = words[0];
  input_array[2] -> next = NULL;
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  input_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> info = words[1];
  input_array[4] -> next = NULL;
  expected_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> info = words[1];
  expected_array[4] -> next = NULL;
  input_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> next -> info = words[2];
  input_array[4] -> next -> next = NULL;
  expected_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> next -> info = words[2];
  expected_array[4] -> next -> next = NULL;
  input_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> info = words[4];
  input_array[3] -> next = NULL;
  expected_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> info = words[4];
  expected_array[3] -> next = NULL;
  input_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> next -> info = words[5];
  input_array[3] -> next -> next = NULL;
  expected_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> next -> info = words[5];
  expected_array[3] -> next -> next = NULL;
  input_array[0] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[0] -> info = words[6];
  input_array[0] -> next = NULL;
  expected_array[0] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[0] -> info = words[6];
  expected_array[0] -> next = NULL;
  expected_array[1] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[1] -> info = words[7];
  expected_array[1] -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[7]);
  check_result();

  input_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> info = words[0];
  input_array[2] -> next = NULL;
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  input_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> info = words[1];
  input_array[4] -> next = NULL;
  expected_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> info = words[1];
  expected_array[4] -> next = NULL;
  input_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> next -> info = words[2];
  input_array[4] -> next -> next = NULL;
  expected_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> next -> info = words[2];
  expected_array[4] -> next -> next = NULL;
  input_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> info = words[4];
  input_array[3] -> next = NULL;
  expected_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> info = words[4];
  expected_array[3] -> next = NULL;
  input_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> next -> info = words[5];
  input_array[3] -> next -> next = NULL;
  expected_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> next -> info = words[5];
  expected_array[3] -> next -> next = NULL;
  input_array[0] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[0] -> info = words[6];
  input_array[0] -> next = NULL;
  expected_array[0] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[0] -> info = words[6];
  expected_array[0] -> next = NULL;
  input_array[1] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[1] -> info = words[7];
  input_array[1] -> next = NULL;
  expected_array[1] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[1] -> info = words[7];
  expected_array[1] -> next = NULL;
  expected_array[2] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> next -> info = words[8];
  expected_array[2] -> next -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[8]);
  check_result();

  input_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> info = words[0];
  input_array[2] -> next = NULL;
  expected_array[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> info = words[0];
  expected_array[2] -> next = NULL;
  input_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> info = words[1];
  input_array[4] -> next = NULL;
  expected_array[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> info = words[1];
  expected_array[4] -> next = NULL;
  input_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[4] -> next -> info = words[2];
  input_array[4] -> next -> next = NULL;
  expected_array[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[4] -> next -> info = words[2];
  expected_array[4] -> next -> next = NULL;
  input_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> info = words[4];
  input_array[3] -> next = NULL;
  expected_array[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> info = words[4];
  expected_array[3] -> next = NULL;
  input_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[3] -> next -> info = words[5];
  input_array[3] -> next -> next = NULL;
  expected_array[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[3] -> next -> info = words[5];
  expected_array[3] -> next -> next = NULL;
  input_array[0] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[0] -> info = words[6];
  input_array[0] -> next = NULL;
  expected_array[0] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[0] -> info = words[6];
  expected_array[0] -> next = NULL;
  input_array[1] = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[1] -> info = words[7];
  input_array[1] -> next = NULL;
  expected_array[1] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[1] -> info = words[7];
  expected_array[1] -> next = NULL;
  input_array[2] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input_array[2] -> next -> info = words[8];
  input_array[2] -> next -> next = NULL;
  expected_array[2] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> next -> info = words[8];
  expected_array[2] -> next -> next = NULL;
  expected_array[2] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected_array[2] -> next -> next -> info = words[9];
  expected_array[2] -> next -> next -> next = NULL;
  printf("\n");
  printf("Inserting the word %s\n", words[i]);
  printf("Input:\n");
  print(input_array, 5);
  added = add_word(input_array, 5, words[9]);
  check_result();  

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
