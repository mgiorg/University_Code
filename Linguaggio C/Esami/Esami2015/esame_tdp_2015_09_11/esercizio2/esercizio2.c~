#include <stdlib.h>

#include "esercizio2.h"

int rotateList(int** v, TipoSCL src, int num) {
  if(src == NULL) {
    *v = NULL;
    return 0;
  }

  int l = 0;
  TipoSCL node = src;
  while(node != NULL) {
    l++;
    node = node->next;
  }

  *v = (int*)malloc(sizeof(int) * l);  
  int i;
  for(i = 0; i < l; ++i) {
    int pos = i + num;
    if(i + num >= l) { pos = i + num - l; }
    (*v)[pos] = src->info; 
    src = src->next;
  }

  return l;
}
