#include <stdlib.h>
#include <string.h>

#include "esercizio2.h"

int add_word(TipoSCL* array, int dim, char* word) {
  int length = strlen(word);
  length--;
  if(length >= dim) { return 0; }
  
  if(array[length] == NULL) {
    array[length] = (TipoSCL) malloc(sizeof(NodoSCL));
    array[length]->info = word;
    array[length]->next = NULL;
    return 1;
  }

  TipoSCL elem = array[length];
  while(elem->next != NULL) {
    elem = elem->next;
  }
  elem->next = (TipoSCL) malloc(sizeof(NodoSCL));
  elem->next->info = word;
  elem->next->next = NULL;
  return 1;
}
