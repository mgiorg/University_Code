#ifndef _ESERCIZIO2_H_
#define _ESERCIZIO2_H_

struct ElemSCL{
  char* info;
  struct ElemSCL* next;
};
typedef struct ElemSCL NodoSCL;
typedef NodoSCL* TipoSCL;

int add_word(TipoSCL* array, int dim, char* word);

#endif
