#include <stdlib.h>

#include "esercizio2.h"

ListNode* fetch_elements(ListNode* element_positions, int* v, int v_size) {
  ListNode* gen_node = (ListNode*)malloc(sizeof(ListNode));
  gen_node->next = NULL;
  ListNode* current_node = gen_node;

  while(element_positions != NULL) {
    current_node->next = (ListNode*)malloc(sizeof(ListNode));
    current_node = current_node->next;
    current_node->value = v[element_positions->value];
    current_node->next = NULL;
    element_positions = element_positions->next;
  }

  current_node = gen_node->next;
  free(gen_node);

  return current_node;
}
