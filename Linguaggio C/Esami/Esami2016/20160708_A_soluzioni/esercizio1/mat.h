#ifndef _MAT_H_
#define _MAT_H_

typedef struct Mat {
  int rows;       
  int cols;       
  float** row_ptrs;
} Mat;

#endif
