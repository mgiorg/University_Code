#ifndef _SPARSE_MATRIX_ELEMENT_H_
#define _SPARSE_MATRIX_ELEMENT_H_

// element of a sparse matrix
struct SparseMatrixElement {
  int row;                    // row index in the matrix
  int col;                    // col index in the matrix
  float value;                // value
  struct SparseMatrixElement* next;  // next ptr
};
typedef struct SparseMatrixElement SparseMatrixElement;
typedef SparseMatrixElement* SparseMatrix;

#endif
