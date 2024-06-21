#include <stdlib.h>
#include <stdio.h>

#include "esercizio1.h"

int matrixBlockCopy(Mat* dest, Mat* src, int start_row, int start_col) {
  if(start_row + src->rows > dest->rows) { return 0; }
  if(start_col + src->cols > dest->cols) { return 0; }

  int r, c;
  for(r = 0; r < src->rows; ++r) {
    for(c = 0; c < src->cols; ++c) {
      dest->row_ptrs[r + start_row][c + start_col] = src->row_ptrs[r][c];
    }
  }

  return src->rows * src->cols;
}
