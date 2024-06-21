#include <stdlib.h>

#include "correttore_esercizio2.h"

ListNode* ground_truth(int* v, int size) {
  ListNode* gen_node = (ListNode*)calloc(1, sizeof(ListNode));
  gen_node->next = NULL;
  ListNode* list = gen_node;

  for(int i = 0; i < size - 1; ++i) {
    if(v[i] != v[i + 1]) {
      list->next = (ListNode*)calloc(1, sizeof(ListNode));
      list = list->next;
      list->value = i;
      list->next = NULL;
    }
  }
  
  list = gen_node->next;
  free(gen_node);

  return list;
}
