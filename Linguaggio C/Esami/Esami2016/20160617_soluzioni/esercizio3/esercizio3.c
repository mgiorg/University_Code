#include "esercizio3.h"

#include <stdlib.h>

ListNode* list_multipliers(ListNode* src, int n) {
  if(src == NULL) {
    return NULL;
  }
  else if((src->value % n) == 0) {
    ListNode *list = list_multipliers(src->next, n);
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->value = src->value;
    node->next = list;
    return node;
  }
  else {
    return list_multipliers(src->next, n);
  }
}
