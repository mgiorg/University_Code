#ifndef _MAT_H_
#define _MAT_H_

#ifdef ESERCIZIO_1
#include "../esercizio1/esercizio1.h"
#endif

#ifdef ESERCIZIO_2
#include "../esercizio2/esercizio2.h"
#endif

#ifdef ESERCIZIO_3
#include "../esercizio3/esercizio3.h"
#endif

void   matrixc_print(char** mat, int rows, int cols);
char** matrixc_read(int* rows, int* cols, char* filename);
void   matrixc_write(char* filename, char** mat, int rows, int cols);
char** matrixc_alloc(int rows, int cols);
void   matrixc_free(char** mat, int rows);
int    matrixc_compare(char** src1, char** src2, int rows, int cols);

void  matrixi_print(int** mat, int rows, int cols);
int** matrixi_read(int* rows, int* cols, char* filename);
void  matrixi_write(char* filename, int** mat, int rows, int cols);
int** matrixi_alloc(int rows, int cols);
void  matrixi_free(int** mat, int rows);
int   matrixi_compare(int** src1, int** src2, int rows, int cols);

void    matrixf_print(float** mat, int rows, int cols);
float** matrixf_read(int* rows, int* cols, char* filename);
void    matrixf_write(char* filename, float** mat, int rows, int cols);
float** matrixf_alloc(int rows, int cols);
void    matrixf_free(float** mat, int rows);
int     matrixf_compare(float** src1, float** src2, int rows, int cols);

#endif
