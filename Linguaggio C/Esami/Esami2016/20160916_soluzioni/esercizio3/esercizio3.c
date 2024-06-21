#include <stdlib.h>

#include "esercizio3.h"

ListNode* compute_derivative_aux(int* v, int size, int index) {
  if(index >= size) {
    return NULL;
  }
  else {
    ListNode *tail = compute_derivative_aux(v, size, index + 1);    
    ListNode *new_node = (ListNode*)calloc(1, sizeof(ListNode));
    new_node->value = v[index] - v[index - 1];
    new_node->next = tail;
    return new_node;
  }
}

ListNode* compute_derivative(int* v, int size) {
  if(size < 2) {
    return NULL;
  }  
  return compute_derivative_aux(v, size, 1);
}
