#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "sparse_matrix.h"

void SparseMatrix_print(SparseMatrix m) {
  while(m != NULL) {
    printf("[%d, %d, %f] ", m->row, m->col, m->value);
    m = m->next;
  }
  printf("\n");
}

SparseMatrix SparseMatrix_load(char* filename) {
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  SparseMatrix gen_node = SparseMatrix_alloc();
  gen_node->next = NULL;
  SparseMatrix mat = gen_node;
  int i = 0;
  while(fscanf(f, "%s", buffer) == 1) {
    if(i % 3 == 0) {
      mat->next = SparseMatrix_alloc();
      mat = mat->next;
      mat->row = atoi(buffer);
      mat->next = NULL;
    }
    else if(i % 3 == 1) {
      mat->col = atoi(buffer);
    }
    else {
      mat->value = atof(buffer);
    }
    i++;
  }
  mat = gen_node->next;
  free(gen_node);

  return mat;
}

SparseMatrix SparseMatrix_alloc() {
  return (SparseMatrix)calloc(1, sizeof(SparseMatrixElement));
}

void SparseMatrix_free(SparseMatrix m) {
  while(m != NULL) {
    SparseMatrix tmp = m;
    m = m->next;
    free(tmp);
  }
}

int SparseMatrix_compare(SparseMatrix src1, SparseMatrix src2) {
  while(src1 != NULL) {
    int found = 0;
    SparseMatrix src2_it = src2;
    while(src2_it != NULL) {
      if(src1->row == src2_it->row &&
	 src1->col == src2_it->col &&
	 src1->value - src2_it->value < 1e-3) { 
	found = 1;
	break;
      }
      src2_it = src2_it->next;
    }
    if(!found) {
      return 0;
    }
    src1 = src1->next;
  }
  
  return 1;
}
