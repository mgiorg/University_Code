#pragma once

typedef struct Mat {
  int rows; // numero di righe
  int cols; // numero di colonne
  int** row_ptrs; // puntatori alle righe
} Mat;

void matrixPrint(Mat* src);
Mat* matrixGenerate(int rows, int cols);

int checkIfGood(Mat* src, Mat* dest, int num_row_blocks, int num_col_blocks);
