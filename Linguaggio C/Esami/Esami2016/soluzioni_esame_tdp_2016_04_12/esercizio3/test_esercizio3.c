#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"
#include "correttore_esercizio3.h"
#include "../utils/sparse_matrix.h"

int main(int argc, char** argv) {
    int total_test_number = 10, successes = 0;
    
    char buffer[1024];
    int i;
    float result;
    for(i = 0; i < total_test_number; ++i) {
        printf("Test number %d out of %d\n", i + 1, total_test_number);

        sprintf(buffer, "data/source_sparse_mat_%d.txt", i);
        SparseMatrix source_sparse_mat = SparseMatrix_load(buffer);
        printf("source sparse matrix: ");
        SparseMatrix_print(source_sparse_mat);

	float gt_result = ground_truth(source_sparse_mat);
	printf("expected result: %f\n", gt_result);
        
        result = sparse_matrix_diagonal_sum(source_sparse_mat);
        printf("output resut: %f\n", result);

        if(result == gt_result) {
	  printf("SUCCESS\n");
	  successes++;
        }
        else {
            printf("FAILURE\n");
        }
        printf("Current success rate: %0.02f%%\n", 
	       (float)(successes) * 100.0f/ (float)(total_test_number));
        printf("\n*************************************************\n\n");

        SparseMatrix_free(source_sparse_mat);
    }

    printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

    return 0;
}
