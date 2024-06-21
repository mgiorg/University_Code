#include "correttore_esercizio1.h"

void ground_truth(Mat* dest, Mat* src) {
  for(int r = 0; r < src->rows; ++r) {
    for(int c = 0; c < src->cols; ++c) {
      float sum = 0.0f;
      for(int rr = 0; rr <= r; ++rr) {
	for(int cc = 0; cc <= c ; ++cc) {
	  sum += src->row_ptrs[rr][cc];
	}
      }
      dest->row_ptrs[r][c] = sum;
    }
  }
}
