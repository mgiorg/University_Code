#include <stdlib.h>

#include "esercizio2.h"

ListNode* lowerValues(Mat* m, int value) {
  ListNode* gen_node = (ListNode*)malloc(sizeof(ListNode));
  gen_node->next = NULL;
  ListNode* current_node = gen_node;
  int r, c;
  for(r = 0; r < m->rows; ++r) {
    for(c = 0; c < m->cols; ++c) {
      if(m->row_ptrs[r][c] < value) {
	current_node->next = (ListNode*)malloc(sizeof(ListNode));
	current_node = current_node->next;
	current_node->value = m->row_ptrs[r][c];
	current_node->next = NULL;
      }
    }
  }

  current_node = gen_node->next;
  free(gen_node);

  return current_node;
}
