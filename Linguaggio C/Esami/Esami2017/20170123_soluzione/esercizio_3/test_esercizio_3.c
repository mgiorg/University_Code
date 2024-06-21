#include <stdio.h>
#include <stdlib.h>
#include "esercizio_3.h"
#include "correttore_esercizio_3.h"

int main(int argc, char** argv) {
  const int total_test_number=10;
  int successes=0;
  int passed;
  int size=0;
  
  for(int test=0; test<total_test_number; ++test){

    printf("Test number %d out of %d\n", test + 1, total_test_number);
    fflush(stdout);
    size=test+1;

    NodoSCL* l1_root = (NodoSCL*)malloc(sizeof(NodoSCL));
    NodoSCL* l2_root = (NodoSCL*)malloc(sizeof(NodoSCL));

    l1_root->info=-1;
    l2_root->info=-1;
    
    for(int i=0; i<size; ++i){
      addRandomNode(l1_root);
      addRandomNode(l2_root);
    }

    printf("\ninput\n");
    printSCL(l1_root);
    printSCL(l2_root);
    
    NodoSCL* gt = squaredGTValues(l1_root, l2_root);
    printf("expected output\n");
    printSCL(gt);
    fflush(stdout);
    
    NodoSCL* out = squaredValues(l1_root, l2_root);
    printf("student output\n");
    printSCL(out);
    fflush(stdout);
    
    passed = compareNodoSCLPtr(gt, out);
    if (passed){
      printf("SUCCESS\n");
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
