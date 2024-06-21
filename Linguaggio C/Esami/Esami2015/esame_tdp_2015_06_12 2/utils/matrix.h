#ifndef _MATRIX_H_
#define _MATRIX_H_

void matrixcPrint(char** m, int rows, int cols);
void matrixiPrint(int** m, int rows, int cols);
void matrixfPrint(float** m, int rows, int cols);

/* 
Expected file format:
row_number columns_number
value value value ... value
value value value ... value
.
.
.
value value value ... value
*/
char** matrixcLoad(int* rows, int* cols, char* filename);
int** matrixiLoad(int* rows, int* cols, char* filename);
float** matrixfLoad(int* rows, int* cols, char* filename);

char** matrixcAlloc(int rows, int cols);
int** matrixiAlloc(int rows, int cols);
float** matrixfAlloc(int rows, int cols);

void matrixcFree(char** m, int rows);
void matrixiFree(int** m, int rows);
void matrixfFree(float** m, int rows);

int matrixcCmp(char** src1, char** src2, int rows, int cols);
int matrixiCmp(int** src1, int** src2, int rows, int cols);
int matrixfCmp(float** src1, float** src2, int rows, int cols);

#endif



