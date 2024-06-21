#ifndef _MAT_H_
#define _MAT_H_

#include "../esercizio1/esercizio1.h"

void Mat_print(Mat* mat);
Mat* Mat_load(char* filename);
Mat* Mat_alloc(int rows, int cols);
void Mat_free(Mat* mat);
int  Mat_compare(Mat* src1, Mat* src2);

#endif



