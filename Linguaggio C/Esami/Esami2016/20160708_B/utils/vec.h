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
char* vectorc_read(int* n, char* filename);
void  vectorc_write(char* filename, char* v, int n);
char* vectorc_alloc(int n);
void  vectorc_free(char* v);
int   vectorc_compare(char* src1, char* src2, int n);

void vectori_print(int* v, int n);
int* vectori_read(int* n, char* filename);
void vectori_write(char* filename, int* v, int n);
int* vectori_alloc(int n);
void vectori_free(int* v);
int  vectori_compare(int* src1, int* src2, int n);
int* vectori_rand(int n, int max_value, int positive_only);

void   vectorf_print(float* v, int n);
float* vectorf_read(int* n, char* filename);
void   vectorf_write(char* filename, float* v, int n);
float* vectorf_alloc(int n);
void   vectorf_free(float* v);
int    vectorf_compare(float* src1, float* src2, int n);

#endif
