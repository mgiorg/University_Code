#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
  int rows;
  int cols;
  double **mat;
} Mat;

typedef int T;
struct NodoSCL
{
    T info;
    struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;

#define ERRORE_InfoAlbBin -99999
typedef int TipoInfoAlbero;

typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;

int diagPrincipale(Mat* m, int a, int b) {
  return m-> mat[a][b]+m-> mat[a+1][b+1]+m-> mat[a+2][b+2];
}

int diagSecondaria(Mat* m, int a, int b) {
  return m-> mat[a+2][b]+m-> mat[a+1][b+1]+m-> mat[a][b+2];
}

Mat* mat_copy(Mat* m, int a, int b) {
  Mat* r = mat_alloc(3, 3);
  r-> mat[0][0] = m-> mat[a][b]; r-> mat[0][1] = m-> mat[a][b+1]; r-> mat[0][2] = m-> mat[a][b+2];
  r-> mat[1][0] = m-> mat[a+1][b]; r-> mat[1][1] = m-> mat[a+1][b+1]; r-> mat[1][2] = m-> mat[a+1][b+2];
  r-> mat[2][0] = m-> mat[a+2][b]; r-> mat[2][1] = m-> mat[a+2][b+1]; r-> mat[2][2] = m-> mat[a+2][b+2];

  return r;
}

Mat* restituisciSottoMatrice(Mat *m) {

  int cols = m-> cols;
  int rows = m-> rows;
  
  for(int i = 0; i <= rows-3; ++i) {
  	for(int j = 0; j <= cols-3; ++j) {
      if(diagPrincipale(m, i, j) > diagSecondaria(m, i, j)) return mat_copy(m, i, j);
    }
  }
  return NULL;
}