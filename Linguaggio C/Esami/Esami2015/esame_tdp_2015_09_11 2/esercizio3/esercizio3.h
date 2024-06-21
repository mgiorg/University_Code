#ifndef _ESERCIZIO3_H_
#define _ESERCIZIO3_H_

struct NodoSCL {
  int info;
  struct NodoSCL* next;
};
typedef NodoSCL* TipoSCL;

TipoSCL minElements(TipoSCL l1, TipoSCL l2);

#endif
