#include <stdlib.h>

#include "esercizio3.h"

SparseVectorElement* recursiveSum(SparseVectorElement* l1, SparseVectorElement* l2) {
  if(l1 == NULL && l2 == NULL) {
    return NULL;
  }
  SparseVectorElement* element = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
  if(l1 == NULL) {    
    element->pos = l2->pos;
    element->value = l2->value;
    element->next = recursiveSum(NULL, l2->next);
  } else if(l2 == NULL) {
    element->pos = l1->pos;
    element->value = l1->value;
    element->next = recursiveSum(l1->next, NULL);
  } else if(l1->pos < l2->pos) {
    element->pos = l1->pos;
    element->value = l1->value;
    element->next = recursiveSum(l1->next, l2);
  } else if(l1->pos > l2->pos) {
    element->pos = l2->pos;
    element->value = l2->value;
    element->next = recursiveSum(l1, l2->next);
  } else {
    if(l1->value + l2->value != 0.0f) {
      element->pos = l1->pos;
      element->value = l1->value + l2->value;
      element->next = recursiveSum(l1->next, l2->next);
    } else {
      free(element);
      return recursiveSum(l1->next, l2->next);
    }
  }

  return element;
}
