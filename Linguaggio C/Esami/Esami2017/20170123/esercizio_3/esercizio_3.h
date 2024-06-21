#ifndef _ESERCIZIO_3_H_
#define _ESERCIZIO_3_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct NodoSCL {
  int info;
  struct NodoSCL* next;
} NodoSCL;

NodoSCL* squaredValues(NodoSCL* l1, NodoSCL* l2);

#endif
