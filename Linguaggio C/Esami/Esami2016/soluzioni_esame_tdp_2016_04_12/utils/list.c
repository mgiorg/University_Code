#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "list.h"

void TipoSCL_print(TipoSCL l) {
  while(l != NULL) {
    printf("[%d, %c] ", l->i, l->c);
    l = l->next;
  }
  printf("\n");
}

TipoSCL TipoSCL_load(char* filename) {
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  TipoSCL gen_node = TipoSCL_alloc();
  gen_node->next = NULL;
  TipoSCL list = gen_node;
  int i = 0;
  while(fscanf(f, "%s", buffer) == 1) {
    if(i % 2 == 0) {
      list->next = TipoSCL_alloc();
      list = list->next;
      list->i = atoi(buffer);
      list->next = NULL;
    }
    else {
      list->c = buffer[0];
    }
    i++;
  }
  list = gen_node->next;
  free(gen_node);

  return list;
}

TipoSCL TipoSCL_alloc() {
  return (TipoSCL)calloc(1, sizeof(NodoSCL));
}

void TipoSCL_free(TipoSCL l) {
  while(l != NULL) {
    TipoSCL tmp = l;
    l = l->next;
    free(tmp);
  }
}

int TipoSCL_compare(TipoSCL src1, TipoSCL src2) {
  while(src1 != NULL && src2 != NULL) {
    if(src1->i != src2->i) { return 0; }
    if(src1->c != src2->c) { return 0; }
    src1 = src1->next;
    src2 = src2->next;
  }
  if(src1 != NULL || src2 != NULL) { return 0; }

  return 1;
}
