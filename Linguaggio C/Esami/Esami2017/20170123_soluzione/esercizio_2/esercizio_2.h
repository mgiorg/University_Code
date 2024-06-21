#ifndef _ESERCIZIO_2_H_
#define _ESERCIZIO_2_H_

typedef struct NodoSCL {
  int value;
  int count;
  struct NodoSCL* next;
} NodoSCL;

//typedef NodoSCL* TipoSCL;

NodoSCL* computeFrequencies(int* v, int v_dim);


#endif
