#ifndef _MAT_H_
#define _MAT_H_

typedef struct Mat {
  int rows;         
  int cols;         
  int** row_ptrs; 
} Mat;

#endif
