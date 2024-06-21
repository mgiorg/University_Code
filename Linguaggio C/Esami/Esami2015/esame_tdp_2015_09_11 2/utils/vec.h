#ifndef _VEC_H_
#define _VEC_H_

#include "../esercizio1/esercizio1.h"

void vectori_print(int* v, int n);
int* vectori_load(int* n, char* filename);
int* vectori_alloc(int n);
void vectori_free(int* v);
int  vectori_compare(int* src1, int* src2, int n);

#endif



