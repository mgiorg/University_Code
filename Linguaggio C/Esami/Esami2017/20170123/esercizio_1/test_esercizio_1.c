#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"
#include "esercizio_1.h"

int main(int argc, char** argv) {
  const int total_test_number=10;
  int successes=0;
  int passed;
  int rep_r, rep_c;
  Mat* input_matrix, *dest;

  for(int i=0; i<total_test_number; ++i){
  
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);
    rep_r = 0;
    rep_c = 0;
    while(rep_r == 0 && rep_r < 5)
      rep_r=rand()%(i+2);
    while(rep_c == 0 && rep_c < 5)
      rep_c=rand()%(i+2);
    input_matrix=matrixGenerate((i+1)%4+1,(i+1)%4+1);
    printf("repeat for %i rows and %i cols\n",rep_r, rep_c);
    fflush(stdout);

    //compute student result
    dest = matrixRepeat(input_matrix, rep_r, rep_c);

    passed=checkIfGood(input_matrix, dest, rep_r, rep_c);
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
