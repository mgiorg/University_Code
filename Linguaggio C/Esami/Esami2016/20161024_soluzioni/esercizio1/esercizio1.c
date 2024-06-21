#include "esercizio1.h"

void mat_rotate_90_clockwise(Mat* dest, Mat* src) {
  for(int r = 0; r < src->rows; ++r) {
    for(int c = 0; c < src->cols; ++c) {
      dest->row_ptrs[c][dest->cols - r - 1] = src->row_ptrs[r][c];
    }
  }
}
