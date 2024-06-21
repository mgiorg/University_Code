#include <stdlib.h>
#include <stdio.h>

#include "vec.h"

void vectori_print(int* v, int n) { 
  printf("vector: ");
  int i;
  for(i = 0; i < n; ++i) {
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
  int* v = (int*) malloc(n * sizeof(int));
  return v;
}

void vectori_free(int* v) {
  free(v);
}

int vectori_compare(int* src1, int* src2, int n) {
  int i;
  for(i = 0; i < n; ++i) {
    if(src1[i] != src2[i]) { return 0; }
  }
  return 1;
}
