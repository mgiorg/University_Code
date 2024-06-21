#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sparse_vector_utils.h"

void SparseVector_print(SparseVector* vec) {
  printf("vec\tdim: %d\n", vec->dimension); 
  int i;
  for(i = 0; i < vec->dimension; ++i) {
    SparseVectorElement* element = vec->values;
    while(element != NULL) {
      if(element->pos == i) {
	printf("\t%d, %f\n", element->pos, element->value);
	break;
      } 
      element = element->next;
    }
    if(element == NULL) {
      printf("\t%d, %f\n", i, 0.0f);
    }
  }
}

SparseVector* SparseVector_alloc(int dimension) {
  SparseVector* v = (SparseVector*) malloc(sizeof(SparseVector));
  v->dimension = dimension;
  v->values = NULL;
  return v;
}

void SparseVector_free(SparseVector* vec) {
  SparseVectorElement* n;
  SparseVectorElement* e = vec->values;
  while(e != NULL) {
    n = e->next;
    free(e);
    e = n;
  }
  free(vec);
}

int SparseVector_compare(SparseVector* vec_a, SparseVector* vec_b) {
  if(vec_a->dimension != vec_b->dimension) {
    return 0;  
  }

  float dec_round_factor = 1000.0f;
  SparseVectorElement* element_a = vec_a->values;
  while(element_a) {
    SparseVectorElement* element_b = vec_b->values;
    while(element_b) {
      if(element_b->pos == element_a->pos && 
	 round(element_b->value * dec_round_factor) / dec_round_factor == round(element_a->value * dec_round_factor) / dec_round_factor) {
	break;
      }
      element_b = element_b->next;      
    }
    if(element_b == NULL) { return 0; }
    element_a = element_a->next;
  }

  SparseVectorElement* element_b = vec_b->values;
  while(element_b) {
    SparseVectorElement* element_a = vec_a->values;
    while(element_a) {
      if(element_a->pos == element_b->pos && 
	 round(element_a->value * dec_round_factor) / dec_round_factor == round(element_b->value * dec_round_factor) / dec_round_factor) {
	break;
      }
      element_a = element_a->next;      
    }
    if(element_a == NULL) { return 0; }
    element_b = element_b->next;
  }

  return 1;
}
