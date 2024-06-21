#include <stdlib.h>
#include <stdio.h>

#include "esercizio1.h"

char isEdge(Image* image, int row, int col, char threshold) {
  int r_min=row-1;
  if (r_min<0)
    r_min=0;
  int r_max=row+1;
  if (r_max>=image->rows)
    r_max=image->rows-1;
  int c_min=col-1;
  if (c_min<0)
    c_min=0;
  int c_max=col+1;
  if (c_max>=image->cols)
    c_max=image->cols-1;

  char v=image->row_ptrs[row][col];
  for (int r=r_min; r<=r_max; r++)
    for (int c=c_min; c<=c_max; c++) {
      int delta=v-image->row_ptrs[r][c];
      if (delta>threshold || delta<-threshold)
	return 1;
    }
  return 0;
}


void Image_extractEdges(Image* dest, Image* src, char threshold) {
  for (int r=0; r<src->rows; r++)  
    for (int c=0; c<src->cols; c++) {
      dest->row_ptrs[r][c]=isEdge(src, r, c, threshold);
    }
}
