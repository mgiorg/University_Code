#include <stdio.h>
#include "esercizio_2.h"
#include "correttore_esercizio_2.h"
#include <stdlib.h>

int main(int argc, char** argv) {
  const int total_test_number=10;
  int successes=0;
  int passed;
  int size=0;

  for(int i=0; i<total_test_number; ++i){

    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);
    size = i+1;
    int v[size];

    printf("input string: ");
    for(int j=0; j<size; ++j){
      v[j] = rand()%4;
      printf("%i ", v[j]);
    }
    printf("\n");
    fflush(stdout);

    NodoSCL* gt_out = computeGTFrequencies(v,size);
    printf("expected output\n");
    printNodoSCLPtr(gt_out);
    fflush(stdout);

    NodoSCL* out = computeFrequencies(v,size);
    printf("\n\nstudent output\n");
    printNodoSCLPtr(out);
    fflush(stdout);

    passed = compareNodoSCLPtr(gt_out, out);
    if (passed){
      printf("\n\nSUCCESS\n");
      fflush(stdout);
      successes++;
    }
    else{
      printf("FAILURE\n");
    }

    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    fflush(stdout);
    printf("\n*************************************************\n\n");
    fflush(stdout);
    
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);
 
  return 0;
}
