#include <stdio.h>
#include <stdlib.h>

#include "../utils/matrix.h"
#include "esercizio1.h"

char* words[10] = {
  "PALLA\0",
  "PERCENTO\0",
  "CINCIO\0",
  "SCOLTA\0",
  "GETAE\0",
  "REFETTORI\0",
  "ADUNCO\0",
  "ABILITA\0",
  "ARI\0",
  "OROLOGIO\0",
};

int positions[10][4] = {
  0,  1, 10, 0,
  0,  4,  4, 1,
  1,  7,  6, 0,
  1,  6,  0, 1,
  1,  0,  5, 0,
  0, 11,  5, 1,
  1,  6, 11, 0,
  1,  5,  3, 1,
  0,  3,  0, 0,
  0,  8,  0, 1,
};

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;

  char buffer[1024];
  int rows, cols, i;
  printf("\n");
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i+1, total_test_number);
    if(positions[i][0] == 0) { printf("Insert the word %s horizontally in [%d, %d]\n", words[i], positions[i][1], positions[i][2]); }
    else { printf("Insert the word %s vertically in [%d, %d]\n", words[i], positions[i][1], positions[i][2]); }
    printf("Input:\n");
    sprintf(buffer, "matrices/matrix%d.txt", i);
    char** input_matrix = matrixcLoad(&rows, &cols, buffer);
    matrixcPrint(input_matrix, rows, cols);
    printf("Expected:\n");
    sprintf(buffer, "matrices/expected_matrix%d.txt", i);
    char** expected_matrix = matrixcLoad(&rows, &cols, buffer);
    matrixcPrint(expected_matrix, rows, cols);
    int inserted = insert_word(words[i], input_matrix, 12, 14, positions[i][1], positions[i][2], positions[i][0]);
    printf("Result:\n");
    matrixcPrint(input_matrix, rows, cols);
    int result = matrixcCmp(input_matrix, expected_matrix, rows, cols);
    if(result > 0 && inserted == positions[i][3]) {
      printf("SUCCESS\n");
      successes++;
    }
    else { printf("FAILURE\n"); }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    matrixcFree(input_matrix, rows);
    matrixcFree(expected_matrix, rows);
  }

  /* printf("Delete all occurences of 1 inside the input list\n"); */
  /* printf("Input   : "); */
  /* print(input[i]);  */
  /* printf("Expected: "); */
  /* print(expected[i]);  */
  /* int deleted = delete_occurrences(&input[i], 1); */
  /* printf("Result  : "); */
  /* print(input[i]); */
  /* printf("Number of deleted elements: %d\n", deleted); */
  /* int result = compare(input[i], expected[i]); */
  /* if(result > 0 && deleted == expected_deleted[i]) { */
  /*   printf("SUCCESS\n"); */
  /*   successes++; */
  /* } */
  /* else { printf("FAILURE\n"); } */
  /* printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number)); */
  /* printf("\n*************************************************\n\n"); */

  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
