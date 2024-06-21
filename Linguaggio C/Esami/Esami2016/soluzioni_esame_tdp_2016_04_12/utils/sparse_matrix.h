#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_

#ifdef ESERCIZIO_1
#include "../esercizio1/esercizio1.h"
#endif

#ifdef ESERCIZIO_2
#include "../esercizio2/esercizio2.h"
#endif

#ifdef ESERCIZIO_3
#include "../esercizio3/esercizio3.h"
#endif

void         SparseMatrix_print(SparseMatrix m);
SparseMatrix SparseMatrix_load(char* filename);
SparseMatrix SparseMatrix_alloc();
void         SparseMatrix_free(SparseMatrix m);
int          SparseMatrix_compare(SparseMatrix src1, SparseMatrix src2);

#endif
