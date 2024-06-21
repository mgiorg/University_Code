#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "mat.h"

/**************************************************************************
 *                                 MATRIXC                                *
 **************************************************************************/

void matrixc_print(char** mat, int rows, int cols) {
  printf("matrix %dx%d:\n", rows, cols);
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      printf("%c ", mat[r][c]);
    }
    printf("\n");
  }
}

char** matrixc_load(int* rows, int* cols, char* filename) {
  *rows = 0;
  *cols = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { *rows = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of rows... aborting!\n", filename);
    exit(-1);
  }
  if(fscanf(f, "%s", buffer) == 1) { *cols = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of cols... aborting!\n", filename);
    exit(-1);
  }
  if(*rows == 0 || *cols == 0) {
    printf("Error while reading file %s, either rows or columns number is zero... aborting!\n", filename);
    exit(-1);
  }

  int i = 0;
  char** mat = matrixc_alloc(*rows, *cols);
  while(i < (*rows) * (*cols) && fscanf(f, "%s", buffer) == 1) {
    int row = i / (*cols);
    int col = i % (*cols);
    mat[row][col] = buffer[0];
    i++;
  }
  if(i != (*rows) * (*cols)) {
    printf("Error while reading file %s, cannot read all matrix values... aborting!\n", filename);
    exit(-1);
  }

  return mat;
}

char** matrixc_alloc(int rows, int cols) {
  char** mat = (char**)calloc(rows, sizeof(char*));
  for(int i = 0; i < rows; ++i) {
    mat[i] = (char*)calloc(cols, sizeof(char));
  }
  return mat;
}

void matrixc_free(char** mat, int rows) {  
  for(int i = 0; i < rows; ++i) {
    free(mat[i]);
  }
  free(mat);
}

int matrixc_compare(char** src1, char** src2, int rows, int cols) {    
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      if(src1[r][c] != src2[r][c]) { return 0; }
    }
  }
  return 1;
}

/**************************************************************************
 *                                 MATRIXI                                *
 **************************************************************************/

void matrixi_print(int** mat, int rows, int cols) {
  printf("matrix %dx%d:\n", rows, cols);
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      printf("%d ", mat[r][c]);
    }
    printf("\n");
  }
}

int** matrixi_load(int* rows, int* cols, char* filename) {
  *rows = 0;
  *cols = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { *rows = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of rows... aborting!\n", filename);
    exit(-1);
  }
  if(fscanf(f, "%s", buffer) == 1) { *cols = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of cols... aborting!\n", filename);
    exit(-1);
  }
  if(*rows == 0 || *cols == 0) {
    printf("Error while reading file %s, either rows or columns number is zero... aborting!\n", filename);
    exit(-1);
  }

  int i = 0;
  int** mat = matrixi_alloc(*rows, *cols);
  while(i < (*rows) * (*cols) && fscanf(f, "%s", buffer) == 1) {
    int row = i / (*cols);
    int col = i % (*cols);
    mat[row][col] = atoi(buffer);
    i++;
  }
  if(i != (*rows) * (*cols)) {
    printf("Error while reading file %s, cannot read all matrix values... aborting!\n", filename);
    exit(-1);
  }

  return mat;
}

int** matrixi_alloc(int rows, int cols) {
  int** mat = (int**)calloc(rows, sizeof(int*));
  for(int i = 0; i < rows; ++i) {
    mat[i] = (int*)calloc(cols, sizeof(int));
  }
  return mat;
}

void matrixi_free(int** mat, int rows) {
  for(int i = 0; i < rows; ++i) {
    free(mat[i]);
  }
  free(mat);
}

int matrixi_compare(int** src1, int** src2, int rows, int cols) {
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      if(src1[r][c] != src2[r][c]) { return 0; }
    }
  }
  return 1;
}


/**************************************************************************
 *                                 MATRIXF                                *
 **************************************************************************/

void matrixf_print(float** mat, int rows, int cols) {
  printf("matrix %dx%d:\n", rows, cols);
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      printf("%f ", mat[r][c]);
    }
    printf("\n");
  }
}

float** matrixf_load(int* rows, int* cols, char* filename) {
  *rows = 0;
  *cols = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { *rows = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of rows... aborting!\n", filename);
    exit(-1);
  }
  if(fscanf(f, "%s", buffer) == 1) { *cols = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of cols... aborting!\n", filename);
    exit(-1);
  }
  if(*rows == 0 || *cols == 0) {
    printf("Error while reading file %s, either rows or columns number is zero... aborting!\n", filename);
    exit(-1);
  }

  int i = 0;
  float** mat = matrixf_alloc(*rows, *cols);
  while(i < (*rows) * (*cols) && fscanf(f, "%s", buffer) == 1) {
    int row = i / (*cols);
    int col = i % (*cols);
    mat[row][col] = atof(buffer);
    i++;
  }
  if(i != (*rows) * (*cols)) {
    printf("Error while reading file %s, cannot read all matrix values... aborting!\n", filename);
    exit(-1);
  }

  return mat;
}

float** matrixf_alloc(int rows, int cols) {
  float** mat = (float**)calloc(rows, sizeof(float*));
  for(int i = 0; i < rows; ++i) {
    mat[i] = (float*)calloc(cols, sizeof(int));
  }
  return mat;
}

void matrixf_free(float** mat, int rows) {
  for(int i = 0; i < rows; ++i) {
    free(mat[i]);
  }
  free(mat);
}

int matrixf_compare(float** src1, float** src2, int rows, int cols) {
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      if((src1[r][c] - src2[r][c]) > 1e-3) { return 0; }
    }
  }
  return 1;
}
