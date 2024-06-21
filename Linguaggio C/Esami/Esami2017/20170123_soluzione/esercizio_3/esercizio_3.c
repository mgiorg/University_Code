#include "esercizio_3.h"

NodoSCL* squaredValues(NodoSCL* l1, NodoSCL* l2){
  if(l1 && l2){
    NodoSCL* result = (NodoSCL*)malloc(sizeof(NodoSCL));
    result->info = l1->info * l2->info;
    result->next = squaredValues(l1->next, l2->next);
    return result;
  }
  else
    {
      return NULL;
    } 
}

