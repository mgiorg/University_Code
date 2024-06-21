#include <stdlib.h>
#include <stdio.h>

#include "correttore_esercizio2.h"

ListNode* ground_truth(ListNode* l1, ListNode* l2) {
  ListNode* gen_node = (ListNode*)calloc(1, sizeof(ListNode));
  gen_node->next = NULL;
  ListNode* list = gen_node;
  while(l1 != NULL || l2 != NULL) {
    list->next = (ListNode*)calloc(1, sizeof(ListNode));
    list = list->next;
    list->next = NULL;
    if(l1 != NULL && l2 == NULL) {
      list->value = l1->value;
      l1 = l1->next;      
    }
    else if(l2 != NULL && l1 == NULL) {
      list->value = l2->value;
      l2 = l2->next;      
    }
    else {
      if(l1->value < l2->value) {
	list->value = l1->value;
	l1 = l1->next;
      }
      else {
	list->value = l2->value;
	l2 = l2->next;
      }
    }
  }
  
  list = gen_node->next;
  free(gen_node);

  return list;
}
