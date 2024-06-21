#include <math.h>

#include "esercizio1.h"

void matrix_compute_neighboor_sub(Mat* dest, Mat* src) {
  for(int r = 0; r < src->rows; ++r) {
    for(int c = 0; c < src->cols; ++c) {
      float sum = 0.0f;
      for(int rr = r - 1; rr <= r + 1 && rr < src->rows; ++rr) {
	for(int cc = c - 1; cc <= c + 1 && cc < src->cols; ++cc) {
	  if(rr >= 0 && cc >= 0 && !(rr == r && cc == c)) {
	    sum += src->row_ptrs[rr][cc];
	  }
	}
      }
      dest->row_ptrs[r][c] = src->row_ptrs[r][c] - sum;
    }
  }   
}
