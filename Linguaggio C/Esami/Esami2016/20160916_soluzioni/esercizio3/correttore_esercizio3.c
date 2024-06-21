#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "correttore_esercizio3.h"

ListNode* ground_truth_aux(int* v, int size, int index) {
  if(index >= size) {
    return NULL;
  }
  else {
    ListNode *tail = ground_truth_aux(v, size, index + 1);    
    ListNode *new_node = (ListNode*)calloc(1, sizeof(ListNode));
    new_node->value = v[index] - v[index - 1];
    new_node->next = tail;
    return new_node;
  }
}

ListNode* ground_truth(int* v, int size) {
  if(size < 2) {
    return NULL;
  }  
  return ground_truth_aux(v, size, 1);
}
