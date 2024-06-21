#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "correttore_esercizio3.h"

int ground_truth(ListNode *l1, ListNode *l2) {
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
    return 1 + ground_truth(l1->next, l2->next);
  }  
}
