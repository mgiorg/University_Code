#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"

void print(char* v, int dim) {
  int i;
  printf("vector: ");
  for(i = 0; i < dim; ++i) { printf("%c ", v[i]); }
  printf("\n");
}

char input_vectors[10][15] = { 
  "#_____###____##",
  "______###_#__##",
  "#_____####___##",
  "#_##__###_#__##",
  "#___#####____##",
  "#___##__#______",
  "###_____#_____#",
  "#__#__###____##",
  "______###______",
  "#_##__###_##_##",
};

char input_words[10][128] = { 
  "ciao\0",
  "pio\0",
  "jacopo\0",
  "a\0",
  "aeronautica\0",
  "polipo\0",
  "monte\0",
  "macchina\0",
  "scuola\0",
  "ultima\0",
};

int expected_returns[10] = { 3, 4, 0, 6, 0, 1, 2, 0, 2, 0 };

int main(int argc, char** argv) {  
  int successes = 0, total_test_number = 10;  
  int i;
  
  printf("\n");
  for(i = 0; i < total_test_number; ++i) { 
    printf("Searching for suitable spots for the word %s\n", input_words[i]);
    printf("Input ");
    print(input_vectors[i], 15); 
    printf("Expected: %d\n", expected_returns[i]);
    int result = find_spots(input_vectors[i], 15, input_words[i]);
    printf("Result: %d\n", result);    
    if(result == expected_returns[i]) {
      printf("SUCCESS\n");
      successes++;
    }
    else { printf("FAILURE\n"); }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
