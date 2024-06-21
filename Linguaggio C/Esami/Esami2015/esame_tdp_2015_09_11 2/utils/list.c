#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void TipoSCL_print(TipoSCL l) {
  printf("list: ");
  while(l != NULL) {
    printf("%d ", l->info);
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
  while(fscanf(f, "%s", buffer) == 1) {
    list->next = TipoSCL_alloc();
    list = list->next;
    list->info = atoi(buffer);
    list->next = NULL;
  }
  list = gen_node->next;
  free(gen_node);

  return list;
}

TipoSCL TipoSCL_alloc() {
  return (TipoSCL) malloc(sizeof(NodoSCL));
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
    if(src1->info != src2->info) { return 0; }
    src1 = src1->next;
    src2 = src2->next;
  }
  if(src1 != NULL || src2 != NULL) { return 0; }

  return 1;
}
