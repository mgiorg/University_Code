#include "funzioni.c"


void applicaFiltro(Mat *src, Mat * filtro, int riga, int colonna){
	printf("Matrice iniziale: \n");
	printMatrix(src);
  // Implementare la soluzione dell'esercizio
	for(int i = 0; i < filtro->rows; i++) {
		for(int j = 0; j < filtro->cols; j++) {
			src-> row_ptrs[riga+i][colonna+j] *= filtro-> row_ptrs[i][j];
		}
	}

  return;
}

int main() {


	return 0;
}