#include <stdio.h>
#include <stdlib.h>

#include "../utils/image_utils.h"
#include "esercizio1.h"

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;
  int thresholds[10] = { 5, 3, 7, 1, 4, 3, 0, 6, 9, 2 };

  char buffer[1024];
  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i+1, total_test_number);

    printf("Threshold %d\n", thresholds[i]);
 
    sprintf(buffer, "images/image%d.txt", i);
    Image* source_image = Image_load(buffer);
    printf("Input ");
    Image_print(source_image);
    
    sprintf(buffer, "images/expected_image%d.txt", i);
    Image* expected_image = Image_load(buffer);
    printf("Expected Edge ");
    Image_print(expected_image);
    
    Image* result_image = Image_alloc(source_image->rows, source_image->cols);
    Image_extractEdges(result_image, source_image, thresholds[i]);
    printf("Result Edge ");
    Image_print(result_image);
  
    int result = Image_compare(expected_image, result_image);
    if(result > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else { 
      printf("FAILURE\n"); 
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    
    Image_free(source_image);
    Image_free(expected_image);
    Image_free(result_image);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
