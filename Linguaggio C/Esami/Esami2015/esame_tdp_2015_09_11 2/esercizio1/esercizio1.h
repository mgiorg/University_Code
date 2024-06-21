#ifndef _ESERCIZIO1_H_
#define _ESERCIZIO1_H_

typedef struct Mat {
  int rows;         // numero di righe
  int cols;         // numero di colonne
  int** row_ptrs; // puntatori alle righe
} Mat;

int matrixBlockCopy(Mat* dest, Mat* src, int start_row, int start_col);

#endif
