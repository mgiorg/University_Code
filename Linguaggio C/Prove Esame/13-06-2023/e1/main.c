#include "funzioni.c"

int somma(Mat* m) {
	int sum = 0;
	int max = -9999;
	for(int row = 0; row < m-> rows/2; ++row) {
		for(int col = 0; col < m->cols/2; ++col) {
			sum+= m-> mat[row][col];
		}
	}
	if(sum > max){ max = sum; }
  	sum = 0;
	for(int row = 0; row < m-> rows/2; ++row) {
		for(int col = m->cols/2; col < m->cols; ++col) {
			sum+= m-> mat[row][col];
		}
	}
	if(sum > max){ max = sum; }
  	sum = 0;
	for(int row = m-> rows/2; row < m-> rows; ++row) {
		for(int col = 0; col < m->cols/2; ++col) {
			sum+= m-> mat[row][col];
		}
	}
	if(sum > max){ max = sum; }
  	sum = 0;
	for(int row = m-> rows/2; row < m-> rows; ++row) {
		for(int col = m->cols/2; col < m->cols; ++col) {
			sum+= m-> mat[row][col];
		}
	}
	if(sum > max){ max = sum; }
  	sum = 0;
	return max;
}

int massimo_flip_riga(Mat *m){
	Mat* mat = mat_alloc(m-> rows, m-> cols);
	for(int i = 0; i < m-> rows; ++i) {
		for(int j = 0; j < m-> cols; ++j) {
			if(i%2 == 0) {
				//riga pari - FLIP
				mat-> mat[i][j] = m-> mat[i][m->cols-1-j];
			}
			else mat-> mat[i][j] = m-> mat[i][j];
		}
	}
	return somma(mat);
}


int main() {

	return 0;
}