#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sparse_vector_element_utils.h"

SparseVectorElement** SparseVectorElementListArray_load(int* size, char* filename) {
  *size = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { *size = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read the number of lists to load... aborting!\n", filename);
    exit(-1);
  }

  if(*size == 0) { 
    printf("Error while reading file %s, either the number of lists to read is zero... aborting!\n", filename);
    exit(-1);
  }
  int i = 0;  
  SparseVectorElement** lists = (SparseVectorElement**) malloc(*size * sizeof(SparseVectorElement*));
  while(i < *size) { 
    fscanf(f, "%s", buffer);
    int num_elements = atoi(buffer);
    int k;
    lists[i] = NULL;
    for(k = 0; k < num_elements; ++k) {
      fscanf(f, "%s", buffer);
      float value = atof(buffer);
      if(value != 0.0f) {
	if(lists[i] == NULL) {
	  lists[i] = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
	  lists[i]->pos = k;
	  lists[i]->value = value;
	  lists[i]->next = NULL;
	}
	else {
	  SparseVectorElement* element = lists[i];
	  while(element->next != NULL) {
	    element = element->next;
	  }
	  element->next = (SparseVectorElement*) malloc(sizeof(SparseVectorElement));
	  element->next->pos = k;
	  element->next->value = value;
	  element->next->next = NULL;
	}
      }
    }
    i++;
  }

  return lists;
}

void SparseVectorElementList_print(SparseVectorElement* l) {
  printf("vec: "); 
  int i = 0;
  while(l) {
    if(i < l->pos) {
      printf("%0.02f ", 0.0f);
    } else {
      printf("%0.02f ", l->value);
      l = l->next;
    }
    i++;
  }
  printf("\n");
}

int SparseVectorElementList_compare(SparseVectorElement* l_a, SparseVectorElement* l_b) {
  SparseVectorElement* element_a = l_a;
  float dec_round_factor = 1000.0f;
  while(element_a) {
    SparseVectorElement* element_b = l_b;
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

  SparseVectorElement* element_b = l_b;
  while(element_b) {
    SparseVectorElement* element_a = l_a;
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
