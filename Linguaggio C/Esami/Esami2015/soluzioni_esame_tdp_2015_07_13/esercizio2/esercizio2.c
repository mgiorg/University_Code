#include <stdlib.h>
#include <cstddef>

#include "esercizio2.h"

SparseVectorElement** SparseVector_getElemAt(SparseVector* vec, int pos) {
  if(pos >= vec->dimension) { return NULL; }

  SparseVectorElement** element = &vec->values;
  while(*element) {
    if((*element)->pos == pos) { 
      return element; 
    } 
    element = &(*element)->next;
  }
  return NULL;
}

float SparseVector_getElem(SparseVector* vec, int pos) {
  SparseVectorElement** element = SparseVector_getElemAt(vec, pos);
  if(element != NULL) {
    return (*element)->value;
  } else {
    return 0;
  }
}

int SparseVector_setElem(SparseVector* vec, int pos, float value) {  
  if(pos >= vec->dimension) { 
    return 0; 
  }

  SparseVectorElement** element = SparseVector_getElemAt(vec, pos);
  if(element == NULL) {
    if(value != 0) {
      SparseVectorElement* new_element = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
      new_element->pos = pos;
      new_element->value = value;
      new_element->next = vec->values;
      vec->values = new_element;
    }
  } else {
    if(value != 0) {
      (*element)->value = value;
    } else {
      SparseVectorElement* tmp = *element;
      *element = (*element)->next;
      free(tmp);
    }
  }
 
  return 1;
}
