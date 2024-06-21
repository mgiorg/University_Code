#include <stdlib.h>
#include <stdio.h>

#include "vec.h"

/**************************************************************************
 *                                 VECTORC                                *
 **************************************************************************/

void vectorc_print(char* v, int n) {
  for(int i = 0; i < n; ++i) {
    printf("%c ", v[i]);
  }
  printf("\n");
}

char* vectorc_load(int* n, char* filename) {
  *n = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { *n = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of elements... aborting!\n", filename);
    exit(-1);
  }
  if(*n == 0) {
    return NULL;
  }

  int i = 0;
  char* v = vectorc_alloc(*n);
  while(i < *n && fscanf(f, "%s", buffer) == 1) {
    v[i] = buffer[0];
    i++;
  }
  if(i != *n) {
    printf("Error while reading file %s, cannot read all vector values... aborting!\n", filename);
    exit(-1);
  }

  return v;
}

char* vectorc_alloc(int n) {
  char* v = (char*)calloc(n, sizeof(char));
  return v;
}

void vectorc_free(char* v) {
  free(v);
}

int vectorc_compare(char* src1, char* src2, int n) {
  for(int i = 0; i < n; ++i) {
    if(src1[i] != src2[i]) { return 0; }
  }
  return 1;
}

/**************************************************************************
 *                                 VECTORI                                *
 **************************************************************************/

void vectori_print(int* v, int n) {
  for(int i = 0; i < n; ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int* vectori_load(int* n, char* filename) {
  *n = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { *n = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of elements... aborting!\n", filename);
    exit(-1);
  }
  if(*n == 0) {
    return NULL;
  }

  int i = 0;
  int* v = vectori_alloc(*n);
  while(i < *n && fscanf(f, "%s", buffer) == 1) {
    v[i] = atoi(buffer);
    i++;
  }
  if(i != *n) {
    printf("Error while reading file %s, cannot read all vector values... aborting!\n", filename);
    exit(-1);
  }

  return v;
}

int* vectori_alloc(int n) {
  int* v = (int*)calloc(n, sizeof(int));
  return v;
}

void vectori_free(int* v) {
  free(v);
}

int vectori_compare(int* src1, int* src2, int n) {
  for(int i = 0; i < n; ++i) {
    if(src1[i] != src2[i]) { return 0; }
  }
  return 1;
}

void vectorf_print(float* v, int n) {
  for(int i = 0; i < n; ++i) {
    printf("%f ", v[i]);
  }
  printf("\n");
}

/**************************************************************************
 *                                 VECTORF                                *
 **************************************************************************/

float* vectorf_load(int* n, char* filename) {
  *n = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { *n = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of elements... aborting!\n", filename);
    exit(-1);
  }
  if(*n == 0) {
    return NULL;
  }

  int i = 0;
  float* v = vectorf_alloc(*n);
  while(i < *n && fscanf(f, "%s", buffer) == 1) {
    v[i] = atof(buffer);
    i++;
  }
  if(i != *n) {
    printf("Error while reading file %s, cannot read all vector values... aborting!\n", filename);
    exit(-1);
  }

  return v;
}

float* vectorf_alloc(int n) {
  float* v = (float*)calloc(n, sizeof(float));
  return v;
}

void vectorf_free(float* v) {
  free(v);
}

int vectorf_compare(float* src1, float* src2, int n) {
  for(int i = 0; i < n; ++i) {
    if((src1[i] - src2[i]) > 1e-3) { return 0; }
  }
  return 1;
}
