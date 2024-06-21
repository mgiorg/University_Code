#include "esercizio3.h"

#include <stdlib.h>

int compute_prefix_length(ListNode *l1, ListNode *l2) {
  if(l1 == NULL) {
    return 0;
  }
  else if(l2 == NULL) {
    return 0;
  }
  else if(l1->value != l2->value) {
    return 0;
  }
  else {
    return 1 + compute_prefix_length(l1->next, l2->next);
  }  
}
