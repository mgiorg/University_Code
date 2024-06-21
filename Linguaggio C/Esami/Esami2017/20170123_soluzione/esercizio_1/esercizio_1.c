#include "esercizio_1.h"
#include <stdlib.h>

Mat* allocaMatrice(int rows, int cols) {
  Mat* dest=(Mat*) malloc(sizeof(Mat));
  dest->rows=rows;
  dest->cols=cols;
  dest->row_ptrs=(int**)malloc(sizeof(int*)*rows);
  for (int r=0; r<rows; r++) {
    dest->row_ptrs[r]=(int*)malloc(sizeof(int)*cols);
  }
  return dest;
}


Mat* matrixRepeat(Mat* src, int num_row_blocks, int num_col_blocks) {
  Mat* dest = allocaMatrice(num_row_blocks*src->rows, num_col_blocks*src->cols);
  for (int r=0; r < dest->rows; r++)
    for (int c=0; c < dest->cols; c++) {
      dest->row_ptrs[r][c]=src->row_ptrs[r%src->rows][c%src->cols];
    }
  return dest;
}

