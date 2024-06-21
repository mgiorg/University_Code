#include <stdlib.h>
#include <math.h>

#include "correttore_esercizio3.h"

float ground_truth_aux(ListNode* l) {
  if(l == NULL) {
    return 0;
  }
  else {
    return (l->value * l->value) + ground_truth_aux(l->next);
  }
}

float ground_truth(ListNode* l) {
  return sqrtf(ground_truth_aux(l));
}
