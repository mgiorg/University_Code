#ifndef _VEC_H_
#define _VEC_H_

#ifdef ESERCIZIO_1
#include "../esercizio1/esercizio1.h"
#endif

#ifdef ESERCIZIO_2
#include "../esercizio2/esercizio2.h"
#endif

#ifdef ESERCIZIO_3
#include "../esercizio3/esercizio3.h"
#endif

void  vectorc_print(char* v, int n);
char* vectorc_load(int* n, char* filename);
char* vectorc_alloc(int n);
void  vectorc_free(char* v);
int   vectorc_compare(char* src1, char* src2, int n);

void vectori_print(int* v, int n);
int* vectori_load(int* n, char* filename);
int* vectori_alloc(int n);
void vectori_free(int* v);
int  vectori_compare(int* src1, int* src2, int n);

void   vectorf_print(float* v, int n);
float* vectorf_load(int* n, char* filename);
float* vectorf_alloc(int n);
void   vectorf_free(float* v);
int    vectorf_compare(float* src1, float* src2, int n);

#endif
