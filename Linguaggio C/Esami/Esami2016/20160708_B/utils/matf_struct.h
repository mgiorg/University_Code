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
Mat* Mat_read(char* filename);
void Mat_write(char* filename, Mat* mat);
Mat* Mat_alloc(int rows, int cols);
void Mat_free(Mat* mat);
int  Mat_compare(Mat* src1, Mat* src2);
Mat* Mat_zeros(int rows, int cols);
Mat* Mat_rand(int rows, int cols, float max_value, int positive_only);

#endif
