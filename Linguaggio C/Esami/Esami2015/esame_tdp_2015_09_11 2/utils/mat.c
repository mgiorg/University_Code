#include <stdlib.h>
#include <stdio.h>

#include "mat.h"

void Mat_print(Mat* mat) {
  printf("matrix %dx%d:\n", mat->rows, mat->cols);
  int r, c;
  for(r = 0; r < mat->rows; ++r) {
    for(c = 0; c < mat->cols; ++c) {
      printf("%d\t", mat->row_ptrs[r][c]);
    }
    printf("\n");
  }
}

Mat* Mat_load(char* filename) {
  int rows = 0;
  int cols = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { rows = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of rows... aborting!\n", filename);
    exit(-1);
  }
  if(fscanf(f, "%s", buffer) == 1) { cols = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of cols... aborting!\n", filename);
    exit(-1);
  }
  if(rows == 0 || cols == 0) { 
    printf("Error while reading file %s, either rows or columns number is zero... aborting!\n", filename);
    exit(-1);
  }

  int i = 0;  
  Mat* mat = Mat_alloc(rows, cols);
  while(i < mat->rows * mat->cols && fscanf(f, "%s", buffer) == 1) {
    int row = i / mat->cols;
    int col = i % mat->cols;
    mat->row_ptrs[row][col] = atoi(buffer);
    i++;
  }
  if(i != mat->rows * mat->cols) {
    printf("Error while reading file %s, cannot read all matrix values... aborting!\n", filename);
    exit(-1);
  }

  return mat;
}

Mat* Mat_alloc(int rows, int cols) {
  Mat* mat = (Mat*) malloc(sizeof(Mat));
  mat->rows = rows;
  mat->cols = cols;
  mat->row_ptrs = (int**) malloc(mat->rows * sizeof(int*));
  int i;
  for(i = 0; i < mat->rows; ++i) {
    mat->row_ptrs[i] = (int*) malloc(mat->cols * sizeof(int));
  }
  return mat;
}

void Mat_free(Mat* mat) {
  int i;
  for(i = 0; i < mat->rows; ++i) {
    free(mat->row_ptrs[i]);
  }
  free(mat->row_ptrs);
  free(mat);
}

int Mat_compare(Mat* src1, Mat* src2) {
  if(src1->rows != src2->rows || src1->cols != src2->cols) { return 0; }

  int r, c;
  for(r = 0; r < src1->rows; ++r) {
    for(c = 0; c < src1->cols; ++c) {
      if(src1->row_ptrs[r][c] != src2->row_ptrs[r][c]) { return 0; }
    }
  }
  return 1;
}
