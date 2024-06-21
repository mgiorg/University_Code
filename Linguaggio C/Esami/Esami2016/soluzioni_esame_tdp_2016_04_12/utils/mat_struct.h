#ifndef _MAT_STRUCT_H_
#define _MAT_STRUCT_H_

#ifdef ESERCIZIO_1
#include "../esercizio1/esercizio1.h"
#endif

#ifdef ESERCIZIO_2
#include "../esercizio2/esercizio2.h"
#endif

#ifdef ESERCIZIO_3
#include "../esercizio3/esercizio3.h"
#endif

void Mat_print(Mat* mat);
Mat* Mat_load(char* filename);
Mat* Mat_alloc(int rows, int cols);
void Mat_free(Mat* mat);
int  Mat_compare(Mat* src1, Mat* src2);

#endif



