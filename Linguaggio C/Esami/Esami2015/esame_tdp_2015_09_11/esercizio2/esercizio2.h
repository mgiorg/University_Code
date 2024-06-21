#ifndef _ESERCIZIO2_H_
#define _ESERCIZIO2_H_

struct NodoSCL {
  int info;
  struct NodoSCL* next;
};
typedef NodoSCL* TipoSCL;

int rotateList(int** v, TipoSCL src, int num);

#endif
