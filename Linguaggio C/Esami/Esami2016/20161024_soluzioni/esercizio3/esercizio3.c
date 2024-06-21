#include <stdlib.h>
#include <math.h>

#include "esercizio3.h"

float recursive_squared_norm(ListNode* l) {
  if(l == NULL) {
    return 0;
  }
  else {
    return (l->value * l->value) + recursive_squared_norm(l->next);
  }
}

float recursive_norm(ListNode* l) {
  return sqrtf(recursive_squared_norm(l));
}
